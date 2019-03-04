EESchema Schematic File Version 2
LIBS:adc-dac
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:cmos4000
LIBS:conn
LIBS:device
LIBS:dsp
LIBS:linear
LIBS:memory
LIBS:microcontrollers
LIBS:motors
LIBS:power
LIBS:relays
LIBS:regul
LIBS:switches
LIBS:transistors
LIBS:74xx
LIBS:xilinx
LIBS:microchip
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:contrib
LIBS:valves
LIBS:arduino
LIBS:Manette_Chevaliers-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Polymanette table à lévitation CORRIGÉ"
Date "2018-06-28"
Rev ""
Comp "CPNV"
Comment1 "PICOTTE Alexandre"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR01
U 1 1 5B03E849
P 1450 2350
F 0 "#PWR01" H 1450 2100 50  0001 C CNN
F 1 "GND" H 1450 2200 50  0000 C CNN
F 2 "" H 1450 2350 50  0001 C CNN
F 3 "" H 1450 2350 50  0001 C CNN
	1    1450 2350
	0    1    -1   0   
$EndComp
$Comp
L LED D1
U 1 1 5B0FD566
P 9000 6250
F 0 "D1" H 9000 6350 50  0000 C CNN
F 1 "LED" H 9100 6150 50  0000 C CNN
F 2 "Polymanette_2018:LED_D3.0mm" H 9000 6250 50  0001 C CNN
F 3 "" H 9000 6250 50  0001 C CNN
	1    9000 6250
	1    0    0    1   
$EndComp
Text GLabel 1000 3650 1    60   Input ~ 0
+5V
Text GLabel 2200 4400 2    60   Output ~ 0
Analog.readX
Text GLabel 7250 2550 2    60   Input ~ 0
Analog.readX
Text GLabel 2200 4650 2    60   Output ~ 0
Analog.readY
Text GLabel 7900 2650 2    60   Input ~ 0
Analog.readY
NoConn ~ 7250 4450
NoConn ~ 7250 4150
NoConn ~ 7250 4050
NoConn ~ 7250 3950
NoConn ~ 7250 3850
NoConn ~ 7250 3750
NoConn ~ 7250 3650
NoConn ~ 7250 3550
NoConn ~ 7250 3450
NoConn ~ 7250 3350
NoConn ~ 7250 3050
NoConn ~ 7250 2950
NoConn ~ 7250 2850
NoConn ~ 7250 1950
NoConn ~ 7250 1850
NoConn ~ 7250 1750
NoConn ~ 7250 1650
NoConn ~ 7250 1550
NoConn ~ 7250 1450
NoConn ~ 7250 1350
NoConn ~ 7250 1250
NoConn ~ 4650 3850
NoConn ~ 4650 4050
NoConn ~ 4650 4250
NoConn ~ 4650 4450
NoConn ~ 4650 5050
NoConn ~ 4650 5550
$Comp
L Screw_Terminal_01x02 J5
U 1 1 5B111BD1
P 8800 900
F 0 "J5" H 8800 1000 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 8800 650 50  0000 C CNN
F 2 "Polymanette_2018:TerminalBlock_bornier-2_P5.08mm" H 8800 900 50  0001 C CNN
F 3 "" H 8800 900 50  0001 C CNN
	1    8800 900 
	1    0    0    1   
$EndComp
Text Label 8600 800  2    60   ~ 0
9.6VDC
$Comp
L GND #PWR02
U 1 1 5B1152B9
P 5850 6000
F 0 "#PWR02" H 5850 5750 50  0001 C CNN
F 1 "GND" H 5850 5850 50  0000 C CNN
F 2 "" H 5850 6000 50  0001 C CNN
F 3 "" H 5850 6000 50  0001 C CNN
	1    5850 6000
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5B115417
P 1000 5250
F 0 "#PWR03" H 1000 5000 50  0001 C CNN
F 1 "GND" H 1000 5100 50  0000 C CNN
F 2 "" H 1000 5250 50  0001 C CNN
F 3 "" H 1000 5250 50  0001 C CNN
	1    1000 5250
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Mega2560_Shield XA1
U 1 1 5B11F8C8
P 5950 3400
F 0 "XA1" V 6050 3400 60  0000 C CNN
F 1 "Arduino_Mega2560_Shield" V 5850 3400 60  0000 C CNN
F 2 "Polymanette_2018:Arduino_Mega2560_Shield" H 6650 6150 60  0001 C CNN
F 3 "" H 6650 6150 60  0001 C CNN
	1    5950 3400
	-1   0    0    -1  
