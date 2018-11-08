#include <python.h>

class Animal
{
public:
  Animal();
  float m_speed;
};

static Animal* g_animal;

Animal* SetCppInstance(PyObject* capsule);
Animal* GetCppInstance();
