# generated from rosidl_generator_py/resource/_idl.py.em
# with input from doosan_m0609_msgs:srv/MoveBlending.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'vel'
# Member 'acc'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveBlending_Request(type):
    """Metaclass of message 'MoveBlending_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('doosan_m0609_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'doosan_m0609_msgs.srv.MoveBlending_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_blending__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_blending__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_blending__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_blending__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_blending__request

            from std_msgs.msg import Float64MultiArray
            if Float64MultiArray.__class__._TYPE_SUPPORT is None:
                Float64MultiArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveBlending_Request(metaclass=Metaclass_MoveBlending_Request):
    """Message class 'MoveBlending_Request'."""

    __slots__ = [
        '_segment',
        '_pos_cnt',
        '_vel',
        '_acc',
        '_time',
        '_ref',
        '_mode',
        '_sync_type',
    ]

    _fields_and_field_types = {
        'segment': 'sequence<std_msgs/Float64MultiArray>',
        'pos_cnt': 'int8',
        'vel': 'double[2]',
        'acc': 'double[2]',
        'time': 'double',
        'ref': 'int8',
        'mode': 'int8',
        'sync_type': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Float64MultiArray')),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.segment = kwargs.get('segment', [])
        self.pos_cnt = kwargs.get('pos_cnt', int())
        if 'vel' not in kwargs:
            self.vel = numpy.zeros(2, dtype=numpy.float64)
        else:
            self.vel = numpy.array(kwargs.get('vel'), dtype=numpy.float64)
            assert self.vel.shape == (2, )
        if 'acc' not in kwargs:
            self.acc = numpy.zeros(2, dtype=numpy.float64)
        else:
            self.acc = numpy.array(kwargs.get('acc'), dtype=numpy.float64)
            assert self.acc.shape == (2, )
        self.time = kwargs.get('time', float())
        self.ref = kwargs.get('ref', int())
        self.mode = kwargs.get('mode', int())
        self.sync_type = kwargs.get('sync_type', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.segment != other.segment:
            return False
        if self.pos_cnt != other.pos_cnt:
            return False
        if any(self.vel != other.vel):
            return False
        if any(self.acc != other.acc):
            return False
        if self.time != other.time:
            return False
        if self.ref != other.ref:
            return False
        if self.mode != other.mode:
            return False
        if self.sync_type != other.sync_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def segment(self):
        """Message field 'segment'."""
        return self._segment

    @segment.setter
    def segment(self, value):
        if __debug__:
            from std_msgs.msg import Float64MultiArray
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Float64MultiArray) for v in value) and
                 True), \
                "The 'segment' field must be a set or sequence and each value of type 'Float64MultiArray'"
        self._segment = value

    @builtins.property
    def pos_cnt(self):
        """Message field 'pos_cnt'."""
        return self._pos_cnt

    @pos_cnt.setter
    def pos_cnt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pos_cnt' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'pos_cnt' field must be an integer in [-128, 127]"
        self._pos_cnt = value

    @builtins.property
    def vel(self):
        """Message field 'vel'."""
        return self._vel

    @vel.setter
    def vel(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'vel' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 2, \
                "The 'vel' numpy.ndarray() must have a size of 2"
            self._vel = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'vel' field must be a set or sequence with length 2 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._vel = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def acc(self):
        """Message field 'acc'."""
        return self._acc

    @acc.setter
    def acc(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'acc' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 2, \
                "The 'acc' numpy.ndarray() must have a size of 2"
            self._acc = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'acc' field must be a set or sequence with length 2 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._acc = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._time = value

    @builtins.property
    def ref(self):
        """Message field 'ref'."""
        return self._ref

    @ref.setter
    def ref(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ref' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ref' field must be an integer in [-128, 127]"
        self._ref = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'mode' field must be an integer in [-128, 127]"
        self._mode = value

    @builtins.property
    def sync_type(self):
        """Message field 'sync_type'."""
        return self._sync_type

    @sync_type.setter
    def sync_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sync_type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'sync_type' field must be an integer in [-128, 127]"
        self._sync_type = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveBlending_Response(type):
    """Metaclass of message 'MoveBlending_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('doosan_m0609_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'doosan_m0609_msgs.srv.MoveBlending_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_blending__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_blending__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_blending__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_blending__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_blending__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveBlending_Response(metaclass=Metaclass_MoveBlending_Response):
    """Message class 'MoveBlending_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_MoveBlending(type):
    """Metaclass of service 'MoveBlending'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('doosan_m0609_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'doosan_m0609_msgs.srv.MoveBlending')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__move_blending

            from doosan_m0609_msgs.srv import _move_blending
            if _move_blending.Metaclass_MoveBlending_Request._TYPE_SUPPORT is None:
                _move_blending.Metaclass_MoveBlending_Request.__import_type_support__()
            if _move_blending.Metaclass_MoveBlending_Response._TYPE_SUPPORT is None:
                _move_blending.Metaclass_MoveBlending_Response.__import_type_support__()


class MoveBlending(metaclass=Metaclass_MoveBlending):
    from doosan_m0609_msgs.srv._move_blending import MoveBlending_Request as Request
    from doosan_m0609_msgs.srv._move_blending import MoveBlending_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
