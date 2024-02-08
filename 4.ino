int ss1=2;
int ss2=3;
int pt1=0;
int pt2=0;
int mt1=10;
int mt2=11;
int mt1_speed=0;
int mt2_speed=0;
int read1=0;
int read2=0;
int serial=0;
int sr1=0;
int sr2=0;

void setup()
{
  Serial.begin(9600);
  pinMode(2,0);
  pinMode(3,0);
  pinMode(10,1);
  pinMode(11,1);
}

void loop()
{
  read1=digitalRead(ss1);
  read2=digitalRead(ss2);
  
  serial=Serial.read();
  switch(serial)
  {
    case'1':sr1=1;
    Serial.println("switch one is on");
    break;
    
    case'2':sr2=1;
    Serial.println("switch two is on");
    break;
    
    case'0':sr1=0;
    sr2=0;
    Serial.println("switchs are off");
    break;
  }
  

  
  pt1 = analogRead(14);
  pt2 = analogRead(13);
  
  mt1_speed = map(pt1,0,1023,0,255);
  mt2_speed = map(pt2,0,1023,0,255);
  
  if(read1==1 || sr1==1)
  {
    analogWrite(mt1,mt1_speed);
  }
  else if (read1==0 || sr1==0)
  {
    analogWrite(mt1,0);
  }
  
  
  if(read2==1 || sr2==1)
  {
    analogWrite(mt2,mt2_speed);
  }
  else if (read2==0 || sr2==0)
  {
    analogWrite(mt2,0);
  }
  
  
 

 
}