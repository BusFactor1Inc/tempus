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
