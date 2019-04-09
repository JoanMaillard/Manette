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
L Switch:SW_Push SW3
U 1 1 5C7D4510
P 10700 2050
F 0 "SW3" H 10700 2335 50  0000 C CNN
F 1 "Button_X" H 10700 2244 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 2250 50  0001 C CNN
F 3 "" H 10700 2250 50  0001 C CNN
	1    10700 2050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5C7D45CD
P 10700 2400
F 0 "SW4" H 10700 2685 50  0000 C CNN
F 1 "Button_Y" H 10700 2594 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 2600 50  0001 C CNN
F 3 "" H 10700 2600 50  0001 C CNN
	1    10700 2400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 5C7D45ED
P 10700 2750
F 0 "SW5" H 10700 3035 50  0000 C CNN
F 1 "Button_START" H 10700 2944 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 2950 50  0001 C CNN
F 3 "" H 10700 2950 50  0001 C CNN
	1    10700 2750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW6
U 1 1 5C7D4610
P 10700 3100
F 0 "SW6" H 10700 3385 50  0000 C CNN
F 1 "Button_SELECT" H 10700 3294 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 3300 50  0001 C CNN
F 3 "" H 10700 3300 50  0001 C CNN
	1    10700 3100
	1    0    0    -1  
$EndComp
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS2
U 1 1 5C7D49EC
P 8350 2100
F 0 "JS2" H 9200 2800 60  0000 R CNN
F 1 "Joystick_Right" H 9650 2650 60  0000 R CNN
F 2 "Polymanette_2018:Joystick_RSF_2-axis" H 8150 2100 60  0001 C CNN
F 3 "" H 8150 2100 60  0001 C CNN
	1    8350 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW9
U 1 1 5C7D4D48
P 10700 4250
F 0 "SW9" H 10700 4535 50  0000 C CNN
F 1 "Button_LEFT" H 10700 4444 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 4450 50  0001 C CNN
F 3 "" H 10700 4450 50  0001 C CNN
	1    10700 4250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW10
U 1 1 5C7D4D4F
P 10700 4600
F 0 "SW10" H 10700 4885 50  0000 C CNN
F 1 "Button_DOWN" H 10700 4794 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 4800 50  0001 C CNN
F 3 "" H 10700 4800 50  0001 C CNN
	1    10700 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5C7D4F76
P 10700 1350
F 0 "SW1" H 10700 1635 50  0000 C CNN
F 1 "Button_A" H 10700 1544 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 1550 50  0001 C CNN
F 3 "" H 10700 1550 50  0001 C CNN
	1    10700 1350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5C7D4F7D
P 10700 1700
F 0 "SW2" H 10700 1985 50  0000 C CNN
F 1 "Button_B" H 10700 1894 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 1900 50  0001 C CNN
F 3 "" H 10700 1900 50  0001 C CNN
	1    10700 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:Speaker LS1
U 1 1 5C7D5866
P 5550 7250
F 0 "LS1" H 5500 6950 50  0000 L CNN
F 1 "Speaker" H 5400 6850 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_T135" H 5550 7050 50  0001 C CNN
F 3 "~" H 5540 7200 50  0001 C CNN
	1    5550 7250
	1    0    0    -1  
$EndComp
Text GLabel 1500 7050 0    50   Output ~ 0
MISO
Text GLabel 1500 6550 0    50   Input ~ 0
SCK
Text GLabel 1500 6450 0    50   Input ~ 0
MOSI
Text GLabel 1500 6750 0    50   Input ~ 0
RESET
$Comp
L Switch:SW_Push SW7
U 1 1 5C7E3FD7
P 10700 3450
F 0 "SW7" H 10700 3735 50  0000 C CNN
F 1 "Button_RIGHT" H 10700 3644 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 3650 50  0001 C CNN
F 3 "" H 10700 3650 50  0001 C CNN
	1    10700 3450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW8
U 1 1 5C7E3FDE
P 10700 3850
F 0 "SW8" H 10700 4135 50  0000 C CNN
F 1 "Button_UP" H 10700 4044 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 4050 50  0001 C CNN
F 3 "" H 10700 4050 50  0001 C CNN
	1    10700 3850
	1    0    0    -1  
$EndComp
$Comp
L MCP23017:MCP23017 U3
U 1 1 5C80D464
P 6275 2725
F 0 "U3" H 6375 2740 50  0000 C CNN
F 1 "MCP23017" H 6375 2649 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6375 2675 50  0001 C CNN
F 3 "" H 6375 2675 50  0001 C CNN
	1    6275 2725
	1    0    0    -1  
