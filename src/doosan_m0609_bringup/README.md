# Doosan M0609 Bringup Package

Clean and properly structured ROS2 bringup package for Doosan M0609 collaborative robot following official Doosan robotics architecture.

## 🏗️ Package Structure

```
doosan_m0609_bringup/
├── launch/
│   ├── m0609_bringup.launch.py     # Main unified launch file
│   ├── m0609_real.launch.py        # Real robot mode launch
│   └── m0609_virtual.launch.py     # Virtual/simulation mode launch
├── config/
│   └── ros2_controllers.yaml       # ROS2 Control configuration
├── rviz/
│   └── m0609.rviz                  # RViz visualization config
├── package.xml                     # Package dependencies
├── CMakeLists.txt                  # Build configuration
└── README.md                       # This file
```

## 🔧 Key Features

### 1. **Clean Architecture**
- **No duplicate files** - Single source of truth for each configuration
- **Modular design** - Separate launch files for different use cases
- **Proper ROS2 Control integration** - Uses dsr_hardware2 interface

### 2. **Dual Mode Support**
- **Real Mode**: Direct connection to physical M0609 robot via DRFL
- **Virtual Mode**: Simulation/testing without physical hardware

### 3. **ROS2 Control Integration**
- **Hardware Interface**: Uses `dsr_hardware2` for DRFL communication
- **Controller Manager**: Manages joint trajectory and state broadcasting
- **Standard Controllers**: Compatible with MoveIt and other ROS2 tools

## 🚀 Usage

### Prerequisites
```bash
# Ensure you have built dsr_hardware2 and dsr_description2
cd /home/jack/project_ws
colcon build --packages-select dsr_hardware2 dsr_description2
source install/setup.bash
```

### Real Robot Mode
```bash
# Connect to physical M0609 robot
ros2 launch doosan_m0609_bringup m0609_real.launch.py host:=192.168.137.100

# With custom network settings
ros2 launch doosan_m0609_bringup m0609_real.launch.py \
    host:=192.168.137.100 \
    rt_host:=192.168.137.100 \
    port:=12345 \
    color:=blue
```

### Virtual Mode (Testing/Development)
```bash
# Launch in virtual mode with RViz
ros2 launch doosan_m0609_bringup m0609_virtual.launch.py

# With MoveIt integration
ros2 launch doosan_m0609_bringup m0609_virtual.launch.py use_moveit:=true
```

### Manual Configuration
```bash
# Full parameter control
ros2 launch doosan_m0609_bringup m0609_bringup.launch.py \
    mode:=real \
    host:=192.168.137.100 \
    use_rviz:=true \
    use_moveit:=false \
    color:=white
```

## 📊 ROS2 Control Flow

```
Physical Robot (M0609)
         ↕ DRFL Protocol
dsr_hardware2 (Hardware Interface)
         ↕ ros2_control
controller_manager
    ├── joint_state_broadcaster → /joint_states
    └── joint_trajectory_controller ← /joint_trajectory_controller/joint_trajectory
```

## 🔍 Troubleshooting

### Connection Issues
```bash
# Check robot controller connectivity
ping 192.168.137.100

# Verify DRFL connection
ros2 topic echo /joint_states

# Check controller status
ros2 control list_controllers
```

### Controller Problems
```bash
# Restart controllers
ros2 control switch_controllers --deactivate joint_trajectory_controller
ros2 control switch_controllers --activate joint_trajectory_controller

# Check hardware interface
ros2 control list_hardware_interfaces
```

## 🔗 Integration with MoveIt

The package is designed to work seamlessly with MoveIt:

```bash
# Launch with MoveIt for motion planning
ros2 launch doosan_m0609_bringup m0609_virtual.launch.py use_moveit:=true

# Or separately after bringup
ros2 launch dsr_moveit_config_m0609 start.launch.py
```

## 📋 Controller Configuration

The ROS2 controllers are configured in `config/ros2_controllers.yaml`:

- **joint_state_broadcaster**: Publishes current joint states to `/joint_states`
- **joint_trajectory_controller**: Accepts trajectory commands via action interface
- **Update rate**: 100Hz for real-time performance
- **Safety tolerances**: Configured for precise motion control

## 🛡️ Safety Considerations

### Real Robot Mode
- Ensure **emergency stop** is accessible
- Start with **low velocities** for testing
- Verify **workspace** is clear of obstacles
- Check **network latency** for RT control

### Network Setup
```bash
# Recommended static IP configuration
# Robot Controller: 192.168.137.100
# Host Computer: 192.168.137.101
# Subnet: 255.255.255.0
```

## 🔄 Migration from Old Structure

If migrating from the previous spaghetti code structure:

1. **Remove old package**:
   ```bash
   rm -rf /home/jack/project_ws/src/doosan_m0609_bringup
   ```

2. **Create clean structure**:
   ```bash
   # Use the provided scripts in artifacts
   ```

3. **Update dependencies**:
   ```bash
   rosdep update
   rosdep install --from-paths src --ignore-src -r -y
   ```

4. **Build and test**:
   ```bash
   colcon build --packages-select doosan_m0609_bringup
   source install/setup.bash
   ```

## 📚 Dependencies

- **Core**: `rclcpp`, `rclpy`, `ros2_control`, `controller_manager`
- **Controllers**: `joint_trajectory_controller`, `joint_state_broadcaster`
- **Doosan**: `dsr_hardware2`, `dsr_description2`
- **Visualization**: `rviz2`, `robot_state_publisher`
- **Launch**: `launch`, `launch_ros`, `xacro`

## 🤝 Contributing

Follow Doosan Robotics coding standards and ROS2 best practices:

- Use **ament_cmake** build system
- Follow **ROS2 Control** patterns  
- Maintain **backward compatibility**
- Add **comprehensive documentation**

---

**Note**: This package replaces the previous duplicated/spaghetti structure with a clean, maintainable architecture following official Doosan guidelines.