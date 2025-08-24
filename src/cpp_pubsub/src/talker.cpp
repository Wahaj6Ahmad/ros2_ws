#include "rclcpp/rclcpp.hpp"       // core ROS 2 C++ API
#include "std_msgs/msg/string.hpp" // message type we'll publish
#include <chrono>                  // for timing
#include <memory>                  // for std::shared_ptr
#include <string>
using namespace std::chrono_literals; // enables 500ms literal etc.
class MinimalPublisher : public rclcpp::Node {
public:
  MinimalPublisher() : Node("minimal_publisher") {
    // create_publisher<T>(topic_name, queue_depth)
    publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
    // create_wall_timer(period, callback)
    timer_ = this->create_wall_timer(500ms, [this]() { this->timer_callback(); });
  }

private:
  void timer_callback() {
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from C++ publisher";
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
    publisher_->publish(msg);
  }
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char **argv) {
  rclcpp::init(argc, argv);                           // initialize ROS 2
  rclcpp::spin(std::make_shared<MinimalPublisher>()); // keep node alive
  rclcpp::shutdown();                                 // clean up
  return 0;
}
