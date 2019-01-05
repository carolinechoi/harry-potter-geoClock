Servo hpServo; 

void setup()
{

Particle.function("hpServo", command);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);
pinMode(D5, OUTPUT);
pinMode(D7, OUTPUT);
    
RGB.control(true);
RGB.color(0, 0, 0);
}
 
void loop()
{
    digitalWrite(D7, HIGH);
    delay(2000);
    digitalWrite(D7, LOW);
    delay(2000);
}
 
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


  
