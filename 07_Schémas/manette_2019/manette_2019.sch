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
L Device:Speaker LS1
U 1 1 5C7D5866
P 10600 5600
F 0 "LS1" H 10800 5650 50  0000 L CNN
F 1 "Speaker" H 10800 5550 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_T135" H 10600 5400 50  0001 C CNN
F 3 "~" H 10590 5550 50  0001 C CNN
	1    10600 5600
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
L MCP23017:MCP23017 U3
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
Text GLabel 8550 1500 0    50   Output ~ 0
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
L MCU_Microchip_ATmega:ATmega328-PU U2
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
Left_joystick_analog_x
Text GLabel 2100 6875 2    50   Output ~ 0
Left_joystick_analog_y
Text GLabel 1950 4350 2    50   Output ~ 0
Right_joystick_analog_x
Text GLabel 1950 4600 2    50   Output ~ 0
Right_joystick_analog_y
Text GLabel 1450 3750 1    50   Output ~ 0
Right_joystick_button
Text GLabel 1600 6025 1    50   Output ~ 0
Left_joystick_button
Wire Wire Line
	700  3750 800  3750
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS1
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
Text GLabel 6100 1175 0    50   Input ~ 0
Right_joystick_button
Text GLabel 6150 4275 2    50   Input ~ 0
L_joystick_analog_x
Text GLabel 6150 4375 2    50   Input ~ 0
L_joystick_analog_y
Text GLabel 6100 1325 0    50   Input ~ 0
Left_joystick_button
Text GLabel 6150 4575 2    50   Input ~ 0
L_trigger
Text GLabel 6150 4475 2    50   Input ~ 0
R_trigger
$Comp
L Transistor_Array:ULN2803A U5
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
L Device:Resonator Y1
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
L power:GND #PWR0110
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
L Device:LED D1
U 1 1 5C83283C
P 10200 5250
F 0 "D1" H 10200 5075 50  0000 C CNN
F 1 "LED_B" H 10250 5150 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 10200 5250 50  0001 C CNN
F 3 "~" H 10200 5250 50  0001 C CNN
	1    10200 5250
	1    0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5C8328E9
P 9900 5250
F 0 "R1" V 9825 5200 50  0000 L CNN
F 1 "R" V 9900 5225 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9830 5250 50  0001 C CNN
F 3 "~" H 9900 5250 50  0001 C CNN
	1    9900 5250
	0    -1   1    0   
$EndComp
Text GLabel 2375 2325 2    50   Output ~ 0
+5V
$Comp
L power:GND #PWR0111
U 1 1 5C8638D7
P 9200 6150
F 0 "#PWR0111" H 9200 5900 50  0001 C CNN
F 1 "GND" H 9205 5977 50  0000 C CNN
F 2 "" H 9200 6150 50  0001 C CNN
F 3 "" H 9200 6150 50  0001 C CNN
	1    9200 6150
	1    0    0    -1  
$EndComp
Text GLabel 8800 5450 0    50   Input ~ 0
Buzzer
$Comp
L Device:R R3
U 1 1 5C865F77
P 9900 5600
F 0 "R3" V 9975 5550 50  0000 L CNN
F 1 "R" V 9900 5575 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9830 5600 50  0001 C CNN
F 3 "~" H 9900 5600 50  0001 C CNN
	1    9900 5600
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5C86BA29
P 10200 5425
F 0 "D2" H 10350 5475 50  0000 C CNN
F 1 "LED_R" H 10350 5550 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 10200 5425 50  0001 C CNN
F 3 "~" H 10200 5425 50  0001 C CNN
	1    10200 5425
	1    0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5C86BA30
P 9900 5425
F 0 "R2" V 9825 5375 50  0000 L CNN
F 1 "R" V 9900 5400 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9830 5425 50  0001 C CNN
F 3 "~" H 9900 5425 50  0001 C CNN
	1    9900 5425
	0    -1   1    0   
$EndComp
$Comp
L Device:D D3
U 1 1 5C878C9C
P 10050 5750
F 0 "D3" H 10050 5950 50  0000 C CNN
F 1 "D" H 10050 5875 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P10.16mm_Horizontal" H 10050 5750 50  0001 C CNN
F 3 "~" H 10050 5750 50  0001 C CNN
	1    10050 5750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10250 5700 10400 5700
