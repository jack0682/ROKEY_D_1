// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from doosan_m0609_msgs:srv/ConfigCreateModbus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "doosan_m0609_msgs/srv/detail/config_create_modbus__struct.h"
#include "doosan_m0609_msgs/srv/detail/config_create_modbus__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool doosan_m0609_msgs__srv__config_create_modbus__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[71];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("doosan_m0609_msgs.srv._config_create_modbus.ConfigCreateModbus_Request", full_classname_dest, 70) == 0);
  }
  doosan_m0609_msgs__srv__ConfigCreateModbus_Request * ros_message = _ros_message;
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // ip
    PyObject * field = PyObject_GetAttrString(_pymsg, "ip");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->ip, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // port
    PyObject * field = PyObject_GetAttrString(_pymsg, "port");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->port = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // reg_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "reg_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reg_type = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // index
    PyObject * field = PyObject_GetAttrString(_pymsg, "index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->index = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // value
    PyObject * field = PyObject_GetAttrString(_pymsg, "value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->value = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // slave_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "slave_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->slave_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * doosan_m0609_msgs__srv__config_create_modbus__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ConfigCreateModbus_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("doosan_m0609_msgs.srv._config_create_modbus");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ConfigCreateModbus_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  doosan_m0609_msgs__srv__ConfigCreateModbus_Request * ros_message = (doosan_m0609_msgs__srv__ConfigCreateModbus_Request *)raw_ros_message;
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ip
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->ip.data,
      strlen(ros_message->ip.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "ip", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // port
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->port);
    {
      int rc = PyObject_SetAttrString(_pymessage, "port", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reg_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->reg_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reg_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // value
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slave_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->slave_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slave_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/config_create_modbus__struct.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/config_create_modbus__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool doosan_m0609_msgs__srv__config_create_modbus__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[72];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("doosan_m0609_msgs.srv._config_create_modbus.ConfigCreateModbus_Response", full_classname_dest, 71) == 0);
  }
  doosan_m0609_msgs__srv__ConfigCreateModbus_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * doosan_m0609_msgs__srv__config_create_modbus__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ConfigCreateModbus_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("doosan_m0609_msgs.srv._config_create_modbus");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ConfigCreateModbus_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  doosan_m0609_msgs__srv__ConfigCreateModbus_Response * ros_message = (doosan_m0609_msgs__srv__ConfigCreateModbus_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
