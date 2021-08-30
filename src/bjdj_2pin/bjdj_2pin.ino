
/*
 * 
 步进电机引脚说明:
 8->EN        步进电机驱动使能端，低电平有效
 7->Z.DIR     Z轴方向控制
 6->Y.DIR     Y轴方向控制
 5->X.DIR     X轴方向控制
 4->Z.STEP    Z轴步进控制
 3->Y.STEP    Y轴步进控制
 2->X.STEP    X轴步进控制
 * 
 * 
 */

#define EN      8     //步进电机使能端，低电平有效
#define X_DIR   5     //x轴 步进电机方向控制
#define Y_DIR   6     //y轴 步进电机方向控制
#define Z_DIR   7     //z轴 步进电机方向控制
#define X_STP   2     //x轴 步进控制
#define Y_STP   3     //y轴 步进控制
#define Z_STP   4     //z轴 步进控制

#define Key 9         //Xlimit
#define dirKey 10     //Ylimit
#define otherKey 11   //Spin_en
 //函数：moveStep 
 //功能:控制步进电机方向,步数
 //参数:
    //dir，方向控制,
    //dirPin,对应步进电机的DIR引脚
    //stepperPin,对应步进电机的step引脚
    //steps,步进的步数
 //返回值:无

void moveStep(boolean dir,byte dirPin,byte stepperPin,int steps)
{
  digitalWrite(dirPin,dir);
  delay(50);
  for(int i = 0;i < steps; i++){
    digitalWrite(stepperPin,HIGH);
//    delayMicroseconds(1000);
    delay(2);
    digitalWrite(stepperPin,LOW);
    delay(2);
//    delayMicroseconds(1000);
  }
}

void move1Step(boolean dir,byte dirPin,byte stepperPin){
    digitalWrite(dirPin,dir);
    digitalWrite(stepperPin,HIGH);
    delayMicroseconds(30);
//    delay(2);
    digitalWrite(stepperPin,LOW);
//    delay(2);
    delayMicroseconds(30);
}

int dirflog = 1;

void setup() {
  // put your setup code here, to run once:
  //步进电机用到的IO脚设置为输出
  pinMode(X_DIR,OUTPUT);
  pinMode(X_STP,OUTPUT);

  pinMode(Y_DIR,OUTPUT);
  pinMode(Y_STP,OUTPUT);

  pinMode(Z_DIR,OUTPUT);
  pinMode(Z_STP,OUTPUT);

  pinMode(EN,OUTPUT);
  digitalWrite(EN,LOW);
  pinMode(Key, INPUT_PULLUP);

  pinMode(dirflog, INPUT_PULLUP);
  pinMode(otherKey, INPUT_PULLUP);
  
  dirflog  = digitalRead(dirKey);
}


void loop() {
  
  int flog  = digitalRead(Key);
   if(!flog){
    move1Step(dirflog,Y_DIR,Y_STP);
  }
}