Wire Wire Line
	10050 5600 10400 5600
Text GLabel 8800 5350 0    50   Input ~ 0
Power
Text GLabel 8800 5250 0    50   Input ~ 0
Connected
Text GLabel 6100 1475 0    50   Input ~ 0
Button_LEFT
Text GLabel 6100 1625 0    50   Input ~ 0
Button_UP
Text GLabel 6100 1775 0    50   Input ~ 0
Button_RIGHT
Text GLabel 6100 1925 0    50   Input ~ 0
Button_DOWN
Text GLabel 7200 875  2    50   Input ~ 0
Button_A
Text GLabel 7200 1025 2    50   Input ~ 0
Button_B
Text GLabel 7200 1175 2    50   Input ~ 0
Button_Y
Text GLabel 7200 1325 2    50   Input ~ 0
Button_X
Text GLabel 7200 1775 2    50   Input ~ 0
Button_START
Text GLabel 7200 1925 2    50   Input ~ 0
Button_SELECT
Text GLabel 7200 1475 2    50   Input ~ 0
R_Bumper
Text GLabel 7200 1625 2    50   Input ~ 0
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
$Comp
L Regulator_Switching:R-78E5.0-0.5 U7
U 1 1 5C9AC915
P 2075 2325
F 0 "U7" H 2075 2567 50  0000 C CNN
F 1 "R-78E5.0-0.5" H 2075 2476 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 2125 2075 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78Exx-0.5.pdf" H 2075 2325 50  0001 C CNN
	1    2075 2325
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5C9B9F3C
P 2075 2625
F 0 "#PWR0112" H 2075 2375 50  0001 C CNN
F 1 "GND" H 2080 2452 50  0000 C CNN
F 2 "" H 2075 2625 50  0001 C CNN
F 3 "" H 2075 2625 50  0001 C CNN
	1    2075 2625
	1    0    0    -1  
$EndComp
Text GLabel 3975 900  2    50   Output ~ 0
Button_START
Text GLabel 3975 1425 2    50   Output ~ 0
Button_SELECT
Text Label 1725 3150 0    197  ~ 0
Inputs
Text GLabel 9050 3925 0    50   Input ~ 0
DC
Text GLabel 8550 1600 0    50   Output ~ 0
DC
Text GLabel 9050 4125 0    50   Input ~ 0
OLEDCS
Text GLabel 8550 1700 0    50   Output ~ 0
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
Text GLabel 10600 3175 2    50   Input ~ 0
RX_ESP32
Text GLabel 10600 3075 2    50   Input ~ 0
TX_ESP32
Text GLabel 9700 3175 0    50   Input ~ 0
TX_Atmega
Text GLabel 9700 3075 0    50   Input ~ 0
RX_Atmega
$Comp
L Regulator_Switching:R-783.3-0.5 U6
U 1 1 5CB0E72E
P 2075 1475
F 0 "U6" H 2075 1717 50  0000 C CNN
F 1 "R-783.3-0.5" H 2075 1626 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 2125 1225 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78xx-0.5.pdf" H 2075 1475 50  0001 C CNN
	1    2075 1475
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5CB1A915
P 2075 1775
F 0 "#PWR0117" H 2075 1525 50  0001 C CNN
F 1 "GND" H 2080 1602 50  0000 C CNN
F 2 "" H 2075 1775 50  0001 C CNN
F 3 "" H 2075 1775 50  0001 C CNN
	1    2075 1775
	1    0    0    -1  
$EndComp
Text GLabel 2375 1475 2    50   Output ~ 0
+3.3V
Text Label 625  775  0    197  ~ 0
Power
Text Label 9150 2700 0    197  ~ 0
SerialComm
Text Label 4800 725  0    197  ~ 0
Command
Wire Wire Line
	950  6025 850  6025
