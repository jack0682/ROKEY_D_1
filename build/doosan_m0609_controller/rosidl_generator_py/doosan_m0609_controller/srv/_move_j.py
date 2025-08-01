# generated from rosidl_generator_py/resource/_idl.py.em
# with input from doosan_m0609_controller:srv/MoveJ.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'target_joints'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveJ_Request(type):
    """Metaclass of message 'MoveJ_Request'."""

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
            module = import_type_support('doosan_m0609_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'doosan_m0609_controller.srv.MoveJ_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_j__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_j__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_j__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_j__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_j__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveJ_Request(metaclass=Metaclass_MoveJ_Request):
    """Message class 'MoveJ_Request'."""

    __slots__ = [
        '_target_joints',
        '_velocity_ratio',
        '_acceleration_ratio',
        '_time_out',
    ]

    _fields_and_field_types = {
        'target_joints': 'double[6]',
        'velocity_ratio': 'double',
        'acceleration_ratio': 'double',
        'time_out': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'target_joints' not in kwargs:
            self.target_joints = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.target_joints = numpy.array(kwargs.get('target_joints'), dtype=numpy.float64)
            assert self.target_joints.shape == (6, )
        self.velocity_ratio = kwargs.get('velocity_ratio', float())
        self.acceleration_ratio = kwargs.get('acceleration_ratio', float())
        self.time_out = kwargs.get('time_out', float())

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
        if any(self.target_joints != other.target_joints):
            return False
        if self.velocity_ratio != other.velocity_ratio:
            return False
        if self.acceleration_ratio != other.acceleration_ratio:
            return False
        if self.time_out != other.time_out:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_joints(self):
        """Message field 'target_joints'."""
        return self._target_joints

    @target_joints.setter
    def target_joints(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'target_joints' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'target_joints' numpy.ndarray() must have a size of 6"
            self._target_joints = value
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
                 len(value) == 6 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'target_joints' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._target_joints = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def velocity_ratio(self):
        """Message field 'velocity_ratio'."""
        return self._velocity_ratio

    @velocity_ratio.setter
    def velocity_ratio(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'velocity_ratio' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'velocity_ratio' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._velocity_ratio = value

    @builtins.property
    def acceleration_ratio(self):
        """Message field 'acceleration_ratio'."""
        return self._acceleration_ratio

    @acceleration_ratio.setter
    def acceleration_ratio(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acceleration_ratio' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acceleration_ratio' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acceleration_ratio = value

    @builtins.property
    def time_out(self):
        """Message field 'time_out'."""
        return self._time_out

    @time_out.setter
    def time_out(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'time_out' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'time_out' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._time_out = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveJ_Response(type):
    """Metaclass of message 'MoveJ_Response'."""

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
            module = import_type_support('doosan_m0609_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'doosan_m0609_controller.srv.MoveJ_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_j__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_j__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_j__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_j__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_j__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveJ_Response(metaclass=Metaclass_MoveJ_Response):
    """Message class 'MoveJ_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

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
        if self.message != other.message:
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

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_MoveJ(type):
    """Metaclass of service 'MoveJ'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('doosan_m0609_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'doosan_m0609_controller.srv.MoveJ')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__move_j

            from doosan_m0609_controller.srv import _move_j
            if _move_j.Metaclass_MoveJ_Request._TYPE_SUPPORT is None:
                _move_j.Metaclass_MoveJ_Request.__import_type_support__()
            if _move_j.Metaclass_MoveJ_Response._TYPE_SUPPORT is None:
                _move_j.Metaclass_MoveJ_Response.__import_type_support__()


class MoveJ(metaclass=Metaclass_MoveJ):
    from doosan_m0609_controller.srv._move_j import MoveJ_Request as Request
    from doosan_m0609_controller.srv._move_j import MoveJ_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
