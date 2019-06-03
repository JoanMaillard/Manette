EESchema Schematic File Version 4
LIBS:manette_2019-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Manette Universelle"
Date "2019-03-04"
Rev ""
Comp "CPNV"
Comment1 "Adel Kahrimanovic"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L manette_2019-rescue:Speaker-Device LS1
U 1 1 5C7D5866
P 10600 5500
F 0 "LS1" H 10800 5550 50  0000 L CNN
F 1 "Speaker" H 10800 5450 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_T135" H 10600 5300 50  0001 C CNN
F 3 "~" H 10590 5450 50  0001 C CNN
	1    10600 5500
	1    0    0    -1  
$EndComp
Text GLabel 9050 4325 0    50   Output ~ 0
MISO
Text GLabel 9050 3825 0    50   Input ~ 0
SCK
Text GLabel 9050 3725 0    50   Input ~ 0
MOSI
Text GLabel 9050 4025 0    50   Input ~ 0
RESET
$Comp
L manette_2019-rescue:MCP23017-MCP23017 U3
U 1 1 5C80D464
P 6550 575
F 0 "U3" H 6650 590 50  0000 C CNN
F 1 "MCP23017" H 6650 499 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6650 525 50  0001 C CNN
F 3 "" H 6650 525 50  0001 C CNN
	1    6550 575 
	1    0    0    -1  
$EndComp
Text GLabel 8550 1900 0    50   Input ~ 0
MISO
Text GLabel 8550 1800 0    50   Output ~ 0
SCK
Text GLabel 8550 2000 0    50   Output ~ 0
MOSI
Text GLabel 8550 1600 0    50   Output ~ 0
RESET
Text GLabel 6150 5375 2    50   Output ~ 0
SDA
Text GLabel 6150 5475 2    50   Output ~ 0
SCL
Text GLabel 6100 2525 0    50   Input ~ 0
SCL
Text GLabel 6100 2675 0    50   Input ~ 0
SDA
$Comp
L manette_2019-rescue:ATmega328-PU-MCU_Microchip_ATmega U2
U 1 1 5C8105C7
P 5550 4375
F 0 "U2" H 5150 5900 50  0000 R CNN
F 1 "ATmega328-PU" H 5450 6025 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5550 4375 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 5550 4375 50  0001 C CNN
	1    5550 4375
	1    0    0    -1  
$EndComp
Text GLabel 2100 6625 2    50   Output ~ 0
L_joystick_analog_x
Text GLabel 2100 6875 2    50   Output ~ 0
L_joystick_analog_y
Text GLabel 1950 4350 2    50   Output ~ 0
R_joystick_analog_x
Text GLabel 1950 4600 2    50   Output ~ 0
R_joystick_analog_y
Text GLabel 1450 3750 1    50   Output ~ 0
Right_joystick_button
Text GLabel 1600 6025 1    50   Output ~ 0
Left_joystick_button
Wire Wire Line
	700  3750 800  3750
$Comp
L manette_2019-rescue:Joystick_RSF_2-Axis-Manette_arcade JS1
U 1 1 5C7D4903
P 1300 6775
F 0 "JS1" H 2150 7200 60  0000 R CNN
F 1 "Joystick_Left" H 2550 7100 60  0000 R CNN
F 2 "Polymanette_2018:Joystick_RSF_2-axis" H 1100 6775 60  0001 C CNN
F 3 "" H 1100 6775 60  0001 C CNN
	1    1300 6775
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  7425 850  7425
Text GLabel 6150 4075 2    50   Input ~ 0
R_joystick_analog_x
Text GLabel 6150 4175 2    50   Input ~ 0
R_joystick_analog_y
Text GLabel 7200 1625 2    50   Input ~ 0
Right_joystick_button
Text GLabel 6150 4275 2    50   Input ~ 0
L_joystick_analog_y
Text GLabel 6150 4375 2    50   Input ~ 0
L_joystick_analog_x
Text GLabel 6100 1025 0    50   Input ~ 0
Left_joystick_button
Text GLabel 6150 4575 2    50   Input ~ 0
L_trigger
Text GLabel 6150 4475 2    50   Input ~ 0
R_trigger
$Comp
L manette_2019-rescue:ULN2803A-Transistor_Array U5
U 1 1 5C82C60F
P 9200 5450
F 0 "U5" H 9200 6017 50  0000 C CNN
F 1 "ULN2803A" H 9200 5926 50  0000 C CNN
F 2 "Package_DIP:DIP-18_W7.62mm" H 9250 4800 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2803a.pdf" H 9300 5250 50  0001 C CNN
	1    9200 5450
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Resonator-Device Y1
U 1 1 5C82CAB8
P 6850 3725
F 0 "Y1" V 7050 3575 50  0000 L CNN
F 1 "Resonator" V 7150 3425 50  0000 L CNN
F 2 "Crystal:Resonator-3Pin_W6.0mm_H3.0mm" H 6825 3725 50  0001 C CNN
F 3 "~" H 6825 3725 50  0001 C CNN
	1    6850 3725
	0    -1   -1   0   
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0110
U 1 1 5C82D22E
P 7150 3825
F 0 "#PWR0110" H 7150 3575 50  0001 C CNN
F 1 "GND" H 7155 3652 50  0000 C CNN
F 2 "" H 7150 3825 50  0001 C CNN
F 3 "" H 7150 3825 50  0001 C CNN
	1    7150 3825
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3825 7150 3725
Wire Wire Line
	7150 3725 7050 3725