Text GLabel 10750 1200 2    50   Output ~ 0
Buzzer
Text GLabel 10750 1300 2    50   Output ~ 0
Power
Text GLabel 10750 1400 2    50   Output ~ 0
Connected
Text GLabel 1325 1100 2    50   Output ~ 0
VCC
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5CA7532E
P 6350 6400
F 0 "#FLG0101" H 6350 6475 50  0001 C CNN
F 1 "PWR_FLAG" H 6350 6574 50  0000 C CNN
F 2 "" H 6350 6400 50  0001 C CNN
F 3 "~" H 6350 6400 50  0001 C CNN
	1    6350 6400
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
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
L power:PWR_FLAG #FLG0103
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
L power:PWR_FLAG #FLG0104
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
Text GLabel 6350 6400 3    50   Input ~ 0
VCC
$Comp
L power:GND #PWR0102
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
L power:GND #PWR0116
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
L power:GND #PWR0101
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
L power:GND #PWR0113
U 1 1 5C9E80F4
P 3375 1975
F 0 "#PWR0113" H 3375 1725 50  0001 C CNN
F 1 "GND" H 3380 1802 50  0000 C CNN
F 2 "" H 3375 1975 50  0001 C CNN
F 3 "" H 3375 1975 50  0001 C CNN
	1    3375 1975
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
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
L power:GND #PWR0105
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
L power:GND #PWR0103
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
L power:GND #PWR0115
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
L power:GND #PWR0118
U 1 1 5CB302EA
P 5550 5875
F 0 "#PWR0118" H 5550 5625 50  0001 C CNN
F 1 "GND" H 5555 5702 50  0000 C CNN
F 2 "" H 5550 5875 50  0001 C CNN
F 3 "" H 5550 5875 50  0001 C CNN
	1    5550 5875
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 5CB6DBAC
P 925 1425
F 0 "#PWR0119" H 925 1175 50  0001 C CNN
F 1 "GND" H 930 1252 50  0000 C CNN
F 2 "" H 925 1425 50  0001 C CNN
F 3 "" H 925 1425 50  0001 C CNN
	1    925  1425
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  1200 925  1200
Text GLabel 6150 5275 2    50   Input ~ 0
Calib
Text GLabel 4075 1850 0    50   Output ~ 0
Calib
$Comp
L ESP32:ESP32 U1
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
L PCA9306:PCA9306 U8
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
L Device:R R4
U 1 1 5CB92D6D
P 7350 2375
F 0 "R4" V 7143 2375 50  0000 C CNN
F 1 "R" V 7234 2375 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 7280 2375 50  0001 C CNN
F 3 "~" H 7350 2375 50  0001 C CNN
	1    7350 2375
	0    1    1    0   
$EndComp
Text GLabel 10500 5075 1    50   Input ~ 0
+3.3V
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
NoConn ~ 10750 2200
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
NoConn ~ 9600 5150
NoConn ~ 9600 5650
NoConn ~ 9600 5750
NoConn ~ 9600 5850
NoConn ~ 9600 5950
NoConn ~ 9700 3275
NoConn ~ 6100 1025
NoConn ~ 6100 875 
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
L Manette_arcade:Joystick_RSF_2-Axis JS2
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
L power:GND #PWR0109
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
L Device:C C2
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
Text GLabel 3375 6400 1    50   Input ~ 0
VCC
$Comp
L Device:C C5
U 1 1 5CC5B24F
P 4850 6725
F 0 "C5" H 4965 6771 50  0000 L CNN
F 1 "C" H 4965 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 4888 6575 50  0001 C CNN
F 3 "Vin_Bus" H 5025 6600 50  0000 C CNN
	1    4850 6725
	1    0    0    -1  
$EndComp
Text GLabel 4850 6400 1    50   Input ~ 0
+5V
Wire Wire Line
	7950 2100 8550 2100
$Comp
L Device:C C6
U 1 1 5CCA67BF
P 5250 6725
F 0 "C6" H 5365 6771 50  0000 L CNN
F 1 "C" H 5365 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 5288 6575 50  0001 C CNN
F 3 "Vin_Atmega" H 5475 6600 50  0000 C CNN
	1    5250 6725
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5CCE01FA
P 5775 6725
F 0 "C7" H 5890 6771 50  0000 L CNN
F 1 "C" H 5890 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 5813 6575 50  0001 C CNN
F 3 "Vin_OLED_Display" H 6125 6600 50  0000 C CNN
	1    5775 6725
	1    0    0    -1  
$EndComp
Text GLabel 5775 6400 1    50   Input ~ 0
+3.3V
$Comp
L Device:C C1
U 1 1 5CCF4611
P 1100 1250
F 0 "C1" H 1215 1296 50  0000 L CNN
F 1 "C" H 1215 1205 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D10.0mm_H20.0mm_P5.00mm" H 1138 1100 50  0001 C CNN
F 3 "~" H 1100 1250 50  0001 C CNN
	1    1100 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	925  1200 925  1400
