
                              
int val = 0;                 // variable to store the sensor status (value)

int pirState = LOW;
// Pin 14 is the D5
// 4th from left top. - this controls the relay
#define CONTROL_RELAY 14


// Pin 16 is the third from the left top. On the 3v3 rail.
// This pin detects any movement on the MD.
// set as INPUT.
#define pirPin         16 //  Motion Sensor data pin is connected to this. ( D0= Wemos)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED OFF - to indicate connection not done yet.
  
  // this is pin 14 for controlling the relay / lights on and off.
  pinMode (CONTROL_RELAY, OUTPUT);
  pinMode ( pirPin , INPUT );      // Indicate that you are going to receive Motion Sensor Data.

  Serial.begin(115200);
  Serial.println ("Starting the MD ");
}

void loop() {
  val = digitalRead(pirPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(LED_BUILTIN, LOW);  // turn LED OFF
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      digitalWrite(CONTROL_RELAY, LOW);  // turn RELAY ON
    }
  } else {
    digitalWrite(LED_BUILTIN, HIGH); // turn LED ON
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
      digitalWrite(CONTROL_RELAY, HIGH);  // turn RELAY OFF
    }
  }
}