$EndComp
$Comp
L Joystick_RSF_2-Axis JS1
U 1 1 5B11FA7D
P 1400 4550
F 0 "JS1" H 1250 4600 60  0000 C CNN
F 1 "Joystick_RSF_2-Axis" V 800 4550 60  0000 C CNN
F 2 "Polymanette_2018:Joystick_RSF_2-axis" H 1200 4550 60  0001 C CNN
F 3 "" H 1200 4550 60  0001 C CNN
	1    1400 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5B123253
P 1300 7250
F 0 "#PWR04" H 1300 7000 50  0001 C CNN
F 1 "GND" H 1300 7100 50  0000 C CNN
F 2 "" H 1300 7250 50  0001 C CNN
F 3 "" H 1300 7250 50  0001 C CNN
	1    1300 7250
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 5B1239FF
P 1300 7250
F 0 "#FLG05" H 1300 7325 50  0001 C CNN
F 1 "PWR_FLAG" H 1300 7400 50  0000 C CNN
F 2 "" H 1300 7250 50  0001 C CNN
F 3 "" H 1300 7250 50  0001 C CNN
	1    1300 7250
	1    0    0    -1  
$EndComp
NoConn ~ 7250 2750
$Comp
L ULN2803A U1
U 1 1 5B126248
P 4100 6550
F 0 "U1" H 4100 7075 50  0000 C CNN
F 1 "ULN2803A" H 4100 7000 50  0000 C CNN
F 2 "Polymanette_2018:ULN2803a" H 4150 5900 50  0001 L CNN
F 3 "" H 4200 6450 50  0001 C CNN
	1    4100 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5B128263
P 4100 7250
F 0 "#PWR06" H 4100 7000 50  0001 C CNN
F 1 "GND" H 4100 7100 50  0000 C CNN
F 2 "" H 4100 7250 50  0001 C CNN
F 3 "" H 4100 7250 50  0001 C CNN
	1    4100 7250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5B1128C7
P 8600 900
F 0 "#PWR07" H 8600 650 50  0001 C CNN
F 1 "GND" H 8600 750 50  0000 C CNN
F 2 "" H 8600 900 50  0001 C CNN
F 3 "" H 8600 900 50  0001 C CNN
	1    8600 900 
	0    1    -1   0   
$EndComp
NoConn ~ 4650 2250
Text GLabel 5950 750  1    60   Output ~ 0
+5V
$Comp
L R R1
U 1 1 5B136B9C
P 9300 6250
F 0 "R1" V 9380 6250 50  0000 C CNN
F 1 "330" V 9300 6250 50  0000 C CNN
F 2 "Polymanette_2018:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9230 6250 50  0001 C CNN
F 3 "" H 9300 6250 50  0001 C CNN
	1    9300 6250
	0    -1   -1   0   
$EndComp
Text Notes 1550 1750 0    60   ~ 0
Boutons\nJoystick
$Comp
L Screw_Terminal_01x04 J3
U 1 1 5B164479
P 7750 2250
F 0 "J3" H 7750 2450 50  0000 C CNN
F 1 "Screw_Terminal_01x04" V 7850 2050 50  0000 C CNN
F 2 "Polymanette_2018:Screw_terminal_2x2_P2.54mm" H 7750 2250 50  0001 C CNN
F 3 "" H 7750 2250 50  0001 C CNN
	1    7750 2250
	1    0    0    1   
$EndComp
Text GLabel 9450 6250 2    60   Input ~ 0
+5V
$Comp
L SW_Push SW1
U 1 1 5B167D3E
P 1650 2350
F 0 "SW1" H 1700 2450 50  0000 L CNN
F 1 "SW_Push" H 1650 2290 50  0000 C CNN
F 2 "Polymanette_2018:Switch_AS11CH" H 1650 2550 50  0001 C CNN
F 3 "" H 1650 2550 50  0001 C CNN
	1    1650 2350
	-1   0    0    -1  
