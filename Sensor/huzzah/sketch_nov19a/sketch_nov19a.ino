void setup() {
    // put your setup code here, to run once:
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(0, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    int analogValue = analogRead(A0);
    if(analogValue < 250)
        digitalWrite(12, HIGH);
    else
        digitalWrite(12, LOW);
    if(analogValue < 500)
        digitalWrite(13, HIGH);
    else
        digitalWrite(13, LOW);
    if(analogValue < 750)
        digitalWrite(15, HIGH);
    else
        digitalWrite(15, LOW);
    if(analogValue < 1000)
        digitalWrite(0, HIGH);
    else
        digitalWrite(0, LOW);
}