$Comp
L manette_2019-rescue:GND-power #PWR0111
U 1 1 5C8638D7
P 9200 6150
F 0 "#PWR0111" H 9200 5900 50  0001 C CNN
F 1 "GND" H 9205 5977 50  0000 C CNN
F 2 "" H 9200 6150 50  0001 C CNN
F 3 "" H 9200 6150 50  0001 C CNN
	1    9200 6150
	1    0    0    -1  
$EndComp
Text GLabel 8800 5350 0    50   Input ~ 0
Buzzer
$Comp
L manette_2019-rescue:R-Device R3
U 1 1 5C865F77
P 9900 5500
F 0 "R3" V 9975 5450 50  0000 L CNN
F 1 "R" V 9900 5475 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9830 5500 50  0001 C CNN
F 3 "~" H 9900 5500 50  0001 C CNN
	1    9900 5500
	0    -1   -1   0   
$EndComp
$Comp
L manette_2019-rescue:D-Device D3
U 1 1 5C878C9C
P 10050 5650
F 0 "D3" H 10050 5850 50  0000 C CNN
F 1 "D" H 10050 5775 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P10.16mm_Horizontal" H 10050 5650 50  0001 C CNN
F 3 "~" H 10050 5650 50  0001 C CNN
	1    10050 5650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10250 5600 10400 5600
Wire Wire Line
	10050 5500 10400 5500
Text GLabel 8800 5450 0    50   Input ~ 0
Connected
Text GLabel 6100 1625 0    50   Input ~ 0
Button_LEFT
Text GLabel 6100 1175 0    50   Input ~ 0
Button_UP
Text GLabel 6100 1325 0    50   Input ~ 0
Button_RIGHT
Text GLabel 6100 1475 0    50   Input ~ 0
Button_DOWN
Text GLabel 7200 1175 2    50   Input ~ 0
Button_Y
Text GLabel 7200 1325 2    50   Input ~ 0
Button_X
Text GLabel 7200 1475 2    50   Input ~ 0
Button_A
Text GLabel 7200 1025 2    50   Input ~ 0
Button_B
Text GLabel 6100 1925 0    50   Input ~ 0
Button_SELECT
Text GLabel 6100 1775 0    50   Input ~ 0
Button_START
Text GLabel 7200 875  2    50   Input ~ 0
R_Bumper
Text GLabel 6100 875  0    50   Input ~ 0
L_Bumper
Wire Wire Line
	6850 3875 6850 3975
Wire Wire Line
	6850 3975 6500 3975
Wire Wire Line
	6500 3975 6500 3875
Wire Wire Line
	6500 3875 6150 3875
Wire Wire Line
	6850 3575 6850 3525
Wire Wire Line
	6850 3525 6500 3525
Wire Wire Line
	6500 3525 6500 3775
Wire Wire Line
	6500 3775 6150 3775
Text Label 1725 3150 0    197  ~ 0
Inputs
Text GLabel 9050 3925 0    50   Input ~ 0
DC
Text GLabel 8550 1700 0    50   Output ~ 0
DC
Text GLabel 9050 4125 0    50   Input ~ 0
OLEDCS
Text GLabel 8550 1500 0    50   Output ~ 0
OLEDCS
Text GLabel 5550 2875 1    50   Input ~ 0
+5V
Text GLabel 8550 1400 0    50   Input ~ 0
SDCS
Text GLabel 9050 4225 0    50   Input ~ 0
SDCS
Text Label 9925 4100 0    197  ~ 0
Outputs
Text GLabel 10750 1100 2    50   Input ~ 0
RX_ESP32
Text GLabel 10750 1000 2    50   Input ~ 0
TX_ESP32
Text GLabel 10600 2975 2    50   Input ~ 0
+3.3V
Text GLabel 7500 2375 2    50   Input ~ 0
+5V
Text GLabel 9700 2975 0    50   Input ~ 0
+5V
Text GLabel 10600 3075 2    50   Input ~ 0
RX_ESP32
Text GLabel 10600 3175 2    50   Input ~ 0
TX_ESP32
Text GLabel 9700 3075 0    50   Input ~ 0
TX_Atmega
Text GLabel 9700 3175 0    50   Input ~ 0
RX_Atmega
Text Label 1050 725  0    197  ~ 0
Power
Text Label 9150 2700 0    197  ~ 0
SerialComm
Text Label 4800 725  0    197  ~ 0
Command
Wire Wire Line
	950  6025 850  6025
