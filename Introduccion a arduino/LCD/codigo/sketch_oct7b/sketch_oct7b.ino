#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte filas = 4;
const byte columnas = 3;
char keys[filas][columnas] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pinesfilas[filas]={4,3,2,1};
byte pinescolumnas[columnas]={7,6,5};

Keypad key = Keypad(makeKeymap(keys), pinesfilas, pinescolumnas, filas , columnas);

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  lcd.begin(0,0);
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("hola mundo");

}

void loop() {
  // put your main code here, to run repeatedly:
  char caracter = key.getKey();
  switch (caracter){
    case 42:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono *");
    break;
    case 35:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono #");
    break;
    case 48:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 0");
    break;
    case 49:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 1");
    break;
    case 50:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 2");
    break;
    case 51:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 3");
    break;
    case 52:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 4");
    break;
    case 53:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 5");
    break;
    case 54:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 6");
    break;
    case 55:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 7");
    break;
    case 56:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 8");
    break;
    case 57:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("se preciono 9");
    break;
  }
}
