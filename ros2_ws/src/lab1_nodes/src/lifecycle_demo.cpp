#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"

using CallbackReturn =
  rclcpp_lifecycle::node_interfaces::
  LifecycleNodeInterface::CallbackReturn;

class DemoLifecycleNode
  : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit DemoLifecycleNode(const std::string & name)
  : rclcpp_lifecycle::LifecycleNode(name)
  {
    RCLCPP_INFO(
      get_logger(),
      "Lifecycle node %s created",
      name.c_str()
    );
  }

  CallbackReturn on_configure(
    const rclcpp_lifecycle::State &)
  {
    RCLCPP_INFO(
      get_logger(),
      "Node configured"
    );

    return CallbackReturn::SUCCESS;
  }

  CallbackReturn on_activate(
    const rclcpp_lifecycle::State &)
  {
    RCLCPP_INFO(
      get_logger(),
      "Node activated"
    );

    return CallbackReturn::SUCCESS;
  }

  CallbackReturn on_deactivate(
    const rclcpp_lifecycle::State &)
  {
    RCLCPP_INFO(
      get_logger(),
      "Node deactivated"
    );

    return CallbackReturn::SUCCESS;
  }

  CallbackReturn on_cleanup(
    const rclcpp_lifecycle::State &)
  {
    RCLCPP_INFO(
      get_logger(),
      "Node cleaned up"
    );

    return CallbackReturn::SUCCESS;
  }

  CallbackReturn on_shutdown(
    const rclcpp_lifecycle::State &)
  {
    RCLCPP_INFO(
      get_logger(),
      "Node shutdown"
    );

    return CallbackReturn::SUCCESS;
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  std::string node_name = "managed_one";

  if (argc > 1) {
    node_name = argv[1];
  }

  auto node =
    std::make_shared<DemoLifecycleNode>(node_name);

  rclcpp::spin(node->get_node_base_interface());

  rclcpp::shutdown();

  return 0;
}