$EndComp
Text GLabel 4850 1900 0    50   Input ~ 0
MISO
Text GLabel 4850 1800 0    50   Output ~ 0
SCK
Text GLabel 4850 2000 0    50   Output ~ 0
MOSI
Text GLabel 4850 1500 0    50   Output ~ 0
RESET
Text GLabel 3950 4900 2    50   Output ~ 0
SDA
Text GLabel 3950 5000 2    50   Output ~ 0
SCL
Text GLabel 5825 4675 0    50   Input ~ 0
SCL
Text GLabel 5825 4825 0    50   Input ~ 0
SDA
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U2
U 1 1 5C8105C7
P 3350 3900
F 0 "U2" H 3750 5400 50  0000 R CNN
F 1 "ATmega328-PU" H 4150 5500 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 3350 3900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3350 3900 50  0001 C CNN
	1    3350 3900
	1    0    0    -1  
$EndComp
Text GLabel 9000 4600 2    50   Output ~ 0
Left_joystick_analog_x
Text GLabel 9000 4850 2    50   Output ~ 0
Left_joystick_analog_y
Text GLabel 9150 1950 2    50   Output ~ 0
Right_joystick_analog_x
Text GLabel 9150 2200 2    50   Output ~ 0
Right_joystick_analog_y
Text GLabel 8650 1350 1    50   Input ~ 0
Right_joystick_button
Text GLabel 8500 4000 1    50   Input ~ 0
Left_joystick_button
Text GLabel 9775 5525 0    50   Input ~ 0
+5V
Text GLabel 9775 5325 0    50   Output ~ 0
Right_trigger
Text GLabel 9775 5950 0    50   Output ~ 0
Left_trigger
Text GLabel 7900 950  1    50   Input ~ 0
+5V
Text GLabel 7750 3600 1    50   Input ~ 0
+5V
Wire Wire Line
	7900 1350 8000 1350
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS1
U 1 1 5C7D4903
P 8200 4750
F 0 "JS1" H 9050 5450 60  0000 R CNN
F 1 "Joystick_Left" H 9450 5300 60  0000 R CNN
F 2 "Polymanette_2018:Joystick_RSF_2-axis" H 8000 4750 60  0001 C CNN
F 3 "" H 8000 4750 60  0001 C CNN
	1    8200 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 5400 7750 5400
Text GLabel 3950 3600 2    50   Input ~ 0
R_joystick_analog_x
Text GLabel 3950 3700 2    50   Input ~ 0
R_joystick_analog_y
Text GLabel 5825 3325 0    50   Output ~ 0
R_joystick_button
Text GLabel 3950 3800 2    50   Input ~ 0
L_joystick_analog_x
Text GLabel 3950 3900 2    50   Input ~ 0
L_joystick_analog_y
Text GLabel 5825 3475 0    50   Output ~ 0
L_joystick_button
Text GLabel 3950 4100 2    50   Input ~ 0
L_trigger
Text GLabel 3950 4000 2    50   Input ~ 0
R_trigger
$Comp
L Transistor_Array:ULN2803A U5
U 1 1 5C82C60F
P 3850 6750
F 0 "U5" H 3850 7317 50  0000 C CNN
F 1 "ULN2803A" H 3850 7226 50  0000 C CNN
F 2 "Package_DIP:DIP-18_W7.62mm" H 3900 6100 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2803a.pdf" H 3950 6550 50  0001 C CNN
	1    3850 6750
	1    0    0    -1  
$EndComp
$Comp
L Device:Resonator Y1
U 1 1 5C82CAB8
P 4650 3250
F 0 "Y1" V 4850 3100 50  0000 L CNN
F 1 "Resonator" V 4950 2950 50  0000 L CNN
F 2 "Crystal:Resonator-3Pin_W6.0mm_H3.0mm" H 4625 3250 50  0001 C CNN
F 3 "~" H 4625 3250 50  0001 C CNN
	1    4650 3250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5C82D22E
P 4950 3350
F 0 "#PWR0110" H 4950 3100 50  0001 C CNN
F 1 "GND" H 4955 3177 50  0000 C CNN
F 2 "" H 4950 3350 50  0001 C CNN
F 3 "" H 4950 3350 50  0001 C CNN
	1    4950 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3350 4950 3250
Wire Wire Line
	4950 3250 4850 3250
$Comp
L Device:LED D1
U 1 1 5C83283C
P 5300 6550
F 0 "D1" H 5300 6640 50  0000 C CNN
F 1 "LED_B" H 5300 6710 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 5300 6550 50  0001 C CNN
F 3 "~" H 5300 6550 50  0001 C CNN
	1    5300 6550
	1    0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5C8328E9
