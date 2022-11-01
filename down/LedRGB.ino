char r1, g1, b1, r2, g2, b2, r3, g3, b3;
String RS, GS, BS, rs1, rs2, rs3, gs1, gs2, gs3, bs1, bs2, bs3;
int R = 255, G = 255, B = 255;

#define PIN_R 9    // пин для канала R
#define PIN_G 10    // пин для канала G
#define PIN_B 11   // пин для канала B

bool take() {
  if (Serial.available() > 8) {
    r1 = Serial.read();
    r2 = Serial.read();
    r3 = Serial.read();

    g1 = Serial.read();
    g2 = Serial.read();
    g3 = Serial.read();

    b1 = Serial.read();
    b2 = Serial.read();
    b3 = Serial.read();

    rs1 = String(r1); rs2 = String(r2); rs3 = String(r3);
    gs1 = String(g1); gs2 = String(g2); gs3 = String(g3);
    bs1 = String(b1); bs2 = String(b2); bs3 = String(b3);

    if (rs1 == "0") {
      rs1 = "";
      if (rs2 == "0") rs2 = "";
    }

    if (gs1 == "0") {
      gs1 = "";
      if (gs2 == "0") gs2 = "";
    }

    if (bs1 == "0") {
      bs1 = "";
      if (bs2 == "0") bs2 = "";
    }

    RS = rs1 + rs2 + rs3;
    GS = gs1 + gs2 + gs3;
    BS = bs1 + bs2 + bs3;
    R = RS.toInt(); G = GS.toInt(); B = BS.toInt();


    return true;
  }
  return false;
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  Serial.begin(9600);
}
bool flag;
void loop() {
  flag = take();

  if (flag) {
    Serial.print(R); Serial.print(" ");
    Serial.print(G); Serial.print(" ");
    Serial.println(B);
  }
  //  R %= 1024; G %= 1024; B %= 1024;
  //    R -= 255; G -= 255; B-= 255;

//  R = 255 - R; G = 255 - G; B = 255 - B;

  //  digitalWrite(GRBLED_PIN_R, 0);
  //  digitalWrite(GRBLED_PIN_G, 0);
  //  digitalWrite(GRBLED_PIN_B, 0);
  //  digitalWrite(GRBLED_PIN_B, 0);
  analogWrite(PIN_R, R);
  analogWrite(PIN_G, G);
  analogWrite(PIN_B, B);

}
//
//
//#define RED_PIN 11       // пин красного канала
//#define GREEN_PIN 10     // пин зелёного канала
//#define BLUE_PIN 9       // пин синего канала
//
//int red = 0, green = 0, blue = 0; // переменные текущего цвета
//
//void setup() {
//  Serial.begin(9600);             //общение с монитором порта
//  Serial.println("RBG LED v 1.0");//отправка версии прошивки в порт
//
//  pinMode(RED_PIN,   OUTPUT); // конфигурируем пин как цифровой выход красного канала
//  pinMode(GREEN_PIN, OUTPUT); // конфигурируем пин как цифровой выход зеленого канала
//  pinMode(BLUE_PIN,  OUTPUT); // конфигурируем пин как цифровой выход синего канала
//}
//
//void loop() {
//  red   = (red + 1)   % 1024; // меняем красный цвет
//  green = (green + 2) % 1024; // меняем зеленый цвет
//  blue  = (blue + 3)  % 1024; // меняем синий цвет
//
//  analogWrite(RED_PIN, red);    // выводим красный цвет
//  analogWrite(GREEN_PIN, green);// выводим зеленый цвет
//  analogWrite(BLUE_PIN, blue);  // выводим синий цвет
//  delay(10);                    // ждём 50 миллисекунд
//}
