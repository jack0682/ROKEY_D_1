import cv2
import numpy as np

def compute_hu_moments(contour) -> np.ndarray:
    """
    Hu Moments (7-dim) 추출
    :param contour: OpenCV contour (numpy array)
    :return: log-transformed Hu Moments (np.ndarray)
    """
    M = cv2.moments(contour)
    if M["m00"] == 0:
        return np.zeros(7)
    hu = cv2.HuMoments(M).flatten()
    hu_log = -np.sign(hu) * np.log10(np.abs(hu) + 1e-10)  # log scale 변환
    return hu_log

def compare_hu_distance(hu1: np.ndarray, hu2: np.ndarray) -> float:
    """
    두 Hu moment 간 유클리드 거리 (log scale)
    :param hu1: Hu vector 1
    :param hu2: Hu vector 2
    :return: L2 거리 (float)
    """
    return np.linalg.norm(hu1 - hu2)

def contour_center(contour) -> tuple:
    """
    contour의 중심점 반환
    :return: (cx, cy)
    """
    M = cv2.moments(contour)
    if M["m00"] == 0:
        return (0, 0)
    cx = int(M["m10"] / M["m00"])
    cy = int(M["m01"] / M["m00"])
    return (cx, cy)

def compute_area(contour) -> float:
    return cv2.contourArea(contour)