Text GLabel 10750 1300 2    50   Output ~ 0
Buzzer
Text GLabel 10750 1200 2    50   Output ~ 0
Connected
Text GLabel 1325 1100 2    50   Output ~ 0
+5V
$Comp
L manette_2019-rescue:PWR_FLAG-power #FLG0102
U 1 1 5CA753AE
P 6525 6400
F 0 "#FLG0102" H 6525 6475 50  0001 C CNN
F 1 "PWR_FLAG" H 6525 6574 50  0000 C CNN
F 2 "" H 6525 6400 50  0001 C CNN
F 3 "~" H 6525 6400 50  0001 C CNN
	1    6525 6400
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:PWR_FLAG-power #FLG0103
U 1 1 5CA77741
P 6675 6400
F 0 "#FLG0103" H 6675 6475 50  0001 C CNN
F 1 "PWR_FLAG" H 6675 6574 50  0000 C CNN
F 2 "" H 6675 6400 50  0001 C CNN
F 3 "~" H 6675 6400 50  0001 C CNN
	1    6675 6400
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:PWR_FLAG-power #FLG0104
U 1 1 5CA79B65
P 6825 6400
F 0 "#FLG0104" H 6825 6475 50  0001 C CNN
F 1 "PWR_FLAG" H 6825 6574 50  0000 C CNN
F 2 "" H 6825 6400 50  0001 C CNN
F 3 "~" H 6825 6400 50  0001 C CNN
	1    6825 6400
	1    0    0    -1  
$EndComp
Text GLabel 6675 6400 3    50   Input ~ 0
+3.3V
Text GLabel 6525 6400 3    50   Input ~ 0
+5V
$Comp
L manette_2019-rescue:GND-power #PWR0102
U 1 1 5C816B1D
P 6825 6400
F 0 "#PWR0102" H 6825 6150 50  0001 C CNN
F 1 "GND" H 6830 6227 50  0000 C CNN
F 2 "" H 6825 6400 50  0001 C CNN
F 3 "" H 6825 6400 50  0001 C CNN
	1    6825 6400
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0116
U 1 1 5CB04B27
P 10725 3300
F 0 "#PWR0116" H 10725 3050 50  0001 C CNN
F 1 "GND" H 10730 3127 50  0000 C CNN
F 2 "" H 10725 3300 50  0001 C CNN
F 3 "" H 10725 3300 50  0001 C CNN
	1    10725 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 4525 9050 4525
Wire Wire Line
	8900 4625 8900 4525
$Comp
L manette_2019-rescue:GND-power #PWR0101
U 1 1 5C7E33B4
P 8900 4625
F 0 "#PWR0101" H 8900 4375 50  0001 C CNN
F 1 "GND" H 8905 4452 50  0000 C CNN
F 2 "" H 8900 4625 50  0001 C CNN
F 3 "" H 8900 4625 50  0001 C CNN
	1    8900 4625
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0113
U 1 1 5C9E80F4
P 3950 2625
F 0 "#PWR0113" H 3950 2375 50  0001 C CNN
F 1 "GND" H 3955 2452 50  0000 C CNN
F 2 "" H 3950 2625 50  0001 C CNN
F 3 "" H 3950 2625 50  0001 C CNN
	1    3950 2625
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0104
U 1 1 5C817E41
P 850 7525
F 0 "#PWR0104" H 850 7275 50  0001 C CNN
F 1 "GND" H 855 7352 50  0000 C CNN
F 2 "" H 850 7525 50  0001 C CNN
F 3 "" H 850 7525 50  0001 C CNN
	1    850  7525
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0105
U 1 1 5C818469
P 700 5225
F 0 "#PWR0105" H 700 4975 50  0001 C CNN
F 1 "GND" H 705 5052 50  0000 C CNN
F 2 "" H 700 5225 50  0001 C CNN
F 3 "" H 700 5225 50  0001 C CNN
	1    700  5225
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0103
U 1 1 5C816DC7
P 5875 2250
F 0 "#PWR0103" H 5875 2000 50  0001 C CNN
F 1 "GND" H 5880 2077 50  0000 C CNN
F 2 "" H 5875 2250 50  0001 C CNN
F 3 "" H 5875 2250 50  0001 C CNN
	1    5875 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2875 7350 2825
