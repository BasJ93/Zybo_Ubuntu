# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from actionlib/TestRequestGoal.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy

class TestRequestGoal(genpy.Message):
  _md5sum = "db5d00ba98302d6c6dd3737e9a03ceea"
  _type = "actionlib/TestRequestGoal"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
int32 TERMINATE_SUCCESS = 0
int32 TERMINATE_ABORTED = 1
int32 TERMINATE_REJECTED = 2
int32 TERMINATE_LOSE = 3
int32 TERMINATE_DROP = 4
int32 TERMINATE_EXCEPTION = 5
int32 terminate_status
bool ignore_cancel  # If true, ignores requests to cancel
string result_text
int32 the_result    # Desired value for the_result in the Result
bool is_simple_client
duration delay_accept  # Delays accepting the goal by this amount of time
duration delay_terminate  # Delays terminating for this amount of time
duration pause_status  # Pauses the status messages for this amount of time

"""
  # Pseudo-constants
  TERMINATE_SUCCESS = 0
  TERMINATE_ABORTED = 1
  TERMINATE_REJECTED = 2
  TERMINATE_LOSE = 3
  TERMINATE_DROP = 4
  TERMINATE_EXCEPTION = 5

  __slots__ = ['terminate_status','ignore_cancel','result_text','the_result','is_simple_client','delay_accept','delay_terminate','pause_status']
  _slot_types = ['int32','bool','string','int32','bool','duration','duration','duration']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       terminate_status,ignore_cancel,result_text,the_result,is_simple_client,delay_accept,delay_terminate,pause_status

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TestRequestGoal, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.terminate_status is None:
        self.terminate_status = 0
      if self.ignore_cancel is None:
        self.ignore_cancel = False
      if self.result_text is None:
        self.result_text = ''
      if self.the_result is None:
        self.the_result = 0
      if self.is_simple_client is None:
        self.is_simple_client = False
      if self.delay_accept is None:
        self.delay_accept = genpy.Duration()
      if self.delay_terminate is None:
        self.delay_terminate = genpy.Duration()
      if self.pause_status is None:
        self.pause_status = genpy.Duration()
    else:
      self.terminate_status = 0
      self.ignore_cancel = False
      self.result_text = ''
      self.the_result = 0
      self.is_simple_client = False
      self.delay_accept = genpy.Duration()
      self.delay_terminate = genpy.Duration()
      self.pause_status = genpy.Duration()

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
      buff.write(_struct_iB.pack(_x.terminate_status, _x.ignore_cancel))
      _x = self.result_text
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_iB6i.pack(_x.the_result, _x.is_simple_client, _x.delay_accept.secs, _x.delay_accept.nsecs, _x.delay_terminate.secs, _x.delay_terminate.nsecs, _x.pause_status.secs, _x.pause_status.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.delay_accept is None:
        self.delay_accept = genpy.Duration()
      if self.delay_terminate is None:
        self.delay_terminate = genpy.Duration()
      if self.pause_status is None:
        self.pause_status = genpy.Duration()
      end = 0
      _x = self
      start = end
      end += 5
      (_x.terminate_status, _x.ignore_cancel,) = _struct_iB.unpack(str[start:end])
      self.ignore_cancel = bool(self.ignore_cancel)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.result_text = str[start:end].decode('utf-8')
      else:
        self.result_text = str[start:end]
      _x = self
      start = end
      end += 29
      (_x.the_result, _x.is_simple_client, _x.delay_accept.secs, _x.delay_accept.nsecs, _x.delay_terminate.secs, _x.delay_terminate.nsecs, _x.pause_status.secs, _x.pause_status.nsecs,) = _struct_iB6i.unpack(str[start:end])
      self.is_simple_client = bool(self.is_simple_client)
      self.delay_accept.canon()
      self.delay_terminate.canon()
      self.pause_status.canon()
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
      buff.write(_struct_iB.pack(_x.terminate_status, _x.ignore_cancel))
      _x = self.result_text
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_iB6i.pack(_x.the_result, _x.is_simple_client, _x.delay_accept.secs, _x.delay_accept.nsecs, _x.delay_terminate.secs, _x.delay_terminate.nsecs, _x.pause_status.secs, _x.pause_status.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.delay_accept is None:
        self.delay_accept = genpy.Duration()
      if self.delay_terminate is None:
        self.delay_terminate = genpy.Duration()
      if self.pause_status is None:
        self.pause_status = genpy.Duration()
      end = 0
      _x = self
      start = end
      end += 5
      (_x.terminate_status, _x.ignore_cancel,) = _struct_iB.unpack(str[start:end])
      self.ignore_cancel = bool(self.ignore_cancel)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.result_text = str[start:end].decode('utf-8')
      else:
        self.result_text = str[start:end]
      _x = self
      start = end
      end += 29
      (_x.the_result, _x.is_simple_client, _x.delay_accept.secs, _x.delay_accept.nsecs, _x.delay_terminate.secs, _x.delay_terminate.nsecs, _x.pause_status.secs, _x.pause_status.nsecs,) = _struct_iB6i.unpack(str[start:end])
      self.is_simple_client = bool(self.is_simple_client)
      self.delay_accept.canon()
      self.delay_terminate.canon()
      self.pause_status.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_iB6i = struct.Struct("<iB6i")
_struct_iB = struct.Struct("<iB")
