import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SimplePublisher(Node): # Node is the base clase. SimplePublizer inherited from node
    def __init__ (self):
        super().__init__("simple_publisher") # initialize the base came with the argument of new Node name
        self.pub_ = self.create_publisher(String, "chatter", 10) # function inherited from node class
        self.counter_ = 0
        self.frequency_ = 1

        self.get_logger().info("Publishing at %d Hz" % self.frequency_)
        self.timer_ = self.create_timer(self.frequency_, self.timerCallback)

    
    def timerCallback(self):
        msg = String()
        msg.data = "Hello ROS 2 - counter: %d" % self.counter_
        self.pub_.publish(msg)
        self.counter_ += 1


def main():
    rclpy.init()

    simple_publisher = SimplePublisher()
    rclpy.spin(simple_publisher) #this make cureent node running
    
    simple_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()