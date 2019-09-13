#define RED 2
#define GREEN 3
#define BLUE 4

void setup(void) 
{
 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
}


void loop() {
  // put your main code here, to run repeatedly:
 static int i = 0;

  if(i < 100)
  {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);   
  }

  if( i > 100 && i < 200)
  {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  }

  if( i >= 200 && i < 256)
  {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  }
 if(i==255)
  {
    i = 0;
  }
  else{
    i = i+1;
  }
  
  delay(5);
}
