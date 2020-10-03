
int vib_pin=7;
int led_pin=13;
int vib_led = 12;
int laserPin = 10;
const int ldrPin = 4;
const int buzzerPin = 5;


              // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int pir_val = 0;                 // variable to store the sensor status (value)`



void setup() {
  
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  pinMode(vib_led,OUTPUT);
  pinMode(sensor, INPUT);
  pinMode (laserPin, OUTPUT); // define the digital output interface 13 feet
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);   

}

void loop() {
  vib_loop();
  
  pir_loop();
  delay(100);
  laser_loop ();
  ldr_loop();

}


void vib_loop() {
  int vib_val;
  vib_val=digitalRead(vib_pin);
  long measurement =pulseIn (vib_pin, HIGH);
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
  
  if(measurement>=1000)
  {
    digitalWrite(vib_led,HIGH);
     delay(100);

    
    Serial.print("Vibration Detected\t");
    
    
    //digitalWrite(vib_led,LOW);
    //delay(100);
    
   }
   else
   digitalWrite(vib_led,LOW);
}



void pir_loop() {
  pir_val = digitalRead(sensor);   // read sensor value
  if (pir_val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led_pin, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds

    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  }
  else {
    digitalWrite(led_pin, LOW); // turn LED OFF
    delay(100);             // delay 200 milliseconds

    if (state == HIGH) {
      Serial.println("Motion stopped!");
      state = LOW;       // update variable state to LOW
    }
  }
}




////
void laser_loop () {
   digitalWrite (laserPin, HIGH); // Turn Laser On
   //delay (1000); // On For Half a Second
   //digitalWrite (laserPin, LOW); // Turn Laser Off
   //delay (500); // Off for half a second
}



////
void ldr_loop() {


unsigned int ldr_measurment;

ldr_measurment = analogRead(A0);

Serial.println(ldr_measurment); 

//int ldrStatus = digitalRead(ldrPin);
//long ldr_measurment = pulseIn(ldrPin, HIGH);


if (ldr_measurment <= 200) {
  
digitalWrite (buzzerPin, LOW) ;
noTone(buzzerPin);

delay(100);
//digitalWrite(led_pin, LOW);

Serial.print("Its BRIGHT : ");



Serial.println(ldr_measurment);

} else {
  
digitalWrite (buzzerPin, HIGH) ;
tone(buzzerPin, 100);

delay(100);

Serial.println("----------- ALARM ACTIVATED -----------");

Serial.print("Its DARK : ");

Serial.println(ldr_measurment);

}

}
