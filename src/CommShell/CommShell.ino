/*
Put Declarations here. 
*/

#define SIZEOFBUF 64
#define S_INI 0 /*State of initialized*/
#define S_REC 1 /*State of recieving*/
#define S_END 2 /*State of ending*/
#define S_ERR 3 /*State of error*/

char buf[64];//定义能容纳64个元素的字符数组
int idx_p = 0;
int state;
int LEDPin=10;
const char WRONGPARAM[] = "Param Wrong.";
const char WRONGCMD[] = "Command Wrong.";

void setup()
{
  Serial.begin(9600);
  state = S_INI; //initial state
  doInitial();
  pinMode(LEDPin,OUTPUT);
  Serial.println("Hello, Arduino ComShell V0.1");
}

void loop()
{
  recieveCmd();
  //processCmd();
}

void doInitial()
{
  idx_p = 0;
  buf[idx_p] = '\0';
}

void recieveCmd()
{
  if(Serial.available() > 0) //recieve no data from the serial port
  {
    char c = Serial.read();
    if(c == '\n'){ //recieve  the '\n' char from the serial port
      if(state == S_INI) return;
      if(state == S_REC){
        state = S_END; 
        doEnding();
        state = S_INI;
        doInitial();
        return;
      }
      if(state == S_ERR){
        state = S_INI;
        doInitial();
        return;
      }
    }
    else{//recieve char that is not '\n'
      if(state == S_INI || state == S_REC) {
        state =S_REC;
        if(doRecieve(c) != 0){
          state = S_ERR;
          doError();
        }
        return;
      }
    }
  }
}

int doRecieve(char c)
{
  buf[idx_p] = c;
  idx_p ++;
  if(idx_p>=SIZEOFBUF)   return 1; //error
  buf[idx_p] = '\0';
  return 0; //OK
}

void doEnding()
{
  //Serial.println(buf);
  processCmd();
}
 
void doError()
{
  Serial.println("Buffer is full.");
}

void processCmd()
{
    char delims[] = " ";
    char *Cmd = NULL;
    Cmd = strtok( buf, delims );
    if(Cmd == NULL ) {
        Cmd = buf;
   }
   /*digitalRead*/
  String tmpS;
  tmpS = "digitalRead";
  char* param;
  char* param2;
  if(tmpS.equals(Cmd)){
      param = strtok(NULL, delims);
      if(!checkIntParam(param)) return;
      //Serial.println(atoi(param));
      if(digitalRead(atoi(param) )== HIGH){
        Serial.println("HIGH");
      }else{
        Serial.println("LOW");
      }
     return; 
  }
  /*digitalWrite*/
  tmpS = "digitalWrite";
  if(tmpS.equals(Cmd)){
      param = strtok(NULL, delims);
      if(!checkIntParam(param)) return;
      param2 = strtok(NULL, delims);
      if(!checkParam(param2)) return;
      //Serial.println(atoi(param));
     if(atoi(param2) == 0){
       digitalWrite(atoi(param), LOW);
     }  else{
       digitalWrite(atoi(param), HIGH);
     }
     Serial.println("OK");
     return;
  }
  
  /*put this at the end*/
  Serial.println(WRONGCMD);
  return;
}

boolean checkParam(char* param)
{
  if(param == NULL){
    Serial.println(WRONGPARAM);
    return false;
  }
  return true;
}

boolean checkIntParam(char* param)
{
  if(atoi(param) == 0){
    Serial.println(WRONGPARAM);
    return false;
  }
  return true;
}