$EndComp
Text GLabel 6300 750  1    60   Output ~ 0
9.6V
$Comp
L C C2
U 1 1 5B156818
P 7600 950
F 0 "C2" H 7625 1050 50  0000 L CNN
F 1 "470µF" H 7625 850 50  0000 L CNN
F 2 "Polymanette_2018:CP_Radial_Couchée_D10.0mm_P5.00mm" H 7638 800 50  0001 C CNN
F 3 "" H 7600 950 50  0001 C CNN
	1    7600 950 
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5B156A41
P 7250 950
F 0 "C1" H 7275 1050 50  0000 L CNN
F 1 "100nF" H 7275 850 50  0000 L CNN
F 2 "Polymanette_2018:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 7288 800 50  0001 C CNN
F 3 "" H 7250 950 50  0001 C CNN
	1    7250 950 
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG08
U 1 1 5B15EA49
P 1700 7250
F 0 "#FLG08" H 1700 7325 50  0001 C CNN
F 1 "PWR_FLAG" H 1700 7400 50  0000 C CNN
F 2 "" H 1700 7250 50  0001 C CNN
F 3 "" H 1700 7250 50  0001 C CNN
	1    1700 7250
	1    0    0    -1  
$EndComp
Text GLabel 1700 7250 3    60   UnSpc ~ 0
Pwr
Text GLabel 6150 750  1    60   UnSpc ~ 0
Pwr
$Comp
L PWR_FLAG #FLG09
U 1 1 5B15F9DC
P 5700 550
F 0 "#FLG09" H 5700 625 50  0001 C CNN
F 1 "PWR_FLAG" V 5700 850 50  0000 C CNN
F 2 "" H 5700 550 50  0001 C CNN
F 3 "" H 5700 550 50  0001 C CNN
	1    5700 550 
	0    -1   -1   0   
$EndComp
Text Notes 1200 7550 0    60   ~ 0
BT = Bluetooth Shield de Seeedstudio
Text Label 4600 1250 2    60   ~ 0
BT_TX
Text Label 4600 1350 2    60   ~ 0
BT_RX
Text Label 5700 700  2    60   ~ 0
BT_5V1
Text Label 5700 800  2    60   ~ 0
BT_3V3
Text Label 7300 4350 0    60   ~ 0
BT_RESET
NoConn ~ 4650 1350
NoConn ~ 7250 4350
NoConn ~ 5750 800 
Text GLabel 4800 7050 3    60   Input ~ 0
9.6V
$Comp
L SW_SPST SW6
U 1 1 5B19442F
P 8000 800
F 0 "SW6" H 8000 925 50  0000 C CNN
F 1 "SW_SPST" H 8000 700 50  0000 C CNN
F 2 "Polymanette_2018:Switch_AS11CH" H 8000 800 50  0001 C CNN
F 3 "" H 8000 800 50  0001 C CNN
	1    8000 800 
	1    0    0    -1  
$EndComp
Text Label 6200 6050 0    60   ~ 0
BT_GND
Text Label 6200 6150 0    60   ~ 0
BT_GND
NoConn ~ 4650 3050
NoConn ~ 4650 3250
NoConn ~ 4650 3450
NoConn ~ 4650 3650
NoConn ~ 7250 3150
NoConn ~ 7250 3250
$Comp
L Screw_Terminal_01x03 J1
U 1 1 5B1A9D03
P 4350 1650
F 0 "J1" H 4350 1850 50  0000 C CNN
F 1 "Screw_Terminal_01x03" H 4850 1650 50  0000 C CNN
F 2 "Polymanette_2018:Screw_terminal_3_P2.54mm" H 4350 1650 50  0001 C CNN
F 3 "" H 4350 1650 50  0001 C CNN
	1    4350 1650
	-1   0    0    -1  
$EndComp
NoConn ~ 4650 2450
NoConn ~ 1500 3800
NoConn ~ 1500 5200
NoConn ~ 4650 4650
NoConn ~ 4650 4850
$Comp
L Screw_Terminal_01x05 J4
U 1 1 5B1EC5E6
P 1600 2750
F 0 "J4" H 1600 3050 50  0000 C CNN
F 1 "Screw_Terminal_01x05" H 1600 3150 50  0000 C CNN
F 2 "Polymanette_2018:Screw_terminal_2x3_P2.54mm" H 1600 2750 50  0001 C CNN
F 3 "" H 1600 2750 50  0001 C CNN
	1    1600 2750
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR010
U 1 1 5B1EC98C
P 1800 2950
F 0 "#PWR010" H 1800 2700 50  0001 C CNN
F 1 "GND" H 1800 2800 50  0000 C CNN
F 2 "" H 1800 2950 50  0001 C CNN
F 3 "" H 1800 2950 50  0001 C CNN
	1    1800 2950
	0    -1   1    0   
