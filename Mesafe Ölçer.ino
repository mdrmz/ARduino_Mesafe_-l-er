#define trigPin 4
#define echoPin 2
long sure, mesafe;
void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.println("Arduino İle Mesafe Sensörü Uygulaması Başlatılıyor...");
delay(3000);
}

void loop() {
  digitalWrite(trigPin, LOW);
delayMicroseconds(3);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
mesafe = (sure/2) * 0.0343;
Serial.print(mesafe);

Serial.println(" cm uzaklıkta");
if(mesafe < 10)
{
  digitalWrite(7,HIGH);
  delay(10);
  digitalWrite(11, HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);

}
else if(mesafe > 10 && mesafe < 40){
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  digitalWrite(11, LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);

}
else{
  digitalWrite(7,LOW);
 digitalWrite(11, LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);  
}
delay(500);

}
