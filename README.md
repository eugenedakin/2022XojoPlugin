# 2022XojoPlugin
Make a Xojo 2022 r1.1 plugin from scratch using Visual Studio 2022 in Windows

This is the code to make a plugin method which adds two numbers together. 
  - Compatible with Windows 11
  - Xojo IDE: 2022 r1.1
  - Xojo API: API 2
  - Level: Advanced
  
  Youtube video:
[![Xojo Plugin Creation from Scratch](https://github.com/eugenedakin/2022XojoPlugin/blob/main/PluginScreen.png)]( https://youtu.be/3IFFxURbbTA)

Instructions:
- Install Visual Studio 2022 community edition
- Install Xojo 2022 r 1.1
- Run the .sln program in Visual Studio 2022 to create the dll
- Place the DLL in the Xojo plugin folder

AddTwoNum.h file
```C++
#include "WinHeader++.h"
#include "rb_plugin.h"

int AddTwo(int x, int y);


REALmethodDefinition TestModuleMethods[] = {
	{ (REALproc)AddTwo, REALnoImplementation, "AddTwo(x as integer, y as integer) as integer", REALconsoleSafe },
};
```

AddTwoNum.cpp file
```C++
#include "AddTwoNum.h"

int AddTwo(int x, int y) {
	return x + y;
}

REALmoduleDefinition AddTwodefn = {
	kCurrentREALControlVersion,
	"AddTwoDLL", //name of module shown to user
	TestModuleMethods, //method names
	sizeof(TestModuleMethods) / sizeof(REALmethodDefinition), //size of methods
	nil, //no constants
	nil, //no properties
};

void PluginEntry(void) {
	REALRegisterModule(&AddTwodefn);
}
```