Wire Wire Line
	1100 1400 925  1400
Connection ~ 925  1400
Wire Wire Line
	925  1400 925  1425
Wire Wire Line
	1100 1100 1325 1100
$Comp
L Device:C C4
U 1 1 5CD26113
P 4350 6725
F 0 "C4" H 4465 6771 50  0000 L CNN
F 1 "C" H 4465 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 4388 6575 50  0001 C CNN
F 3 "Vin_Rec_U7" H 4575 6600 50  0000 C CNN
	1    4350 6725
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5CD5092B
P 3825 6725
F 0 "C3" H 3940 6771 50  0000 L CNN
F 1 "C" H 3940 6680 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 3863 6575 50  0001 C CNN
F 3 "Vin_Rec_U6" H 4100 6600 50  0000 C CNN
	1    3825 6725
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5250 9750 5250
Wire Wire Line
	10350 5250 10500 5250
Wire Wire Line
	10350 5425 10500 5425
Wire Wire Line
	10500 5425 10500 5250
Wire Wire Line
	10500 5250 10500 5075
Connection ~ 10500 5250
Wire Wire Line
	9750 5425 9725 5425
Wire Wire Line
	9725 5425 9725 5350
Wire Wire Line
	9600 5350 9725 5350
Wire Wire Line
	9600 5450 9725 5450
Wire Wire Line
	9725 5450 9725 5600
Wire Wire Line
	9725 5600 9750 5600
Wire Wire Line
	10050 5900 10250 5900
Wire Wire Line
	10250 5900 10250 5700
Connection ~ 10050 5600
$Comp
L Device:R R15
U 1 1 5CDA7820
P 9925 6125
F 0 "R15" V 10000 6075 50  0000 L CNN
F 1 "R" V 9925 6100 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9855 6125 50  0001 C CNN
F 3 "~" H 9925 6125 50  0001 C CNN
	1    9925 6125
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D4
U 1 1 5CDA7827
P 10075 6275
F 0 "D4" H 10075 6475 50  0000 C CNN
F 1 "D" H 10075 6400 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P10.16mm_Horizontal" H 10075 6275 50  0001 C CNN
F 3 "~" H 10075 6275 50  0001 C CNN
	1    10075 6275
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9775 6125 9675 6125
Wire Wire Line
	9675 6125 9675 5550
Wire Wire Line
	9675 5550 9600 5550
Wire Wire Line
	10075 6425 10075 6450
Wire Wire Line
	11150 6450 11150 5900
Wire Wire Line
	11150 5250 10500 5250
Wire Wire Line
	10250 5900 11150 5900
Connection ~ 10250 5900
Connection ~ 11150 5900
Wire Wire Line
	11150 5900 11150 5250
Text GLabel 8800 5550 0    50   Input ~ 0
Rumble
Wire Wire Line
	10075 6450 10300 6450
$Comp
L Connector:Screw_Terminal_01x02 J5
U 1 1 5CDD987E
P 10500 6125
F 0 "J5" H 10579 6117 50  0000 L CNN
F 1 "Rumble" H 10579 6026 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 10500 6125 50  0001 C CNN
F 3 "~" H 10500 6125 50  0001 C CNN
	1    10500 6125
	1    0    0    -1  
$EndComp
Connection ~ 10075 6125
Wire Wire Line
	10075 6125 10300 6125
Wire Wire Line
	10300 6225 10300 6450
Connection ~ 10300 6450
Wire Wire Line
	10300 6450 11150 6450
$Comp
L Switch:SW_Push_LED SW5
U 1 1 5CCB42C2
P 3775 1000
F 0 "SW5" H 3775 1385 50  0000 C CNN
F 1 "Button_START" H 3775 1294 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 3775 1300 50  0001 C CNN
F 3 "" H 3775 1300 50  0001 C CNN
	1    3775 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3575 900  3375 900 
Wire Wire Line
	3575 1000 3375 1000
Wire Wire Line
	3375 900  3375 1000
Connection ~ 3375 1000
Wire Wire Line
	3375 1000 3375 1425
$Comp
L Switch:SW_Push_LED SW6
U 1 1 5CCCB259
P 3775 1525
F 0 "SW6" H 3775 1910 50  0000 C CNN
F 1 "Button_SELECT" H 3775 1819 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 3775 1825 50  0001 C CNN
F 3 "" H 3775 1825 50  0001 C CNN
	1    3775 1525
	1    0    0    -1  
