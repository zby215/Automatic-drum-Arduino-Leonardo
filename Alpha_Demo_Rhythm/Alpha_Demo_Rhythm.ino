// Drum Pins
int kick = 2;
int snare = 3;
int tom_s = 4;
int tom_m = 5;
int tom_l = 6;
int tamb = 7;
int cym_l = 8;
int cym_r = 9;

// Constants
const int BPM = 100;
const int KICK_C = 25;
const int SNARE_C = 20;
const int TOM_C = 20;
const int TAMB_C = 35;
const int CYM_C = 100;

// Debug Mode (0 or 1);
int debug = 1;

// Constant Calculations
const int Tick16 = 64;

void setup() {
  // Setting pinMode for all drums
  for (int drum = 2; drum <= 9; ++drum) {
    pinMode(drum, OUTPUT);
  }

  // initiating debugger Serial monitor
  if (debug == 1) {
    Serial.begin(9600);
  }
}

void loop() {  
  
  intro(400);
  verse1_1(400);
  verse1_2(400);
  verse1_1(400);
  verse1fill(400);
  
  verse2_1(400);
  verse2_2(400);
  verse2_1(400);
  verse2fill(400);

  digitalWrite(cym_l, HIGH);
  digitalWrite(kick, HIGH);
  digitalWrite(cym_r,HIGH);
  digitalWrite(tamb, HIGH);
  delay(80);
  digitalWrite(cym_l, LOW);
  digitalWrite(kick, LOW);
  digitalWrite(cym_r,LOW);
  digitalWrite(tamb, LOW);

  delay(100000);
  
}

void hit(int drum, int hitLen) {
  digitalWrite(drum, HIGH);
  delay(hitLen);
  digitalWrite(drum, LOW);
  delay(Tick16 - hitLen);
}
void wait(int period) {
  delay(period);
}

void intro(int tempo) {
  hit(snare, SNARE_C);
  delay(tempo);
  hit(snare, SNARE_C);
  delay(tempo);
  hit(snare, SNARE_C);
  delay(tempo/2);
  hit(snare, SNARE_C);
  delay(tempo/2);
  hit(snare, SNARE_C);
  delay(tempo/2);
  hit(snare, SNARE_C);
  delay(tempo/2);
}

void verse1_1(int tempo) {
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_l, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_l, LOW);
  delay(tempo);
  hit(snare, SNARE_C);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(tom_m, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 2);
  hit(snare, SNARE_C);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  digitalWrite(tamb, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  delay(tempo / 6);
}

void verse1_2(int tempo) {
  digitalWrite(tamb, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  delay(tempo / 2);
  hit(kick, KICK_C);
  delay(tempo / 2);
  hit(snare, SNARE_C);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 2);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 6);
}

void verse1fill(int tempo) {
  digitalWrite(tamb, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  delay(tempo / 2);
  hit(kick, KICK_C);
  delay(tempo / 2);
  hit(snare, SNARE_C);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 2);
  hit(tom_s, TOM_C);
  delay(tempo / 24);
  hit(tom_s, TOM_C);
  delay(tempo / 24);
  hit(tom_m, TOM_C);
  delay(tempo / 24);
  hit(tom_m, TOM_C);
  delay(tempo / 24);
  hit(tom_l, TOM_C);
  delay(tempo / 24);
  hit(tom_l, TOM_C);
  delay(tempo / 24);
  hit(tom_l, TOM_C);
  delay(tempo / 24);
}





void verse2_1(int tempo) {
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_l, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_l, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo);
  digitalWrite(cym_r, HIGH);
  hit(snare, SNARE_C);
  digitalWrite(cym_r, LOW);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  digitalWrite(cym_r, HIGH);
  hit(tom_m, TOM_C);
  digitalWrite(cym_r, LOW);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 2);
  digitalWrite(cym_r, HIGH);
  hit(snare, SNARE_C);
  digitalWrite(cym_r, LOW);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  digitalWrite(tamb, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  delay(tempo / 6);
}

void verse2_2(int tempo) {
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 2);
  hit(kick, KICK_C);
  delay(tempo / 2);
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(snare, SNARE_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 2);
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(snare, SNARE_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 6);
}

void verse2fill(int tempo) {
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 2);
  hit(kick, KICK_C);
  delay(tempo / 2);
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(snare, SNARE_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 2);
  hit(tom_l, TOM_C);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(kick, KICK_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 6);
  hit(snare, SNARE_C);
  delay(tempo / 6);
  hit(kick, KICK_C);
  delay(tempo / 2);
  digitalWrite(tamb, HIGH);
  digitalWrite(cym_r, HIGH);
  hit(tom_s, TOM_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 24);
  hit(tom_s, TOM_C);
  delay(tempo / 24);
  hit(tom_m, TOM_C);
  digitalWrite(tamb, LOW);
  digitalWrite(cym_r, LOW);
  delay(tempo / 24);
  hit(tom_m, TOM_C);
  delay(tempo / 24);
  hit(tom_l, TOM_C);
  delay(tempo / 24);
  hit(tom_l, TOM_C);
  delay(tempo / 24);
  hit(tom_l, TOM_C);
  delay(tempo / 24);
}
