#include "python.h"
#include "animal.h"

int main()
{
  Animal animal;
  PyObject* py_capsule_animal = PyCapsule_New((void*)&animal, "animal", NULL);
  
  Py_Initialize();

  // Initialize animal module.
  PyObject *py_module_animal = PyImport_ImportModule("animal");
  PyObject *py_module_animal_setcppinstance = PyObject_GetAttrString(py_module_animal, "SetCppInstance");
  PyObject_CallFunction(py_module_animal_setcppinstance, "O", py_capsule_animal);

  // Call plugin.
  PyImport_ImportModule("plugin.py");

  printf("animal speed : %f\n", animal.m_speed);

  Py_Finalize();

  return 0;
}
