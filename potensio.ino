void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int nilai_sensor = analogRead(A0);
//Serial.println(nilai_sensor);
float tegangan = nilai_sensor*5/1023;
Serial.println(tegangan);
}
