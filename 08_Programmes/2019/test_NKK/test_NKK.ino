#include <SPI.h>

#define SDA 2
#define SCK 4
#define RST 5
#define SS 18
#define DC 19
#define SW2 22

static const int spiClk = 160000000;

byte image[] = {0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0xc6,0x38,0xce,0x59,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xc6,0x18,0xb5,0xb6,0xb5,0xb6,0xb5,0xb6,0xb5,0xb6,0xbd,0xf7,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xb5,0x96,0xb5,0xb6,0xb5,0xb6,0xbd,0xf7,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xce,0x59,0x8c,0x71,0x7b,0xcf,0x7b,0xcf,0x9c,0xf3,0xd6,0x9a,0xce,0x79,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xa5,0x14,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xad,0x75,0xd6,0x9a,0xc6,0x38,0xc6,0x18,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xce,0x59,0x9c,0xd3,0x84,0x30,0x8c,0x71,0xbd,0xf7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xad,0x55,0x84,0x30,0x8c,0x51,0xad,0x55,0xd6,0x9a,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xc6,0x38,0x94,0xb2,0x84,0x10,0x94,0x92,0xc6,0x18,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xa5,0x14,0x84,0x30,0x8c,0x51,0xb5,0x96,0xd6,0x9a,0xc6,0x38
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0x94,0x92,0x73,0xae,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x9c,0xd3,0xd6,0x9a,0xd6,0x9a,0xc6,0x38,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0x94,0x92,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x7b,0xef,0xc6,0x38,0xd6,0x9a,0xad,0x55,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xad,0x75,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0x8c,0x51,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x84,0x10,0xce,0x59,0xd6,0x9a,0xa5,0x14,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x7b,0xcf,0xb5,0xb6,0xc6,0x38
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xa5,0x14,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xa5,0x14,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xce,0x79,0x7b,0xcf,0x7b,0xcf,0x84,0x10,0x7b,0xcf,0x7b,0xcf,0xad,0x55,0xd6,0x9a,0x8c,0x71,0x73,0xae,0x7b,0xef,0x7b,0xef,0x7b,0xcf,0x94,0x92,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xc6,0x18,0x7b,0xcf,0x7b,0xef,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0xb5,0x96,0xce,0x79,0x84,0x30,0x73,0xae,0x84,0x10,0x7b,0xef,0x7b,0xcf,0x9c,0xd3,0xc6,0x38
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0xc6,0x38,0xce,0x79,0xd6,0x9a,0xce,0x59,0x8c,0x71,0x7b,0xcf,0x7b,0xcf,0x8c,0x51,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0x84,0x10,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xb5,0xb6,0xd6,0x9a,0x94,0xb2,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0x9c,0xd3,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xce,0x59,0x7b,0xef,0x73,0xae,0x73,0xae,0x73,0xae,0x7b,0xcf,0xbd,0xf7,0xd6,0x9a,0x8c,0x71,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xa5,0x14,0xc6,0x38
,0xd6,0xba,0xd6,0xba,0xce,0x59,0xc6,0x38,0x8c,0x51,0x7b,0xcf,0x7b,0xcf,0xad,0x55,0xd6,0x9a,0xce,0x79,0xbd,0xf7,0xbd,0xd7,0xce,0x79,0xce,0x79,0xa5,0x34,0x84,0x10,0x84,0x10,0xa5,0x14,0xce,0x79,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0xad,0x75,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0x94,0x92,0xce,0x79,0xd6,0x9a,0xc6,0x18,0x84,0x10,0x7b,0xcf,0x7b,0xcf,0x84,0x10,0xc6,0x38,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59,0xd6,0x9a,0xad,0x55,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x9c,0xd3,0xd6,0x9a,0xd6,0x9a,0xbd,0xf7,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0x84,0x30,0xce,0x59,0xc6,0x38
,0xd6,0xba,0xce,0x79,0xd6,0x9a,0x94,0x92,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xbd,0xf7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xb5,0xb6,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xad,0x55,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xc6,0x18,0xad,0x75,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xb5,0x96,0xb5,0x96,0xce,0x59,0xd6,0x9a,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xbd,0xf7,0xad,0x75,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xad,0x75,0xb5,0x96,0xce,0x79,0xd6,0x9a,0xc6,0x38
,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0x84,0x10,0x73,0xae,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0xa5,0x34,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0x9c,0xf3,0x7b,0xcf,0x84,0x10,0x7b,0xcf,0x7b,0xcf,0x8c,0x71,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xce,0x59,0xce,0x59,0xce,0x59,0xc6,0x38,0xce,0x59,0xce,0x59,0xce,0x79,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xce,0x59,0xd6,0x9a,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xc6,0x18
,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0x94,0xb2,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xb5,0x96,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xad,0x55,0x7b,0xcf,0x73,0xae,0x7b,0xef,0x7b,0xcf,0x94,0x92,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xc6,0x38,0xc6,0x18,0xce,0x59,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x79,0xce,0x79,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xce,0x59,0xc6,0x18
,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xc6,0x38,0x8c,0x51,0x7b,0xcf,0x7b,0xcf,0x94,0x92,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0x8c,0x51,0x7b,0xcf,0x7b,0xcf,0x7b,0xef,0xbd,0xd7,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xbd,0xf7,0xc6,0x38,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xb5,0xb6,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xb5,0x96,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xbd,0xd7,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xce,0x59
,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xce,0x79,0xbd,0xd7,0xbd,0xf7,0xce,0x79,0xce,0x79,0x9c,0xf3,0x7b,0xef,0x84,0x10,0xad,0x75,0xd6,0x9a,0xce,0x79,0xb5,0x96,0xad,0x55,0xc6,0x38,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0x94,0xb2,0x9c,0xf3,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xad,0x75,0x84,0x30,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xc6,0x38,0x84,0x10,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0x94,0x92,0xa5,0x14,0xd6,0x9a,0xd6,0x9a,0xce,0x59
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xa5,0x34,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0xb5,0xb6,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xbd,0xf7,0x7b,0xef,0x7b,0xef,0xc6,0x38,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0x84,0x30,0x7b,0xef,0xad,0x55,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0x9c,0xf3,0x7b,0xef,0x94,0x92,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xb5,0xb6,0x7b,0xef,0x7b,0xef,0xce,0x59,0xd6,0x9a,0xc6,0x38
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0x94,0x92,0x7b,0xcf,0x84,0x10,0x73,0xae,0x7b,0xcf,0x9c,0xd3,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0x94,0x92,0x7b,0xef,0x84,0x10,0x9c,0xd3,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xad,0x75,0x7b,0xef,0x7b,0xef,0x84,0x10,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xc6,0x38,0x7b,0xef,0x84,0x10,0x7b,0xcf,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0x8c,0x71,0x84,0x10,0x7b,0xef,0xa5,0x14,0xd6,0x9a,0xc6,0x38
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0x9c,0xf3,0x7b,0xcf,0x73,0xae,0x7b,0xef,0x7b,0xcf,0x9c,0xf3,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xbd,0xf7,0x7b,0xef,0x7b,0xef,0x7b,0xef,0x7b,0xef,0xc6,0x38,0xd6,0x9a,0xce,0x79,0x84,0x30,0x7b,0xef,0x7b,0xef,0x7b,0xef,0xad,0x55,0xd6,0x9a,0xd6,0x9a,0x9c,0xf3,0x7b,0xef,0x7b,0xef,0x7b,0xef,0x94,0x92,0xd6,0x9a,0xd6,0x9a,0xbd,0xd7,0x7b,0xef,0x7b,0xef,0x7b,0xef,0x84,0x10,0xce,0x59,0xc6,0x38
,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xc6,0x38,0x84,0x30,0x7b,0xcf,0x7b,0xcf,0x84,0x10,0xc6,0x38,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xad,0x75,0x94,0xb2,0x94,0xb2,0x94,0xb2,0x94,0xb2,0xb5,0x96,0xd6,0x9a,0xbd,0xf7,0x94,0xb2,0x94,0x92,0x94,0x92,0x94,0xb2,0x9c,0xf3,0xd6,0x9a,0xce,0x79,0x94,0xb2,0x94,0xb2,0x94,0x92,0x94,0x92,0x94,0xb2,0xc6,0x38,0xd6,0x9a,0xa5,0x34,0x94,0xb2,0x94,0xb2,0x94,0xb2,0x94,0xb2,0xb5,0xb6,0xc6,0x38
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xce,0x79,0xad,0x75,0xad,0x75,0xce,0x59,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xc6,0x38,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xc6,0x38,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xbd,0xf7,0x94,0x92,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0x8c,0x51,0xc6,0x38,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0x94,0x92,0x7b,0xef,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xad,0x55,0x7b,0xef,0x9c,0xf3,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xbd,0xd7,0x7b,0xef,0x7b,0xef,0x8c,0x71,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0x84,0x10,0x7b,0xef,0x7b,0xef,0xc6,0x38,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0x94,0x92,0x7b,0xef,0x7b,0xef,0x7b,0xef,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xad,0x75,0x7b,0xef,0x84,0x10,0x7b,0xef,0xa5,0x14,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xc6,0x38,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xbd,0xf7,0x84,0x10,0x7b,0xef,0x7b,0xef,0x7b,0xef,0x94,0x92,0xd6,0x9a,0xce,0x79,0x84,0x30,0x7b,0xef,0x7b,0xef,0x7b,0xef,0x84,0x30,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xce,0x59,0xad,0x75,0xad,0x75,0xce,0x59,0xce,0x59,0xbd,0xd7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xd6,0x9a,0xce,0x79,0xce,0x79,0xce,0x59,0xc6,0x38,0xc6,0x38,0xc6,0x38,0xc6,0x38,0xc6,0x38,0xce,0x79,0xce,0x59,0xc6,0x38,0xc6,0x38,0xc6,0x38,0xc6,0x38,0xc6,0x38,0xce,0x59,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xc6,0x18
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xce,0x59,0x84,0x10,0x7b,0xcf,0x7b,0xcf,0x84,0x10,0xc6,0x18,0xce,0x59,0xbd,0xf7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xa5,0x34,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0x94,0xb2,0xd6,0x9a,0xce,0x59,0xbd,0xd7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xa5,0x14,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x73,0xae,0x8c,0x51,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xbd,0xf7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xbd,0xf7,0x7b,0xcf,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x9c,0xf3,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xbd,0xd7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xc6,0x38,0xad,0x75,0xb5,0x96,0xce,0x79,0xce,0x79,0xb5,0x96,0x84,0x30,0x7b,0xef,0x94,0xb2,0xce,0x59,0xd6,0x9a,0xc6,0x18,0xbd,0xd7,0xce,0x79,0xce,0x59,0xce,0x79,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xc6,0x18,0x7b,0xef,0x7b,0xcf,0x73,0xae,0x84,0x30,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xce,0x79,0x94,0xb2,0x7b,0xcf,0x7b,0xcf,0x84,0x10,0xc6,0x18,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0x9c,0xd3,0x7b,0xcf,0x73,0xae,0x73,0xae,0x73,0xae,0xa5,0x14,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xbd,0xd7,0x7b,0xcf,0x73,0xae,0x73,0xae,0x7b,0xcf,0x8c,0x71,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xc6,0x18,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xce,0x59,0xd6,0xba,0xd6,0x9a,0x94,0xb2,0x7b,0xcf,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x94,0xb2,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xad,0x75,0x7b,0xcf,0x73,0xae,0x7b,0xef,0x73,0xae,0x7b,0xef,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0x9c,0xf3,0x9c,0xf3,0x9c,0xd3,0x9c,0xd3,0x94,0x92,0x9c,0xd3,0x9c,0xd3,0x9c,0xf3,0x9c,0xf3,0xb5,0xb6,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xb5,0x96,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0xad,0x55,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xc6,0x18,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x8c,0x51,0xd6,0x9a,0xce,0x59,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x59,0x7b,0xcf,0x73,0xae,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x7b,0xcf,0xa5,0x14,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xad,0x55,0x84,0x30,0x84,0x10,0x9c,0xf3,0xce,0x79,0xce,0x79,0xbd,0xf7,0xbd,0xf7,0xce,0x79,0xce,0x79,0xad,0x75,0x7b,0xef,0x7b,0xef,0x84,0x30,0xbd,0xf7,0xce,0x59,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x59,0x73,0xae,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0xa5,0x14,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79
,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xce,0x79,0x8c,0x71,0x73,0xae,0x73,0xae,0x8c,0x51,0xce,0x59,0xd6,0x9a,0xce,0x79,0xc6,0x38,0xd6,0x9a,0xce,0x59,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xc6,0x18,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x73,0xae,0x9c,0xd3,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x59
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xad,0x55,0x7b,0xcf,0x73,0xae,0x73,0xae,0x73,0xae,0x9c,0xd3,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x59,0xce,0x59,0xbd,0xd7,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x9c,0xd3,0xce,0x59,0xce,0x79,0xce,0x79,0xd6,0x9a,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x59,0xc6,0x18,0xc6,0x18,0xc6,0x18,0xc6,0x18,0xce,0x59,0xce,0x79,0xce,0x79,0xce,0x79,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x79
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0x9a,0xa5,0x14,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x7b,0xcf,0x8c,0x51,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x59,0x7b,0xcf,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x73,0xae,0xa5,0x14,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xad,0x75,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x8c,0x71,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xbd,0xd7,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x9c,0xd3,0xd6,0x9a,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0x7b,0xef,0x7b,0xcf,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x7b,0xcf,0x7b,0xcf,0xa5,0x34,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xad,0x75,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x8c,0x71,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xa5,0x34,0x7b,0xef,0x7b,0xef,0x8c,0x71,0xc6,0x38,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0x9c,0xd3,0x9c,0xd3,0x94,0xb2,0x94,0xb2,0x94,0x92,0x94,0xb2,0x94,0xb2,0x94,0xb2,0x9c,0xd3,0xb5,0xb6,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xb5,0x96,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x94,0x92,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x79,0xd6,0x9a,0xce,0x59,0xc6,0x38,0xd6,0x9a,0xce,0x59,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0x9c,0xd3,0x73,0xae,0x73,0x8e,0x73,0x8e,0x6b,0x6d,0x6b,0x6d,0x6b,0x6d,0x73,0x8e,0x73,0xae,0x7b,0xcf,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xce,0x79,0xc6,0x18,0x94,0x92,0x7b,0xef,0x7b,0xcf,0x7b,0xcf,0x73,0xae,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x7b,0xef,0x7b,0xcf,0xce,0x79,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xce,0x79,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0x9c,0xd3,0x73,0xae,0x73,0x8e,0x73,0xae,0x7b,0xcf,0x7b,0xcf,0x7b,0xcf,0x73,0x8e,0x73,0xae,0x7b,0xcf,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xa5,0x14,0x7b,0xcf,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x7b,0xef,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xce,0x79,0x8c,0x71,0x73,0xae,0x73,0xae,0x73,0x8e,0x73,0x8e,0x73,0x8e,0x73,0xae,0x7b,0xef,0xbd,0xd7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xde,0xdb,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xce,0x59,0x8c,0x51,0x73,0xae,0x73,0xae,0x73,0xae,0x73,0xae,0x7b,0xef,0xbd,0xd7,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba
,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0x9a,0xd6,0x9a,0xce,0x59,0x9c,0xf3,0x9c,0xd3,0x9c,0xd3,0x9c,0xf3,0xbd,0xd7,0xd6,0x9a,0xd6,0x9a,0xd6,0x9a,0xd6,0xba,0xd6,0xba,0xd6,0xba,0xd6,0xba};

