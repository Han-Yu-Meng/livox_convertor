#pragma once

#include <fins/functional_node.hpp>
#include <livox_ros_driver2/msg/custom_msg.hpp>
#include <livox_driver2/msg/custom_msg.hpp>
#include <vector>
#include <memory>
#include <cstdint>

/**
 * @brief Namespace for livox_convertor driver
 * This driver handles conversion between livox_driver2 and livox_ros_driver2 formats.
 */

namespace livox_convertor {

using fins::Function;
using fins::Input;
using fins::Output;

/**
 * @brief Conversion from livox_ros_driver2::msg::CustomMsg to internal CustomMsg.
 */
static auto livox_to_internal_node = Function("fromROS",
  [](Input<livox_ros_driver2::msg::CustomMsg> &msg_in,
     Output<livox_driver2::msg::CustomMsg> &msg_out) {
    if (msg_in->point_num == 0) return;
    
    msg_out->header = msg_in->header;
    msg_out->timebase = msg_in->timebase;
    msg_out->point_num = msg_in->point_num;
    msg_out->lidar_id = msg_in->lidar_id;
    msg_out->rsvd = msg_in->rsvd;
    
    msg_out->points.resize(msg_in->point_num);
    for (size_t i = 0; i < msg_in->point_num; ++i) {
        msg_out->points[i].offset_time = msg_in->points[i].offset_time;
        msg_out->points[i].x = msg_in->points[i].x;
        msg_out->points[i].y = msg_in->points[i].y;
        msg_out->points[i].z = msg_in->points[i].z;
        msg_out->points[i].reflectivity = msg_in->points[i].reflectivity;
        msg_out->points[i].tag = msg_in->points[i].tag;
        msg_out->points[i].line = msg_in->points[i].line;
    }
  }
).with_description("Converts livox_ros_driver2 CustomMsg to internal CustomMsg.")
 .with_inputs_description({"ros_msg"})
 .with_outputs_description({"msg"})
 .with_category("Livox")
 .build();

/**
 * @brief Conversion from internal CustomMsg to livox_ros_driver2::msg::CustomMsg.
 */
static auto internal_to_livox_node = Function("toROS",
  [](Input<livox_driver2::msg::CustomMsg> &msg_in,
     Output<livox_ros_driver2::msg::CustomMsg> &msg_out) {
    if (msg_in->point_num == 0) return;
    
    msg_out->header = msg_in->header;
    msg_out->timebase = msg_in->timebase;
    msg_out->point_num = msg_in->point_num;
    msg_out->lidar_id = msg_in->lidar_id;
    msg_out->rsvd = msg_in->rsvd;
    
    msg_out->points.resize(msg_in->point_num);
    for (size_t i = 0; i < msg_in->point_num; ++i) {
        msg_out->points[i].offset_time = msg_in->points[i].offset_time;
        msg_out->points[i].x = msg_in->points[i].x;
        msg_out->points[i].y = msg_in->points[i].y;
        msg_out->points[i].z = msg_in->points[i].z;
        msg_out->points[i].reflectivity = msg_in->points[i].reflectivity;
        msg_out->points[i].tag = msg_in->points[i].tag;
        msg_out->points[i].line = msg_in->points[i].line;
    }
  }
).with_description("Converts internal CustomMsg to livox_ros_driver2 CustomMsg.")
 .with_inputs_description({"msg"})
 .with_outputs_description({"ros_msg"})
 .with_category("Livox")
 .build();

} // namespace livox_convertor
