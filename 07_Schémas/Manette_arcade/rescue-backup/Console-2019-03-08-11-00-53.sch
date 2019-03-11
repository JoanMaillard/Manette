EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino
LIBS:Manette_arcade
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "Console"
Date "2018-06-21"
Rev ""
Comp "CPNV"
Comment1 "PICOTTE Alexandre"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 7450 3300
NoConn ~ 7450 3400
NoConn ~ 7450 3500
NoConn ~ 7450 3600
NoConn ~ 7450 3700
NoConn ~ 7450 3800
NoConn ~ 7450 3900
NoConn ~ 7450 3000
NoConn ~ 7450 2900
NoConn ~ 7450 2700
NoConn ~ 7450 2600
NoConn ~ 4850 3900
NoConn ~ 4850 4000
NoConn ~ 4850 4100
NoConn ~ 4850 4200
NoConn ~ 4850 4300
NoConn ~ 4850 4400
NoConn ~ 4850 4600
NoConn ~ 4850 4700
NoConn ~ 4850 3700
NoConn ~ 4850 3600
NoConn ~ 4850 3500
NoConn ~ 4850 3400
NoConn ~ 4850 3300
NoConn ~ 4850 3200
NoConn ~ 4850 3100
NoConn ~ 4850 3000
NoConn ~ 4850 2900
NoConn ~ 4850 2800
NoConn ~ 6050 2150
Wire Wire Line
	6150 2150 6150 2050
Wire Wire Line
	6150 2050 4200 2050
Wire Wire Line
	4200 2050 4200 2700
Wire Wire Line
	4200 2700 4100 2700
Wire Wire Line
	6050 5150 6250 5150
Wire Wire Line
	4200 2900 4200 5250
Wire Wire Line
	4200 2900 4100 2900
Connection ~ 6150 5150
Wire Wire Line
	4200 5250 6150 5250
Wire Wire Line
	6150 5250 6150 5150
Wire Wire Line
	4100 3300 4450 3300
Wire Wire Line
	4450 3300 4450 2600
Wire Wire Line
	4450 2600 4850 2600
Wire Wire Line
	4100 3100 4550 3100
Wire Wire Line
	4550 3100 4550 2700
Wire Wire Line
	4550 2700 4850 2700
NoConn ~ 4100 3400
NoConn ~ 4100 3200
NoConn ~ 4100 3000
NoConn ~ 4100 2800
NoConn ~ 4100 2600
Text Notes 6250 2100 0    60   ~ 0
Alimentation et communication avec Raspberry Pi via port USB
$Comp
L PWR_FLAG #FLG3
U 1 1 5B290F5B
P 6150 2050
F 0 "#FLG3" H 6150 2125 50  0001 C CNN
F 1 "PWR_FLAG" H 6150 2200 50  0000 C CNN
F 2 "" H 6150 2050 50  0001 C CNN
F 3 "" H 6150 2050 50  0001 C CNN
	1    6150 2050
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG4
U 1 1 5B290FF8
P 6150 5250
F 0 "#FLG4" H 6150 5325 50  0001 C CNN
F 1 "PWR_FLAG" H 6150 5400 50  0000 C CNN
F 2 "" H 6150 5250 50  0001 C CNN
F 3 "" H 6150 5250 50  0001 C CNN
	1    6150 5250
	-1   0    0    1   
$EndComp
$Comp
L Arduino_Leonardo_Shield XA2
U 1 1 5B2BB244
P 6150 3650
F 0 "XA2" V 6250 3650 60  0000 C CNN
F 1 "Arduino_Leonardo_Shield" V 6050 3650 60  0000 C CNN
F 2 "" H 7950 7400 60  0001 C CNN
F 3 "" H 7950 7400 60  0001 C CNN
	1    6150 3650
	-1   0    0    -1  
$EndComp
Text Label 4850 2600 2    60   ~ 0
SDA
Text Label 4850 2700 2    60   ~ 0
SCL
NoConn ~ 6250 2150
Wire Notes Line
	6250 2150 6250 2100
Wire Notes Line
	6250 2100 9150 2100
$Comp
L DB9_Male J2
U 1 1 5B2BC2F0
P 3800 3100
F 0 "J2" H 3800 3650 50  0000 C CNN
F 1 "DB9_Male" H 3800 2525 50  0000 C CNN
F 2 "" H 3800 3100 50  0001 C CNN
F 3 "" H 3800 3100 50  0001 C CNN
	1    3800 3100
	-1   0    0    1   
$EndComp
$EndSCHEMATC
