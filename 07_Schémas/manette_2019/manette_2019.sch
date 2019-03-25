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
P 10400 2100
F 0 "SW3" H 10400 2385 50  0000 C CNN
F 1 "Button_X" H 10400 2294 50  0000 C CNN
F 2 "" H 10400 2300 50  0001 C CNN
F 3 "" H 10400 2300 50  0001 C CNN
	1    10400 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5C7D45CD
P 10400 2450
F 0 "SW4" H 10400 2735 50  0000 C CNN
F 1 "Button_Y" H 10400 2644 50  0000 C CNN
F 2 "" H 10400 2650 50  0001 C CNN
F 3 "" H 10400 2650 50  0001 C CNN
	1    10400 2450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 5C7D45ED
P 10400 2800
F 0 "SW5" H 10400 3085 50  0000 C CNN
F 1 "Button_START" H 10400 2994 50  0000 C CNN
F 2 "" H 10400 3000 50  0001 C CNN
F 3 "" H 10400 3000 50  0001 C CNN
	1    10400 2800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW6
U 1 1 5C7D4610
P 10400 3150
F 0 "SW6" H 10400 3435 50  0000 C CNN
F 1 "Button_SELECT" H 10400 3344 50  0000 C CNN
F 2 "" H 10400 3350 50  0001 C CNN
F 3 "" H 10400 3350 50  0001 C CNN
	1    10400 3150
	1    0    0    -1  
$EndComp
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS2
U 1 1 5C7D49EC
P 8050 2100
F 0 "JS2" H 7470 2203 60  0000 R CNN
F 1 "Joystick_RSF_2-Axis" H 7470 2097 60  0000 R CNN
F 2 "" H 7850 2100 60  0001 C CNN
F 3 "" H 7850 2100 60  0001 C CNN
	1    8050 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5C7D4ACF
P 8500 6000
F 0 "RV?" H 8430 6046 50  0000 R CNN
F 1 "R_POT" H 8430 5955 50  0000 R CNN
F 2 "" H 8500 6000 50  0001 C CNN
F 3 "~" H 8500 6000 50  0001 C CNN
	1    8500 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 5C7D4B89
P 9600 6000
F 0 "RV?" H 9530 6046 50  0000 R CNN
F 1 "R_POT" H 9530 5955 50  0000 R CNN
F 2 "" H 9600 6000 50  0001 C CNN
F 3 "~" H 9600 6000 50  0001 C CNN
	1    9600 6000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW11
U 1 1 5C7D4D3A
P 10400 5000
F 0 "SW11" H 10400 5285 50  0000 C CNN
F 1 "R_bumper" H 10400 5194 50  0000 C CNN
F 2 "" H 10400 5200 50  0001 C CNN
F 3 "" H 10400 5200 50  0001 C CNN
	1    10400 5000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW9
U 1 1 5C7D4D48
P 10400 4300
F 0 "SW9" H 10400 4585 50  0000 C CNN
F 1 "Button_LEFT" H 10400 4494 50  0000 C CNN
F 2 "" H 10400 4500 50  0001 C CNN
F 3 "" H 10400 4500 50  0001 C CNN
	1    10400 4300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW10
U 1 1 5C7D4D4F
P 10400 4650
F 0 "SW10" H 10400 4935 50  0000 C CNN
F 1 "Button_DOWN" H 10400 4844 50  0000 C CNN
F 2 "" H 10400 4850 50  0001 C CNN
F 3 "" H 10400 4850 50  0001 C CNN
	1    10400 4650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5C7D4F76
P 10400 1400
F 0 "SW1" H 10400 1685 50  0000 C CNN
F 1 "Button_A" H 10400 1594 50  0000 C CNN
F 2 "" H 10400 1600 50  0001 C CNN
F 3 "" H 10400 1600 50  0001 C CNN
	1    10400 1400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5C7D4F7D
P 10400 1750
F 0 "SW2" H 10400 2035 50  0000 C CNN
F 1 "Button_B" H 10400 1944 50  0000 C CNN
F 2 "" H 10400 1950 50  0001 C CNN
F 3 "" H 10400 1950 50  0001 C CNN
	1    10400 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:Speaker LS?
U 1 1 5C7D5866
P 5550 7250
F 0 "LS?" H 5500 6950 50  0000 L CNN
F 1 "Speaker" H 5400 6850 50  0000 L CNN
F 2 "" H 5550 7050 50  0001 C CNN
F 3 "~" H 5540 7200 50  0001 C CNN
	1    5550 7250
	1    0    0    -1  
