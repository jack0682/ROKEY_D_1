from chemistry_experiment_manager.experiment_protocols import fixed_concentration_protocol
from chemistry_experiment_manager.experiment_logger import ExperimentLogger

from precision_liquid_pouring.scale_interface import ScaleInterface
from precision_liquid_pouring.pouring_controller import PouringController
from precision_liquid_pouring.concentration_calculator import ConcentrationCalculator


def main():
    # 하드웨어 및 알고리즘 구성 요소 초기화
    scale = ScaleInterface()
    controller = PouringController(scale)
    calculator = ConcentrationCalculator()

    # 로그 기록기 생성
    logger = ExperimentLogger(log_dir="./logs", filename_prefix="salinity_test")

    # 실험 실행
    fixed_concentration_protocol(
        scale=scale,
        controller=controller,
        calculator=calculator,
        log_result=logger.log,
    )

    print(f"\n✅ 실험 완료! 결과 로그 저장 위치: {logger.get_log_path()}")


if __name__ == "__main__":
    main()
