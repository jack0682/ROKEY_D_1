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

    def __init__(self, salt_mass_g: float = 0.0, initial_water_mass_g: float = 0.0):
        """
        :param salt_mass_g: 투입된 소금의 질량 (g)
        :param initial_water_mass_g: 초기 물의 질량 (g)
        """
        self.salt_mass = salt_mass_g
        self.initial_water_mass = initial_water_mass_g
        self.total_mass = salt_mass_g + initial_water_mass_g
        self.current_water_mass = initial_water_mass_g

        if salt_mass_g > 0 and initial_water_mass_g > 0:
            logger.info(f"초기 설정: 소금 {salt_mass_g}g, 물 {initial_water_mass_g}g")

    def compute_concentration(self, salt_mass: float, total_mass: float) -> float:
        """Static method for computing concentration from masses"""
        if total_mass <= 0:
            return 0.0
        return (salt_mass / total_mass) * 100.0

    def get_concentration_percent(self) -> float:
        """현재 소금물의 농도를 %로 반환 (w/w)"""
        if self.total_mass <= 0:
            return 0.0
        concentration = (self.salt_mass / self.total_mass) * 100.0
        logger.debug(f"현재 농도 계산: {concentration:.4f}%")
        return round(concentration, 4)

    def add_water(self, added_mass_g: float):
        """정밀하게 물을 추가하여 농도 갱신"""
        if added_mass_g <= 0.0:
            return
        self.current_water_mass += added_mass_g
        self.total_mass = self.salt_mass + self.current_water_mass
        logger.info(f"물 {added_mass_g:.4f}g 추가됨, 총 물: {self.current_water_mass:.4f}g")

    def is_target_reached(self, current_concentration: float, target_percent: float, tolerance: float = 0.05) -> bool:
        """목표 농도 도달 여부 평가
        :param current_concentration: 현재 농도 (%)
        :param target_percent: 목표 농도 (%)
        :param tolerance: 허용 오차 범위 (단위: %)
        """
        deviation = abs(current_concentration - target_percent)
        logger.debug(f"목표: {target_percent:.3f}%, 현재: {current_concentration:.3f}%, 편차: {deviation:.3f}%")
        return deviation <= tolerance

    def required_water_for_target(self, salt_mass: float, target_percent: float) -> Optional[float]:
        """목표 농도에 도달하기 위해 필요한 물의 질량 (g) 계산
        :param salt_mass: 소금 질량 (g)
        :param target_percent: 목표 농도 (%)
        :return: 필요한 총 물의 질량. 도달 불가능할 경우 None
        """
        if target_percent <= 0.0 or target_percent >= 100.0:
            logger.warning("비현실적 목표 농도")
            return None

        try:
            required_total_mass = salt_mass * 100.0 / target_percent
            required_water = required_total_mass - salt_mass
            logger.debug(f"목표 농도 {target_percent:.3f}% 도달 위해 물 {required_water:.4f}g 필요")
            return round(required_water, 4) if required_water > 0 else 0.0
        except ZeroDivisionError:
            logger.exception("0으로 나누기 오류")
            return None

    def calculate_concentration(self, salt_weight: float, total_volume: float) -> float:
        """Calculate concentration from salt weight and total volume"""
        if total_volume <= 0:
            return 0.0
        # Assuming density is approximately 1 g/ml for dilute solutions
        return (salt_weight / total_volume) * 100.0


def main():
    """Test function for direct execution"""
    print("Testing Concentration Calculator...")
    
    calc = ConcentrationCalculator()
    
    # Test cases
    test_cases = [
        (5.0, 100.0, 5.0),  # 5g salt in 100g total = 5%
        (2.0, 50.0, 4.0),   # 2g salt in 50g total = 4%
        (1.0, 20.0, 5.0),   # 1g salt in 20g total = 5%
    ]
    
    for salt, total, expected in test_cases:
        result = calc.compute_concentration(salt, total)
        print(f"Salt: {salt}g, Total: {total}g => Concentration: {result:.2f}% (Expected: {expected:.2f}%)")
        
        # Test target reached
        reached = calc.is_target_reached(result, expected, 0.1)
        print(f"Target reached: {reached}")
        
    # Test required water calculation
    required = calc.required_water_for_target(5.0, 3.0)  # 5g salt for 3% concentration
    print(f"Required water for 5g salt at 3% concentration: {required:.2f}g")


if __name__ == "__main__":
    main()
