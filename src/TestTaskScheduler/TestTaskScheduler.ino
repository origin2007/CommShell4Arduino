#include <taskscheduler.h>

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  sch_init();
  sch_addTask(do1, 0, 100);
  sch_addTask(do2, 1, 100);
  sch_start();
}

void loop() {
  // put your main code here, to run repeatedly:
  sch_dispatchtasks();
  //Serial.print("+");
}

void do1()
{
  //Serial.print("+");
  digitalWrite(13, HIGH);
}

void do2()
{
  //Serial.println(sch_getTicker());
  //Serial.println(sch_getQueueSize());
  digitalWrite(13, LOW);
}

