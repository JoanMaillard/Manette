#define SDA_PORT PORTD
#define SDA_PIN 6 // = A4
#define SCL_PORT PORTD
#define SCL_PIN 7 // = A5
#include <SoftI2CMaster.h>

#define iobusAddress 0
#define pinaxis1 0
#define pinaxis2 1
#define pinaxis3 2
#define pinaxis4 3
#define pinaxis5 4
#define pinaxis6 5
#define DATA_SIZE 8
#define I2C_7BITADDR 0x20


const byte regA = 0x12;
const byte regB = 0x13;
byte potVal1, potVal2, joy1X, joy1Y, joy2X, joy2Y;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  i2c_init();
  if (!i2c_start((I2C_7BITADDR<<1)|I2C_WRITE)) { // start transfer
        Serial.println("I2C device busy");
        return;
    }
  i2c_write(0);
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR<<1)|I2C_WRITE);
  i2c_write(1);
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR<<1)|I2C_WRITE);
  i2c_write(0x0C);
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR<<1)|I2C_WRITE);
  i2c_write(0x0D);
  i2c_write(0xFF);
  i2c_stop();
  Serial.println("setup complete");
  pinMode(pinaxis1, INPUT);
  pinMode(pinaxis2, INPUT);
  pinMode(pinaxis3, INPUT);
  pinMode(pinaxis4, INPUT);
  pinMode(pinaxis5, INPUT);
  pinMode(pinaxis6, INPUT);

}

void loop() {
  if (!i2c_start((I2C_7BITADDR<<1)|I2C_WRITE)) { // start transfer
        Serial.println("I2C device busy");
        return;
    }
  i2c_write(regA);
  i2c_rep_start((I2C_7BITADDR<<1)|I2C_READ); // restart for reading
    byte val1 = i2c_read(true); // read one byte and send NAK to terminate
    i2c_stop(); // send stop condition
   if (!i2c_start((I2C_7BITADDR<<1)|I2C_WRITE)) { // start transfer
        Serial.println("I2C device busy");
        return;
    }
   i2c_write(regB);
   i2c_rep_start((I2C_7BITADDR<<1)|I2C_READ); // restart for reading
   byte val2 = i2c_read(true); // read one byte and send NAK to terminate
   i2c_stop(); // send stop condition
Serial.print(val1);
Serial.print(", ");
Serial.println(val2);
  // put your main code here, to run repeatedly:
  /*potVal1 = map(analogRead(pinaxis1),0,1023,0,255);
  potVal2 = map(analogRead(pinaxis2),0,1023,0,255);
  joy1X = map(analogRead(pinaxis3),0,1023,0,255);
  joy1Y = map(analogRead(pinaxis4),0,1023,0,255);
  joy2X = map(analogRead(pinaxis5),0,1023,0,255);
  joy2Y = map(analogRead(pinaxis6),0,1023,0,255);*/
  /*byte *mainData = conc();
  //Serial.write(mainData,DATA_SIZE);
  Serial.print(mainData[0]);
  Serial.print(", ");
  Serial.print(mainData[1]);
  Serial.print(", ");
  Serial.print(mainData[2]);
  Serial.print(", ");
  Serial.print(mainData[3]);
  Serial.print(", ");
  Serial.print(mainData[4]);
  Serial.print(", ");
  Serial.print(mainData[5]);
  Serial.print(", ");
  Serial.print(mainData[6]);
  Serial.print(", ");
  Serial.println(mainData[7]);*/
}

/*byte * conc() {
  static byte concatenated[DATA_SIZE];
  for (int i = 0; i<DATA_SIZE; i++) {
    concatenated[i]=0;
  }
 
  concatenated[2] = potVal1;
  concatenated[3] = potVal2;
  concatenated[4] = joy1X;
  concatenated[5] = joy1Y;
  concatenated[6] = joy2X;
  concatenated[7] = joy2Y;
  return concatenated;
}*/