Wire Wire Line
	7350 2825 7350 2675
Connection ~ 7350 2825
Wire Wire Line
	7200 2825 7350 2825
Wire Wire Line
	7350 2675 7200 2675
Connection ~ 7350 2675
Wire Wire Line
	7350 2525 7350 2675
Wire Wire Line
	7200 2525 7350 2525
$Comp
L manette_2019-rescue:GND-power #PWR0115
U 1 1 5CABEA89
P 7350 2875
F 0 "#PWR0115" H 7350 2625 50  0001 C CNN
F 1 "GND" H 7355 2702 50  0000 C CNN
F 2 "" H 7350 2875 50  0001 C CNN
F 3 "" H 7350 2875 50  0001 C CNN
	1    7350 2875
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0118
U 1 1 5CB302EA
P 5550 5875
F 0 "#PWR0118" H 5550 5625 50  0001 C CNN
F 1 "GND" H 5555 5702 50  0000 C CNN
F 2 "" H 5550 5875 50  0001 C CNN
F 3 "" H 5550 5875 50  0001 C CNN
	1    5550 5875
	1    0    0    -1  
$EndComp
Text GLabel 6150 5275 2    50   Input ~ 0
Calib
Text GLabel 4075 2500 0    50   Output ~ 0
Calib
$Comp
L manette_2019-rescue:ESP32-ESP32 U1
U 1 1 5CABDA52
P 9650 1050
F 0 "U1" H 9650 1525 50  0000 C CNN
F 1 "ESP32" H 9650 1434 50  0000 C CNN
F 2 "manette_2019:ESP32" H 9050 1000 50  0001 C CNN
F 3 "" H 9050 1000 50  0001 C CNN
	1    9650 1050
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:PCA9306-PCA9306 U8
U 1 1 5CABE2FF
P 10150 3175
F 0 "U8" H 10150 3600 50  0000 C CNN
F 1 "PCA9306" H 10150 3509 50  0000 C CNN
F 2 "manette_2019:PCA9306" H 9950 3175 50  0001 C CNN
F 3 "" H 9950 3175 50  0001 C CNN
	1    10150 3175
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 3275 10725 3275
Wire Wire Line
	10725 3275 10725 3300
Wire Notes Line
	475  2850 2700 2850
Wire Wire Line
	700  5225 700  5150
Wire Wire Line
	1400 7425 950  7425
Connection ~ 950  7425
Wire Wire Line
	850  7525 850  7425
Connection ~ 850  7425
Text GLabel 6150 4975 2    50   Output ~ 0
TX_Atmega
Text GLabel 6150 4875 2    50   Output ~ 0
RX_Atmega
$Comp
L manette_2019-rescue:R-Device R4
U 1 1 5CB92D6D
P 7350 2375
F 0 "R4" V 7143 2375 50  0000 C CNN
F 1 "R" V 7234 2375 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 7280 2375 50  0001 C CNN
F 3 "~" H 7350 2375 50  0001 C CNN
	1    7350 2375
	0    1    1    0   
$EndComp
Text GLabel 11150 4975 1    50   Input ~ 0
+5V
NoConn ~ 5825 3175
NoConn ~ 6150 3275
NoConn ~ 6150 3375
NoConn ~ 6150 3475
NoConn ~ 6150 3575
NoConn ~ 6150 3675
NoConn ~ 6150 4675
NoConn ~ 6150 5075
NoConn ~ 6150 5175
NoConn ~ 6150 5575
NoConn ~ 8550 1300
NoConn ~ 8550 1200
NoConn ~ 8550 1100
NoConn ~ 8550 1000
NoConn ~ 8550 900 
NoConn ~ 8550 800 
NoConn ~ 10750 2100
NoConn ~ 10750 2000
NoConn ~ 10750 1900
NoConn ~ 10750 1800
NoConn ~ 10750 1700
NoConn ~ 10750 1600
NoConn ~ 10750 1500
NoConn ~ 10750 900 
NoConn ~ 10750 800 
NoConn ~ 1250 3750
NoConn ~ 1450 5150
NoConn ~ 1600 7425
NoConn ~ 1400 6025
NoConn ~ 8800 5950
NoConn ~ 8800 5850
NoConn ~ 8800 5750
NoConn ~ 8800 5650
NoConn ~ 9600 5650
NoConn ~ 9600 5750
NoConn ~ 9600 5850
NoConn ~ 9700 3275
NoConn ~ 7200 1925
NoConn ~ 7200 1775
NoConn ~ 7200 2225
NoConn ~ 7200 2075
Wire Wire Line
	850  6025 850  5875
