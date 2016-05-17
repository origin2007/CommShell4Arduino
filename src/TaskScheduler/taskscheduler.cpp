#include <MsTimer2.h>
#include <taskscheduler.h>

#define TIME_INTERVAL 1

  sTask taskQueue[TASK_MAX];
	unsigned int ticker;

    void sch_init()
    {
      int i;
      for(i=0; i<TASK_MAX; i++)
      {
        sch_deleteTask(i);
      }
      MsTimer2::set(TIME_INTERVAL, sch_update);
	ticker = 0;
    }

    void sch_addTask(void (*pFun)(), long d, long p)
    {
      int i;
      for(i=0; i<TASK_MAX; i++)
      {
        if(taskQueue[i].pTask == 0)
        {
         taskQueue[i].pTask = pFun;
          taskQueue[i].delay = d;
          taskQueue[i].peroid = p;
          taskQueue[i].runme = 0;
	  break;
        }
      }
    }

    void sch_start()
    {
	MsTimer2::start();
    }

    void sch_dispatchtasks()
    {
     int index;
     for(index=0; index<TASK_MAX; index++)
      {
      if(taskQueue[index].runme>0)
       {
       (* taskQueue[index].pTask)();
       taskQueue[index].runme = 0;

       if(taskQueue[index].peroid==0)
        {
        sch_deleteTask(index);
        }
       }
      } //run task
    }

  void sch_deleteTask(byte i)
  {
    if(taskQueue[i].pTask != 0)
    {
      taskQueue[i].pTask = 0;
      taskQueue[i].delay = 0;
      taskQueue[i].peroid = 0;
      taskQueue[i].runme = 0;
    }
  }
  
    void sch_update()
    {
      int i;
	ticker ++;
      for(i=0; i<TASK_MAX; i++)
      {
        if(taskQueue[i].pTask != 0)
        {
          if(taskQueue[i].delay == 0)
          {
            taskQueue[i].runme = 1;
            if(taskQueue[i].peroid > 0)
            {
              taskQueue[i].delay = taskQueue[i].peroid;
            }
          }
          else{
            taskQueue[i].delay -= 1;
          }
        }
      }
   }

	unsigned int sch_getTicker()
{
	return ticker;
}

unsigned int sch_getQueueSize()
{
  int i;
  int c = 0;
  for(i=0; i<TASK_MAX; i++)
  {
    if(taskQueue[i].pTask != 0) c++;
  }
  return c;
}