unsigned char STANDARD_CONTRAST_A_DEFAULT             =0x15;
unsigned char STANDARD_CONTRAST_B_DEFAULT             =0x1A;
unsigned char STANDARD_CONTRAST_C_DEFAULT             =0x17;
unsigned char STANDARD_MASTER_CURRENT_DEFAULT         =0x0F;
unsigned char STANDARD_COLOR_DEPTH_DEFAULT            =0x70;
unsigned char STANDARD_DISPLAY_START_LINE_DEFAULT     =0x00;
unsigned char STANDARD_DISPLAY_OFFSET_DEFAULT         =0x10;
unsigned char STANDARD_MULTIPLEX_RATIO_DEFAULT        =0x2F;
unsigned char STANDARD_DIM_MODE_DEFAULT_1             =0x00;
unsigned char STANDARD_DIM_MODE_DEFAULT_2             =0x12;
unsigned char STANDARD_DIM_MODE_DEFAULT_3             =0x0C;
unsigned char STANDARD_DIM_MODE_DEFAULT_4             =0x14;
unsigned char STANDARD_DIM_MODE_DEFAULT_5             =0x12;
unsigned char STANDARD_MASTER_CONFIGURATION_DEFAULT   =0x8E;
unsigned char STANDARD_POWER_SAVE_MODE_DEFAULT        =0x0B;
unsigned char STANDARD_PHASE_PERIOD_DEFAULT           =0x44;
unsigned char STANDARD_DISPLAY_CLOCK_DIVIDER_DEFAULT  =0xA0;
unsigned char STANDARD_PRECHARGE_LEVEL_DEFAULT        =0xB9;
unsigned char STANDARD_VCOMH_DEFAULT                  =0x3E;
unsigned char STANDARD_WINDOW_COLUMN_DEFAULT_1        =0x10;
unsigned char STANDARD_WINDOW_COLUMN_DEFAULT_2        =0x4F;
unsigned char STANDARD_WINDOW_ROW_DEFAULT_1           =0x00;
unsigned char STANDARD_WINDOW_ROW_DEFAULT_2           =0x2F;
byte SWITCH_WINDOW_COLUMN            =0x15;
byte SWITCH_DRAW_LINE                =0x21;
byte SWITCH_WINDOW_ROW               =0x75;
byte SWITCH_CONTRAST_COLOR_A         =0x81;
byte SWITCH_CONTRAST_COLOR_B         =0x82;
byte SWITCH_CONTRAST_COLOR_C         =0x83;
byte SWITCH_MASTER_CURRENT_CONTROL   =0x87;
byte SWITCH_COLOR_A_PRECHARGE_SPEED  =0x8A;
byte SWITCH_COLOR_B_PRECHARGE_SPEED  =0x8B;
byte SWITCH_COLOR_C_PRECHARGE_SPEED  =0x8C;    
byte SWITCH_COLOR_DEPTH              =0xA0;
byte SWITCH_DISPLAY_START_LINE       =0xA1;
byte SWITCH_DISPLAY_OFFSET           =0xA2;
byte SWITCH_DISPLAY_NORMAL           =0xA4;
byte SWITCH_MULTIPLEX_RATIO          =0xA8;
byte SWITCH_COLOR_DIM_MODE           =0xAB;
byte SWITCH_MASTER_CONFIGURATION     =0xAD;
byte SWITCH_POWER_SAVE_MODE          =0xB0;
byte SWITCH_PHASE_1_2_PERIOD_ADJUST  =0xB1;
byte SWITCH_DISPLAY_CLOCK_DIVIDER    =0xB3;
byte SWITCH_ENABLE_LINEAR_GRAYSCALE  =0xB9;
byte SWITCH_PRECHARGE_LEVEL          =0xBB;
byte SWITCH_SET_VCOMH                =0xBE;
byte SWITCH_DISPLAY_OFF              =0xAE;
byte SWITCH_DISPLAY_ON               =0xAF;
byte currentColor1 = 0b11111111;
byte currentColor2 = 0b11100000;
byte stage = 0;
bool hasReset = false;