Connection ~ 850  6025
Wire Wire Line
	1250 5150 800  5150
Wire Wire Line
	800  5150 700  5150
Connection ~ 800  5150
Connection ~ 700  5150
$Comp
L manette_2019-rescue:Joystick_RSF_2-Axis-Manette_arcade JS2
U 1 1 5C7D49EC
P 1150 4500
F 0 "JS2" H 1975 4950 60  0000 R CNN
F 1 "Joystick_Right" H 2450 4850 60  0000 R CNN
F 2 "Polymanette_2018:Joystick_RSF_2-axis" H 950 4500 60  0001 C CNN
F 3 "" H 950 4500 60  0001 C CNN
	1    1150 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  3750 700  3600
Connection ~ 700  3750
Wire Wire Line
	5875 2250 5875 2225
Wire Wire Line
	5875 2225 6100 2225
$Comp
L manette_2019-rescue:GND-power #PWR0109
U 1 1 5CBC802A
P 7950 2200
F 0 "#PWR0109" H 7950 1950 50  0001 C CNN
F 1 "GND" H 7955 2027 50  0000 C CNN
F 2 "" H 7950 2200 50  0001 C CNN
F 3 "" H 7950 2200 50  0001 C CNN
	1    7950 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 2200 7950 2100
Wire Notes Line
	8200 3525 11225 3525
Wire Notes Line
	8975 2450 11200 2450
Wire Notes Line
	8200 3525 8200 6525
Wire Notes Line
	8975 2450 8975 3525
Wire Notes Line
	2700 2850 2700 475 
$Comp
L manette_2019-rescue:C-Device C2
U 1 1 5CB980CB
P 3375 6725
F 0 "C2" H 3490 6771 50  0000 L CNN
F 1 "C" H 3490 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 3413 6575 50  0001 C CNN
F 3 "Vin_Esp32" H 3575 6600 50  0000 C CNN
	1    3375 6725
	1    0    0    -1  
$EndComp
Wire Notes Line
	3200 6100 8200 6100
Wire Notes Line
	3200 6100 3200 7800
Wire Notes Line
	4725 6100 4725 475 
Text GLabel 3975 6400 1    50   Input ~ 0
+5V
$Comp
L manette_2019-rescue:C-Device C5
U 1 1 5CC5B24F
P 3775 6725
F 0 "C5" H 3890 6771 50  0000 L CNN
F 1 "C" H 3890 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 3813 6575 50  0001 C CNN
F 3 "Vin_Bus" H 3950 6600 50  0000 C CNN
	1    3775 6725
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 2100 8550 2100
$Comp
L manette_2019-rescue:C-Device C6
U 1 1 5CCA67BF
P 4175 6725
F 0 "C6" H 4290 6771 50  0000 L CNN
F 1 "C" H 4290 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 4213 6575 50  0001 C CNN
F 3 "Vin_Atmega" H 4400 6600 50  0000 C CNN
	1    4175 6725
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:C-Device C7
U 1 1 5CCE01FA
P 4725 6725
F 0 "C7" H 4840 6771 50  0000 L CNN
F 1 "C" H 4840 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 4763 6575 50  0001 C CNN
F 3 "Vin_OLED_Display" H 5075 6600 50  0000 C CNN
	1    4725 6725
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5350 9725 5350
Wire Wire Line
	9725 5350 9725 5500
Wire Wire Line
	9725 5500 9750 5500
Wire Wire Line
	10050 5800 10250 5800
Wire Wire Line
	10250 5800 10250 5600
Connection ~ 10050 5500
$Comp
L manette_2019-rescue:R-Device R15
U 1 1 5CDA7820
P 9925 5000
F 0 "R15" V 10000 4950 50  0000 L CNN
F 1 "R" V 9925 4975 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9855 5000 50  0001 C CNN
F 3 "~" H 9925 5000 50  0001 C CNN
	1    9925 5000
	0    -1   -1   0   
$EndComp
$Comp
L manette_2019-rescue:D-Device D4
U 1 1 5CDA7827
P 10075 5150
F 0 "D4" H 10075 5350 50  0000 C CNN
F 1 "D" H 10075 5275 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P10.16mm_Horizontal" H 10075 5150 50  0001 C CNN
F 3 "~" H 10075 5150 50  0001 C CNN
	1    10075 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9675 6025 9675 5450
Wire Wire Line
	9675 5450 9600 5450
Wire Wire Line
	10075 5300 10075 5325
Wire Wire Line
	10250 5800 11150 5800
Connection ~ 10250 5800
Text GLabel 8800 5250 0    50   Input ~ 0
Rumble
Wire Wire Line
	10075 5325 10300 5325
