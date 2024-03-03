#define LED 8
#define TEMP A0

//Initiallizing the values for LED to blink 500 milliseconds
unsigned long CurrentMillis = 0;
unsigned long PrevBlinkMillis = 0;
const unsigned long BlinkPeriod = 500;


//Initiallizing the values for LED to blink 250 milliseconds
unsigned long CrrentMillis = 0;
unsigned long PreBlinkMillis = 0;
const unsigned long Blinkeriod = 250;

//Setting up the input and output pins
void setup()
{
  pinMode(TEMP, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

//Function to blink LED for 500 milliseconds
void blinkLed()
{
  if(CurrentMillis - PrevBlinkMillis >= BlinkPeriod)
  {
    PrevBlinkMillis = CurrentMillis;
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

//Function to blink LED for 250 milliseconds
void blink_Led()
{
  if(CrrentMillis - PreBlinkMillis >= Blinkeriod)
  {
    PreBlinkMillis = CrrentMillis;
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

void loop()
{
  int value=analogRead(TEMP);
  double volts,temp;
  //Calculate the analog voltage value that LM35 generates
  volts=0.0048828125*value; 

  //To calculte the temperature from analog value
  temp = (volts-0.5)*100; 
  
  //Printing the degree of temperature on the monitor
  Serial.print("TEMPERATURE: ");
  Serial.print(temp);
  Serial.print("\n");

  CurrentMillis = millis();
  CrrentMillis = millis();

  if(temp>=30)
  {
    blinkLed();  // Function calling to blink LED every 500 milliseconds
  }
  else
  {
    blink_Led(); // Function calling to blink LED every 250 milliseconds
  }
  
  
}
  