P 4800 6550
F 0 "R1" H 4870 6596 50  0000 L CNN
F 1 "R" H 4870 6505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4730 6550 50  0001 C CNN
F 3 "~" H 4800 6550 50  0001 C CNN
	1    4800 6550
	0    -1   1    0   
$EndComp
Text GLabel 2325 1975 2    50   Output ~ 0
+5V
$Comp
L Manette_arcade:SW_Push SW13
U 1 1 5C83B5DB
P 10700 4975
F 0 "SW13" H 10700 5260 50  0000 C CNN
F 1 "Calib" H 10700 5169 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 5175 50  0001 C CNN
F 3 "" H 10700 5175 50  0001 C CNN
	1    10700 4975
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 6550 5800 6300
$Comp
L power:GND #PWR0111
U 1 1 5C8638D7
P 3850 7450
F 0 "#PWR0111" H 3850 7200 50  0001 C CNN
F 1 "GND" H 3855 7277 50  0000 C CNN
F 2 "" H 3850 7450 50  0001 C CNN
F 3 "" H 3850 7450 50  0001 C CNN
	1    3850 7450
	1    0    0    -1  
$EndComp
Text GLabel 3450 6750 0    50   Input ~ 0
Buzzer
$Comp
L Device:R R3
U 1 1 5C865F77
P 4800 7250
F 0 "R3" H 4870 7296 50  0000 L CNN
F 1 "R" H 4870 7205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4730 7250 50  0001 C CNN
F 3 "~" H 4800 7250 50  0001 C CNN
	1    4800 7250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5C86BA29
P 5300 6850
F 0 "D2" H 5300 6950 50  0000 C CNN
F 1 "LED_R" H 5300 7020 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 5300 6850 50  0001 C CNN
F 3 "~" H 5300 6850 50  0001 C CNN
	1    5300 6850
	1    0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5C86BA30
P 4800 6850
F 0 "R2" H 4870 6896 50  0000 L CNN
F 1 "R" H 4870 6805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4730 6850 50  0001 C CNN
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
L Device:D D3
U 1 1 5C878C9C
P 5000 7400
F 0 "D3" H 5000 7600 50  0000 C CNN
F 1 "D" H 5000 7525 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P10.16mm_Horizontal" H 5000 7400 50  0001 C CNN
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
Text GLabel 5825 3625 0    50   Output ~ 0
Button_LEFT
Text GLabel 5825 3775 0    50   Output ~ 0
Button_UP
Text GLabel 5825 3925 0    50   Output ~ 0
Button_RIGHT
Text GLabel 5825 4075 0    50   Output ~ 0
Button_DOWN
Text GLabel 6925 3025 2    50   Output ~ 0
Button_A
Text GLabel 6925 3175 2    50   Output ~ 0
Button_B
Text GLabel 6925 3325 2    50   Output ~ 0
Button_Y
Text GLabel 6925 3475 2    50   Output ~ 0
Button_X
Text GLabel 6925 3925 2    50   Output ~ 0
Button_START
Text GLabel 6925 4075 2    50   Output ~ 0
Button_SELECT
Text GLabel 6925 3625 2    50   Output ~ 0
R_Bumper
Text GLabel 6925 3775 2    50   Output ~ 0
L_Bumper
Wire Wire Line
	4650 3400 4650 3500
Wire Wire Line
	4650 3500 4300 3500
Wire Wire Line
	4300 3500 4300 3400
Wire Wire Line
	4300 3400 3950 3400
Wire Wire Line
	4650 3100 4650 3050
Wire Wire Line
	4650 3050 4300 3050
Wire Wire Line
	4300 3050 4300 3300
Wire Wire Line
	4300 3300 3950 3300
$Comp
L Regulator_Switching:R-78E5.0-0.5 U7
U 1 1 5C9AC915
P 2025 1975
F 0 "U7" H 2025 2217 50  0000 C CNN
F 1 "R-78E5.0-0.5" H 2025 2126 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 2075 1725 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78Exx-0.5.pdf" H 2025 1975 50  0001 C CNN
	1    2025 1975
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5C9B9F3C
P 2025 2275
F 0 "#PWR0112" H 2025 2025 50  0001 C CNN
F 1 "GND" H 2030 2102 50  0000 C CNN
F 2 "" H 2025 2275 50  0001 C CNN
F 3 "" H 2025 2275 50  0001 C CNN
	1    2025 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	11100 4975 10900 4975
Wire Wire Line
	10900 4600 11100 4600
Wire Wire Line
	10900 4250 11100 4250
Wire Wire Line
	11100 4250 11100 4600
