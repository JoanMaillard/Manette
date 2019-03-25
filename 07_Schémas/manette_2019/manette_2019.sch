EESchema Schematic File Version 4
LIBS:manette_2019-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Manette 2019"
Date "2019-03-04"
Rev ""
Comp "CPNV"
Comment1 "Adel Kahrimanovic"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push SW3
U 1 1 5C7D4510
P 6200 2100
F 0 "SW3" H 6200 2385 50  0000 C CNN
F 1 "Button_X" H 6200 2294 50  0000 C CNN
F 2 "" H 6200 2300 50  0001 C CNN
F 3 "" H 6200 2300 50  0001 C CNN
	1    6200 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5C7D45CD
P 6200 2650
F 0 "SW4" H 6200 2935 50  0000 C CNN
F 1 "Button_Y" H 6200 2844 50  0000 C CNN
F 2 "" H 6200 2850 50  0001 C CNN
F 3 "" H 6200 2850 50  0001 C CNN
	1    6200 2650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 5C7D45ED
P 6200 3150
F 0 "SW5" H 6200 3435 50  0000 C CNN
F 1 "Button_START" H 6200 3344 50  0000 C CNN
F 2 "" H 6200 3350 50  0001 C CNN
F 3 "" H 6200 3350 50  0001 C CNN
	1    6200 3150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW6
U 1 1 5C7D4610
P 6200 3700
F 0 "SW6" H 6200 3985 50  0000 C CNN
F 1 "Button_SELECT" H 6200 3894 50  0000 C CNN
F 2 "" H 6200 3900 50  0001 C CNN
F 3 "" H 6200 3900 50  0001 C CNN
	1    6200 3700
	1    0    0    -1  
$EndComp
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS2
U 1 1 5C7D49EC
P 9100 3900
F 0 "JS2" H 8520 4003 60  0000 R CNN
F 1 "Joystick_RSF_2-Axis" H 8520 3897 60  0000 R CNN
F 2 "" H 8900 3900 60  0001 C CNN
F 3 "" H 8900 3900 60  0001 C CNN
	1    9100 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5C7D4ACF
P 8500 5400
F 0 "RV?" H 8430 5446 50  0000 R CNN
F 1 "R_POT" H 8430 5355 50  0000 R CNN
F 2 "" H 8500 5400 50  0001 C CNN
F 3 "~" H 8500 5400 50  0001 C CNN
	1    8500 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5C7D4B89
P 9600 5400
F 0 "RV?" H 9530 5446 50  0000 R CNN
F 1 "R_POT" H 9530 5355 50  0000 R CNN
F 2 "" H 9600 5400 50  0001 C CNN
F 3 "~" H 9600 5400 50  0001 C CNN
	1    9600 5400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW11
U 1 1 5C7D4D3A
P 6800 3150
F 0 "SW11" H 6800 3435 50  0000 C CNN
F 1 "R_bumper" H 6800 3344 50  0000 C CNN
F 2 "" H 6800 3350 50  0001 C CNN
F 3 "" H 6800 3350 50  0001 C CNN
	1    6800 3150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW9
U 1 1 5C7D4D48
P 6800 2100
F 0 "SW9" H 6800 2385 50  0000 C CNN
F 1 "Button_LEFT" H 6800 2294 50  0000 C CNN
F 2 "" H 6800 2300 50  0001 C CNN
F 3 "" H 6800 2300 50  0001 C CNN
	1    6800 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW10
U 1 1 5C7D4D4F
P 6800 2650
F 0 "SW10" H 6800 2935 50  0000 C CNN
F 1 "Button_DOWN" H 6800 2844 50  0000 C CNN
F 2 "" H 6800 2850 50  0001 C CNN
F 3 "" H 6800 2850 50  0001 C CNN
	1    6800 2650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5C7D4F76
