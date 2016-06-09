#include "receiver.h"

void setup() {
  int pins[] = {10, 11, 12, 13, A8, A9, A10, A11};
  initReceiver(8, pins);
}

void loop() {
  int values[8];
  readReceiver(values);
}