Connection ~ 11100 4600
Wire Wire Line
	10900 3850 11100 3850
Wire Wire Line
	11100 3850 11100 4250
Connection ~ 11100 4250
Wire Wire Line
	10900 3450 11100 3450
Wire Wire Line
	11100 3450 11100 3850
Connection ~ 11100 3850
Wire Wire Line
	11100 3450 11100 3100
Wire Wire Line
	11100 3100 10900 3100
Connection ~ 11100 3450
Wire Wire Line
	11100 3100 11100 2750
Wire Wire Line
	11100 2750 10900 2750
Connection ~ 11100 3100
Wire Wire Line
	10900 2400 11100 2400
Wire Wire Line
	11100 2400 11100 2750
Connection ~ 11100 2750
Wire Wire Line
	10900 2050 11100 2050
Wire Wire Line
	11100 2050 11100 2400
Connection ~ 11100 2400
Wire Wire Line
	10900 1700 11100 1700
Wire Wire Line
	11100 1700 11100 2050
Connection ~ 11100 2050
Wire Wire Line
	10900 1350 11100 1350
Wire Wire Line
	11100 1350 11100 1700
Connection ~ 11100 1700
Text GLabel 10500 1350 0    50   Input ~ 0
Button_A
Text GLabel 10500 1700 0    50   Input ~ 0
Button_B
Text GLabel 10500 2400 0    50   Input ~ 0
Button_Y
Text GLabel 10500 2050 0    50   Input ~ 0
Button_X
Text GLabel 10500 2750 0    50   Input ~ 0
Button_START
Text GLabel 10500 3100 0    50   Input ~ 0
Button_SELECT
Text GLabel 9775 5425 0    50   Input ~ 0
R_Bumper
Text GLabel 9775 6050 0    50   Input ~ 0
L_Bumper
Text GLabel 10500 4250 0    50   Input ~ 0
Button_LEFT
Text GLabel 10500 3850 0    50   Input ~ 0
Button_UP
Text GLabel 10500 3450 0    50   Input ~ 0
Button_RIGHT
Text GLabel 10500 4600 0    50   Input ~ 0
Button_DOWN
Text Label 9850 800  0    197  ~ 0
Inputs
Text GLabel 1500 6650 0    50   Input ~ 0
DC
Text GLabel 4850 1600 0    50   Output ~ 0
DC
Text GLabel 1500 6850 0    50   Input ~ 0
OLEDCS
Text GLabel 4850 1700 0    50   Output ~ 0
OLEDCS
Text GLabel 3350 1875 1    50   Input ~ 0
+5V
Text GLabel 4850 1400 0    50   Input ~ 0
SDCS
Text GLabel 1500 6950 0    50   Input ~ 0
SDCS
Text Label 650  6300 0    197  ~ 0
Outputs
Text GLabel 7050 1100 2    50   Input ~ 0
RX_ESP32
Text GLabel 7050 1000 2    50   Input ~ 0
TX_ESP32
Text GLabel 875  7275 0    50   Input ~ 0
+3.3V
Text GLabel 1950 3575 2    50   Input ~ 0
+3.3V
Text GLabel 7225 4525 2    50   Input ~ 0
+5V
Text GLabel 1050 3575 0    50   Input ~ 0
+5V
Text GLabel 1950 3775 2    50   Input ~ 0
RX_ESP32
Text GLabel 1950 3675 2    50   Input ~ 0
TX_ESP32
Text GLabel 1050 3775 0    50   Input ~ 0
TX_Atmega
Text GLabel 1050 3675 0    50   Input ~ 0
RX_Atmega
$Comp
L Regulator_Switching:R-783.3-0.5 U6
U 1 1 5CB0E72E
P 2025 1125
F 0 "U6" H 2025 1367 50  0000 C CNN
F 1 "R-783.3-0.5" H 2025 1276 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 2075 875 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78xx-0.5.pdf" H 2025 1125 50  0001 C CNN
	1    2025 1125
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5CB1A915
P 2025 1425
F 0 "#PWR0117" H 2025 1175 50  0001 C CNN
F 1 "GND" H 2030 1252 50  0000 C CNN
F 2 "" H 2025 1425 50  0001 C CNN
F 3 "" H 2025 1425 50  0001 C CNN
	1    2025 1425
	1    0    0    -1  
$EndComp
Wire Wire Line
	1625 1975 1625 1125
Wire Wire Line
	1625 1125 1725 1125
Connection ~ 1625 1975
Wire Wire Line
	1625 1975 1725 1975
Text GLabel 2325 1125 2    50   Output ~ 0
+3.3V
Text Label 750  750  0    197  ~ 0
Power
Wire Notes Line
	7600 500  7600 6500
