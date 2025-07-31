# pouring_controller.py
# Core control logic for saltwater precision pouring based on real-time weight and concentration feedback

import time
from .scale_interface import ScaleInterface
from .concentration_calculator import ConcentrationCalculator

class PouringController:
    def __init__(self, scale: ScaleInterface, salt_mass_grams: float,
                 target_concentration_percent: float, tolerance: float = 0.05):
        """
        :param scale: Interface to physical or simulated scale
        :param salt_mass_grams: Fixed salt mass in grams (pre-mixed)
        :param target_concentration_percent: Target concentration in % (e.g., 3.0)
        :param tolerance: Acceptable deviation from target (default 0.05%)
        """
        self.scale = scale
        self.salt_mass = salt_mass_grams
        self.target_conc = target_concentration_percent
        self.tolerance = tolerance
        self.calc = ConcentrationCalculator()

    def wait_for_initial_zero(self):
        """Waits until scale stabilizes near 0g to begin"""
        print("[INFO] Waiting for scale to be tared to ~0g...")
        while True:
            current = self.scale.read_weight()
            if abs(current) < 1.0:
                break
            time.sleep(0.2)
        print("[INFO] Scale tared. Starting control.")

    def pour_loop(self):
        """Main loop to monitor and stop pouring at precise concentration"""
        print(f"[INFO] Target: {self.target_conc:.3f}% with salt mass = {self.salt_mass:.3f}g")
        self.wait_for_initial_zero()

        while True:
            total_mass = self.scale.read_weight()
            if total_mass <= self.salt_mass:
                print("[WARN] Total mass less than salt mass. Waiting for water...")
                time.sleep(0.5)
                continue

            concentration = self.calc.compute_concentration(self.salt_mass, total_mass)
            print(f"[DEBUG] Total mass: {total_mass:.3f} g | Concentration: {concentration:.3f}%")

            if self.calc.is_target_reached(concentration, self.target_conc, self.tolerance):
                print("[SUCCESS] Target concentration reached. Stopping pouring.")
                break
            time.sleep(0.1)  # Adjust if pouring is slow or noisy

    def estimate_required_water(self):
        """Calculates and returns water mass needed to reach target from current state"""
        current_total_mass = self.scale.read_weight()
        required = self.calc.required_water_for_target(self.salt_mass, self.target_conc)
        remaining = required - current_total_mass
        return max(0.0, remaining)


if __name__ == "__main__":
    # Example usage (for manual testing)
    scale = ScaleInterface(port="/dev/ttyUSB0", reference_unit=-7050, offset=0)
    controller = PouringController(scale, salt_mass_grams=15.0, target_concentration_percent=3.0)
    controller.pour_loop()
