#ifndef taskschedular_h
#define taskschedular_h

#include "Arduino.h"

#define TASK_MAX 10

typedef struct {
  void (*pTask)();
  long delay;
  long peroid;
  byte runme;
} sTask;


  void sch_init(void);
  void sch_addTask(void (*pFun)(), long delay, long peroid);
  void sch_deleteTask(byte i);
  void sch_start();
  void sch_dispatchtasks();
  void sch_update();
  unsigned int sch_getTicker();
  unsigned int sch_getQueueSize();
#endif