SPIClass * spi = NULL;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SS, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(RST, OUTPUT);
  spi = new SPIClass(VSPI);
  spi->begin(SCK,25,SDA,SS);
  digitalWrite(RST,LOW);
  delay(1);
  digitalWrite(RST,HIGH);
  ConfigureStandardOledSwitch();
}

void loop() {
 /* byte currentRed = currentColor2 & 0b00011111;
  byte currentBlue = (currentColor1 & 0b11111000) >> 3;
  byte currentGreen = ((currentColor2 & 0b11100000) >> 3) | ((currentColor1 & 0b00000111)>>1);

  if (currentRed == 0b00011111 && currentBlue == 0b00011111) {
    stage = 1;
  }
  if (currentBlue == 0b00011111 && currentGreen == 0b00011111){
    stage = 2;
  }
  if (currentGreen == 0b00011111 && currentRed == 0b00011111) {
    stage = 0;
  }

  switch (stage) {
    case 0:
      currentRed--;
      currentGreen++;
      break;
    case 1:
      currentBlue--;
      currentRed++;
      break;
    case 2:
      currentGreen--;
      currentBlue++;
      break;
    default:
        currentColor1 = 0b11111111;
        currentColor2 = 0b11100000;
        stage = 0;
        hasReset = true;
      break;
  }

  if (!hasReset) {
    currentColor1 = (currentBlue << 3) | ((currentGreen & 0b00011100)>>2);
    currentColor2 = ((currentGreen&0b00000011)<<6)|currentRed;
  }
  hasReset = false;//*/
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 3072; i++) {
  spiCommand(0b00000000);
  spiCommand(0b00011111);
  }
  //delay(500);
  for (int i = 0; i <3072; i++) {
  spiCommand(0b11111000);
  spiCommand(0b00000000);
  }
  //delay(500);
  for (int i = 0; i <3072; i++) {
  spiCommand(0b00000111);
  spiCommand(0b11100000);
  }
  //delay(500);
  for (int i = 0; i <3072; i++) {
  spiCommand(0b11111111);
  spiCommand(0b11111111);
  }
  //delay(500);
  for (int i = 0; i <3072; i++) {
  spiCommand(image[2*i]);
  spiCommand(image[2*i+1]);
  }
  //delay(500);//*/
}

