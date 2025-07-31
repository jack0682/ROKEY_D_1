import time
import logging

from precision_liquid_pouring.config import Config
from precision_liquid_pouring.utils import setup_logger, wait_until
from precision_liquid_pouring.scale_interface import ScaleInterface
from precision_liquid_pouring.concentration_calculator import ConcentrationCalculator
from precision_liquid_pouring.pouring_controller import PouringController


def main():
    setup_logger()
    logger = logging.getLogger("main")
    logger.info("Starting Precision Liquid Pouring System")

    # Initialize modules
    config = Config()
    scale = ScaleInterface(config)
    calculator = ConcentrationCalculator(config)
    controller = PouringController(config, scale, calculator)

    try:
        # Step 1: Tare the scale
        scale.tare()

        # Step 2: Set initial mass of salt (already placed)
        controller.set_salt_mass(config.salt_mass_g)

        # Step 3: Execute pouring process
        controller.execute_pouring()

        # Step 4: Get final result
        final_result = calculator.calculate_concentration(
            controller.salt_mass, controller.poured_mass
        )
        logger.info(f"Final concentration: {final_result:.4f} %")

    except Exception as e:
        logger.exception(f"Exception occurred during operation: {e}")
    finally:
        logger.info("Experiment finished. Shutting down.")


if __name__ == "__main__":
    main()