Text Label 500  3250 0    197  ~ 0
SerialComm
Text Label 3125 750  0    197  ~ 0
Command
Text GLabel 5350 4225 0    50   Input ~ 0
+5V
Wire Wire Line
	7850 4000 7750 4000
Text GLabel 7050 1200 2    50   Output ~ 0
Buzzer
Text GLabel 7050 1300 2    50   Output ~ 0
Power
Text GLabel 7050 1400 2    50   Output ~ 0
Connected
Wire Notes Line
	500  5975 7600 5975
Wire Wire Line
	1625 1975 1625 2625
Wire Wire Line
	1625 2625 2250 2625
Text GLabel 2250 2625 2    50   Output ~ 0
+9V
Text GLabel 4450 2200 0    50   Input ~ 0
+9V
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5CA7532E
P 825 4425
F 0 "#FLG0101" H 825 4500 50  0001 C CNN
F 1 "PWR_FLAG" H 825 4599 50  0000 C CNN
F 2 "" H 825 4425 50  0001 C CNN
F 3 "~" H 825 4425 50  0001 C CNN
	1    825  4425
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5CA753AE
P 1225 4425
F 0 "#FLG0102" H 1225 4500 50  0001 C CNN
F 1 "PWR_FLAG" H 1225 4599 50  0000 C CNN
F 2 "" H 1225 4425 50  0001 C CNN
F 3 "~" H 1225 4425 50  0001 C CNN
	1    1225 4425
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5CA77741
P 1625 4425
F 0 "#FLG0103" H 1625 4500 50  0001 C CNN
F 1 "PWR_FLAG" H 1625 4599 50  0000 C CNN
F 2 "" H 1625 4425 50  0001 C CNN
F 3 "~" H 1625 4425 50  0001 C CNN
	1    1625 4425
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5CA79B65
P 2025 4425
F 0 "#FLG0104" H 2025 4500 50  0001 C CNN
F 1 "PWR_FLAG" H 2025 4599 50  0000 C CNN
F 2 "" H 2025 4425 50  0001 C CNN
F 3 "~" H 2025 4425 50  0001 C CNN
	1    2025 4425
	1    0    0    -1  
$EndComp
Text GLabel 1625 4425 3    50   Input ~ 0
+3.3V
Text GLabel 1225 4425 3    50   Input ~ 0
+5V
Text GLabel 825  4425 3    50   Input ~ 0
+9V
$Comp
L power:GND #PWR0102
U 1 1 5C816B1D
P 2025 4425
F 0 "#PWR0102" H 2025 4175 50  0001 C CNN
F 1 "GND" H 2030 4252 50  0000 C CNN
F 2 "" H 2025 4425 50  0001 C CNN
F 3 "" H 2025 4425 50  0001 C CNN
	1    2025 4425
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5CB04B27
P 2075 3900
F 0 "#PWR0116" H 2075 3650 50  0001 C CNN
F 1 "GND" H 2080 3727 50  0000 C CNN
F 2 "" H 2075 3900 50  0001 C CNN
F 3 "" H 2075 3900 50  0001 C CNN
	1    2075 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 7350 1500 7350
Wire Wire Line
	1350 7450 1500 7450
Wire Wire Line
	1350 7550 1350 7450
$Comp
L power:GND #PWR0101
U 1 1 5C7E33B4
P 1350 7550
F 0 "#PWR0101" H 1350 7300 50  0001 C CNN
F 1 "GND" H 1355 7377 50  0000 C CNN
F 2 "" H 1350 7550 50  0001 C CNN
F 3 "" H 1350 7550 50  0001 C CNN
	1    1350 7550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5C81DB7C
P 9700 5650
F 0 "#PWR0108" H 9700 5400 50  0001 C CNN
F 1 "GND" H 9705 5477 50  0000 C CNN
F 2 "" H 9700 5650 50  0001 C CNN
F 3 "" H 9700 5650 50  0001 C CNN
	1    9700 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5C9E80F4
P 11100 5175
F 0 "#PWR0113" H 11100 4925 50  0001 C CNN
F 1 "GND" H 11105 5002 50  0000 C CNN
F 2 "" H 11100 5175 50  0001 C CNN
F 3 "" H 11100 5175 50  0001 C CNN
	1    11100 5175
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5C817E41
P 7750 5500
F 0 "#PWR0104" H 7750 5250 50  0001 C CNN
F 1 "GND" H 7755 5327 50  0000 C CNN
F 2 "" H 7750 5500 50  0001 C CNN
F 3 "" H 7750 5500 50  0001 C CNN
	1    7750 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2750 7900 2750
