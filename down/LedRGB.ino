char r1, g1, b1, r2, g2, b2, r3, g3, b3;
String RS, GS, BS, rs1, rs2, rs3, gs1, gs2, gs3, bs1, bs2, bs3;
int R, G, B;

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


}
