//arduino
//created by jack
//2016.4.26


#include”taskscheduler.h” //包含这个头文件，才能调用这个调度器

//用于储存led状态
boolean g_led1State = 1 ;
boolean g_led2State = 0 ;
Void setup()
{
  //第12，13引脚接有led
  pinMode(13, output);
  pinMode(12, output)；
  MsTimer2::set(1000, flash); // 中断设置函数，每 1000ms 进入一次中断
  MsTimer2::start();      //开始计时

  Sch.init();//初始化调度器
  //向调度器中添加任务，
  //第一个参数为要添加的函数名
  //第二个参数为任务的第一次执行时间
  //合理设置有利于防止任务重叠，有利于提高任务执行的精度
  //第二三个参数的单位均为毫秒，也可以配置定时器修改其单位
  Sch.addTask(led1Update, 0, 1000); //添加任务
  Sch.addTask(led2Update, 30, 2000);
  Sch.start();//启动调度器
}
Void loop()
{
  Sch.dispatchTasks();
}
Void led1Update(void) {
  If (g_led1State == 0)
  {
    g_led1State = 1;
    digitalWrite(13, HIGH);
  }
  else
  {
    g_led1State = 0;
    digitalWrite(13, LOW);
  }
}
//闪烁第12引脚的led灯
Void led1Update(void) {
  If (g_led2state == 0)
  {
    g_led2State = 1;
    digitalWrite(12, HIGH);
  }
  else
  {
    g_led2State = 0;
    digitalWrite(12, LOW);
  }
}

