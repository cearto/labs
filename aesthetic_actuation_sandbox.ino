/*  Aesthetic Actuation Lab
 *  Updated 31 October 2016
 *  Author: Cesar Torres
 */

#define NUMPIXELS 16 // Number of LEDs in strip
#define LED1_PIN 9
#define LED2_PIN 10 
#define LED3_PIN 11 

/* BEHAVIORS GO HERE */
void all_off(){
  analogWrite(LED1_PIN, 0);
  analogWrite(LED2_PIN, 0);
  analogWrite(LED3_PIN, 0);
}
void all_on(){
  analogWrite(LED1_PIN, 255);
  analogWrite(LED2_PIN, 255);
  analogWrite(LED3_PIN, 255);
}

void utter_failure_behavior(){
  /* YOUR CODE HERE */
  Serial.println("NOT IMPLEMENTED");
}

void error_behavior(){
  /* YOUR CODE HERE */
  Serial.println("NOT IMPLEMENTED");
}

void warning_behavior(){
  /* YOUR CODE HERE */
  Serial.println("NOT IMPLEMENTED");
}

void calm_behavior(){
  /* YOUR CODE HERE */
  Serial.println("NOT IMPLEMENTED");
}

void victory_behavior(){
  /* YOUR CODE HERE */
  Serial.println("NOT IMPLEMENTED");
}



/* SANDBOX API */
char prefix = 0;

void api_call(char prefix){
  switch (prefix) {
    case 'p': 
      Serial.println("API COMMANDS");
      Serial.println("o - ALL ON");
      Serial.println("f - ALL OFF");
      Serial.println("q - UTTER FAILURE");
      Serial.println("w - ERROR");
      Serial.println("e - WARNING");
      Serial.println("r - CALM");
      Serial.println("t - VICTORY");       
      break;
    case 'o':
      Serial.println("ALL ON");
      all_on();
      break;
    case 'f':
      Serial.println("ALL OFF");
      all_off();
      break;
    case 'q':
      Serial.println("UTTER FAILURE");
      utter_failure_behavior();
      break;
    case 'w':
      Serial.println("ERROR");
       error_behavior();
      break;
    case 'e':
      Serial.println("WARNING");
       warning_behavior();
      break;
    case 'r':
      Serial.println("CALM");
       calm_behavior();
      break;
    case 't':
      Serial.println("VICTORY");
       victory_behavior();
       break;
    default: 
      Serial.print(prefix);
      Serial.println(" API command does not exist");
    break;
  }
}



// SERIAL CONSOLE INTERFACE
void registerActuators(){
  // add all setup commands for actuators here
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}


void setup() {
  Serial.begin(9600);
  Serial.println("Aesthetic Actuation Controller");
  registerActuators();
}


void enable_api(){
   // Listening for character input for Serial console
  if (Serial.available() > 0) {
      // read the incoming byte:
      prefix = Serial.read();
      if(Serial.read() == '\n'){
       Serial.print("Calling API Command: ");
       Serial.print(prefix);
       Serial.print(" ");
       api_call(prefix);
    }
  }
  delay(50);              // wait for a 50 milliseconds
}
void loop() {
 enable_api();
}
