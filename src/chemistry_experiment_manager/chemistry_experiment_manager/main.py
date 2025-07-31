#!/usr/bin/env python3

import sys
import os
from pathlib import Path

# Add the package to Python path for imports
sys.path.insert(0, str(Path(__file__).parent.parent))

from chemistry_experiment_manager.experiment_protocols import fixed_concentration_protocol
from chemistry_experiment_manager.experiment_logger import ExperimentLogger
from chemistry_experiment_manager import config

# Import from precision_liquid_pouring package
try:
    from precision_liquid_pouring.scale_interface import ScaleInterface
    from precision_liquid_pouring.pouring_controller import PouringController
    from precision_liquid_pouring.concentration_calculator import ConcentrationCalculator
except ImportError as e:
    print(f"Warning: Could not import precision_liquid_pouring components: {e}")
    print("Running in simulation mode...")
    
    # Provide mock classes for testing
    class ScaleInterface:
        def __init__(self, *args, **kwargs):
            print("[MOCK] ScaleInterface initialized")
        def tare(self):
            print("[MOCK] Scale tared")
            return True
        def read_weight(self):
            import random
            return random.uniform(50.0, 150.0)  # Mock weight reading
        def close(self):
            print("[MOCK] Scale closed")
    
    class PouringController:
        def __init__(self, scale, *args, **kwargs):
            self.scale = scale
            print("[MOCK] PouringController initialized")
        def set_salt_mass(self, mass):
            print(f"[MOCK] Salt mass set to {mass}g")
        def set_target_concentration(self, conc):
            print(f"[MOCK] Target concentration set to {conc}%")
        def pour_until_target(self):
            import random
            volume = random.uniform(95.0, 105.0)
            print(f"[MOCK] Pouring complete, final volume: {volume:.2f}ml")
            return volume
    
    class ConcentrationCalculator:
        def __init__(self, *args, **kwargs):
            print("[MOCK] ConcentrationCalculator initialized")
        def calculate_concentration(self, salt_weight, volume):
            if volume > 0:
                return (salt_weight / volume) * 100.0
            return 0.0


def main():
    """Main entry point for chemistry experiment manager"""
    print("🧪 Starting Chemistry Experiment Manager")
    print("=" * 50)
    
    try:
        # Initialize hardware and algorithm components
        print("Initializing components...")
        scale = ScaleInterface(port="/dev/ttyUSB0", baudrate=38400, samples=15)
        calculator = ConcentrationCalculator()
        controller = PouringController(scale, salt_mass_grams=config.FIXED_SALT_WEIGHT_GRAMS, 
                                     target_concentration_percent=3.0)

        # Create experiment logger
        logger = ExperimentLogger(log_dir=str(config.RESULT_DIR), filename_prefix="chemistry_experiment")
        
        print(f"📊 Experiment Configuration:")
        print(f"   - Target concentrations: {config.TARGET_CONCENTRATIONS}")
        print(f"   - Number of trials per concentration: {config.NUM_TRIALS}")
        print(f"   - Salt weight: {config.FIXED_SALT_WEIGHT_GRAMS}g")
        print(f"   - Tolerance: ±{config.CONCENTRATION_TOLERANCE}%")
        print(f"   - Results will be saved to: {config.RESULT_DIR}")
        print()

        # Run the experiment protocol
        print("🚀 Starting experiment protocol...")
        
        def log_result(entry: dict):
            """Enhanced logging function"""
            trial = entry.get('trial', '?')
            target = entry.get('target_concentration', 0)
            actual = entry.get('actual_concentration', 0)
            volume = entry.get('final_volume_ml', 0)
            error = abs(actual - target) if target > 0 else 0
            
            print(f"   Trial {trial}: Target={target:.2f}%, Actual={actual:.2f}%, "
                  f"Volume={volume:.1f}ml, Error={error:.3f}%")
            
            # Call the original logger
            logger.log(entry)

        fixed_concentration_protocol(
            scale=scale,
            controller=controller,
            calculator=calculator,
            log_result=log_result,
        )

        print(f"\n✅ Experiment completed successfully!")
        print(f"📁 Results saved to: {logger.get_log_path()}")
        
    except KeyboardInterrupt:
        print("\n⚠️  Experiment interrupted by user")
    except Exception as e:
        print(f"\n❌ Experiment failed with error: {e}")
        import traceback
        traceback.print_exc()
    finally:
        # Cleanup
        try:
            if 'scale' in locals():
                scale.close()
            print("🔧 Cleanup completed")
        except:
            pass


def test_components():
    """Test individual components"""
    print("🔧 Testing Chemistry Experiment Components")
    print("=" * 50)
    
    # Test ConcentrationCalculator
    print("Testing ConcentrationCalculator...")
    calc = ConcentrationCalculator()
    
    test_cases = [
        (5.0, 100.0, 5.0),
        (2.0, 50.0, 4.0),
        (10.0, 200.0, 5.0),
    ]
    
    for salt, volume, expected in test_cases:
        result = calc.calculate_concentration(salt, volume)
        print(f"   {salt}g salt in {volume}ml → {result:.2f}% (expected {expected:.2f}%)")
    
    # Test ScaleInterface (mock)
    print("\nTesting ScaleInterface...")
    scale = ScaleInterface()
    if scale.tare():
        print("   Scale tare: ✅")
    weight = scale.read_weight()
    print(f"   Weight reading: {weight:.2f}g")
    scale.close()
    
    print("\n✅ Component tests completed")


if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1 and sys.argv[1] == "test":
        test_components()
    else:
        main()