$Comp
L power:GND #PWR0105
U 1 1 5C818469
P 7900 2825
F 0 "#PWR0105" H 7900 2575 50  0001 C CNN
F 1 "GND" H 7905 2652 50  0000 C CNN
F 2 "" H 7900 2825 50  0001 C CNN
F 3 "" H 7900 2825 50  0001 C CNN
	1    7900 2825
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5C816DC7
P 5450 4525
F 0 "#PWR0103" H 5450 4275 50  0001 C CNN
F 1 "GND" H 5455 4352 50  0000 C CNN
F 2 "" H 5450 4525 50  0001 C CNN
F 3 "" H 5450 4525 50  0001 C CNN
	1    5450 4525
	1    0    0    -1  
$EndComp
Wire Wire Line
	7075 5025 7075 4975
Wire Wire Line
	7075 4975 7075 4825
Connection ~ 7075 4975
Wire Wire Line
	6925 4975 7075 4975
Wire Wire Line
	7075 4825 6925 4825
Connection ~ 7075 4825
Wire Wire Line
	7075 4675 7075 4825
Wire Wire Line
	6925 4675 7075 4675
$Comp
L power:GND #PWR0115
U 1 1 5CABEA89
P 7075 5025
F 0 "#PWR0115" H 7075 4775 50  0001 C CNN
F 1 "GND" H 7080 4852 50  0000 C CNN
F 2 "" H 7075 5025 50  0001 C CNN
F 3 "" H 7075 5025 50  0001 C CNN
	1    7075 5025
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 5CB302EA
P 3350 5400
F 0 "#PWR0118" H 3350 5150 50  0001 C CNN
F 1 "GND" H 3355 5227 50  0000 C CNN
F 2 "" H 3350 5400 50  0001 C CNN
F 3 "" H 3350 5400 50  0001 C CNN
	1    3350 5400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5CB34D45
P 775 1225
F 0 "J1" H 695 900 50  0000 C CNN
F 1 "Power" H 695 991 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 775 1225 50  0001 C CNN
F 3 "~" H 775 1225 50  0001 C CNN
	1    775  1225
	-1   0    0    1   
$EndComp
Wire Notes Line
	475  4175 2700 4175
Connection ~ 1625 1125
$Comp
L power:GND #PWR0119
U 1 1 5CB6DBAC
P 1100 1325
F 0 "#PWR0119" H 1100 1075 50  0001 C CNN
F 1 "GND" H 1105 1152 50  0000 C CNN
F 2 "" H 1100 1325 50  0001 C CNN
F 3 "" H 1100 1325 50  0001 C CNN
	1    1100 1325
	1    0    0    -1  
$EndComp
Wire Wire Line
	975  1225 1100 1225
Wire Wire Line
	1100 1225 1100 1325
Text GLabel 3950 4800 2    50   Output ~ 0
Calib
Text GLabel 10500 4975 0    50   Input ~ 0
Calib
$Comp
L ESP32:ESP32 U1
U 1 1 5CABDA52
P 5950 1050
F 0 "U1" H 5950 1525 50  0000 C CNN
F 1 "ESP32" H 5950 1434 50  0000 C CNN
F 2 "ESP32:ESP32" H 5350 1000 50  0001 C CNN
F 3 "" H 5350 1000 50  0001 C CNN
	1    5950 1050
	1    0    0    -1  
$EndComp
$Comp
L OLED:OLED_Display U4
U 1 1 5CAC3235
P 1800 7000
F 0 "U4" H 2028 7076 50  0000 L CNN
F 1 "OLED_Display" H 2028 6985 50  0000 L CNN
F 2 "OLED:OLED RGB" H 1800 7000 50  0001 C CNN
F 3 "" H 1800 7000 50  0001 C CNN
	1    1800 7000
	1    0    0    -1  
$EndComp
$Comp
L PCA9306:PCA9306 U8
U 1 1 5CABE2FF
P 1500 3775
F 0 "U8" H 1500 4200 50  0000 C CNN
F 1 "PCA9306" H 1500 4109 50  0000 C CNN
F 2 "PCA9306:PCA9306" H 1300 3775 50  0001 C CNN
F 3 "" H 1300 3775 50  0001 C CNN
	1    1500 3775
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3875 2075 3875
Wire Wire Line
	2075 3875 2075 3900
Wire Notes Line
	2700 4175 2700 475 
Wire Notes Line
	475  2850 2700 2850
Wire Wire Line
	8450 2750 8000 2750
Connection ~ 8000 2750
Wire Wire Line
	7900 2825 7900 2750