$EndComp
Wire Wire Line
	3575 1425 3375 1425
Connection ~ 3375 1425
Wire Wire Line
	3375 1425 3375 1525
Wire Wire Line
	3375 1975 3375 1950
Wire Wire Line
	4075 1950 3375 1950
$Comp
L Device:R R10
U 1 1 5CD95D34
P 4125 1525
F 0 "R10" V 4025 1525 50  0000 C CNN
F 1 "R" V 3950 1525 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4055 1525 50  0001 C CNN
F 3 "~" H 4125 1525 50  0001 C CNN
	1    4125 1525
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R9
U 1 1 5CD9F3F2
P 4125 1000
F 0 "R9" V 4025 1000 50  0000 C CNN
F 1 "R" V 3950 1000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4055 1000 50  0001 C CNN
F 3 "~" H 4125 1000 50  0001 C CNN
	1    4125 1000
	0    -1   -1   0   
$EndComp
Text GLabel 4275 1000 2    50   Input ~ 0
+5V
Text GLabel 4275 1525 2    50   Input ~ 0
+5V
Text GLabel 2325 4900 1    50   Input ~ 0
+5V
$Comp
L power:GND #PWR0108
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
Left_trigger
Text GLabel 2475 5775 2    50   Output ~ 0
Right_trigger
Text GLabel 2325 5625 1    50   Input ~ 0
+5V
$Comp
L Device:R_POT RV2
U 1 1 5CC9B38B
P 2325 5775
F 0 "RV2" H 2255 5821 50  0000 R CNN
F 1 "R_POT" H 2255 5730 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTA2043_Single_Slide" H 2325 5775 50  0001 C CNN
F 3 "~" H 2325 5775 50  0001 C CNN
	1    2325 5775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
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
L Device:R_POT RV1
U 1 1 5CCA4804
P 2325 5050
F 0 "RV1" H 2255 5096 50  0000 R CNN
F 1 "R_POT" H 2255 5005 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTA2043_Single_Slide" H 2325 5050 50  0001 C CNN
F 3 "~" H 2325 5050 50  0001 C CNN
	1    2325 5050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
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
L Connector_Generic:Conn_01x02 J3
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
L power:GND #PWR0126
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
L power:GND #PWR0127
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
L Connector_Generic:Conn_01x09 J4
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
L Connector_Generic:Conn_01x02 J6
U 1 1 5CD55C77
P 4275 1850
F 0 "J6" H 4354 1842 50  0000 L CNN
F 1 "Calib" H 4354 1751 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 4275 1850 50  0001 C CNN
F 3 "~" H 4275 1850 50  0001 C CNN
	1    4275 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3575 1525 3375 1525
Wire Wire Line
	3375 1525 3375 1950
Connection ~ 3375 1525
Connection ~ 3375 1950
$Comp
L power:GND #PWR0128
U 1 1 5CC9AA68
P 3375 3050
F 0 "#PWR0128" H 3375 2800 50  0001 C CNN
F 1 "GND" H 3380 2877 50  0000 C CNN
F 2 "" H 3375 3050 50  0001 C CNN
F 3 "" H 3375 3050 50  0001 C CNN
	1    3375 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3375 3050 3375 3025
$Comp
L power:GND #PWR0129
U 1 1 5CCA0050
P 3375 3750
F 0 "#PWR0129" H 3375 3500 50  0001 C CNN
F 1 "GND" H 3380 3577 50  0000 C CNN
F 2 "" H 3375 3750 50  0001 C CNN
F 3 "" H 3375 3750 50  0001 C CNN
	1    3375 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3375 3750 3375 3725
Text GLabel 3950 3825 0    50   Output ~ 0
Button_LEFT
Wire Wire Line
	3375 3725 3950 3725
Text GLabel 3950 3925 0    50   Output ~ 0
Button_UP
Text GLabel 3950 4025 0    50   Output ~ 0
Button_RIGHT
Text GLabel 3950 4125 0    50   Output ~ 0
Button_DOWN
Wire Wire Line
	3375 3025 3950 3025
