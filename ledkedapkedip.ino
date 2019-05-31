int led = 9;
int led2 = 12;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
}
