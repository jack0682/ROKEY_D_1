#!/usr/bin/env python3

import sys
import time
from pathlib import Path

# Add package to path for testing
sys.path.insert(0, str(Path(__file__).parent.parent))

try:
    from precision_liquid_pouring.scale_interface import ScaleInterface
    from precision_liquid_pouring.pouring_controller import PouringController
    from precision_liquid_pouring.concentration_calculator import ConcentrationCalculator
    from precision_liquid_pouring.utils import Timer, setup_logger
    from precision_liquid_pouring import config
except ImportError as e:
    print(f"Import error: {e}")
    sys.exit(1)


def main():
    """Main entry point for precision liquid pouring system"""
    print("💧 Precision Liquid Pouring System")
    print("=" * 40)
    
    # Setup logging
    logger = setup_logger("precision_pouring")
    logger.info("Starting Precision Liquid Pouring System...")
    
    # Initialize timer
    timer = Timer()
    timer.start()
    
    try:
        # Initialize components
        print("🔧 Initializing components...")
        
        # Scale interface
        scale = ScaleInterface(
            port=config.SCALE_SERIAL_PORT,
            baudrate=38400,
            samples=15
        )
        
        # Concentration calculator
        calculator = ConcentrationCalculator()
        
        # Pouring controller
        controller = PouringController(
            scale=scale,
            salt_mass_grams=config.FIXED_SALT_GRAMS,
            target_concentration_percent=config.TARGET_CONCENTRATION_PERCENT,
            tolerance=config.TOLERANCE_PERCENT
        )
        
        print("✅ Components initialized successfully!")
        print(f"📊 Configuration:")
        print(f"   - Target: {controller.target_conc:.2f}% concentration")
        print(f"   - Salt mass: {controller.salt_mass:.2f}g")
        print(f"   - Tolerance: ±{controller.tolerance:.3f}%")
        print(f"   - Scale port: {config.SCALE_SERIAL_PORT}")
        
        # Perform tare
        print("\n🔄 Performing scale calibration...")
        if scale.tare():
            print("✅ Scale tared successfully")
        else:
            print("⚠️  Scale tare failed, continuing anyway...")
        
        # Estimate required water
        required_water = controller.estimate_required_water()
        print(f"📏 Estimated required water: {required_water:.2f}g")
        
        # Display instructions
        print("\n📋 Instructions:")
        print("   1. Place container with salt on scale")
        print("   2. Press Enter to start pouring control")
        print("   3. Add water gradually while system monitors")
        print("   4. System will indicate when target is reached")
        print("   5. Press Ctrl+C to stop at any time")
        
        input("\nPress Enter to start pouring control...")
        
        # Start pouring control loop
        print("\n🚀 Starting pouring control loop...")
        start_time = time.time()
        
        final_volume = controller.pour_until_target()
        
        end_time = time.time()
        duration = end_time - start_time
        
        # Calculate final results
        final_concentration = calculator.compute_concentration(
            controller.salt_mass, final_volume
        )
        
        # Display results
        print("\n" + "=" * 40)
        print("📊 EXPERIMENT RESULTS")
        print("=" * 40)
        print(f"✅ Target concentration: {controller.target_conc:.3f}%")
        print(f"📈 Actual concentration: {final_concentration:.3f}%")
        print(f"📏 Final volume: {final_volume:.2f}ml")
        print(f"🧂 Salt mass: {controller.salt_mass:.2f}g")
        print(f"⏱️  Duration: {duration:.1f} seconds")
        
        error = abs(final_concentration - controller.target_conc)
        error_percent = (error / controller.target_conc) * 100 if controller.target_conc > 0 else 0
        print(f"📐 Absolute error: {error:.3f}%")
        print(f"📊 Relative error: {error_percent:.2f}%")
        
        if error <= controller.tolerance:
            print("🎯 SUCCESS: Target achieved within tolerance!")
        else:
            print("⚠️  WARNING: Target not achieved within tolerance")
        
        logger.info(f"Experiment completed: {final_concentration:.3f}% in {duration:.1f}s")
        
    except KeyboardInterrupt:
        print("\n⚠️  Experiment interrupted by user")
        logger.info("Experiment interrupted by user")
    except Exception as e:
        print(f"\n❌ Experiment failed with error: {e}")
        logger.error(f"Experiment failed: {e}")
        import traceback
        traceback.print_exc()
    finally:
        # Cleanup
        print("\n🔧 Performing cleanup...")
        try:
            if 'scale' in locals():
                scale.close()
            print("✅ Cleanup completed")
            total_time = timer.elapsed()
            print(f"⏱️  Total runtime: {total_time:.1f} seconds")
        except Exception as e:
            print(f"⚠️  Cleanup error: {e}")