$Comp
L manette_2019-rescue:Screw_Terminal_01x02-Connector J5
U 1 1 5CDD987E
P 10500 5000
F 0 "J5" H 10579 4992 50  0000 L CNN
F 1 "Rumble" H 10579 4901 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 10500 5000 50  0001 C CNN
F 3 "~" H 10500 5000 50  0001 C CNN
	1    10500 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10075 5000 10300 5000
Wire Wire Line
	10300 5100 10300 5325
Connection ~ 10300 5325
Wire Wire Line
	10300 5325 11150 5325
Wire Wire Line
	3950 2625 3950 2600
Text GLabel 2325 4900 1    50   Input ~ 0
+5V
$Comp
L manette_2019-rescue:GND-power #PWR0108
U 1 1 5C81DB7C
P 2325 5925
F 0 "#PWR0108" H 2325 5675 50  0001 C CNN
F 1 "GND" H 2330 5752 50  0000 C CNN
F 2 "" H 2325 5925 50  0001 C CNN
F 3 "" H 2325 5925 50  0001 C CNN
	1    2325 5925
	1    0    0    -1  
$EndComp
Text GLabel 2475 5050 2    50   Output ~ 0
L_trigger
Text GLabel 2475 5775 2    50   Output ~ 0
R_trigger
Text GLabel 2325 5625 1    50   Input ~ 0
+5V
$Comp
L manette_2019-rescue:R_POT-Device RV2
U 1 1 5CC9B38B
P 2325 5775
F 0 "RV2" H 2255 5821 50  0000 R CNN
F 1 "R_POT" H 2255 5730 50  0000 R CNN
F 2 "manette_2019:Potentiomètre linéaire" H 2325 5775 50  0001 C CNN
F 3 "~" H 2325 5775 50  0001 C CNN
	1    2325 5775
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0106
U 1 1 5CCA47FE
P 2325 5200
F 0 "#PWR0106" H 2325 4950 50  0001 C CNN
F 1 "GND" H 2330 5027 50  0000 C CNN
F 2 "" H 2325 5200 50  0001 C CNN
F 3 "" H 2325 5200 50  0001 C CNN
	1    2325 5200
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:R_POT-Device RV1
U 1 1 5CCA4804
P 2325 5050
F 0 "RV1" H 2255 5096 50  0000 R CNN
F 1 "L_POT" H 2255 5005 50  0000 R CNN
F 2 "manette_2019:Potentiomètre linéaire" H 2325 5050 50  0001 C CNN
F 3 "~" H 2325 5050 50  0001 C CNN
	1    2325 5050
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Conn_01x02-Connector_Generic J2
U 1 1 5CD06004
P 2850 3300
F 0 "J2" H 2929 3292 50  0000 L CNN
F 1 "L_Bumper" H 2929 3201 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 2850 3300 50  0001 C CNN
F 3 "~" H 2850 3300 50  0001 C CNN
	1    2850 3300
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Conn_01x02-Connector_Generic J3
U 1 1 5CD06125
P 2850 3750
F 0 "J3" H 2930 3742 50  0000 L CNN
F 1 "R_Bumper" H 2930 3651 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 2850 3750 50  0001 C CNN
F 3 "~" H 2850 3750 50  0001 C CNN
	1    2850 3750
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0126
U 1 1 5CD0AD74
P 2550 3425
F 0 "#PWR0126" H 2550 3175 50  0001 C CNN
F 1 "GND" H 2555 3252 50  0000 C CNN
F 2 "" H 2550 3425 50  0001 C CNN
F 3 "" H 2550 3425 50  0001 C CNN
	1    2550 3425
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0127
U 1 1 5CD0F199
P 2550 3875
F 0 "#PWR0127" H 2550 3625 50  0001 C CNN
F 1 "GND" H 2555 3702 50  0000 C CNN
F 2 "" H 2550 3875 50  0001 C CNN
F 3 "" H 2550 3875 50  0001 C CNN
	1    2550 3875
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3425 2550 3400
Wire Wire Line
	2550 3400 2650 3400
Wire Wire Line
	2550 3875 2550 3850
Wire Wire Line
	2550 3850 2650 3850
