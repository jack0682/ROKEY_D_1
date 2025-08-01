#!/bin/bash

# Final setup script for clean Doosan M0609 bringup package
# This script makes the launch files executable and prepares the package for use

set -e  # Exit on any error

echo "======================================================"
echo "🚀 Finalizing Doosan M0609 Clean Bringup Package"
echo "======================================================"

# Navigate to the workspace
cd /home/jack/project_ws

# Make launch files executable
echo "🔑 Setting executable permissions..."
chmod +x src/doosan_m0609_bringup/launch/*.py

# Check if required packages exist
echo "📦 Checking dependencies..."
REQUIRED_PACKAGES=("dsr_description2" "dsr_hardware2" "dsr_common2")
for pkg in "${REQUIRED_PACKAGES[@]}"; do
    if [[ ! -d "src/$pkg" ]]; then
        echo "⚠️  Warning: Required package '$pkg' not found in src/"
        echo "   Make sure this package is available before building"
    else
        echo "✅ Found: $pkg"
    fi
done

# Build only the new bringup package
echo "🔨 Building doosan_m0609_bringup package..."
colcon build --packages-select doosan_m0609_bringup --cmake-args -DCMAKE_BUILD_TYPE=Release

# Source the workspace
echo "🔄 Sourcing workspace..."
source install/setup.bash

# Verify the package installation
echo "🔍 Verifying package installation..."
if ros2 pkg list | grep -q "doosan_m0609_bringup"; then
    echo "✅ Package successfully installed!"
else
    echo "❌ Package installation failed!"
    exit 1
fi

# Show available launch files
echo ""
echo "📋 Available launch files:"
echo "   ros2 launch doosan_m0609_bringup m0609_real.launch.py --show-args"
echo "   ros2 launch doosan_m0609_bringup m0609_virtual.launch.py --show-args"  
echo "   ros2 launch doosan_m0609_bringup m0609_bringup.launch.py --show-args"

# Test launch file syntax
echo ""
echo "🧪 Testing launch file syntax..."
LAUNCH_FILES=("m0609_bringup.launch.py" "m0609_real.launch.py" "m0609_virtual.launch.py")
for launch_file in "${LAUNCH_FILES[@]}"; do
    if python3 -m py_compile "src/doosan_m0609_bringup/launch/$launch_file"; then
        echo "✅ $launch_file syntax OK"
    else
        echo "❌ $launch_file syntax error!"
        exit 1
    fi
done

echo ""
echo "======================================================"
echo "🎉 Setup Complete! Package is ready to use."
echo "======================================================"
echo ""
echo "📖 Quick Start:"
echo ""
echo "1. For Virtual Mode (Testing):"
echo "   ros2 launch doosan_m0609_bringup m0609_virtual.launch.py"
echo ""
echo "2. For Real Robot Mode:"
echo "   ros2 launch doosan_m0609_bringup m0609_real.launch.py host:=192.168.137.100"
echo ""
echo "3. Check available options:"
echo "   ros2 launch doosan_m0609_bringup m0609_bringup.launch.py --show-args"
echo ""
echo "🔍 Troubleshooting:"
echo "   - Check dependencies: rosdep install --from-paths src --ignore-src -r -y"
echo "   - Rebuild if needed: colcon build --packages-select doosan_m0609_bringup"
echo "   - Source workspace: source install/setup.bash"
echo ""
echo "📚 Full documentation available in:"
echo "   src/doosan_m0609_bringup/README.md"
echo "======================================================"