const int rojo1 = 13;
const int verde1 = 12;
const int amarillo1 = 11;
const int rojo2 = 10;
const int amarillo2 = 9;
const int verde2 = 8;

void setup() {
  pinMode(rojo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(amarillo1, OUTPUT);
  pinMode(rojo2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde2, OUTPUT);


}

void loop() {
  digitalWrite(rojo1, HIGH);
  digitalWrite(verde2, HIGH);
  delay(5000);
  digitalWrite(amarillo2, HIGH);
  digitalWrite(verde2, LOW);
  delay(1000);
  digitalWrite(amarillo2, LOW);
  digitalWrite(rojo1, LOW);
  digitalWrite(rojo2, HIGH);
  digitalWrite(verde1, HIGH);
  delay(5000);
  digitalWrite(amarillo1, HIGH);
  digitalWrite(verde1, LOW);
  delay(1000);
  digitalWrite(amarillo1, LOW);
  digitalWrite(rojo2, LOW);

}