void spiCommand(byte transferData) { //if isData, use data, otherwise use command
  spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(SS, LOW);
  //for (int i = 0; i < (64*48*2); i++) {
    spi->transfer(transferData);  
  //}
  digitalWrite(SS, HIGH);
  spi->endTransaction();
}

void ConfigureStandardOledSwitch()
{
    unsigned char parameters[5] = {0};
    
    parameters[0] = STANDARD_CONTRAST_A_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_CONTRAST_COLOR_A, parameters, 1);
    
    parameters[0] = STANDARD_CONTRAST_B_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_CONTRAST_COLOR_B, parameters, 1);   
    
    parameters[0] = STANDARD_CONTRAST_C_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_CONTRAST_COLOR_C, parameters, 1); 
    
    parameters[0] = STANDARD_MASTER_CURRENT_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_MASTER_CURRENT_CONTROL, parameters, 1);  
    
    parameters[0] = STANDARD_COLOR_DEPTH_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_COLOR_DEPTH, parameters, 1);
    
    parameters[0] = STANDARD_DISPLAY_START_LINE_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_DISPLAY_START_LINE, parameters, 1);
    
    parameters[0] = STANDARD_DISPLAY_OFFSET_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_DISPLAY_OFFSET, parameters, 1);
    
    parameters[0] = 0x00;
    SendSwitchConfigurationCommand(SWITCH_DISPLAY_NORMAL, parameters, 0);
    
    parameters[0] = STANDARD_MULTIPLEX_RATIO_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_MULTIPLEX_RATIO, parameters, 1);
    
    parameters[0] = STANDARD_DIM_MODE_DEFAULT_1;
    parameters[1] = STANDARD_DIM_MODE_DEFAULT_2;
    parameters[2] = STANDARD_DIM_MODE_DEFAULT_3;
    parameters[3] = STANDARD_DIM_MODE_DEFAULT_4;
    parameters[4] = STANDARD_DIM_MODE_DEFAULT_5;
    SendSwitchConfigurationCommand(SWITCH_COLOR_DIM_MODE, parameters, 5);
    
    parameters[0] = STANDARD_MASTER_CONFIGURATION_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_MASTER_CONFIGURATION, parameters, 1);
    
    parameters[0] = STANDARD_POWER_SAVE_MODE_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_POWER_SAVE_MODE, parameters, 1);
    
    parameters[0] = STANDARD_PHASE_PERIOD_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_PHASE_1_2_PERIOD_ADJUST, parameters, 1);
    
    parameters[0] = STANDARD_DISPLAY_CLOCK_DIVIDER_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_DISPLAY_CLOCK_DIVIDER, parameters, 1);
    
    parameters[0] = 0x00;
    SendSwitchConfigurationCommand(SWITCH_ENABLE_LINEAR_GRAYSCALE, parameters, 0);
  
    parameters[0] = STANDARD_PRECHARGE_LEVEL_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_PRECHARGE_LEVEL, parameters, 1);
    
    parameters[0] = STANDARD_VCOMH_DEFAULT;
    SendSwitchConfigurationCommand(SWITCH_SET_VCOMH, parameters, 1);
    
    
    parameters[0] = 0x00;
    SendSwitchConfigurationCommand(SWITCH_DISPLAY_ON, parameters, 0);
    
    parameters[0] = STANDARD_WINDOW_COLUMN_DEFAULT_1;
    parameters[1] = STANDARD_WINDOW_COLUMN_DEFAULT_2;
    SendSwitchConfigurationCommand(SWITCH_WINDOW_COLUMN, parameters, 2);
   
    parameters[0] = STANDARD_WINDOW_ROW_DEFAULT_1;
    parameters[1] = STANDARD_WINDOW_ROW_DEFAULT_2;
    SendSwitchConfigurationCommand(SWITCH_WINDOW_ROW, parameters, 2);           
}

void SendSwitchConfigurationCommand(unsigned char command, unsigned char* parameters, unsigned char numberOfParameters)
{
    digitalWrite(DC, LOW);
   spiCommand(command);
    
    for (unsigned char i = 0; i < numberOfParameters; i++)
    {
       spiCommand(parameters[i]);
    }
    digitalWrite(DC, HIGH);
}
