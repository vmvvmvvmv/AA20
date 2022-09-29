//
// AA00, TMP36 sensor
//
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define TMP36_INPUT 0
#define CDS_INPUT 1
// or  int TEMP_INPUT = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AA20,Temp: ");
  lcd.setCursor(0,1);
  lcd.print("Light: ");
  lcd.setCursor(13,1);
  lcd.print("lux");
}

void loop() {
   //getting the voltage reading from the temperature sensor
  int temp_value = analogRead(TMP36_INPUT);
  float voltage = temp_value * 5.0 * 1000;
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10;

  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));

  lcd.setCursor(12,0);
  lcd.print("    ");
  lcd.setCursor(12,0);
  lcd.print(tempC);
  lcd.setCursor(9,1);
  lcd.print("    ");
  lcd.setCursor(9,1);
  lcd.print(lux);
  
  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);
 
  delay(1000);
}
  double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
  
}
