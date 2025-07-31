# pouring_controller.py
# Core control logic for saltwater precision pouring based on real-time weight and concentration feedback

import time
from .scale_interface import ScaleInterface
from .concentration_calculator import ConcentrationCalculator

class PouringController:
    def __init__(self, scale: ScaleInterface, salt_mass_grams: float = 15.0,
                 target_concentration_percent: float = 3.0, tolerance: float = 0.05):
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

    def set_salt_mass(self, mass: float):
        """Set the salt mass for the experiment"""
        self.salt_mass = mass
        print(f"[INFO] Salt mass set to {mass:.3f}g")

    def set_target_concentration(self, concentration: float):
        """Set the target concentration"""
        self.target_conc = concentration
        print(f"[INFO] Target concentration set to {concentration:.3f}%")

    def wait_for_initial_zero(self):
        """Waits until scale stabilizes near 0g to begin"""
        print("[INFO] Waiting for scale to be tared to ~0g...")
        max_attempts = 50
        attempts = 0
        
        while attempts < max_attempts:
            current = self.scale.read_weight()
            if current is not None and abs(current) < 1.0:
                break
            time.sleep(0.2)
            attempts += 1
            
        if attempts >= max_attempts:
            print("[WARN] Scale did not stabilize, proceeding anyway...")
        else:
            print("[INFO] Scale tared. Starting control.")

    def pour_loop(self):
        """Main loop to monitor and stop pouring at precise concentration"""
        print(f"[INFO] Target: {self.target_conc:.3f}% with salt mass = {self.salt_mass:.3f}g")
        self.wait_for_initial_zero()

        max_iterations = 1000  # Prevent infinite loop
        iterations = 0

        while iterations < max_iterations:
            total_mass = self.scale.read_weight()
            if total_mass is None:
                print("[WARN] Could not read weight, retrying...")
                time.sleep(0.5)
                iterations += 1
                continue
                
            if total_mass <= self.salt_mass:
                print("[WARN] Total mass less than salt mass. Waiting for water...")
                time.sleep(0.5)
                iterations += 1
                continue

            concentration = self.calc.compute_concentration(self.salt_mass, total_mass)
            print(f"[DEBUG] Total mass: {total_mass:.3f} g | Concentration: {concentration:.3f}%")

            if self.calc.is_target_reached(concentration, self.target_conc, self.tolerance):
                print("[SUCCESS] Target concentration reached. Stopping pouring.")
                return total_mass  # Return final mass
                
            time.sleep(0.1)  # Adjust if pouring is slow or noisy
            iterations += 1

        print("[WARN] Pour loop exceeded maximum iterations")
        return self.scale.read_weight() or 0.0

    def pour_until_target(self):
        """Pour until target concentration is reached and return final volume"""
        final_mass = self.pour_loop()
        # Assuming density ≈ 1 g/ml for dilute salt solutions
        final_volume = final_mass  
        print(f"[INFO] Final volume: {final_volume:.2f}ml")
        return final_volume

    def estimate_required_water(self):
        """Calculates and returns water mass needed to reach target from current state"""
        current_total_mass = self.scale.read_weight()
        if current_total_mass is None:
            current_total_mass = self.salt_mass  # Assume only salt present
            
        required = self.calc.required_water_for_target(self.salt_mass, self.target_conc)
        if required is None:
            return 0.0
            
        remaining = required - (current_total_mass - self.salt_mass)
        return max(0.0, remaining)


def main():
    """Test function for pouring controller"""
    print("🧪 Testing Pouring Controller")
    print("=" * 30)
    
    # Mock scale for testing
    class MockScale:
        def __init__(self):
            self.weight = 0.0
            
        def read_weight(self):
            # Simulate gradual weight increase
            self.weight += 0.5
            return self.weight
            
        def tare(self):
            self.weight = 0.0
            return True
            
        def close(self):
            pass
    
    # Test with mock scale
    mock_scale = MockScale()
    controller = PouringController(
        scale=mock_scale,
        salt_mass_grams=5.0,
        target_concentration_percent=3.0,
        tolerance=0.1
    )
    
    print(f"Initial setup:")
    print(f"  Salt mass: {controller.salt_mass}g")
    print(f"  Target concentration: {controller.target_conc}%")
    print(f"  Tolerance: {controller.tolerance}%")
    
    # Estimate required water
    required_water = controller.estimate_required_water()
    print(f"  Estimated required water: {required_water:.2f}g")
    
    # Test changing parameters
    controller.set_salt_mass(10.0)
    controller.set_target_concentration(5.0)
    
    print("\n✅ Pouring controller test completed")


if __name__ == "__main__":
    main()