$EndComp
Text GLabel 1350 7350 0    50   Input ~ 0
+5V
Text GLabel 1500 7050 0    50   Output ~ 0
MISO
Text GLabel 1500 6550 0    50   Input ~ 0
SCK
Text GLabel 1500 6450 0    50   Input ~ 0
MOSI
Text GLabel 900  6600 0    50   UnSpc ~ 0
LCD
Text GLabel 700  6300 0    50   UnSpc ~ 0
SD
Text GLabel 900  6950 0    50   UnSpc ~ 0
D/C
Text GLabel 1500 6750 0    50   Input ~ 0
RESET
$Comp
L power:GND #PWR?
U 1 1 5C7E33B4
P 1350 7550
F 0 "#PWR?" H 1350 7300 50  0001 C CNN
F 1 "GND" H 1355 7377 50  0000 C CNN
F 2 "" H 1350 7550 50  0001 C CNN
F 3 "" H 1350 7550 50  0001 C CNN
	1    1350 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 7550 1350 7450
Wire Wire Line
	1350 7450 1500 7450
Wire Wire Line
	1350 7350 1500 7350
$Comp
L Switch:SW_Push SW7
U 1 1 5C7E3FD7
P 10400 3500
F 0 "SW7" H 10400 3785 50  0000 C CNN
F 1 "Button_RIGHT" H 10400 3694 50  0000 C CNN
F 2 "" H 10400 3700 50  0001 C CNN
F 3 "" H 10400 3700 50  0001 C CNN
	1    10400 3500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW8
U 1 1 5C7E3FDE
P 10400 3900
F 0 "SW8" H 10400 4185 50  0000 C CNN
F 1 "Button_UP" H 10400 4094 50  0000 C CNN
F 2 "" H 10400 4100 50  0001 C CNN
F 3 "" H 10400 4100 50  0001 C CNN
	1    10400 3900
	1    0    0    -1  
$EndComp
$Comp
L MCP23017:MCP23017 U2
U 1 1 5C80D464
P 4900 3700
F 0 "U2" H 5000 3715 50  0000 C CNN
F 1 "MCP23017" H 5000 3624 50  0000 C CNN
F 2 "" H 5000 3650 50  0001 C CNN
F 3 "" H 5000 3650 50  0001 C CNN
	1    4900 3700
	1    0    0    -1  
$EndComp
Text GLabel 2700 7050 2    50   Input ~ 0
MISO
Text GLabel 2700 7200 2    50   Output ~ 0
SCK
Text GLabel 2700 6950 2    50   Output ~ 0
MOSI
Text GLabel 2700 6650 2    50   UnSpc ~ 0
LCD
Text GLabel 2700 6500 2    50   UnSpc ~ 0
SD
Text GLabel 2700 6750 2    50   UnSpc ~ 0
D/C
Text GLabel 2700 6850 2    50   Output ~ 0
RESET
Text GLabel 2550 5550 2    50   Output ~ 0
SDA
Text GLabel 2550 5650 2    50   Output ~ 0
SCL
Text GLabel 4450 5650 0    50   Input ~ 0
SCL
Text GLabel 4450 5800 0    50   Input ~ 0
SDA
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U1
U 1 1 5C8105C7
P 1950 4550
F 0 "U1" H 1309 4596 50  0000 R CNN
F 1 "ATmega328-PU" H 1309 4505 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 1950 4550 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 1950 4550 50  0001 C CNN
	1    1950 4550
	1    0    0    -1  
$EndComp
Text GLabel 8700 4600 2    50   Output ~ 0
Left_joystick_analog_x
Text GLabel 8700 4850 2    50   Output ~ 0
Left_joystick_analog_y
Text GLabel 8850 1950 2    50   Output ~ 0
Right_joystick_analog_x
Text GLabel 8850 2200 2    50   Output ~ 0
Right_joystick_analog_y
Text GLabel 8350 1350 1    50   Input ~ 0
Right_joystick_button
Text GLabel 8200 4000 1    50   Input ~ 0
Left_joystick_button
$Comp
L power:GND #PWR?
U 1 1 5C816B1D
P 1950 6050
F 0 "#PWR?" H 1950 5800 50  0001 C CNN
F 1 "GND" H 1955 5877 50  0000 C CNN
F 2 "" H 1950 6050 50  0001 C CNN
F 3 "" H 1950 6050 50  0001 C CNN
	1    1950 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C816DC7
