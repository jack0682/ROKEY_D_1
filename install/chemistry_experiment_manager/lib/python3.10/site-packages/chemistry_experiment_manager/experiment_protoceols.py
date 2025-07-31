# chemistry_experiment_manager/experiment_protocols.py

from time import sleep
from typing import List, Callable
from pathlib import Path
import csv

from precision_liquid_pouring.scale_interface import ScaleInterface
from precision_liquid_pouring.pouring_controller import PouringController
from precision_liquid_pouring.concentration_calculator import ConcentrationCalculator
from chemistry_experiment_manager import config

# 타입 힌트용 로거 함수
ResultLogger = Callable[[dict], None]

def fixed_concentration_protocol(
    scale: ScaleInterface,
    controller: PouringController,
    calculator: ConcentrationCalculator,
    log_result: ResultLogger,
):
    for concentration in config.TARGET_CONCENTRATIONS:
        for trial in range(config.NUM_TRIALS):
            print(f"\n[Trial {trial + 1}] Target: {concentration:.2f}%")

            scale.tare()
            salt_weight = config.FIXED_SALT_WEIGHT_GRAMS
            controller.set_salt_mass(salt_weight)
            controller.set_target_concentration(concentration)

            final_volume = controller.pour_until_target()
            final_conc = calculator.calculate_concentration(salt_weight, final_volume)

            result = {
                "trial": trial + 1,
                "target_concentration": concentration,
                "actual_concentration": final_conc,
                "final_volume_ml": final_volume,
                "salt_weight_g": salt_weight,
            }

            log_result(result)
            sleep(config.INTER_TRIAL_DELAY_SEC)


def save_results_to_csv(results: List[dict], filename: str):
    filepath = config.RESULT_DIR / filename
    with open(filepath, mode="w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=results[0].keys())
        writer.writeheader()
        for row in results:
            writer.writerow(row)
    print(f"[✔] Results saved to {filepath}")
