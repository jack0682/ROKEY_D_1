# generated from rosidl_generator_py/resource/_idl.py.em
# with input from doosan_m0609_msgs:srv/GetLastAlarm.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetLastAlarm_Request(type):
    """Metaclass of message 'GetLastAlarm_Request'."""

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
                'doosan_m0609_msgs.srv.GetLastAlarm_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_last_alarm__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_last_alarm__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_last_alarm__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_last_alarm__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_last_alarm__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetLastAlarm_Request(metaclass=Metaclass_GetLastAlarm_Request):
    """Message class 'GetLastAlarm_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetLastAlarm_Response(type):
    """Metaclass of message 'GetLastAlarm_Response'."""

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
                'doosan_m0609_msgs.srv.GetLastAlarm_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_last_alarm__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_last_alarm__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_last_alarm__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_last_alarm__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_last_alarm__response

            from doosan_m0609_msgs.msg import LogAlarm
            if LogAlarm.__class__._TYPE_SUPPORT is None:
                LogAlarm.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetLastAlarm_Response(metaclass=Metaclass_GetLastAlarm_Response):
    """Message class 'GetLastAlarm_Response'."""

    __slots__ = [
        '_log_alarm',
        '_success',
    ]

    _fields_and_field_types = {
        'log_alarm': 'doosan_m0609_msgs/LogAlarm',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['doosan_m0609_msgs', 'msg'], 'LogAlarm'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from doosan_m0609_msgs.msg import LogAlarm
        self.log_alarm = kwargs.get('log_alarm', LogAlarm())
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
        if self.log_alarm != other.log_alarm:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def log_alarm(self):
        """Message field 'log_alarm'."""
        return self._log_alarm

    @log_alarm.setter
    def log_alarm(self, value):
        if __debug__:
            from doosan_m0609_msgs.msg import LogAlarm
            assert \
                isinstance(value, LogAlarm), \
                "The 'log_alarm' field must be a sub message of type 'LogAlarm'"
        self._log_alarm = value

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


class Metaclass_GetLastAlarm(type):
    """Metaclass of service 'GetLastAlarm'."""

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
                'doosan_m0609_msgs.srv.GetLastAlarm')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_last_alarm

            from doosan_m0609_msgs.srv import _get_last_alarm
            if _get_last_alarm.Metaclass_GetLastAlarm_Request._TYPE_SUPPORT is None:
                _get_last_alarm.Metaclass_GetLastAlarm_Request.__import_type_support__()
            if _get_last_alarm.Metaclass_GetLastAlarm_Response._TYPE_SUPPORT is None:
                _get_last_alarm.Metaclass_GetLastAlarm_Response.__import_type_support__()


class GetLastAlarm(metaclass=Metaclass_GetLastAlarm):
    from doosan_m0609_msgs.srv._get_last_alarm import GetLastAlarm_Request as Request
    from doosan_m0609_msgs.srv._get_last_alarm import GetLastAlarm_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