P 4300 5350
F 0 "#PWR?" H 4300 5100 50  0001 C CNN
F 1 "GND" H 4305 5177 50  0000 C CNN
F 2 "" H 4300 5350 50  0001 C CNN
F 3 "" H 4300 5350 50  0001 C CNN
	1    4300 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5350 4450 5350
$Comp
L power:GND #PWR?
U 1 1 5C817E41
P 7450 5400
F 0 "#PWR?" H 7450 5150 50  0001 C CNN
F 1 "GND" H 7455 5227 50  0000 C CNN
F 2 "" H 7450 5400 50  0001 C CNN
F 3 "" H 7450 5400 50  0001 C CNN
	1    7450 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C818469
P 7600 2750
F 0 "#PWR?" H 7600 2500 50  0001 C CNN
F 1 "GND" H 7605 2577 50  0000 C CNN
F 2 "" H 7600 2750 50  0001 C CNN
F 3 "" H 7600 2750 50  0001 C CNN
	1    7600 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 2750 7600 2750
Connection ~ 7600 2750
$Comp
L power:GND #PWR?
U 1 1 5C8190CD
P 8000 5550
F 0 "#PWR?" H 8000 5300 50  0001 C CNN
F 1 "GND" H 8005 5377 50  0000 C CNN
F 2 "" H 8000 5550 50  0001 C CNN
F 3 "" H 8000 5550 50  0001 C CNN
	1    8000 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C819881
P 8150 2900
F 0 "#PWR?" H 8150 2650 50  0001 C CNN
F 1 "GND" H 8155 2727 50  0000 C CNN
F 2 "" H 8150 2900 50  0001 C CNN
F 3 "" H 8150 2900 50  0001 C CNN
	1    8150 2900
	1    0    0    -1  
$EndComp
Text GLabel 8500 5850 1    50   Input ~ 0
+5V
Text GLabel 9600 5850 1    50   Input ~ 0
+5V
$Comp
L power:GND #PWR?
U 1 1 5C81DB7C
P 8500 6150
F 0 "#PWR?" H 8500 5900 50  0001 C CNN
F 1 "GND" H 8505 5977 50  0000 C CNN
F 2 "" H 8500 6150 50  0001 C CNN
F 3 "" H 8500 6150 50  0001 C CNN
	1    8500 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C81DD4B
P 9600 6150
F 0 "#PWR?" H 9600 5900 50  0001 C CNN
F 1 "GND" H 9605 5977 50  0000 C CNN
F 2 "" H 9600 6150 50  0001 C CNN
F 3 "" H 9600 6150 50  0001 C CNN
	1    9600 6150
	1    0    0    -1  
$EndComp
Text GLabel 9750 6000 2    50   Output ~ 0
Right_trigger
Text GLabel 8650 6000 2    50   Output ~ 0
Left_trigger
Text GLabel 7600 1350 1    50   Input ~ 0
+5V
Text GLabel 7450 4000 1    50   Input ~ 0
+5V
Wire Wire Line
	7600 1350 7700 1350
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS1
U 1 1 5C7D4903
P 7900 4750
F 0 "JS1" H 7320 4853 60  0000 R CNN
F 1 "Joystick_RSF_2-Axis" H 7320 4747 60  0000 R CNN
F 2 "" H 7700 4750 60  0001 C CNN
F 3 "" H 7700 4750 60  0001 C CNN
	1    7900 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 5400 7450 5400
Connection ~ 7450 5400
Text GLabel 2550 4250 2    50   Input ~ 0
R_joystick_analog_x
Text GLabel 2550 4350 2    50   Input ~ 0
R_joystick_analog_y
Text GLabel 4450 4300 0    50   Output ~ 0
R_joystick_button
Text GLabel 2550 4450 2    50   Input ~ 0
L_joystick_analog_x
Text GLabel 2550 4550 2    50   Input ~ 0
L_joystick_analog_y
Text GLabel 4450 4450 0    50   Output ~ 0
L_joystick_button
Text GLabel 2550 4750 2    50   Input ~ 0
L_trigger
Text GLabel 2550 4650 2    50   Input ~ 0
R_trigger
$Comp
L Switch:SW_Push SW12
U 1 1 5C7D4D41
P 10400 5350
F 0 "SW12" H 10400 5635 50  0000 C CNN
F 1 "L_bumper" H 10400 5544 50  0000 C CNN
F 2 "" H 10400 5550 50  0001 C CNN
F 3 "" H 10400 5550 50  0001 C CNN
	1    10400 5350
	1    0    0    -1  