P 6200 1000
F 0 "SW1" H 6200 1285 50  0000 C CNN
F 1 "Button_A" H 6200 1194 50  0000 C CNN
F 2 "" H 6200 1200 50  0001 C CNN
F 3 "" H 6200 1200 50  0001 C CNN
	1    6200 1000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5C7D4F7D
P 6200 1550
F 0 "SW2" H 6200 1835 50  0000 C CNN
F 1 "Button_B" H 6200 1744 50  0000 C CNN
F 2 "" H 6200 1750 50  0001 C CNN
F 3 "" H 6200 1750 50  0001 C CNN
	1    6200 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:Speaker LS?
U 1 1 5C7D5866
P 5600 6700
F 0 "LS?" H 5550 6400 50  0000 L CNN
F 1 "Speaker" H 5450 6300 50  0000 L CNN
F 2 "" H 5600 6500 50  0001 C CNN
F 3 "~" H 5590 6650 50  0001 C CNN
	1    5600 6700
	1    0    0    -1  
$EndComp
Text GLabel 1450 4350 0    50   Input ~ 0
+5V
Text GLabel 1200 4450 0    50   Output ~ 0
MISO
Text GLabel 1450 4550 0    50   Input ~ 0
SCK
Text GLabel 1200 4650 0    50   Input ~ 0
MOSI
Text GLabel 1400 4750 0    50   UnSpc ~ 0
LCD
Text GLabel 1150 4850 0    50   UnSpc ~ 0
SD
Text GLabel 1400 4950 0    50   UnSpc ~ 0
D/C
Text GLabel 1150 5050 0    50   Input ~ 0
RESET
Text GLabel 1400 5150 0    50   Input ~ 0
+5V
$Comp
L power:GND #PWR?
U 1 1 5C7E33B4
P 1450 5350
F 0 "#PWR?" H 1450 5100 50  0001 C CNN
F 1 "GND" H 1455 5177 50  0000 C CNN
F 2 "" H 1450 5350 50  0001 C CNN
F 3 "" H 1450 5350 50  0001 C CNN
	1    1450 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5350 1450 5250
Wire Wire Line
	1450 5250 1600 5250
Wire Wire Line
	1400 5150 1600 5150
Wire Wire Line
	1150 5050 1600 5050
Wire Wire Line
	1400 4950 1600 4950
Wire Wire Line
	1600 4850 1150 4850
Wire Wire Line
	1400 4750 1600 4750
Wire Wire Line
	1200 4650 1600 4650
Wire Wire Line
	1600 4550 1450 4550
Wire Wire Line
	1200 4450 1600 4450
Wire Wire Line
	1450 4350 1600 4350
$Comp
L Connector_Generic:Conn_01x10 J1
U 1 1 5C7E2DEA
P 1800 4750
F 0 "J1" H 1880 4742 50  0000 L CNN
F 1 "Conn_01x10" H 1880 4651 50  0000 L CNN
F 2 "" H 1800 4750 50  0001 C CNN
F 3 "~" H 1800 4750 50  0001 C CNN
	1    1800 4750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW7
U 1 1 5C7E3FD7
P 6800 1000
F 0 "SW7" H 6800 1285 50  0000 C CNN
F 1 "Button_RIGHT" H 6800 1194 50  0000 C CNN
F 2 "" H 6800 1200 50  0001 C CNN
F 3 "" H 6800 1200 50  0001 C CNN
	1    6800 1000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW8
U 1 1 5C7E3FDE
P 6800 1550
F 0 "SW8" H 6800 1835 50  0000 C CNN
F 1 "Button_UP" H 6800 1744 50  0000 C CNN
F 2 "" H 6800 1750 50  0001 C CNN
F 3 "" H 6800 1750 50  0001 C CNN
	1    6800 1550
	1    0    0    -1  
$EndComp
$Comp
L MCP23017:MCP23017 U2
U 1 1 5C80D464
P 4350 2850
F 0 "U2" H 4450 2865 50  0000 C CNN
F 1 "MCP23017" H 4450 2774 50  0000 C CNN
F 2 "" H 4450 2800 50  0001 C CNN
F 3 "" H 4450 2800 50  0001 C CNN
	1    4350 2850
	1    0    0    -1  
