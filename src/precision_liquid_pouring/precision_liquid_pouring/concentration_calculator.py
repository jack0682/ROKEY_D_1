# concentration_calculator.py
# 정밀 액체 주입 제어 시스템을 위한 소금물 농도 계산 모듈

import math
import logging
from typing import Optional

logger = logging.getLogger("ConcentrationCalculator")
logger.setLevel(logging.INFO)


class ConcentrationCalculator:
    """
    순수물 + 소금 혼합물에서 정확한 농도를 계산하고 타겟 농도 도달 여부를 평가하는 유틸리티 클래스
    """

    def __init__(self, salt_mass_g: float, initial_water_mass_g: float):
        """
        :param salt_mass_g: 투입된 소금의 질량 (g)
        :param initial_water_mass_g: 초기 물의 질량 (g)
        """
        assert salt_mass_g > 0.0, "소금 질량은 0 이상이어야 합니다."
        assert initial_water_mass_g > 0.0, "물 질량은 0 이상이어야 합니다."

        self.salt_mass = salt_mass_g
        self.initial_water_mass = initial_water_mass_g
        self.total_mass = salt_mass_g + initial_water_mass_g
        self.current_water_mass = initial_water_mass_g

        logger.info(f"초기 설정: 소금 {salt_mass_g}g, 물 {initial_water_mass_g}g")

    def get_concentration_percent(self) -> float:
        """현재 소금물의 농도를 %로 반환 (w/w)"""
        concentration = (self.salt_mass / self.total_mass) * 100.0
        logger.debug(f"현재 농도 계산: {concentration:.4f}%")
        return round(concentration, 4)

    def add_water(self, added_mass_g: float):
        """정밀하게 물을 추가하여 농도 갱신"""
        assert added_mass_g > 0.0, "추가할 물의 질량은 0 이상이어야 합니다."
        self.current_water_mass += added_mass_g
        self.total_mass = self.salt_mass + self.current_water_mass
        logger.info(f"물 {added_mass_g:.4f}g 추가됨, 총 물: {self.current_water_mass:.4f}g")

    def is_target_reached(self, target_percent: float, tolerance: float = 0.05) -> bool:
        """목표 농도 도달 여부 평가
        :param target_percent: 목표 농도 (%)
        :param tolerance: 허용 오차 범위 (단위: %)
        """
        current = self.get_concentration_percent()
        deviation = abs(current - target_percent)
        logger.debug(f"목표: {target_percent:.3f}%, 현재: {current:.3f}%, 편차: {deviation:.3f}%")
        return deviation <= tolerance

    def required_water_for_target(self, target_percent: float) -> Optional[float]:
        """목표 농도에 도달하기 위해 필요한 물의 추가 질량 (g) 계산
        :return: 추가로 필요한 물의 질량. 도달 불가능할 경우 None
        """
        if target_percent <= 0.0 or target_percent >= 100.0:
            logger.warning("비현실적 목표 농도")
            return None

        try:
            required_total_mass = self.salt_mass * 100.0 / target_percent
            additional_water = required_total_mass - self.salt_mass - self.current_water_mass
            logger.debug(f"목표 농도 {target_percent:.3f}% 도달 위해 물 {additional_water:.4f}g 추가 필요")
            return round(additional_water, 4) if additional_water > 0 else 0.0
        except ZeroDivisionError:
            logger.exception("0으로 나누기 오류")
            return None