$EndComp
$Comp
L Transistor_Array:ULN2803A U3
U 1 1 5C82C60F
P 3850 6750
F 0 "U3" H 3850 7317 50  0000 C CNN
F 1 "ULN2803A" H 3850 7226 50  0000 C CNN
F 2 "" H 3900 6100 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2803a.pdf" H 3950 6550 50  0001 C CNN
	1    3850 6750
	1    0    0    -1  
$EndComp
$Comp
L Device:Resonator Y?
U 1 1 5C82CAB8
P 3250 3900
F 0 "Y?" V 3550 3850 50  0000 L CNN
F 1 "Resonator" V 3500 3700 50  0000 L CNN
F 2 "" H 3225 3900 50  0001 C CNN
F 3 "~" H 3225 3900 50  0001 C CNN
	1    3250 3900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C82D22E
P 3550 4000
F 0 "#PWR?" H 3550 3750 50  0001 C CNN
F 1 "GND" H 3555 3827 50  0000 C CNN
F 2 "" H 3550 4000 50  0001 C CNN
F 3 "" H 3550 4000 50  0001 C CNN
	1    3550 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 4000 3550 3900
Wire Wire Line
	3550 3900 3450 3900
$Comp
L Device:LED D?
U 1 1 5C83283C
P 5300 6550
F 0 "D?" H 5291 6766 50  0000 C CNN
F 1 "LED" H 5291 6675 50  0000 C CNN
F 2 "" H 5300 6550 50  0001 C CNN
F 3 "~" H 5300 6550 50  0001 C CNN
	1    5300 6550
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5C8328E9
P 4800 6550
F 0 "R?" H 4870 6596 50  0000 L CNN
F 1 "R" H 4870 6505 50  0000 L CNN
F 2 "" V 4730 6550 50  0001 C CNN
F 3 "~" H 4800 6550 50  0001 C CNN
	1    4800 6550
	0    -1   1    0   
$EndComp
$Comp
L Switch:SW_DPST_x2 SW14
U 1 1 5C83593E
P 1150 1050
F 0 "SW14" V 1200 1350 50  0000 C CNN
F 1 "Power On/Off" V 1100 1500 50  0000 C CNN
F 2 "" H 1150 1050 50  0001 C CNN
F 3 "" H 1150 1050 50  0001 C CNN
	1    1150 1050
	0    -1   -1   0   
$EndComp
Text GLabel 1900 1500 2    50   Input ~ 0
+5V
$Comp
L power:+5V #PWR?
U 1 1 5C8399A9
P 1150 850
F 0 "#PWR?" H 1150 700 50  0001 C CNN
F 1 "+5V" H 1165 1023 50  0000 C CNN
F 2 "" H 1150 850 50  0001 C CNN
F 3 "" H 1150 850 50  0001 C CNN
	1    1150 850 
	1    0    0    -1  
$EndComp
$Comp
L Manette_arcade:SW_Push SW13
U 1 1 5C83B5DB
P 10400 5700
F 0 "SW13" H 10400 5985 50  0000 C CNN
F 1 "Calib" H 10400 5894 50  0000 C CNN
F 2 "" H 10400 5900 50  0001 C CNN
F 3 "" H 10400 5900 50  0001 C CNN
	1    10400 5700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C866717
P 5800 6300
F 0 "#PWR?" H 5800 6150 50  0001 C CNN
F 1 "+5V" H 5815 6473 50  0000 C CNN
F 2 "" H 5800 6300 50  0001 C CNN
F 3 "" H 5800 6300 50  0001 C CNN
	1    5800 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 6550 5800 6300
$Comp
L power:GND #PWR?
U 1 1 5C8638D7
P 3850 7450
F 0 "#PWR?" H 3850 7200 50  0001 C CNN
F 1 "GND" H 3855 7277 50  0000 C CNN
F 2 "" H 3850 7450 50  0001 C CNN
F 3 "" H 3850 7450 50  0001 C CNN
	1    3850 7450
	1    0    0    -1  
$EndComp
Text GLabel 3450 6750 0    50   Input ~ 0
Buzzer
$Comp
L Device:R R?
U 1 1 5C865F77
P 4800 7250
F 0 "R?" H 4870 7296 50  0000 L CNN
F 1 "R" H 4870 7205 50  0000 L CNN
F 2 "" V 4730 7250 50  0001 C CNN
F 3 "~" H 4800 7250 50  0001 C CNN
	1    4800 7250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 5C86BA29
