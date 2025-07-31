// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from doosan_m0609_msgs:srv/SetVelxRt.idl
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
#include "doosan_m0609_msgs/srv/detail/set_velx_rt__struct.h"
#include "doosan_m0609_msgs/srv/detail/set_velx_rt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool doosan_m0609_msgs__srv__set_velx_rt__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
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
    assert(strncmp("doosan_m0609_msgs.srv._set_velx_rt.SetVelxRt_Request", full_classname_dest, 52) == 0);
  }
  doosan_m0609_msgs__srv__SetVelxRt_Request * ros_message = _ros_message;
  {  // trans
    PyObject * field = PyObject_GetAttrString(_pymsg, "trans");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->trans = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rotation
    PyObject * field = PyObject_GetAttrString(_pymsg, "rotation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rotation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * doosan_m0609_msgs__srv__set_velx_rt__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetVelxRt_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("doosan_m0609_msgs.srv._set_velx_rt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetVelxRt_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  doosan_m0609_msgs__srv__SetVelxRt_Request * ros_message = (doosan_m0609_msgs__srv__SetVelxRt_Request *)raw_ros_message;
  {  // trans
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->trans);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trans", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rotation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rotation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rotation", field);
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
// #include "doosan_m0609_msgs/srv/detail/set_velx_rt__struct.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/set_velx_rt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool doosan_m0609_msgs__srv__set_velx_rt__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
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
    assert(strncmp("doosan_m0609_msgs.srv._set_velx_rt.SetVelxRt_Response", full_classname_dest, 53) == 0);
  }
  doosan_m0609_msgs__srv__SetVelxRt_Response * ros_message = _ros_message;
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
PyObject * doosan_m0609_msgs__srv__set_velx_rt__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetVelxRt_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("doosan_m0609_msgs.srv._set_velx_rt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetVelxRt_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  doosan_m0609_msgs__srv__SetVelxRt_Response * ros_message = (doosan_m0609_msgs__srv__SetVelxRt_Response *)raw_ros_message;
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
