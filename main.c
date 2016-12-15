#include "fbanim.h"
#include "fbanim.c"

void proc(int arg) {
  
}

int main() {
  ListInit();
  InitFrameBasedAnimSystem();
  InsertProc(0, -1, 1, 0, proc, 0);
  RunFrameBasedAnimSystem();
}