$EndComp
NoConn ~ 4650 2850
NoConn ~ 4650 2650
NoConn ~ 4650 3350
NoConn ~ 4650 3550
Wire Wire Line
	7900 2650 7250 2650
Wire Wire Line
	1000 3650 1000 3800
Connection ~ 1000 5200
Wire Wire Line
	950  5200 1050 5200
Connection ~ 1000 3800
Wire Wire Line
	950  3800 1050 3800
Wire Wire Line
	5100 6450 4500 6450
Wire Wire Line
	4500 6550 5100 6550
Wire Wire Line
	5100 6650 4500 6650
Wire Wire Line
	4500 6750 5100 6750
Wire Wire Line
	5100 6850 4500 6850
Wire Wire Line
	4500 6950 5100 6950
Wire Wire Line
	4500 6250 8850 6250
Wire Notes Line
	650  1800 2900 1800
Wire Wire Line
	5850 800  6050 800 
Wire Wire Line
	5950 800  5950 750 
Connection ~ 5950 800 
Wire Wire Line
	5750 6000 6150 6000
Connection ~ 5850 6000
Connection ~ 5950 6000
Connection ~ 6050 6000
Wire Wire Line
	6300 800  6300 750 
Connection ~ 6300 800 
Wire Wire Line
	5100 7050 5100 7150
Connection ~ 5100 7100
Wire Wire Line
	6150 750  6150 800 
Wire Wire Line
	5850 550  5850 800 
Wire Wire Line
	5850 550  5700 550 
Wire Notes Line
	650  5450 2900 5450
Wire Notes Line
	650  5450 650  1800
Wire Notes Line
	2900 5450 2900 1800
Connection ~ 5850 700 
Wire Wire Line
	5850 700  5700 700 
Wire Wire Line
	3400 1250 4650 1250
Wire Wire Line
	7250 4350 7300 4350
Wire Wire Line
	5750 800  5700 800 
Wire Wire Line
	4500 7050 5050 7050
Wire Wire Line
	5050 7050 5050 7100
Wire Wire Line
	5050 7100 5100 7100
Wire Wire Line
	6050 6000 6050 6050
Wire Wire Line
	6050 6050 6200 6050
Wire Wire Line
	5950 6000 5950 6150
Wire Wire Line
	5950 6150 6200 6150
Wire Wire Line
	3700 3750 4650 3750
Wire Wire Line
	3700 3750 3700 6250
Wire Wire Line
	3600 6350 3700 6350
Wire Wire Line
	3600 3950 3600 6350
Wire Wire Line
	3500 6450 3700 6450
Wire Wire Line
	3500 4150 3500 6450
Wire Wire Line
	3400 6550 3700 6550
Wire Wire Line
	3400 4350 3400 6550
Wire Wire Line
	3300 6650 3700 6650
Wire Wire Line
	3300 4550 3300 6650
Wire Wire Line
	3200 6750 3700 6750
Wire Wire Line
	3200 4750 3200 6750
Wire Wire Line
	3100 6850 3700 6850
Wire Wire Line
	3100 4950 3100 6850
Wire Wire Line
	3700 6950 3000 6950
Wire Wire Line
	3000 5150 4650 5150
Wire Wire Line
	7250 2350 7450 2350
Wire Wire Line
	7450 2350 7450 2250
Wire Wire Line
	7450 2250 7550 2250
Wire Wire Line
	7250 2250 7400 2250
Wire Wire Line
	7400 2250 7400 2300
Wire Wire Line
	7400 2300 7550 2300
Wire Wire Line
	7550 2300 7550 2350
Wire Wire Line
	7250 2050 7450 2050
Wire Wire Line
	7450 2050 7450 2150
Wire Wire Line
	7450 2150 7550 2150
Wire Wire Line
	7250 2150 7400 2150
Wire Wire Line
	7400 2150 7400 2100
Wire Wire Line
	7400 2100 7550 2100
Wire Wire Line
	7550 2100 7550 2050
Wire Wire Line
	4550 1550 4650 1550
Wire Wire Line
	4650 1650 4550 1650
Wire Wire Line
	4550 1750 4650 1750
Wire Wire Line
	1800 2550 4650 2550