Text GLabel 2650 3750 0    50   Output ~ 0
R_Bumper
Text GLabel 2650 3300 0    50   Output ~ 0
L_Bumper
$Comp
L manette_2019-rescue:Conn_01x09-Connector_Generic J4
U 1 1 5CD4740A
P 9250 4125
F 0 "J4" H 9330 4167 50  0000 L CNN
F 1 "OLED_Display" H 9330 4076 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x09_P2.54mm_Vertical" H 9250 4125 50  0001 C CNN
F 3 "~" H 9250 4125 50  0001 C CNN
	1    9250 4125
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Conn_01x02-Connector_Generic J6
U 1 1 5CD55C77
P 4275 2500
F 0 "J6" H 4354 2492 50  0000 L CNN
F 1 "Calib" H 4354 2401 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 4275 2500 50  0001 C CNN
F 3 "~" H 4275 2500 50  0001 C CNN
	1    4275 2500
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0129
U 1 1 5CCA0050
P 3250 4100
F 0 "#PWR0129" H 3250 3850 50  0001 C CNN
F 1 "GND" H 3255 3927 50  0000 C CNN
F 2 "" H 3250 4100 50  0001 C CNN
F 3 "" H 3250 4100 50  0001 C CNN
	1    3250 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 4100 3250 4075
Text GLabel 3850 4775 0    50   Output ~ 0
Button_LEFT
Text GLabel 3850 4175 0    50   Output ~ 0
Button_UP
Text GLabel 3850 4375 0    50   Output ~ 0
Button_RIGHT
Text GLabel 3850 4575 0    50   Output ~ 0
Button_DOWN
Text GLabel 3850 3225 0    50   Output ~ 0
Button_X
Text GLabel 3850 3425 0    50   Output ~ 0
Button_Y
Text GLabel 3850 3025 0    50   Output ~ 0
Button_A
Text GLabel 3850 3625 0    50   Output ~ 0
Button_B
Text GLabel 8550 2200 0    50   Input ~ 0
+5V
Text GLabel 850  5875 1    50   Input ~ 0
+5V
Text GLabel 700  3600 1    50   Input ~ 0
+5V
Text GLabel 6100 2075 0    50   Input ~ 0
+5V
Wire Wire Line
	3375 6875 3375 7000
Wire Wire Line
	3775 7000 3775 6875
Wire Wire Line
	4175 7000 4175 6875
Wire Wire Line
	3975 6400 3975 6475
Wire Wire Line
	3375 6475 3375 6575
$Comp
L manette_2019-rescue:GND-power #PWR0107
U 1 1 5CCF972D
P 3675 7000
F 0 "#PWR0107" H 3675 6750 50  0001 C CNN
F 1 "GND" H 3680 6827 50  0000 C CNN
F 2 "" H 3675 7000 50  0001 C CNN
F 3 "" H 3675 7000 50  0001 C CNN
	1    3675 7000
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:C-Device C1
U 1 1 5CCF4611
P 1275 1400
F 0 "C1" H 1390 1446 50  0000 L CNN
F 1 "C" H 1390 1355 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D10.0mm_H20.0mm_P5.00mm" H 1313 1250 50  0001 C CNN
F 3 "~" H 1275 1400 50  0001 C CNN
	1    1275 1400
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:GND-power #PWR0119
U 1 1 5CB6DBAC
P 1275 1875
F 0 "#PWR0119" H 1275 1625 50  0001 C CNN
F 1 "GND" H 1280 1702 50  0000 C CNN
F 2 "" H 1275 1875 50  0001 C CNN
F 3 "" H 1275 1875 50  0001 C CNN
	1    1275 1875
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Screw_Terminal_01x02-Connector J1
U 1 1 5CCCFDC6
P 600 1100
F 0 "J1" H 520 775 50  0000 C CNN
F 1 "Vcc" H 520 866 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 600 1100 50  0001 C CNN
F 3 "~" H 600 1100 50  0001 C CNN
	1    600  1100
	-1   0    0    1   
$EndComp
$Comp
L manette_2019-rescue:Screw_Terminal_01x02-Connector J10
U 1 1 5CCCFFAC
P 600 1825
F 0 "J10" H 520 1500 50  0000 C CNN
F 1 "Alim_LED" H 520 1591 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 600 1825 50  0001 C CNN
F 3 "~" H 600 1825 50  0001 C CNN
	1    600  1825
	-1   0    0    1   
$EndComp
Text GLabel 800  1725 2    50   Output ~ 0
VCC_LED
Connection ~ 1275 1100
Wire Wire Line
	1275 1100 1325 1100
Wire Wire Line
	800  1100 900  1100
Wire Wire Line
	800  1000 900  1000
Wire Wire Line
	900  1000 900  1100
Connection ~ 900  1100
Wire Wire Line
	900  1100 1275 1100
Wire Wire Line
	1275 1250 1275 1100
Text GLabel 3850 3125 0    50   Input ~ 0
VCC_LED
Text GLabel 3850 4275 0    50   Input ~ 0
VCC_LED
Wire Wire Line
	4075 2600 3950 2600
Wire Wire Line
	11150 4975 11150 5325
