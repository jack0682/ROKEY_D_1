# 단일 이미지 추론 테스트 스크립트
import cv2
import torch
import numpy as np
from pathlib import Path
import sys
import os

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
MODEL_DIR = os.path.abspath(os.path.join(CURRENT_DIR, "..", "agsenet_model"))
sys.path.append(MODEL_DIR)

from AGSENet import AGSENet

model_path = str(Path(__file__).parent.parent / "models" / "best.pt")
image_path = str(Path(__file__).parent.parent / "test_image.jpg")  # 테스트 이미지 지정

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = AGSENet()
model.load_state_dict(torch.load(model_path, map_location=device))
model.eval().to(device)

img = cv2.imread(image_path)
img_resized = cv2.resize(img, (256, 256))
input_tensor = torch.from_numpy(img_resized.transpose(2, 0, 1)).float() / 255.0
input_tensor = input_tensor.unsqueeze(0).to(device)

with torch.no_grad():
    output = model(input_tensor)

mask = torch.sigmoid(output).squeeze().cpu().numpy()
mask_bin = (mask > 0.5).astype(np.uint8) * 255
mask_up = cv2.resize(mask_bin, (img.shape[1], img.shape[0]))

cv2.imshow("Original", img)
cv2.imshow("Puddle Mask", mask_up)
cv2.waitKey(0)