Connection ~ 7900 2750
Wire Wire Line
	8300 5400 7850 5400
Connection ~ 7850 5400
Wire Wire Line
	7750 5500 7750 5400
Connection ~ 7750 5400
Wire Wire Line
	9700 5650 9700 5625
Wire Wire Line
	9700 5625 9775 5625
Wire Wire Line
	11100 4600 11100 4975
Wire Wire Line
	11100 5175 11100 4975
Connection ~ 11100 4975
Wire Wire Line
	975  1125 1625 1125
$Comp
L Connector:Screw_Terminal_01x04 J3
U 1 1 5CB5236C
P 9975 6050
F 0 "J3" H 10055 6042 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 10055 5951 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-4_P5.08mm" H 9975 6050 50  0001 C CNN
F 3 "~" H 9975 6050 50  0001 C CNN
	1    9975 6050
	1    0    0    -1  
$EndComp
Text GLabel 9775 6150 0    50   Input ~ 0
+5V
$Comp
L power:GND #PWR0106
U 1 1 5CB5E3D5
P 9700 6275
F 0 "#PWR0106" H 9700 6025 50  0001 C CNN
F 1 "GND" H 9705 6102 50  0000 C CNN
F 2 "" H 9700 6275 50  0001 C CNN
F 3 "" H 9700 6275 50  0001 C CNN
	1    9700 6275
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 6275 9700 6250
Wire Wire Line
	9700 6250 9775 6250
$Comp
L Connector:Screw_Terminal_01x04 J2
U 1 1 5CB6269D
P 9975 5425
F 0 "J2" H 10055 5417 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 10055 5326 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-4_P5.08mm" H 9975 5425 50  0001 C CNN
F 3 "~" H 9975 5425 50  0001 C CNN
	1    9975 5425
	1    0    0    -1  
$EndComp
Text GLabel 3950 4500 2    50   Output ~ 0
TX_Atmega
Text GLabel 3950 4400 2    50   Output ~ 0
RX_Atmega
$Comp
L Device:R R4
U 1 1 5CB92D6D
P 7075 4525
F 0 "R4" V 6868 4525 50  0000 C CNN
F 1 "R" V 6959 4525 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 7005 4525 50  0001 C CNN
F 3 "~" H 7075 4525 50  0001 C CNN
	1    7075 4525
	0    1    1    0   
$EndComp
Text GLabel 5800 6300 1    50   Input ~ 0
+3.3V
$Comp
L Device:C C2
U 1 1 5CBA884D
P 3075 2125
F 0 "C2" H 3190 2171 50  0000 L CNN
F 1 "C" H 3190 2080 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 3113 1975 50  0001 C CNN
F 3 "~" H 3075 2125 50  0001 C CNN
	1    3075 2125
	1    0    0    -1  
$EndComp
Wire Wire Line
	3075 1975 3075 1950
Wire Wire Line
	3075 1950 3350 1950
Wire Wire Line
	3350 1950 3350 1875
Connection ~ 3350 1950
$Comp
L power:GND #PWR0107
U 1 1 5CBB5A66
P 3075 2275
F 0 "#PWR0107" H 3075 2025 50  0001 C CNN
F 1 "GND" H 3080 2102 50  0000 C CNN
F 2 "" H 3075 2275 50  0001 C CNN
F 3 "" H 3075 2275 50  0001 C CNN
	1    3075 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1950 3350 2400
$Comp
L power:GND #PWR0109
U 1 1 5CBC802A
P 4550 2500
F 0 "#PWR0109" H 4550 2250 50  0001 C CNN
F 1 "GND" H 4555 2327 50  0000 C CNN
F 2 "" H 4550 2500 50  0001 C CNN
F 3 "" H 4550 2500 50  0001 C CNN
	1    4550 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CBC80B3
P 4550 2350
F 0 "C1" H 4665 2396 50  0000 L CNN
F 1 "C" H 4665 2305 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 4588 2200 50  0001 C CNN
F 3 "~" H 4550 2350 50  0001 C CNN
	1    4550 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2200 4550 2200
Connection ~ 4550 2200
Wire Wire Line
	4550 2200 4850 2200
Wire Wire Line
	4850 2100 4775 2100
Wire Wire Line
	4775 2100 4775 2500
Wire Wire Line
	4775 2500 4550 2500
Connection ~ 4550 2500
$Comp
L Device:C C3
U 1 1 5CBE21EC
P 5450 4375
F 0 "C3" H 5565 4421 50  0000 L CNN
F 1 "C" H 5565 4330 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 5488 4225 50  0001 C CNN
F 3 "~" H 5450 4375 50  0001 C CNN
	1    5450 4375
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4225 5450 4225
Wire Wire Line
	5450 4225 5825 4225
