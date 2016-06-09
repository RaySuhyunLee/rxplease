/* Receiver.cpp
 * 
 * read pwm signals from the RC receiver. 
 */

#define EI_ARDUINO_INTERRUPTED_PIN

#include <Arduino.h>
#include <EnableInterrupt.h>

#define CHANNEL_MAX 10
uint16_t value[CHANNEL_MAX];

uint8_t _pins[CHANNEL_MAX];
uint8_t _channel_num;

volatile long timeStamp[CHANNEL_MAX];

#define READ_SIGNAL(pin, channel) \
  if (digitalRead((pin)) == HIGH) { \
    timeStamp[channel] = micros(); \
  } else { \
    value[channel] = micros() - timeStamp[channel]; \
  }

#define NEUTRALIZE(value) \
  (1500 - (value))

void readSignal() {
  uint8_t pin = arduinoInterruptedPin;
  long m = micros();
  for (uint8_t i=0; i<CHANNEL_MAX; i++) {
    if (_pins[i] == pin) {
      if (digitalRead(pin) == HIGH) {
        timeStamp[i] = m;
      } else {
        value[i] = m - timeStamp[i];
      }
    }
  }
}

void initReceiver(int channel_num, int *pins) {
  _channel_num = channel_num;
  for (int i=0; i<_channel_num && i<CHANNEL_MAX; i++) {
    _pins[i] = pins[i];
    pinMode(_pins[i], INPUT);
    enableInterrupt(_pins[i], &readSignal, CHANGE);
  }
}

void readReceiver(int *values) {
  for (int i=0; i<_channel_num; i++) {
    values[i] = (int)value[i];
  }
}
