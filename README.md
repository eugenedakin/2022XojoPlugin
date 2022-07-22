# 2022XojoPlugin
Make a Xojo 2022 r1.1 plugin from scratch using Visual Studio 2022 in Windows.

Update which uses RBInteger instead of C++ Int to increase stability.

This is the code to make a plugin method which adds two numbers together. 
  - Compatible with Windows 11
  - Xojo IDE: 2022 r1.1
  - Xojo API: API 2
  - Level: Advanced
  
  Youtube video:
[![Xojo Plugin Creation from Scratch](https://github.com/eugenedakin/2022XojoPlugin/blob/main/PluginScreenUpdated.png)](https://youtu.be/Ap3Ufre_RXk)

Instructions:
- Install Visual Studio 2022 community edition
- Install Xojo 2022 r 1.1
- Run the .sln program in Visual Studio 2022 to create the dll
- Place the DLL in the Xojo plugin folder
- Restart Xojo IDE
- Run the AddTwoApp.xojo_binary_project

AddTwoDLL.h file
```C++
#include "WinHeader++.h"
#include "rb_plugin.h"

RBInteger AddTwo(RBInteger x, RBInteger y);

REALmethodDefinition TestModuleMethods[] = {
	{ (REALproc)AddTwo, REALnoImplementation, "AddTwo(x as integer, y as integer) as integer", REALconsoleSafe },
};
```

AddTwoDLL.cpp file
```C++
#include "AddTwoDLL.h"

RBInteger AddTwo(RBInteger x, RBInteger y) {
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

The file: AddTwoNum.dll can be downloaded and placed in the Xojo 2022 r1.1 plugin folder.

Xojo code
```xojo
Sub Pressed() Handles Pressed
  Var Answer As Integer
  Answer = AddTwoDLL.AddTwo(4,9)
  Label1.Text = Answer.ToString
End Sub
```
