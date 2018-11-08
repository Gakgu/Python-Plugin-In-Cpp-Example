#include "animal.h"

Animal::Animal()
  : m_speed(10)
{
}

Animal* SetCppInstance(PyObject* capsule)
{
  g_animal = (Animal*)PyCapsule_GetPointer(capsule, "animal");
}

Animal* GetCppInstance()
{
  return g_animal;
}