$EndComp
Text GLabel 2050 6050 2    50   Input ~ 0
MISO
Text GLabel 2050 6200 2    50   Output ~ 0
SCK
Text GLabel 2050 5950 2    50   Output ~ 0
MOSI
Text GLabel 2050 5650 2    50   UnSpc ~ 0
LCD
Text GLabel 2050 5500 2    50   UnSpc ~ 0
SD
Text GLabel 2050 5750 2    50   UnSpc ~ 0
D/C
Text GLabel 2050 5850 2    50   Output ~ 0
RESET
Text GLabel 2750 2550 2    50   Output ~ 0
SDA
Text GLabel 2750 2650 2    50   Output ~ 0
SCL
Text GLabel 3900 4800 0    50   Input ~ 0
SCL
Text GLabel 3900 4950 0    50   Input ~ 0
SDA
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U1
U 1 1 5C8105C7
P 2150 2450
F 0 "U1" H 1509 2496 50  0000 R CNN
F 1 "ATmega328-PU" H 1509 2405 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 2150 2450 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 2150 2450 50  0001 C CNN
	1    2150 2450
	1    0    0    -1  
$EndComp
Text GLabel 9900 1550 2    50   Output ~ 0
Left_joystick_analog_x
Text GLabel 9900 1800 2    50   Output ~ 0
Left_joystick_analog_y
Text GLabel 9900 3750 2    50   Output ~ 0
Right_joystick_analog_x
Text GLabel 9900 4000 2    50   Output ~ 0
Right_joystick_analog_y
Text GLabel 9300 4650 2    50   Output ~ 0
Right_joystick_button
Text GLabel 9300 2450 2    50   Output ~ 0
Left_joystick_button
$Comp
L power:GND #PWR?
U 1 1 5C816B1D
P 2150 3950
F 0 "#PWR?" H 2150 3700 50  0001 C CNN
F 1 "GND" H 2155 3777 50  0000 C CNN
F 2 "" H 2150 3950 50  0001 C CNN
F 3 "" H 2150 3950 50  0001 C CNN
	1    2150 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C816DC7
P 3750 4500
F 0 "#PWR?" H 3750 4250 50  0001 C CNN
F 1 "GND" H 3755 4327 50  0000 C CNN
F 2 "" H 3750 4500 50  0001 C CNN
F 3 "" H 3750 4500 50  0001 C CNN
	1    3750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4500 3900 4500
$Comp
L power:GND #PWR?
U 1 1 5C817E41
P 8650 2350
F 0 "#PWR?" H 8650 2100 50  0001 C CNN
F 1 "GND" H 8655 2177 50  0000 C CNN
F 2 "" H 8650 2350 50  0001 C CNN
F 3 "" H 8650 2350 50  0001 C CNN
	1    8650 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C818469
P 8650 4550
F 0 "#PWR?" H 8650 4300 50  0001 C CNN
F 1 "GND" H 8655 4377 50  0000 C CNN
F 2 "" H 8650 4550 50  0001 C CNN
F 3 "" H 8650 4550 50  0001 C CNN
	1    8650 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4550 8650 4550
Connection ~ 8650 4550
Wire Wire Line
	9200 2450 9300 2450
$Comp
L power:GND #PWR?
U 1 1 5C8190CD
P 9200 2500
F 0 "#PWR?" H 9200 2250 50  0001 C CNN
F 1 "GND" H 9205 2327 50  0000 C CNN
F 2 "" H 9200 2500 50  0001 C CNN
F 3 "" H 9200 2500 50  0001 C CNN
	1    9200 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 2500 9200 2450
Wire Wire Line
	9200 4650 9300 4650
