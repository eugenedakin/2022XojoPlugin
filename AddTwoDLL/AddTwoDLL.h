#include "WinHeader++.h"
#include "rb_plugin.h"

RBInteger AddTwo(RBInteger x, RBInteger y);

REALmethodDefinition TestModuleMethods[] = {
	{ (REALproc)AddTwo, REALnoImplementation, "AddTwo(x as integer, y as integer) as integer", REALconsoleSafe },
};
