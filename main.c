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
