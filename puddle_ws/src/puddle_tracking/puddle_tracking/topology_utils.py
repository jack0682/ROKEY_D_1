import cv2
import numpy as np
from scipy.ndimage import label

def compute_euler_characteristic(mask: np.ndarray) -> int:
    """
    binary mask로부터 Euler 특성 χ = β₀ - β₁ 계산
    :param mask: binary mask (255 = puddle, 0 = background)
    :return: 정수형 Euler characteristic
    """

    # 1. Connected components (β₀): foreground 연결 요소 개수
    num_labels, _ = cv2.connectedComponents(mask)

    # 2. Holes (β₁): 내부 구멍 = inverse mask에서 연결 컴포넌트 개수 - 1 (배경 제외)
    inverse = cv2.bitwise_not(mask)
    holes, _ = cv2.connectedComponents(inverse)

    beta_0 = num_labels - 1  # label=0은 배경
    beta_1 = holes - 1

    chi = beta_0 - beta_1
    return chi

def beta_components(mask: np.ndarray) -> tuple:
    """
    β₀, β₁ 값을 직접 반환
    """
    num_labels, _ = cv2.connectedComponents(mask)
    inverse = cv2.bitwise_not(mask)
    holes, _ = cv2.connectedComponents(inverse)
    return num_labels - 1, holes - 1
