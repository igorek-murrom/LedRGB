# 1 "c:\\Users\\dmina\\LedRGB\\down\\LedRGB.ino"
char r1, g1, b1, r2, g2, b2, r3, g3, b3, check = '0';
String RS, GS, BS, rs1, rs2, rs3, gs1, gs2, gs3, bs1, bs2, bs3;
int R = 0, G = 0, B = 0;
const int VIEW_PAUSE = 500;
bool flag;
unsigned long timing;




bool take() {
  if (Serial.available() > 9) {
    r1 = Serial.read();
    r2 = Serial.read();
    r3 = Serial.read();

    g1 = Serial.read();
    g2 = Serial.read();
    g3 = Serial.read();

    b1 = Serial.read();
    b2 = Serial.read();
    b3 = Serial.read();

    check = Serial.read();

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
  pinMode(9 /* пин для канала R*/, 0x1);
  pinMode(10 /* пин для канала G*/, 0x1);
  pinMode(6 /* пин для канала B*/, 0x1);
  Serial.begin(9600);
}

void loop() {
  flag = take();

  if (flag) {
    Serial.print(R); Serial.print(" ");
    Serial.print(G); Serial.print(" ");
    Serial.print(B); Serial.println(" ");
  }
  //  Serial.println(check);
  if (check == '0') setRGB(R, G, B, 0);
  else if (check == '1') RGB(25);
}

void RGB(int p)
{
  int red, green, blue;
  Serial.println("r-y");
  red = 255; green = 0; blue = 0;
  for (green = 0; green <= 255; green++) {
    setRGB(red, green, blue, p); if (sleep(p)) return;
  }
  if (sleep(VIEW_PAUSE)) return;

  Serial.println("y-g");
  red = 255; green = 255; blue = 0;
  for (red = 255; red >= 0; red--) {
    setRGB(red, green, blue, p); if (sleep(p)) return;
  }
  if (sleep(VIEW_PAUSE)) return;

  Serial.println("g-bb");
  red = 0; green = 255; blue = 0;
  for (blue = 0; blue <= 255; blue++) {
    setRGB(red, green, blue, p); if (sleep(p)) return;
  }
  if (sleep(VIEW_PAUSE)) return;

  Serial.println("bb-b");
  red = 0; green = 255; blue = 255;
  for (green = 255; green >= 0; green--) {
    setRGB(red, green, blue, p); if (sleep(p)) return;
  }
  timing = millis();
  if (sleep(VIEW_PAUSE)) return;

  Serial.println("b-p");
  red = 0; green = 0; blue = 255;
  for (red = 0; red <= 255; red++) {
    setRGB(red, green, blue, p); if (sleep(p)) return;
  }
  if (sleep(VIEW_PAUSE)) return;

  Serial.println("p-r");
  red = 255; green = 0; blue = 255;
  for (blue = 255; blue >= 0; blue--) {
    setRGB(red, green, blue, p); if (sleep(p)) return;
  }
  if (sleep(VIEW_PAUSE)) return;
Serial.print("a");
}
void setRGB(int r, int g, int b, int pause)
{
  r = 255 - r; g = 255 - g; b = 255 - b;
  analogWrite(9 /* пин для канала R*/, r);
  analogWrite(10 /* пин для канала G*/, g);
  analogWrite(6 /* пин для канала B*/, b);
  delay(pause);
}

bool sleep(int vipe) {
  timing = millis();
  while (millis() - timing < vipe) {
    take();
    if (check == '0') return true;
  }
  return false;
}
