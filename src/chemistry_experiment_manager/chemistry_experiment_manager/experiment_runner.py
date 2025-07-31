# chemistry_experiment_manager/experiment_runner.py

from precision_liquid_pouring.scale_interface import ScaleInterface
from precision_liquid_pouring.pouring_controller import PouringController
from precision_liquid_pouring.concentration_calculator import ConcentrationCalculator
from chemistry_experiment_manager.experiment_protocols import fixed_concentration_protocol, save_results_to_csv


def main():
    scale = ScaleInterface()
    controller = PouringController(scale)
    calculator = ConcentrationCalculator()

    results = []

    def log_result(entry: dict):
        print(entry)
        results.append(entry)

    fixed_concentration_protocol(
        scale=scale,
        controller=controller,
        calculator=calculator,
        log_result=log_result,
    )

    save_results_to_csv(results, filename="experiment_results.csv")


if __name__ == "__main__":
    main()
