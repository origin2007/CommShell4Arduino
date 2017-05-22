#include "funclib.h"

FuncItem funlib[100];
int pSize = 0;

void initFunLib()
{
  funlib[0].cmd = "testcmd";
  funlib[0].func = testcmd;
  pSize = 1;
}

void testcmd(char** ags, char* res)
{
  int i = 0;
  strcpy(res, "0 OK OK");
}

