#RxPlease!

RxPlease is a arduino library for reading RC receiver signal.
Whenever you need to read RC receiver signal from arduino, you struggle with some issues such as:
* Why does the delay happens?
* What the hell is an interrupt?
* Where am I and who am I?

Now time to forget about them. All you need to do is just download and use it.

## Usage
This library has only **two** functions you can use. How simple!

### initReceiver()
```c
int pinNum = 4;
int pins[] = {10, 11, 12, 13};
initReceiver(pinNum, pins); // specify how many and which pins you use
```

### readReceiver()
```c
int values[4];
readReceiver(values); // it stores the receiver values in the given array
Serial.print("channel 0: ");
Serial.println(values[0]);
```