$Comp
L Connector:Screw_Terminal_01x03 J10
U 1 1 5CCBD83F
P 4150 4025
F 0 "J10" H 4230 4067 50  0000 L CNN
F 1 "L_button_In2" H 4230 3976 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 4150 4025 50  0001 C CNN
F 3 "~" H 4150 4025 50  0001 C CNN
	1    4150 4025
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J9
U 1 1 5CCBD964
P 4150 3725
F 0 "J9" H 4230 3767 50  0000 L CNN
F 1 "L_button_In1" H 4230 3676 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 4150 3725 50  0001 C CNN
F 3 "~" H 4150 3725 50  0001 C CNN
	1    4150 3725
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J8
U 1 1 5CCC0940
P 4150 3325
F 0 "J8" H 4230 3367 50  0000 L CNN
F 1 "R_button_In2" H 4230 3276 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 4150 3325 50  0001 C CNN
F 3 "~" H 4150 3325 50  0001 C CNN
	1    4150 3325
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J7
U 1 1 5CCC0947
P 4150 3025
F 0 "J7" H 4229 3067 50  0000 L CNN
F 1 "R_Button_In1" H 4229 2976 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 4150 3025 50  0001 C CNN
F 3 "~" H 4150 3025 50  0001 C CNN
	1    4150 3025
	1    0    0    -1  
$EndComp
Text GLabel 3950 3125 0    50   Output ~ 0
Button_B
Text GLabel 3950 3225 0    50   Output ~ 0
Button_A
Text GLabel 3950 3325 0    50   Output ~ 0
Button_Y
Text GLabel 3950 3425 0    50   Output ~ 0
Button_X
Connection ~ 1100 1100
Wire Wire Line
	800  1100 1100 1100
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5CB34D45
P 600 1200
F 0 "J1" H 520 875 50  0000 C CNN
F 1 "Power" H 520 966 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 600 1200 50  0001 C CNN
F 3 "~" H 600 1200 50  0001 C CNN
	1    600  1200
	-1   0    0    1   
$EndComp
Text GLabel 8550 2200 0    50   Input ~ 0
VCC
Text GLabel 1775 2325 0    50   Input ~ 0
VCC
Text GLabel 1775 1475 0    50   Input ~ 0
VCC
Text GLabel 850  5875 1    50   Input ~ 0
+5V
Text GLabel 700  3600 1    50   Input ~ 0
+5V
Text GLabel 6100 2075 0    50   Input ~ 0
+5V
Text GLabel 9050 4425 0    50   Input ~ 0
+3.3V
Wire Wire Line
	3375 6875 3375 7000
Wire Wire Line
	3375 7000 3825 7000
Wire Wire Line
	3825 7000 3825 6875
Connection ~ 3825 7000
Wire Wire Line
	4850 7000 4850 6875
Wire Wire Line
	5250 7000 5250 6875
Wire Wire Line
	5775 7000 5775 6875
Wire Wire Line
	3375 6400 3375 6475
Wire Wire Line
	3375 6475 3825 6475
Wire Wire Line
	3825 6475 3825 6575
Connection ~ 3375 6475
Wire Wire Line
	3375 6475 3375 6575
Connection ~ 3825 6475
Wire Wire Line
	4850 6400 4850 6475
Wire Wire Line
	5250 6475 4850 6475
Wire Wire Line
	5250 6475 5250 6575
Connection ~ 4850 6475
Wire Wire Line
	4850 6475 4850 6575
$Comp
L power:GND #PWR?
U 1 1 5CCF972D
P 4350 7000
F 0 "#PWR?" H 4350 6750 50  0001 C CNN
F 1 "GND" H 4355 6827 50  0000 C CNN
F 2 "" H 4350 7000 50  0001 C CNN
F 3 "" H 4350 7000 50  0001 C CNN
	1    4350 7000
	1    0    0    -1  
$EndComp
Connection ~ 4350 7000
Wire Wire Line
	3825 7000 4350 7000
Wire Wire Line
	4350 7000 4350 6875
Wire Wire Line
	4350 6575 4350 6475
Wire Wire Line
	3825 6475 4350 6475
Wire Wire Line
	4350 7000 4850 7000
Connection ~ 4850 7000
Wire Wire Line
	4850 7000 5250 7000
Wire Wire Line
	5250 7000 5775 7000
Connection ~ 5250 7000
Wire Wire Line
	5775 6400 5775 6575
$EndSCHEMATC
