// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
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
#include "doosan_m0609_msgs/msg/detail/modbus_state__struct.h"
#include "doosan_m0609_msgs/msg/detail/modbus_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool doosan_m0609_msgs__msg__modbus_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("doosan_m0609_msgs.msg._modbus_state.ModbusState", full_classname_dest, 47) == 0);
  }
  doosan_m0609_msgs__msg__ModbusState * ros_message = _ros_message;
  {  // modbus_symbol
    PyObject * field = PyObject_GetAttrString(_pymsg, "modbus_symbol");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->modbus_symbol, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // modbus_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "modbus_value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->modbus_value = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * doosan_m0609_msgs__msg__modbus_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ModbusState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("doosan_m0609_msgs.msg._modbus_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ModbusState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  doosan_m0609_msgs__msg__ModbusState * ros_message = (doosan_m0609_msgs__msg__ModbusState *)raw_ros_message;
  {  // modbus_symbol
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->modbus_symbol.data,
      strlen(ros_message->modbus_symbol.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "modbus_symbol", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // modbus_value
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->modbus_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "modbus_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
