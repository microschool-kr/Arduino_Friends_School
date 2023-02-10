int IRSensor = 9;
int LED = 13;

void setup() {
    Serial.begin(115200);
    Serial.println("Serial Working");
    pinMode(IRSensor, INPUT);
    pinMode(LED, OUTPUT);
    
}

void loop() {
    int sensorStatus = digitalRead(IRSensor);
    if (sensorStatus == 1)
    {
        digitalWrite(LED, LOW);
        Serial.println("Motion Ended!");
        delay(1000);
    }

    else
    {
       digitalWrite(LED, HIGH);
       Serial.println("Motion Detected!");
       delay(1000);
    }

}
