#include "MIDIUSB.h"

int val;

// light
int kick_LED = A0;
int snare_LED = A1;
int tom_s_LED = A2;
int tom_m_LED = A3;
int tom_l_LED = A4;

// Midi Constants
const int KICK_LED = 31;
const int SNARE_LED = 32;
const int TOML_LED = 33;
const int TOMM_LED = 34;
const int TOMS_LED = 35;

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup() {
  Serial.begin(115200);
  for(int LED=A0;LED<=A5;LED++)
  {
    pinMode(LED,OUTPUT);
  }
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      if (rx.header == 9) {
        val = HIGH;
      }
      else if (rx.header == 8) {
        val = LOW;
      }
      Serial.println(rx.byte2);
      switch (rx.byte2) {
        case KICK_LED:
          digitalWrite(kick_LED,val);
          break;
        case SNARE_LED:
          digitalWrite(snare_LED,val);
          break;
        case TOML_LED:
          digitalWrite(tom_l_LED,val);
          break;
        case TOMM_LED:
          digitalWrite(tom_m_LED,val);
          break;
        case TOMS_LED:
          digitalWrite(tom_s_LED,val);
          break;
      }
    }
  } while (rx.header != 0);
}