$Comp
L power:GND #PWR?
U 1 1 5C819881
P 9200 4700
F 0 "#PWR?" H 9200 4450 50  0001 C CNN
F 1 "GND" H 9205 4527 50  0000 C CNN
F 2 "" H 9200 4700 50  0001 C CNN
F 3 "" H 9200 4700 50  0001 C CNN
	1    9200 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4700 9200 4650
Connection ~ 9200 4650
Text GLabel 8500 5250 1    50   Input ~ 0
+5V
Text GLabel 9600 5250 1    50   Input ~ 0
+5V
$Comp
L power:GND #PWR?
U 1 1 5C81DB7C
P 8500 5550
F 0 "#PWR?" H 8500 5300 50  0001 C CNN
F 1 "GND" H 8505 5377 50  0000 C CNN
F 2 "" H 8500 5550 50  0001 C CNN
F 3 "" H 8500 5550 50  0001 C CNN
	1    8500 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C81DD4B
P 9600 5550
F 0 "#PWR?" H 9600 5300 50  0001 C CNN
F 1 "GND" H 9605 5377 50  0000 C CNN
F 2 "" H 9600 5550 50  0001 C CNN
F 3 "" H 9600 5550 50  0001 C CNN
	1    9600 5550
	1    0    0    -1  
$EndComp
Text GLabel 9750 5400 2    50   Output ~ 0
Right_trigger
Text GLabel 8650 5400 2    50   Output ~ 0
Left_trigger
Text GLabel 8650 3150 1    50   Input ~ 0
+5V
Text GLabel 8650 950  1    50   Input ~ 0
+5V
Wire Wire Line
	8650 3150 8750 3150
Wire Wire Line
	9200 4550 9200 4650
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS1
U 1 1 5C7D4903
P 9100 1700
F 0 "JS1" H 8520 1803 60  0000 R CNN
F 1 "Joystick_RSF_2-Axis" H 8520 1697 60  0000 R CNN
F 2 "" H 8900 1700 60  0001 C CNN
F 3 "" H 8900 1700 60  0001 C CNN
	1    9100 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2350 8650 2350
Connection ~ 8650 2350
Wire Wire Line
	9200 2450 9200 2350
Connection ~ 9200 2450
Text GLabel 9400 950  1    50   Input ~ 0
+5V
Text GLabel 9400 3150 1    50   Input ~ 0
+5V
Text GLabel 4700 2100 2    50   Input ~ 0
R_joystick_analog_x
Text GLabel 4700 2250 2    50   Input ~ 0
R_joystick_analog_y
Text GLabel 3900 3450 0    50   Input ~ 0
R_joystick_button
Text GLabel 4700 2400 2    50   Input ~ 0
L_joystick_analog_x
Text GLabel 4700 2550 2    50   Input ~ 0
L_joystick_analog_y
Text GLabel 3900 3600 0    50   Input ~ 0
L_joystick_button
Text GLabel 4150 2550 2    50   Input ~ 0
L_trigger
Text GLabel 4150 2400 2    50   Input ~ 0
R_trigger
$Comp
L Switch:SW_Push SW12
U 1 1 5C7D4D41
P 6800 3700
F 0 "SW12" H 6800 3985 50  0000 C CNN
F 1 "L_bumper" H 6800 3894 50  0000 C CNN
F 2 "" H 6800 3900 50  0001 C CNN
F 3 "" H 6800 3900 50  0001 C CNN
	1    6800 3700
	1    0    0    -1  
$EndComp
$Comp
L Transistor_Array:ULN2803A U3
U 1 1 5C82C60F
P 3900 6200
F 0 "U3" H 3900 6767 50  0000 C CNN
F 1 "ULN2803A" H 3900 6676 50  0000 C CNN
F 2 "" H 3950 5550 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2803a.pdf" H 4000 6000 50  0001 C CNN
	1    3900 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:Resonator Y?
