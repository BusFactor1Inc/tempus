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

Next Steps
----------

This could be used in conjunction with 'sxc' to generate data to be
fed into the scheduler beyond the normal capabilities of C.  To do
this, one would have to define the data structure to be fed to the
scheduler, something like so:

```c
struct {
       unsigned int start_frame;
       unsigned int end_frame;
       unsigned int period;
       unsigned int priority;
       void* function;
       unsigned long argument;
} Process;
```

The input 'data' file would be C code defining the functions and the
array of Proceses to be fed to the scheduler.

```c
#include "fbanim.h"
#include "fbanim.c"

typedef struct {
       unsigned int start_frame;
       unsigned int end_frame;
       unsigned int period;
       unsigned int priority;
       void* function;
       unsigned long argument;
} Process;

void proc1(int arg) {
  printf(".");
}

void proc2(int arg) {
  printf(",");
}

Process procs[] = {
  { 0, -1, 1, 0, proc1, 0 },
  { 0, -1, 1, 0, proc2, 0 }
};

int nprocs = sizeof(procs)/sizeof(procs[0]);

void loadup() {
  for(int i = 0; i < nprocs; i++) {
    Process *proc = &procs[i];
    InsertProc(proc->start_frame,
	       proc->end_frame,
	       proc->period,
	       proc->priority,
	       proc->function,
	       proc->argument);
  }
}

int main() {
  ListInit();
  InitFrameBasedAnimSystem();

  loadup();

  RunFrameBasedAnimSystem();
}
```

TODO
----

- turn into shared library.

- writing bindings for Common Lisp?

- re-write in Common Lisp.

--
Copyleft - Burton Samograd
burton.samograd@gmail.com
2016