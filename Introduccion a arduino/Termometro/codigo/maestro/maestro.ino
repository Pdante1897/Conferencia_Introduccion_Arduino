#include <Wire.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const byte filas=4;
const byte columnas=3;
char keys[filas][columnas]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};
byte pinesfilas[filas]={10,9,8,7};
byte pinescolumnas[columnas]={13,12,11};

Keypad key= Keypad(makeKeymap(keys),pinesfilas,pinescolumnas,filas,columnas);

LiquidCrystal_I2C lcd(0x20,16,2);

char ClaveMaestro[7]="202302";
char Clave[7]="";
int contador = 0;



void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("CASA ORGA");
  lcd.setCursor(0,1);
  lcd.print("2023 S2");
}

void loop() {
  // put your main code here, to run repeatedly:
  char lectura = key.getKey();
  if (lectura){
    if(lectura == 42){
      boolean comprobacion = comprobarcontra();
      if(comprobacion){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("BIENVENIDO A");
        lcd.setCursor(0,1);
        lcd.print("ORGA");
        Wire.beginTransmission(23);
        Wire.write('a');
        Wire.endTransmission();
      }else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("CONTRASENIA");
        lcd.setCursor(0,1);
        lcd.print("INCORRECTA");
        contador = 0;
      }
    }else if (lectura == 35){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("SE APAGARA");
        Wire.beginTransmission(23);
        Wire.write('b');
        Wire.endTransmission();
    }
    else{
      if(contador == sizeof(ClaveMaestro)){
        contador = 0;
      }
      Clave[contador]= lectura;
      contador++;
    }
  }
}

boolean comprobarcontra(){
  for(int i=0; i<7; i++){
    if(ClaveMaestro[i]!=Clave[i]){
      return false;
    }

  }  
  return true;
}





