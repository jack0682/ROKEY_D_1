/*
 * doosan_m0609_controller.hpp
 * Author: Jack (based on dsr_controller2)
 *
 * Copyright (c) 2024 Doosan Robotics
 * Use of this source code is governed by the BSD, see LICENSE
*/

#ifndef DOOSAN_M0609_CONTROLLER__DOOSAN_M0609_CONTROLLER_HPP_
#define DOOSAN_M0609_CONTROLLER__DOOSAN_M0609_CONTROLLER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "controller_interface/controller_interface.hpp"
#include "doosan_m0609_msgs/msg/robot_error.hpp"
#include "doosan_m0609_msgs/msg/robot_state.hpp"
#include "doosan_m0609_msgs/msg/robot_stop.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_buffer.h"

namespace doosan_m0609_controller
{
using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class DoosanM0609Controller : public controller_interface::ControllerInterface
{
public:
    DoosanM0609Controller();

    controller_interface::InterfaceConfiguration command_interface_configuration() const override;

    controller_interface::InterfaceConfiguration state_interface_configuration() const override;

    CallbackReturn on_init() override;

    CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state) override;

    CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;

    CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

    controller_interface::return_type update(
        const rclcpp::Time & time, const rclcpp::Duration & period) override;

private:
    std::string m_model;
};

} // namespace doosan_m0609_controller

#endif // DOOSAN_M0609_CONTROLLER__DOOSAN_M0609_CONTROLLER_HPP_