P 5300 6850
F 0 "D?" H 5291 7066 50  0000 C CNN
F 1 "LED" H 5291 6975 50  0000 C CNN
F 2 "" H 5300 6850 50  0001 C CNN
F 3 "~" H 5300 6850 50  0001 C CNN
	1    5300 6850
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5C86BA30
P 4800 6850
F 0 "R?" H 4870 6896 50  0000 L CNN
F 1 "R" H 4870 6805 50  0000 L CNN
F 2 "" V 4730 6850 50  0001 C CNN
F 3 "~" H 4800 6850 50  0001 C CNN
	1    4800 6850
	0    -1   1    0   
$EndComp
Wire Wire Line
	5150 6850 4950 6850
Wire Wire Line
	5150 6550 4950 6550
Wire Wire Line
	5800 6850 5800 6550
Connection ~ 5800 6550
Wire Wire Line
	4650 6550 4250 6550
Wire Wire Line
	4250 6650 4500 6650
Wire Wire Line
	4500 6650 4500 6850
Wire Wire Line
	4500 6850 4650 6850
Wire Wire Line
	4950 7250 5000 7250
Wire Wire Line
	4650 7250 4400 7250
Wire Wire Line
	4400 7250 4400 6750
Wire Wire Line
	4400 6750 4250 6750
Wire Wire Line
	5800 7750 5800 6850
Connection ~ 5800 6850
$Comp
L Device:D D?
U 1 1 5C878C9C
P 5000 7400
F 0 "D?" H 5000 7616 50  0000 C CNN
F 1 "D" H 5000 7525 50  0000 C CNN
F 2 "" H 5000 7400 50  0001 C CNN
F 3 "~" H 5000 7400 50  0001 C CNN
	1    5000 7400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5450 6850 5800 6850
Wire Wire Line
	5450 6550 5800 6550
Connection ~ 5000 7250
Wire Wire Line
	5000 7750 5000 7550
Wire Wire Line
	5000 7750 5200 7750
Wire Wire Line
	5200 7750 5200 7350
Wire Wire Line
	5200 7350 5350 7350
Connection ~ 5200 7750
Wire Wire Line
	5200 7750 5800 7750
Wire Wire Line
	5000 7250 5350 7250
Text GLabel 3450 6650 0    50   Input ~ 0
Power
Text GLabel 3450 6550 0    50   Input ~ 0
Connected
Text GLabel 2550 5450 2    50   Output ~ 0
Connected
Text GLabel 2550 5350 2    50   Output ~ 0
Power
Text GLabel 2550 5250 2    50   Output ~ 0
Buzzer
Text GLabel 4450 4600 0    50   Output ~ 0
Button_LEFT
Text GLabel 4450 4750 0    50   Output ~ 0
Button_UP
Text GLabel 4450 4900 0    50   Output ~ 0
Button_RIGHT
Text GLabel 4450 5050 0    50   Output ~ 0
Button_DOWN
Text GLabel 5550 4000 2    50   Output ~ 0
Button_A
Text GLabel 5550 4150 2    50   Output ~ 0
Button_B
Text GLabel 5550 4300 2    50   Output ~ 0
Button_Y
Text GLabel 5550 4450 2    50   Output ~ 0
Button_X
Text GLabel 5550 4900 2    50   Output ~ 0
Button_START
Text GLabel 5550 5050 2    50   Output ~ 0
Button_SELECT
Text GLabel 5550 4600 2    50   Output ~ 0
R_Bumper
Text GLabel 5550 4750 2    50   Output ~ 0
L_Bumper
Wire Wire Line
	3250 4050 3250 4150
Wire Wire Line
	3250 4150 2900 4150
Wire Wire Line
	2900 4150 2900 4050
Wire Wire Line
	2900 4050 2550 4050
Wire Wire Line
	3250 3750 3250 3700
Wire Wire Line
	3250 3700 2900 3700
Wire Wire Line
	2900 3700 2900 3950
Wire Wire Line
	2900 3950 2550 3950
$Comp
L Regulator_Switching:R-78E5.0-0.5 U?
U 1 1 5C9AC915
P 1600 1500
F 0 "U?" H 1600 1742 50  0000 C CNN
F 1 "R-78E5.0-0.5" H 1600 1651 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 1650 1250 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78Exx-0.5.pdf" H 1600 1500 50  0001 C CNN
	1    1600 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C9B9F3C
