//#include <libopencm3/stm32/f1/rcc.h>
//#include <libopencm3/stm32/f1/gpio.h>
//#include <libopencm3/stm32/timer.h>

#define LED PC13
#define SRV PC14
#define IMP_MIN 500
#define IMP_MAX 2360

#define SECOND 1000
#define MINUTE SECOND * 60
#define HOUR MINUTE * 60
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SRV, OUTPUT);
}

void loop() {

  digitalWrite(LED, HIGH);
  delay(SECOND);
  digitalWrite(LED, LOW);
  delay(SECOND);
  digitalWrite(LED, HIGH);
  delay(SECOND);
  digitalWrite(LED, LOW);
  delay(SECOND);
  digitalWrite(LED, HIGH);
  delay(SECOND);
  digitalWrite(LED, LOW);
  delay(SECOND);
  digitalWrite(LED, HIGH);

  
  writeMk(IMP_MIN);
  delay(MINUTE);

  writeMk(IMP_MAX);
  delay(2000);

  writeMk(IMP_MIN);
  delay(24 * HOUR);

}

void writeMk(int mks) {
  int i;
  for (i=0; i<10; i++){
    digitalWrite(SRV, HIGH);
    delayMicroseconds(mks);
    digitalWrite(SRV, LOW);
    delayMicroseconds(20000 - mks);
  }
}

void servoWrite(int angle){
  int i;
  for (i=0; i<8; i++){
    double absImp = angle*5;
    double imp = absImp + IMP_MIN;
    digitalWrite(SRV, HIGH);
    delayMicroseconds(imp);
    digitalWrite(SRV, LOW);
    delayMicroseconds(20000 - imp);
  }

}
