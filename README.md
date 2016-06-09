#RxPlease!

RxPlease is a arduino library for reading RC receiver signal.
Whenever you need to read RC receiver signal from arduino, you struggle with some issues such as:
* Why does the delay happens?
* What the hell is a interrupt?
* Where am I and who am I?

Now time to forget about them. All you need to do is just download and use this.

## Usage
This library has only two functions you can use. How simple!

### initReceiver()
```c
int pinNum = 4;
int pins[] = {10, 11, 12, 13};
initReceiver(pinNum, pins);
```

### readReceiver()
```c
int values[4];
readReceiver(values);
Serial.print("channel 0: ");
Serial.println(values[0]);
```
