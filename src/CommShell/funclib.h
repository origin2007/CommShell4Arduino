#ifndef _FUNCLIB_H
#define _FUNCLIB_H

struct _FuncItem{
  char* cmd;
  void (*func)(char**, char*);
};

typedef _FuncItem FuncItem;

void initFunLib();

#endif
