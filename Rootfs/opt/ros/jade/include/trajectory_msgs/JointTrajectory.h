// Generated by gencpp from file trajectory_msgs/JointTrajectory.msg
// DO NOT EDIT!


#ifndef TRAJECTORY_MSGS_MESSAGE_JOINTTRAJECTORY_H
#define TRAJECTORY_MSGS_MESSAGE_JOINTTRAJECTORY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

namespace trajectory_msgs
{
template <class ContainerAllocator>
struct JointTrajectory_
{
  typedef JointTrajectory_<ContainerAllocator> Type;

  JointTrajectory_()
    : header()
    , joint_names()
    , points()  {
    }
  JointTrajectory_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , joint_names(_alloc)
    , points(_alloc)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _joint_names_type;
  _joint_names_type joint_names;

   typedef std::vector< ::trajectory_msgs::JointTrajectoryPoint_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::trajectory_msgs::JointTrajectoryPoint_<ContainerAllocator> >::other >  _points_type;
  _points_type points;




  typedef boost::shared_ptr< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> const> ConstPtr;

}; // struct JointTrajectory_

typedef ::trajectory_msgs::JointTrajectory_<std::allocator<void> > JointTrajectory;

typedef boost::shared_ptr< ::trajectory_msgs::JointTrajectory > JointTrajectoryPtr;
typedef boost::shared_ptr< ::trajectory_msgs::JointTrajectory const> JointTrajectoryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::trajectory_msgs::JointTrajectory_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace trajectory_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg'], 'trajectory_msgs': ['/tmp/binarydeb/ros-jade-trajectory-msgs-1.12.3/msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "65b4f94a94d1ed67169da35a02f33d3f";
  }

  static const char* value(const ::trajectory_msgs::JointTrajectory_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x65b4f94a94d1ed67ULL;
  static const uint64_t static_value2 = 0x169da35a02f33d3fULL;
};

template<class ContainerAllocator>
struct DataType< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "trajectory_msgs/JointTrajectory";
  }

  static const char* value(const ::trajectory_msgs::JointTrajectory_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
string[] joint_names\n\
JointTrajectoryPoint[] points\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: trajectory_msgs/JointTrajectoryPoint\n\
# Each trajectory point specifies either positions[, velocities[, accelerations]]\n\
# or positions[, effort] for the trajectory to be executed.\n\
# All specified values are in the same order as the joint names in JointTrajectory.msg\n\
\n\
float64[] positions\n\
float64[] velocities\n\
float64[] accelerations\n\
float64[] effort\n\
duration time_from_start\n\
";
  }

  static const char* value(const ::trajectory_msgs::JointTrajectory_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.joint_names);
      stream.next(m.points);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct JointTrajectory_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::trajectory_msgs::JointTrajectory_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::trajectory_msgs::JointTrajectory_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "joint_names[]" << std::endl;
    for (size_t i = 0; i < v.joint_names.size(); ++i)
    {
      s << indent << "  joint_names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.joint_names[i]);
    }
    s << indent << "points[]" << std::endl;
    for (size_t i = 0; i < v.points.size(); ++i)
    {
      s << indent << "  points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::trajectory_msgs::JointTrajectoryPoint_<ContainerAllocator> >::stream(s, indent + "    ", v.points[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // TRAJECTORY_MSGS_MESSAGE_JOINTTRAJECTORY_H