def test_system():
    """Test the precision liquid pouring system components"""
    print("🧪 Testing Precision Liquid Pouring System")
    print("=" * 45)
    
    # Test ConcentrationCalculator
    print("\n1️⃣ Testing ConcentrationCalculator...")
    calc = ConcentrationCalculator()
    
    test_cases = [
        (5.0, 100.0, 5.0),    # 5g salt in 100g total = 5%
        (2.0, 50.0, 4.0),     # 2g salt in 50g total = 4%
        (10.0, 200.0, 5.0),   # 10g salt in 200g total = 5%
        (1.0, 33.33, 3.0),    # 1g salt in 33.33g total ≈ 3%
    ]
    
    for i, (salt, total, expected) in enumerate(test_cases, 1):
        result = calc.compute_concentration(salt, total)
        error = abs(result - expected)
        status = "✅" if error < 0.1 else "⚠️"
        print(f"   Test {i}: {salt}g/{total}g → {result:.2f}% (exp: {expected:.2f}%) {status}")
    
    # Test required water calculation
    print("\n2️⃣ Testing required water calculation...")
    test_targets = [(5.0, 3.0), (10.0, 2.0), (2.0, 5.0)]
    
    for salt, target_conc in test_targets:
        required = calc.required_water_for_target(salt, target_conc)
        if required:
            total_mass = salt + required
            actual_conc = calc.compute_concentration(salt, total_mass)
            print(f"   {salt}g salt for {target_conc}% → need {required:.2f}g water (actual: {actual_conc:.2f}%)")
    
    # Test Timer utility
    print("\n3️⃣ Testing Timer utility...")
    timer = Timer()
    timer.start()
    time.sleep(0.1)
    elapsed = timer.elapsed()
    print(f"   Timer test: {elapsed:.3f}s (expected ~0.1s)")
    
    # Test Scale Interface (mock mode)
    print("\n4️⃣ Testing Scale Interface (mock mode)...")
    try:
        scale = ScaleInterface(port="/dev/null", baudrate=9600, samples=5)  # Will fail gracefully
        print("   Scale interface created ✅")
    except Exception as e:
        print(f"   Scale interface test failed (expected): {e}")
    
    print("\n✅ System component tests completed")


def demo_mode():
    """Run a demonstration with simulated data"""
    print("🎬 Running Precision Pouring Demo")
    print("=" * 35)
    
    # Mock scale that simulates realistic behavior
    class DemoScale:
        def __init__(self):
            self.current_weight = 0.0
            self.tared = False
            
        def tare(self):
            self.current_weight = 0.0
            self.tared = True
            return True
            
        def read_weight(self):
            if not self.tared:
                return None
            # Simulate gradual water addition
            self.current_weight += 0.8  # Add ~0.8g per reading
            return round(self.current_weight, 2)
            
        def close(self):
            pass
    
    # Run demo
    demo_scale = DemoScale()
    calculator = ConcentrationCalculator()
    controller = PouringController(
        scale=demo_scale,
        salt_mass_grams=5.0,
        target_concentration_percent=3.0,
        tolerance=0.1
    )
    
    print("🔧 Demo setup:")
    print(f"   Salt: {controller.salt_mass}g")
    print(f"   Target: {controller.target_conc}%")
    print(f"   Required water: ~{calculator.required_water_for_target(5.0, 3.0):.1f}g")
    
    print("\n🚀 Starting demo pouring simulation...")
    final_volume = controller.pour_until_target()
    final_conc = calculator.compute_concentration(controller.salt_mass, final_volume)
    
    print(f"\n📊 Demo Results:")
    print(f"   Final volume: {final_volume:.1f}ml")
    print(f"   Final concentration: {final_conc:.2f}%")
    print(f"   Error: {abs(final_conc - controller.target_conc):.3f}%")
    print("\n✅ Demo completed successfully!")


if __name__ == "__main__":
    import sys
    
    if len(sys.argv) > 1:
        command = sys.argv[1].lower()
        if command == "test":
            test_system()
        elif command == "demo":
            demo_mode()
        else:
            print(f"Unknown command: {command}")
            print("Available commands: test, demo")
            sys.exit(1)
    else:
        main()