Wire Wire Line
	1850 2350 4650 2350
Wire Wire Line
	1800 2650 4600 2650
Wire Wire Line
	4600 2650 4600 2750
Wire Wire Line
	4600 2750 4650 2750
Wire Wire Line
	1800 2750 4500 2750
Wire Wire Line
	4500 2750 4500 2950
Wire Wire Line
	4500 2950 4650 2950
Wire Wire Line
	1800 2850 4400 2850
Wire Wire Line
	4400 2850 4400 3150
Wire Wire Line
	4400 3150 4650 3150
Wire Wire Line
	4650 4950 3100 4950
Wire Wire Line
	4650 4750 3200 4750
Wire Wire Line
	4650 4550 3300 4550
Wire Wire Line
	4650 4350 3400 4350
Wire Wire Line
	4650 4150 3500 4150
Wire Wire Line
	4650 3950 3600 3950
Wire Wire Line
	3000 6950 3000 5150
Wire Wire Line
	3400 1250 3400 2150
Wire Wire Line
	3400 2150 4650 2150
Wire Wire Line
	4600 1350 4650 1350
Wire Wire Line
	1000 5250 1700 5250
Wire Wire Line
	1700 5250 1700 5200
Wire Wire Line
	1000 5250 1000 5200
Connection ~ 1000 5250
$Comp
L Conn_01x01 J7
U 1 1 5B1FDEB7
P 1700 3600
F 0 "J7" H 1700 3700 50  0000 C CNN
F 1 "Conn_01x01" V 1800 3600 50  0000 C CNN
F 2 "Polymanette_2018:Pad" H 1700 3600 50  0001 C CNN
F 3 "" H 1700 3600 50  0001 C CNN
	1    1700 3600
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5B1FF0B9
P 1850 3800
F 0 "R2" V 1930 3800 50  0000 C CNN
F 1 "4K7" V 1850 3800 50  0000 C CNN
F 2 "Polymanette_2018:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1780 3800 50  0001 C CNN
F 3 "" H 1850 3800 50  0001 C CNN
	1    1850 3800
	0    1    1    0   
$EndComp
Text GLabel 2000 3800 2    60   Input ~ 0
+5V
NoConn ~ 7250 4850
NoConn ~ 7250 4950
NoConn ~ 7250 5050
NoConn ~ 7250 5150
NoConn ~ 7250 5250
NoConn ~ 7250 5350
Text Notes 8850 6000 0    60   ~ 0
LED d'alimentation
NoConn ~ 4650 5250
NoConn ~ 4650 5350
NoConn ~ 4650 5450
NoConn ~ 4650 1450
NoConn ~ 4650 1850
NoConn ~ 4650 1950
NoConn ~ 4650 2050
$Comp
L Screw_Terminal_01x09 J2
U 1 1 5B23CAAA
P 5300 6750
F 0 "J2" H 5300 7250 50  0000 C CNN
F 1 "Screw_Terminal_01x09" V 5400 6750 50  0000 C CNN
F 2 "Polymanette_2018:Screw_terminal_3x3_P2.54mm" H 5300 6750 50  0001 C CNN
F 3 "" H 5300 6750 50  0001 C CNN
	1    5300 6750
	1    0    0    1   
$EndComp
Wire Wire Line
	5100 6350 4500 6350
$Comp
L Conn_01x01 J6
U 1 1 5B320F85
P 5550 6000
F 0 "J6" H 5550 6100 50  0000 C CNN
F 1 "Conn_01x01" V 5650 6000 50  0000 C CNN
F 2 "Polymanette_2018:Pad" H 5550 6000 50  0001 C CNN
F 3 "" H 5550 6000 50  0001 C CNN
	1    5550 6000
	-1   0    0    1   
$EndComp
Connection ~ 7600 800 
Connection ~ 7250 800 
$Comp
L GND #PWR011
U 1 1 5B350D85
P 7450 1100
F 0 "#PWR011" H 7450 850 50  0001 C CNN
F 1 "GND" H 7450 950 50  0000 C CNN
F 2 "" H 7450 1100 50  0001 C CNN
F 3 "" H 7450 1100 50  0001 C CNN
	1    7450 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1100 7600 1100
Connection ~ 7450 1100
Wire Wire Line
	6150 800  7800 800 
Wire Wire Line
	8200 800  8600 800 
$EndSCHEMATC
