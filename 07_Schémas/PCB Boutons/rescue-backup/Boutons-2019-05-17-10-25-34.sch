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
LIBS:Manette_arcade
LIBS:Boutons-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Polymanette boutons"
Date "2018-06-12"
Rev ""
Comp "CPNV"
Comment1 "PICOTTE Alexandre"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Conn_01x06_Male J1
U 1 1 5B1F9A71
P 4800 3500
F 0 "J1" H 4800 3800 50  0000 C CNN
F 1 "Conn_01x06_Male" V 4700 3400 50  0000 C CNN
F 2 "Manette_2018:Conn_Grove_6_pôles" H 4800 3500 50  0001 C CNN
F 3 "" H 4800 3500 50  0001 C CNN
	1    4800 3500
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW4
U 1 1 5B1F9AF0
P 5600 4000
F 0 "SW4" H 5650 4100 50  0000 L CNN
F 1 "SW_Push" H 5600 3940 50  0000 C CNN
F 2 "Manette_2018:Switch_D6R" H 5600 4200 50  0001 C CNN
F 3 "" H 5600 4200 50  0001 C CNN
	1    5600 4000
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5B1F9B0D
P 5600 3500
F 0 "SW2" H 5650 3600 50  0000 L CNN
F 1 "SW_Push" H 5600 3440 50  0000 C CNN
F 2 "Manette_2018:Switch_D6R" H 5600 3700 50  0001 C CNN
F 3 "" H 5600 3700 50  0001 C CNN
	1    5600 3500
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW1
U 1 1 5B1F9B33
P 5600 3250
F 0 "SW1" H 5650 3350 50  0000 L CNN
F 1 "SW_Push" H 5600 3190 50  0000 C CNN
F 2 "Manette_2018:Switch_D6R" H 5600 3450 50  0001 C CNN
F 3 "" H 5600 3450 50  0001 C CNN
	1    5600 3250
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5B1F9B5B
P 5600 3750
F 0 "SW3" H 5650 3850 50  0000 L CNN
F 1 "SW_Push" H 5600 3690 50  0000 C CNN
F 2 "Manette_2018:Switch_D6R" H 5600 3950 50  0001 C CNN
F 3 "" H 5600 3950 50  0001 C CNN
	1    5600 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3800 5200 4000
Wire Wire Line
	5400 3750 5400 3600
Wire Wire Line
	5400 3600 5000 3600
Wire Wire Line
	5000 3500 5400 3500
Wire Wire Line
	5150 3250 5150 3400
Wire Wire Line
	5150 3400 5000 3400
Wire Wire Line
	5200 4000 5400 4000
Wire Wire Line
	5150 3250 5400 3250
Wire Wire Line
	5000 3300 5000 3100
Wire Wire Line
	5000 3100 5950 3100
Wire Wire Line
	5950 3100 5950 4000
Wire Wire Line
	5950 4000 5800 4000
Wire Wire Line
	5800 3750 5950 3750
Connection ~ 5950 3750
Wire Wire Line
	5800 3500 5950 3500
Connection ~ 5950 3500
Wire Wire Line
	5800 3250 5950 3250
Connection ~ 5950 3250
Text Label 5350 3100 0    60   ~ 0
GND
Text Notes 4550 2800 0    60   ~ 0
Connecteur Grove
Wire Notes Line
	4900 2850 4900 3150
Wire Notes Line
	4900 3850 4900 4200
Wire Wire Line
	5200 3800 5000 3800
NoConn ~ 5000 3700
$Comp
L Conn_01x01 J2
U 1 1 5B350F51
P 5950 2900
F 0 "J2" H 5950 3000 50  0000 C CNN
F 1 "Conn_01x01" H 5950 2800 50  0000 C CNN
F 2 "Polymanette_2018:Pad" H 5950 2900 50  0001 C CNN
F 3 "" H 5950 2900 50  0001 C CNN
	1    5950 2900
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
