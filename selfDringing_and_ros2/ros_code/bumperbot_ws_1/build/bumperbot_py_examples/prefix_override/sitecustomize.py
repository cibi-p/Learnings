import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/cibi/Documents/Learning/Github_learning/Learnings/selfDringing_and_ros2/ros_code/bumperbot_ws_1/install/bumperbot_py_examples'
