fbanim - frame based animation system
-------------------------------------

fbanim is a 'time' based scheduler written in C.  It is used to
perodically schedule function calls over an arbitrary timeline.

It is what is normally known as a 'dynamic main loop'.

Frames are run over specified frame boundaries or dynamically at
run-time.

The following is a short example:

```c
#include "fbanim.h"
#include "fbanim.c"

void proc1(int arg) {
  printf(".");
}

void proc2(int arg) {
  printf(",");
}

int main() {
  ListInit();
  InitFrameBasedAnimSystem();
  InsertProc(0,		/* start frame	*/
  	     -1,	/* end frame	*/
	     1,		/* period	*/
	     0,		/* priority	*/
	     proc1,	/* function	*/
	     0		/* argument	*/);
  InsertProc(0, -1, 1, 0, proc2, 0);
  RunFrameBasedAnimSystem();
}
```

This will print a series of dots and commas on the screen until you
hit Ctrl-C.

TODO: turn into shared library.
TODO: writing bindings for Common Lisp?
TODO: re-write in Common Lisp.

--
Copyleft - Burton Samograd
burton.samograd@gmail.com
2016