NoConn ~ 9600 5950
NoConn ~ 8800 5550
NoConn ~ 9600 5550
Connection ~ 10075 5000
Text GLabel 10750 1400 2    50   Output ~ 0
Rumble
Wire Wire Line
	800  1825 1275 1825
Wire Wire Line
	1275 1825 1275 1875
Wire Wire Line
	1275 1550 1275 1825
Connection ~ 1275 1825
Connection ~ 11150 5325
Wire Wire Line
	11150 5325 11150 5800
Wire Wire Line
	9600 5250 9700 5250
Wire Wire Line
	9700 5250 9700 5000
Wire Wire Line
	9700 5000 9775 5000
Wire Wire Line
	9950 6025 9675 6025
$Comp
L manette_2019-rescue:Conn_01x08-Connector_Generic J8
U 1 1 5CCEC7D5
P 4050 4375
F 0 "J8" H 4130 4367 50  0000 L CNN
F 1 "Conn_L_Button" H 4130 4276 50  0000 L CNN
F 2 "manette_2019:Conn_8" H 4050 4375 50  0001 C CNN
F 3 "~" H 4050 4375 50  0001 C CNN
	1    4050 4375
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Conn_01x08-Connector_Generic J7
U 1 1 5CCEC8A9
P 4050 3225
F 0 "J7" H 4130 3217 50  0000 L CNN
F 1 "Conn_R_Button" H 4130 3126 50  0000 L CNN
F 2 "manette_2019:Conn_8" H 4050 3225 50  0001 C CNN
F 3 "~" H 4050 3225 50  0001 C CNN
	1    4050 3225
	1    0    0    -1  
$EndComp
$Comp
L manette_2019-rescue:Conn_01x08-Connector_Generic J9
U 1 1 5CCF355A
P 3700 1900
F 0 "J9" H 3780 1942 50  0000 L CNN
F 1 "Conn_Middle_PCB" H 3780 1851 50  0000 L CNN
F 2 "manette_2019:Conn_8" H 3700 1900 50  0001 C CNN
F 3 "~" H 3700 1900 50  0001 C CNN
	1    3700 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2325 3500 2300
Text GLabel 3500 1600 0    50   Output ~ 0
Button_SELECT
Text GLabel 3500 1800 0    50   Output ~ 0
Button_START
$Comp
L manette_2019-rescue:GND-power #PWR0114
U 1 1 5CCE01A7
P 3500 2325
F 0 "#PWR0114" H 3500 2075 50  0001 C CNN
F 1 "GND" H 3505 2152 50  0000 C CNN
F 2 "" H 3500 2325 50  0001 C CNN
F 3 "" H 3500 2325 50  0001 C CNN
	1    3500 2325
	1    0    0    -1  
$EndComp
Text GLabel 3500 2100 0    50   Input ~ 0
+5V
Text GLabel 9950 6025 2    50   Output ~ 0
Conn_LED_On
Text GLabel 3500 1700 0    50   Output ~ 0
Conn_LED_On
NoConn ~ 3850 3325
NoConn ~ 3850 3525
NoConn ~ 3850 4675
NoConn ~ 3850 4475
NoConn ~ 3500 2000
NoConn ~ 3500 1900
NoConn ~ 3500 2200
Wire Wire Line
	3250 4075 3850 4075
Wire Wire Line
	3775 6475 3775 6575
Wire Wire Line
	4175 6475 4175 6575
Wire Wire Line
	4725 7000 4725 6875
Wire Wire Line
	4725 6575 4725 6475
Text GLabel 9050 4425 0    50   Input ~ 0
+5V
Wire Wire Line
	3375 7000 3675 7000
Wire Wire Line
	3375 6475 3775 6475
Connection ~ 3675 7000
Wire Wire Line
	3675 7000 3775 7000
Connection ~ 3775 6475
Wire Wire Line
	3775 6475 3975 6475
Connection ~ 3775 7000
Wire Wire Line
	3775 7000 4175 7000
Connection ~ 4175 6475
Connection ~ 4175 7000
Wire Wire Line
	4175 7000 4725 7000
Connection ~ 3975 6475
Wire Wire Line
	3975 6475 4175 6475
Wire Wire Line
	4175 6475 4725 6475
Text GLabel 10750 2200 2    50   Output ~ 0
+3.3V
$Comp
L manette_2019-rescue:GND-power #PWR0128
U 1 1 5CC9AA68
P 3275 2950
F 0 "#PWR0128" H 3275 2700 50  0001 C CNN
F 1 "GND" H 3280 2777 50  0000 C CNN
F 2 "" H 3275 2950 50  0001 C CNN
F 3 "" H 3275 2950 50  0001 C CNN
	1    3275 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 2950 3275 2925
Wire Wire Line
	3275 2925 3850 2925
$EndSCHEMATC
