/*
 * doosan_m0609_controller
 * Author: Jack (based on dsr_controller2 by Minsoo Song)
 *
 * Copyright (c) 2024 Doosan Robotics
 * Use of this source code is governed by the BSD, see LICENSE
*/

#include "doosan_m0609_controller/doosan_m0609_controller.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

#include <stddef.h>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/qos.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"

using config_type = controller_interface::interface_configuration_type;

namespace doosan_m0609_controller
{

DoosanM0609Controller::DoosanM0609Controller() : controller_interface::ControllerInterface() {}

controller_interface::CallbackReturn DoosanM0609Controller::on_init()
{
    return CallbackReturn::SUCCESS;
}

controller_interface::InterfaceConfiguration DoosanM0609Controller::command_interface_configuration() const
{
    controller_interface::InterfaceConfiguration conf = {config_type::INDIVIDUAL, {}};
    return conf;
}

controller_interface::InterfaceConfiguration DoosanM0609Controller::state_interface_configuration() const
{
    controller_interface::InterfaceConfiguration conf = {config_type::INDIVIDUAL, {}};
    return conf;
}

controller_interface::CallbackReturn DoosanM0609Controller::on_configure(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}

controller_interface::CallbackReturn DoosanM0609Controller::on_activate(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}

controller_interface::CallbackReturn DoosanM0609Controller::on_deactivate(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}

controller_interface::return_type DoosanM0609Controller::update(
    const rclcpp::Time & time, const rclcpp::Duration & period)
{
    (void)time;
    (void)period;
    return controller_interface::return_type::OK;
}

} // namespace doosan_m0609_controller

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
    doosan_m0609_controller::DoosanM0609Controller,
    controller_interface::ControllerInterface
)
