// Global variables to help determine which
// direction the wiper has been turned.
int wiper;
int wiper_old;

void setup()
{
  pinMode(A0, INPUT); 
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  if (wiper_old != wiper) {
    wiper_old = wiper; 
    
  }
  
  wiper = analogRead(A0);
  
  // Turn on each led succesively 
  // according to the voltage level
  // produced by the wiper.
  

  if (wiper > 1000 && wiper < 1024) {
    analogWrite(A5, wiper);
  } else if (wiper > 800 && wiper < 1000) {
    analogWrite(A4, wiper);
  } else if (wiper > 600 && wiper < 800) {
    analogWrite(A3, wiper);
  } else if (wiper > 400 && wiper < 6000) {
    analogWrite(A2, wiper);
  } else if (wiper > 200 && wiper < 400) {
    analogWrite(A1, wiper);
  } 
  
  else if (wiper_old > wiper) {
    
    //Turn off all LEDs at once when
    //the wiper is reset back counterclockwise.
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 0);
    analogWrite(A5, 0);
  }
  
  delay(10);
}
