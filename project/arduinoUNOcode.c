int sensorPin=0;				// Sensor's value initialization
int red_led = 3;				// Red's pin number
int orange_led = 4;				// Orange's pin number
int green_led = 5;				// Green's pin number
int buzzer = 10;				// Buzzer's pin number
int clear_value = 487;			// Sensor's clear air value
int frequency = 750;			// The frequency of the buzzer's note
int duration = 50;				// Just a duration for the buzzer's note
int scan_delay = duration;		// Each scan should be as long as a note
int medium_value = 50;			// The least value for a medium scan
int high_value = 200;			// The least value for a high scan
int data_rate = 9600;			// Arduino's data rate

void setup()
{
  Serial.begin(data_rate);		/* Sets the data rate */
  pinMode(red_led, OUTPUT);		/* RED LED            */
  pinMode(orange_led, OUTPUT);	/* ORANGE LED         */
  pinMode(green_led, OUTPUT);	/* GREEN LED          */
  pinMode(buzzer, OUTPUT);		/* BUZZER             */
}

void loop()
{
  sensorPin=analogRead(A0)-clear_value;	// Normalizing the values to zero
  //Serial.println(sensorPin);			// Printing values on screen
  delay(scan_delay);				// Time till next scan
  if(sensorPin<=medium_value){			// If co2 is low then
    digitalWrite(green_led, HIGH);		// Turn on green led
    digitalWrite(orange_led, LOW);		// Turn off orange led
    digitalWrite(red_led, LOW);			// Turn off red led
  }
  else if(sensorPin<=high_value){		// If co2 is medium then
    digitalWrite(green_led, LOW);		// Turn off green led
    digitalWrite(orange_led, HIGH);		// Turn on orange led
    digitalWrite(red_led, LOW);			// Turn off red led
  }
  else{						// If co2 is high then
  	digitalWrite(green_led, LOW);		// Turn off green led
    digitalWrite(orange_led, LOW);		// Turn off orange led
    digitalWrite(red_led, HIGH);		// Turn on red led
    tone(buzzer, frequency, duration);	// Play the note
  }   
}
