#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

namespace lab1_nodes
{

class DemoComponent : public rclcpp::Node
{
public:
  explicit DemoComponent(const rclcpp::NodeOptions & options)
  : Node("demo_component", options)
  {
    RCLCPP_INFO(
      this->get_logger(),
      "Demo Component created successfully!"
    );
  }
};

}  // namespace lab1_nodes

RCLCPP_COMPONENTS_REGISTER_NODE(lab1_nodes::DemoComponent)