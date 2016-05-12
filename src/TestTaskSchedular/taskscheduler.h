#ifndef taskschedular_h
#define taskschedular_h

#define MAX_TASK_COUNT = 10

typedef struct {
  (void *) pFunc;
 
} Task;

Class Sch
{
  public:
    Sch();
    init();
    addTask();
    start();
    dispatchtasks();
  private:
    Task taskqueue[MAX_TASK_COUNT];
    update();
}

#endif