Connection ~ 5450 4225
Wire Wire Line
	5825 4375 5750 4375
Wire Wire Line
	5750 4525 5450 4525
Wire Wire Line
	5750 4375 5750 4525
Connection ~ 5450 4525
$Comp
L Device:C C4
U 1 1 5CBEE334
P 8125 1175
F 0 "C4" H 8240 1221 50  0000 L CNN
F 1 "C" H 8240 1130 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 8163 1025 50  0001 C CNN
F 3 "~" H 8125 1175 50  0001 C CNN
	1    8125 1175
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5CBF3C35
P 8125 1325
F 0 "#PWR0114" H 8125 1075 50  0001 C CNN
F 1 "GND" H 8130 1152 50  0000 C CNN
F 2 "" H 8125 1325 50  0001 C CNN
F 3 "" H 8125 1325 50  0001 C CNN
	1    8125 1325
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5CBF68CD
P 8000 3825
F 0 "C5" H 8115 3871 50  0000 L CNN
F 1 "C" H 8115 3780 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 8038 3675 50  0001 C CNN
F 3 "~" H 8000 3825 50  0001 C CNN
	1    8000 3825
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5CBF68D4
P 8000 3975
F 0 "#PWR0120" H 8000 3725 50  0001 C CNN
F 1 "GND" H 8005 3802 50  0000 C CNN
F 2 "" H 8000 3975 50  0001 C CNN
F 3 "" H 8000 3975 50  0001 C CNN
	1    8000 3975
	1    0    0    -1  
$EndComp
Wire Wire Line
	8125 1025 8125 950 
Wire Wire Line
	8125 950  7900 950 
Wire Wire Line
	7900 1350 7900 950 
Connection ~ 7900 1350
Connection ~ 7750 4000
Wire Wire Line
	8000 3600 7750 3600
Wire Wire Line
	7750 3600 7750 4000
Wire Wire Line
	8000 3675 8000 3600
$Comp
L Device:C C6
U 1 1 5CC1D714
P 1025 7425
F 0 "C6" H 1140 7471 50  0000 L CNN
F 1 "C" H 1140 7380 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 1063 7275 50  0001 C CNN
F 3 "~" H 1025 7425 50  0001 C CNN
	1    1025 7425
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5CC1D71B
P 1025 7575
F 0 "#PWR0121" H 1025 7325 50  0001 C CNN
F 1 "GND" H 1030 7402 50  0000 C CNN
F 2 "" H 1025 7575 50  0001 C CNN
F 3 "" H 1025 7575 50  0001 C CNN
	1    1025 7575
	1    0    0    -1  
$EndComp
Wire Wire Line
	875  7275 1025 7275
Wire Wire Line
	1025 7275 1350 7275
Wire Wire Line
	1350 7275 1350 7350
Connection ~ 1025 7275
NoConn ~ 3950 2700
NoConn ~ 3950 2800
NoConn ~ 3950 2900
NoConn ~ 3950 3000
NoConn ~ 3950 3100
NoConn ~ 3950 3200
NoConn ~ 3950 4200
NoConn ~ 3950 4600
NoConn ~ 3950 4700
NoConn ~ 3950 5100
NoConn ~ 4850 1300
NoConn ~ 4850 1200
NoConn ~ 4850 1100
NoConn ~ 4850 1000
NoConn ~ 4850 900 
NoConn ~ 4850 800 
NoConn ~ 7050 2200
NoConn ~ 7050 2100
NoConn ~ 7050 2000
NoConn ~ 7050 1900
NoConn ~ 7050 1800
NoConn ~ 7050 1700
NoConn ~ 7050 1600
NoConn ~ 7050 1500
NoConn ~ 7050 900 
NoConn ~ 7050 800 
NoConn ~ 8450 1350
NoConn ~ 8650 2750
NoConn ~ 8500 5400
NoConn ~ 8300 4000
NoConn ~ 1500 7250
NoConn ~ 1500 7150
NoConn ~ 3450 7250
NoConn ~ 3450 7150
NoConn ~ 3450 7050
NoConn ~ 3450 6950
NoConn ~ 3450 6850
NoConn ~ 4250 6450
NoConn ~ 4250 6850
NoConn ~ 4250 6950
NoConn ~ 4250 7050
NoConn ~ 4250 7150
NoConn ~ 4250 7250
NoConn ~ 1050 3875
NoConn ~ 5825 3175
NoConn ~ 5825 3025
NoConn ~ 6925 4375
NoConn ~ 6925 4225
$EndSCHEMATC
