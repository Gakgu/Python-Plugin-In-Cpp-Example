TARGET 			= _animal.pyd
FLAGS 			= -fPIC -shared
PYTHON_PATH		= C:\Python36
INCLUDE_PATH 	= -I$(PYTHON_PATH)\include
LIBRARY_PATH	= -L$(PYTHON_PATH)\libs
LIBRARY 		= -lpython36
SOURCE 			= animal.cpp\
				  animal_wrap.cpp
  
target: 
	swig -c++ -python -o animal_wrap.cpp animal.i
	g++ $(FLAGS) $(INCLUDE_PATH) $(LIBRARY_PATH) -o $(TARGET) $(SOURCE) $(LIBRARY)
	g++ -g $(INCLUDE_PATH) $(LIBRARY_PATH) -o main main.cpp animal.cpp $(LIBRARY)