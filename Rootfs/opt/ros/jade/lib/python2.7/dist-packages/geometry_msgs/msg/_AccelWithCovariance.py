# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from geometry_msgs/AccelWithCovariance.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class AccelWithCovariance(genpy.Message):
  _md5sum = "ad5a718d699c6be72a02b8d6a139f334"
  _type = "geometry_msgs/AccelWithCovariance"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# This expresses acceleration in free space with uncertainty.

Accel accel

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/Accel
# This expresses acceleration in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 

float64 x
float64 y
float64 z
"""
  __slots__ = ['accel','covariance']
  _slot_types = ['geometry_msgs/Accel','float64[36]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       accel,covariance

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(AccelWithCovariance, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.accel is None:
        self.accel = geometry_msgs.msg.Accel()
      if self.covariance is None:
        self.covariance = [0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.]
    else:
      self.accel = geometry_msgs.msg.Accel()
      self.covariance = [0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.]

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_6d.pack(_x.accel.linear.x, _x.accel.linear.y, _x.accel.linear.z, _x.accel.angular.x, _x.accel.angular.y, _x.accel.angular.z))
      buff.write(_struct_36d.pack(*self.covariance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.accel is None:
        self.accel = geometry_msgs.msg.Accel()
      end = 0
      _x = self
      start = end
      end += 48
      (_x.accel.linear.x, _x.accel.linear.y, _x.accel.linear.z, _x.accel.angular.x, _x.accel.angular.y, _x.accel.angular.z,) = _struct_6d.unpack(str[start:end])
      start = end
      end += 288
      self.covariance = _struct_36d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_6d.pack(_x.accel.linear.x, _x.accel.linear.y, _x.accel.linear.z, _x.accel.angular.x, _x.accel.angular.y, _x.accel.angular.z))
      buff.write(self.covariance.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.accel is None:
        self.accel = geometry_msgs.msg.Accel()
      end = 0
      _x = self
      start = end
      end += 48
      (_x.accel.linear.x, _x.accel.linear.y, _x.accel.linear.z, _x.accel.angular.x, _x.accel.angular.y, _x.accel.angular.z,) = _struct_6d.unpack(str[start:end])
      start = end
      end += 288
      self.covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=36)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_36d = struct.Struct("<36d")
_struct_6d = struct.Struct("<6d")
