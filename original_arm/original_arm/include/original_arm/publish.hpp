// Copyright (c) 2023 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ORIGINAL_ARM__PUBLISH_HPP_
#define ORIGINAL_ARM__PUBLISH_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "original_arm/visibility_control.h"

namespace original_arm
{

// rclcpp::Nodeを継承することでROS2ノード実装に必要な関数をかんたんに容易することができる。
class Publish : public rclcpp::Node
{
public:
  // マルチプラットフォーム対応のためのマクロ
  ORIGINAL_ARM_PUBLIC
  // コンストラクタの引数は必ず「const rclcpp::NodeOptions & options」でなければならない
  explicit Publish(const rclcpp::NodeOptions & options);

  // virtualなデストラクタを定義（参照：https://www.yunabe.jp/docs/cpp_virtual_destructor.html）
  virtual ~Publish();

private:
  // Publisher（データ送信器）の共有ポインタ
  // データ型はstd_msgs/msg/String型（https://github.com/ros2/common_interfaces/blob/rolling/std_msgs/msg/String.msg）
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

}  // namespace original_arm

#endif  // ORIGINAL_ARM__PUBLISH_HPP_