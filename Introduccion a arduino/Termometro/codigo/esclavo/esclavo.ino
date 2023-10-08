#include <LiquidCrystal.h>
#include <Wire.h>

char estado; //a o b de lo que reciba del arduino maestro

const int rs=12, en=11, d4=5, d5=4, d6=3,d7=2, MOTOR1 = 6, MOTOR2 = 7;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int tempC=0;
int direccion = 0x48;
void setup() {
  // put your setup code here, to run once:
  Wire.begin(23);
  Serial.begin(9600);
  Wire.onReceive(RecibirDatos);
  lcd.begin(16,2);

  Wire.beginTransmission(direccion);
  Wire.write(0xAC);
  Wire.write(0X02);
  Wire.beginTransmission(direccion);
  Wire.write(0xEE);
  Wire.endTransmission();

  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  digitalWrite(MOTOR1, LOW);
  digitalWrite(MOTOR2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (estado == 97){
    Wire.beginTransmission(direccion);
    Wire.write(0xAA);
    Wire.endTransmission();
    Wire.requestFrom(direccion, 1);
    tempC= Wire.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(tempC);
    lcd.setCursor(8, 0);
    lcd.write((byte)0);
    lcd.print("C");
    if (tempC <= 18){
      lcd.setCursor(0, 1);
      lcd.print("Nivel: 1");
      digitalWrite(MOTOR1, LOW);
      digitalWrite(MOTOR2, LOW);
    }else if (tempC >18 && tempC < 25){
      lcd.setCursor(0, 1);
      lcd.print("Nivel: 2");
      digitalWrite(MOTOR1, HIGH);
      digitalWrite(MOTOR2, LOW);
    }
    else if (tempC >= 25){
      lcd.setCursor(0, 1);
      lcd.print("Nivel: 3");
      digitalWrite(MOTOR1, HIGH);
      digitalWrite(MOTOR2, HIGH);
    }
  }else{
    lcd.clear();
    lcd.print("Apagado");
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, LOW);
  }
  delay(500);

}

void RecibirDatos(){
  estado = Wire.read();
}