P 1600 1800
F 0 "#PWR?" H 1600 1550 50  0001 C CNN
F 1 "GND" H 1605 1627 50  0000 C CNN
F 2 "" H 1600 1800 50  0001 C CNN
F 3 "" H 1600 1800 50  0001 C CNN
	1    1600 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1500 1150 1500
Wire Wire Line
	1150 1500 1150 1250
$Comp
L power:GND #PWR?
U 1 1 5C9E80F4
P 10800 5800
F 0 "#PWR?" H 10800 5550 50  0001 C CNN
F 1 "GND" H 10805 5627 50  0000 C CNN
F 2 "" H 10800 5800 50  0001 C CNN
F 3 "" H 10800 5800 50  0001 C CNN
	1    10800 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 5800 10800 5700
Wire Wire Line
	10800 5700 10600 5700
Wire Wire Line
	10600 5350 10800 5350
Wire Wire Line
	10800 5350 10800 5700
Connection ~ 10800 5700
Wire Wire Line
	10600 5000 10800 5000
Wire Wire Line
	10800 5000 10800 5350
Connection ~ 10800 5350
Wire Wire Line
	10600 4650 10800 4650
Wire Wire Line
	10800 4650 10800 5000
Connection ~ 10800 5000
Wire Wire Line
	10600 4300 10800 4300
Wire Wire Line
	10800 4300 10800 4650
Connection ~ 10800 4650
Wire Wire Line
	10600 3900 10800 3900
Wire Wire Line
	10800 3900 10800 4300
Connection ~ 10800 4300
Wire Wire Line
	10600 3500 10800 3500
Wire Wire Line
	10800 3500 10800 3900
Connection ~ 10800 3900
Wire Wire Line
	10800 3500 10800 3150
Wire Wire Line
	10800 3150 10600 3150
Connection ~ 10800 3500
Wire Wire Line
	10800 3150 10800 2800
Wire Wire Line
	10800 2800 10600 2800
Connection ~ 10800 3150
Wire Wire Line
	10600 2450 10800 2450
Wire Wire Line
	10800 2450 10800 2800
Connection ~ 10800 2800
Wire Wire Line
	10600 2100 10800 2100
Wire Wire Line
	10800 2100 10800 2450
Connection ~ 10800 2450
Wire Wire Line
	10600 1750 10800 1750
Wire Wire Line
	10800 1750 10800 2100
Connection ~ 10800 2100
Wire Wire Line
	10600 1400 10800 1400
Wire Wire Line
	10800 1400 10800 1750
Connection ~ 10800 1750
Text GLabel 10200 1400 0    50   Input ~ 0
Button_A
Text GLabel 10200 1750 0    50   Input ~ 0
Button_B
Text GLabel 10200 2450 0    50   Input ~ 0
Button_Y
Text GLabel 10200 2100 0    50   Input ~ 0
Button_X
Text GLabel 10200 2800 0    50   Input ~ 0
Button_START
Text GLabel 10200 3150 0    50   Input ~ 0
Button_SELECT
Text GLabel 10200 5000 0    50   Input ~ 0
R_Bumper
Text GLabel 10200 5350 0    50   Input ~ 0
L_Bumper
Text GLabel 10200 4300 0    50   Input ~ 0
Button_LEFT
Text GLabel 10200 3900 0    50   Input ~ 0
Button_UP
Text GLabel 10200 3500 0    50   Input ~ 0
Button_RIGHT
Text GLabel 10200 4650 0    50   Input ~ 0
Button_DOWN
Wire Wire Line
	8150 2750 8150 2900
Wire Wire Line
	8000 5400 8000 5550
$Comp
L ESP32:ESP32 U?
U 1 1 5CA33ACA
P 4050 1400
F 0 "U?" H 4050 1875 50  0000 C CNN
F 1 "ESP32" H 4050 1784 50  0000 C CNN
F 2 "" H 3450 1350 50  0001 C CNN
F 3 "" H 3450 1350 50  0001 C CNN
	1    4050 1400
	1    0    0    -1  
$EndComp
Wire Notes Line
	6950 6550 6300 6550
Wire Notes Line
	6300 6550 6300 500 
Text Label 6500 900  0    197  ~ 0
Inputs
$Comp
L Adafruit_OLED_RGB_Screen:OLED_Display U?
U 1 1 5CA3C6B3
P 1800 7000
F 0 "U?" H 2028 7076 50  0000 L CNN
F 1 "OLED_Display" H 2028 6985 50  0000 L CNN
F 2 "" H 1800 7000 50  0001 C CNN
F 3 "" H 1800 7000 50  0001 C CNN
	1    1800 7000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
