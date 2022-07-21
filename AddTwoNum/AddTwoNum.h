#include "WinHeader++.h"
#include "rb_plugin.h"

int AddTwo(int x, int y);


REALmethodDefinition TestModuleMethods[] = {
	{ (REALproc)AddTwo, REALnoImplementation, "AddTwo(x as integer, y as integer) as integer", REALconsoleSafe },
};
