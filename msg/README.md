**package.xml**
    +
    <build_depend>std_msgs</build_depend>
    <build_depend>geometry_msgs</build_depend>
    <exec_depend>std_msgs</exec_depend>
    <exec_depend>geometry_msgs</exec_depend>


**directory**

  ros2_ws/
  └─ src/
     └─ your_ros_pkg/
        ├── package.xml
        ├── setup.py
        ├── resource/
        │   └── your_ros_pkg
        ├── your_ros_pkg/
        │   ├── __init__.py
        │   └── msg/
        │       ├── PersonDetection.msg
        │       ├── PPEViolation.msg
        │       └── RoleAssignment.msg
        └── setup.cfg