U 1 1 5C82CAB8
P 3200 1900
F 0 "Y?" V 3500 1850 50  0000 L CNN
F 1 "Resonator" V 3450 1700 50  0000 L CNN
F 2 "" H 3175 1900 50  0001 C CNN
F 3 "~" H 3175 1900 50  0001 C CNN
	1    3200 1900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C82D22E
P 3500 2000
F 0 "#PWR?" H 3500 1750 50  0001 C CNN
F 1 "GND" H 3505 1827 50  0000 C CNN
F 2 "" H 3500 2000 50  0001 C CNN
F 3 "" H 3500 2000 50  0001 C CNN
	1    3500 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2000 3500 1900
Wire Wire Line
	3500 1900 3400 1900
Wire Wire Line
	3200 2050 3200 2100
Wire Wire Line
	3200 2100 3050 2100
Wire Wire Line
	3050 2100 3050 1950
Wire Wire Line
	3200 1750 3200 1700
Wire Wire Line
	3200 1700 3050 1700
Wire Wire Line
	3050 1700 3050 1850
Wire Wire Line
	2750 1850 3050 1850
Wire Wire Line
	3050 1950 2750 1950
$Comp
L Device:LED D?
U 1 1 5C83283C
P 5350 6000
F 0 "D?" H 5341 6216 50  0000 C CNN
F 1 "LED" H 5341 6125 50  0000 C CNN
F 2 "" H 5350 6000 50  0001 C CNN
F 3 "~" H 5350 6000 50  0001 C CNN
	1    5350 6000
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5C8328E9
P 4850 6000
F 0 "R?" H 4920 6046 50  0000 L CNN
F 1 "R" H 4920 5955 50  0000 L CNN
F 2 "" V 4780 6000 50  0001 C CNN
F 3 "~" H 4850 6000 50  0001 C CNN
	1    4850 6000
	0    -1   1    0   
$EndComp
$Comp
L Switch:SW_DPST_x2 SW14
U 1 1 5C83593E
P 800 1500
F 0 "SW14" V 850 1250 50  0000 C CNN
F 1 "Power On/Off" V 750 1100 50  0000 C CNN
F 2 "" H 800 1500 50  0001 C CNN
F 3 "" H 800 1500 50  0001 C CNN
	1    800  1500
	0    -1   -1   0   
$EndComp
Text GLabel 800  1700 3    50   Input ~ 0
+5V
$Comp
L power:+5V #PWR?
U 1 1 5C8399A9
P 800 1300
F 0 "#PWR?" H 800 1150 50  0001 C CNN
F 1 "+5V" H 815 1473 50  0000 C CNN
F 2 "" H 800 1300 50  0001 C CNN
F 3 "" H 800 1300 50  0001 C CNN
	1    800  1300
	1    0    0    -1  
$EndComp
$Comp
L Manette_arcade:SW_Push SW13
U 1 1 5C83B5DB
P 6800 4350
F 0 "SW13" H 6800 4635 50  0000 C CNN
F 1 "Calib" H 6800 4544 50  0000 C CNN
F 2 "" H 6800 4550 50  0001 C CNN
F 3 "" H 6800 4550 50  0001 C CNN
	1    6800 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C866717
P 5850 5750
F 0 "#PWR?" H 5850 5600 50  0001 C CNN
F 1 "+5V" H 5865 5923 50  0000 C CNN
F 2 "" H 5850 5750 50  0001 C CNN
F 3 "" H 5850 5750 50  0001 C CNN
	1    5850 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 6000 5850 5750
$Comp
L power:GND #PWR?
U 1 1 5C8638D7
P 3900 6900
F 0 "#PWR?" H 3900 6650 50  0001 C CNN
F 1 "GND" H 3905 6727 50  0000 C CNN
F 2 "" H 3900 6900 50  0001 C CNN
F 3 "" H 3900 6900 50  0001 C CNN
	1    3900 6900
	1    0    0    -1  
