// create servo object to control a servo
// a maximum of eight servo objects can be created
// Servo denotes the variable type, and hpServo is the name.
Servo hpServo; 
 // variable to store the servo position
 // we should start this at the initial position which we can denote as 0 

void setup()
{

//Setup the Servo to the function 
// replace args encased in {}s with designated names
Particle.function("hpServo", command);
//Set an output pin
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);
pinMode(D5, OUTPUT);
pinMode(D7, OUTPUT);
    
//Take control over the LED on the board
RGB.control(true);
//Turn off the LED - we dont want it flashing behind the photo frame at night
//Think about what this next line does. HINT: Google RGB values
RGB.color(0, 0, 0);
}
 
void loop()
{
    digitalWrite(D7, HIGH);
    delay(2000);
    digitalWrite(D7, LOW);
    delay(2000);
// We don't need to do anything here. Think about why.
// Because this void loop() is necessary for the code to run, but it does not need to do anything - just part of syntax. 
}
 

//Define a function here. We want this function to be called when IFTTT sends an update to our Particle device.
//Consider that this update function necessarily takes in a string labeled "command" that corresponds to the input given by IFTTT
int command(String x) {
hpServo.attach(D2);
    if (x == "home") {
        hpServo.write((uint8_t) 90);
        digitalWrite(D5, HIGH);
        delay(2000);
        digitalWrite(D5,LOW);
        delay(2000);
    } else if (x == "school") {
        hpServo.write((uint8_t) 45);
        digitalWrite(D3, HIGH);
        delay(2000);
        digitalWrite(D3,LOW);
        delay(2000);
    } else {
        hpServo.write((uint8_t) 135);
        digitalWrite(D4,HIGH);
        delay(2000);
        digitalWrite(D4,LOW);
        delay(2000);
    }
hpServo.detach();

return 1;
}


  
