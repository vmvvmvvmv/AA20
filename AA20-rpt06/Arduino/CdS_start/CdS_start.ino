#define CDS_INPUT 0 

const int ledA = 13;

int threshold = 1000;

void setup() {
  pinMode(ledA,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(CDS_INPUT);
//  int lux = int(luminosity(value));
  Serial.println(int(luminosity(value)));
//  if (lux > threshold) {
//    digitalWrite(ledA,LOW);
//  }
//  else {
//    digitalWrite(ledA,HIGH);
//  }
  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
  
}