$EndComp
Text GLabel 3500 6200 0    50   Input ~ 0
Buzzer
$Comp
L Device:R R?
U 1 1 5C865F77
P 4850 6700
F 0 "R?" H 4920 6746 50  0000 L CNN
F 1 "R" H 4920 6655 50  0000 L CNN
F 2 "" V 4780 6700 50  0001 C CNN
F 3 "~" H 4850 6700 50  0001 C CNN
	1    4850 6700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 5C86BA29
P 5350 6300
F 0 "D?" H 5341 6516 50  0000 C CNN
F 1 "LED" H 5341 6425 50  0000 C CNN
F 2 "" H 5350 6300 50  0001 C CNN
F 3 "~" H 5350 6300 50  0001 C CNN
	1    5350 6300
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5C86BA30
P 4850 6300
F 0 "R?" H 4920 6346 50  0000 L CNN
F 1 "R" H 4920 6255 50  0000 L CNN
F 2 "" V 4780 6300 50  0001 C CNN
F 3 "~" H 4850 6300 50  0001 C CNN
	1    4850 6300
	0    -1   1    0   
$EndComp
Wire Wire Line
	5200 6300 5000 6300
Wire Wire Line
	5200 6000 5000 6000
Wire Wire Line
	5850 6300 5850 6000
Connection ~ 5850 6000
Wire Wire Line
	4700 6000 4300 6000
Wire Wire Line
	4300 6100 4550 6100
Wire Wire Line
	4550 6100 4550 6300
Wire Wire Line
	4550 6300 4700 6300
Wire Wire Line
	5000 6700 5050 6700
Wire Wire Line
	4700 6700 4450 6700
Wire Wire Line
	4450 6700 4450 6200
Wire Wire Line
	4450 6200 4300 6200
Wire Wire Line
	5850 7200 5850 6300
Connection ~ 5850 6300
$Comp
L Device:D D?
U 1 1 5C878C9C
P 5050 6850
F 0 "D?" H 5050 7066 50  0000 C CNN
F 1 "D" H 5050 6975 50  0000 C CNN
F 2 "" H 5050 6850 50  0001 C CNN
F 3 "~" H 5050 6850 50  0001 C CNN
	1    5050 6850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5500 6300 5850 6300
Wire Wire Line
	5500 6000 5850 6000
Connection ~ 5050 6700
Wire Wire Line
	5050 7200 5050 7000
Wire Wire Line
	5050 7200 5250 7200
Wire Wire Line
	5250 7200 5250 6800
Wire Wire Line
	5250 6800 5400 6800
Connection ~ 5250 7200
Wire Wire Line
	5250 7200 5850 7200
Wire Wire Line
	5050 6700 5400 6700
Text GLabel 3500 6100 0    50   Input ~ 0
Power
Text GLabel 3500 6000 0    50   Input ~ 0
Connected
Text GLabel 2750 3350 2    50   Output ~ 0
Connected
Text GLabel 2750 3250 2    50   Output ~ 0
Power
Text GLabel 2750 3150 2    50   Output ~ 0
Buzzer
Text GLabel 3900 3750 0    50   Input ~ 0
Button_LEFT
Text GLabel 3900 3900 0    50   Input ~ 0
Button_UP
Text GLabel 3900 4050 0    50   Input ~ 0
Button_RIGHT
Text GLabel 3900 4200 0    50   Input ~ 0
Button_DOWN
Text GLabel 5000 3150 2    50   Input ~ 0
Button_A
Text GLabel 5000 3300 2    50   Input ~ 0
Button_B
Text GLabel 5000 3450 2    50   Input ~ 0
Button_Y
Text GLabel 5000 3600 2    50   Input ~ 0
Button_X
Text GLabel 5000 4050 2    50   Input ~ 0
Button_START
Text GLabel 5000 4200 2    50   Input ~ 0
Button_SELECT
Text GLabel 5000 3750 2    50   Input ~ 0
R_Bumper
Text GLabel 5000 3900 2    50   Input ~ 0
L_Bumper
$EndSCHEMATC
