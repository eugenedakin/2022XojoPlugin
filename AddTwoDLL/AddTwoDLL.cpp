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
