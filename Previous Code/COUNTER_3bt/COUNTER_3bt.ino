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
  //int x = 0;
}

void loop(void) 
{
  static int i = 0;

  if(i == 1)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
  }else
  if( i == 2)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }else
  if( i == 3)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }else
  {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  }
  
  if(i==7)
  {
    i = 0;
  }
  else{
    i = i+1;
  }
  
  delay(1000);
}
