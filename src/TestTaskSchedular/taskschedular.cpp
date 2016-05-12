#include <MsTimer2.h>
#include taskschedular.h

#define TIME_INTERVAL 1

Class Sch
{
  public:
    Sch()
    {
      //
    }
    init();
    {
      MsTimer2.set(TIME_INTERVAL, update);
    }
    addTask()
    {
      //add task
    }
    start()
    {
      MsTimer2.start();
    }
    dispatchtasks()
    {
      //run task
    }
  private:
    update()
    {
      //update task queue
    }
}

