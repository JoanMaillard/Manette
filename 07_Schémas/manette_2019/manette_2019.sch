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
F 1 "Joystick_RSF_2-Axis" H 9950 2650 60  0000 R CNN
F 2 "Polymanette_2018:Joystick_RSF_2-axis" H 8150 2100 60  0001 C CNN
F 3 "" H 8150 2100 60  0001 C CNN
	1    8350 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 5C7D4ACF
P 8800 6000
F 0 "RV1" H 8730 6046 50  0000 R CNN
F 1 "L_trigger" H 8730 5955 50  0000 R CNN
F 2 "" H 8800 6000 50  0001 C CNN
F 3 "~" H 8800 6000 50  0001 C CNN
	1    8800 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV2
U 1 1 5C7D4B89
P 9900 6000
F 0 "RV2" H 9830 6046 50  0000 R CNN
F 1 "R_trigger" H 9830 5955 50  0000 R CNN
F 2 "" H 9900 6000 50  0001 C CNN
F 3 "~" H 9900 6000 50  0001 C CNN
	1    9900 6000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW11
U 1 1 5C7D4D3A
P 10700 4950
F 0 "SW11" H 10700 5235 50  0000 C CNN
F 1 "R_bumper" H 10700 5144 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 5150 50  0001 C CNN
F 3 "" H 10700 5150 50  0001 C CNN
	1    10700 4950
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
Text GLabel 8800 5850 1    50   Input ~ 0
+5V
Text GLabel 9900 5850 1    50   Input ~ 0
+5V
Text GLabel 10050 6000 2    50   Output ~ 0
Right_trigger
Text GLabel 8950 6000 2    50   Output ~ 0
Left_trigger
Text GLabel 7900 1350 1    50   Input ~ 0
+5V
Text GLabel 7750 4000 1    50   Input ~ 0
+5V
Wire Wire Line
	7900 1350 8000 1350
$Comp
L Manette_arcade:Joystick_RSF_2-Axis JS1
U 1 1 5C7D4903
P 8200 4750
F 0 "JS1" H 9050 5450 60  0000 R CNN
F 1 "Joystick_RSF_2-Axis" H 9800 5300 60  0000 R CNN
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
L Switch:SW_Push SW12
U 1 1 5C7D4D41
P 10700 5300
F 0 "SW12" H 10700 5585 50  0000 C CNN
F 1 "L_bumper" H 10700 5494 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 10700 5500 50  0001 C CNN
F 3 "" H 10700 5500 50  0001 C CNN
	1    10700 5300
	1    0    0    -1  
$EndComp
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
F 2 "" H 4625 3250 50  0001 C CNN
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
$Comp
L Switch:SW_DPST_x2 SW14
U 1 1 5C83593E
P 1275 1125
F 0 "SW14" V 1325 1350 50  0000 C CNN
F 1 "On/Off" V 1225 1350 50  0000 C CNN
F 2 "" H 1275 1125 50  0001 C CNN
F 3 "" H 1275 1125 50  0001 C CNN
	1    1275 1125
	1    0    0    -1  
$EndComp
Text GLabel 2325 1975 2    50   Output ~ 0
+5V
$Comp
L Manette_arcade:SW_Push SW13
U 1 1 5C83B5DB
P 10700 5650
F 0 "SW13" H 10700 5935 50  0000 C CNN
F 1 "Calib" H 10700 5844 50  0000 C CNN
F 2 "" H 10700 5850 50  0001 C CNN
F 3 "" H 10700 5850 50  0001 C CNN
	1    10700 5650
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
	11100 5750 11100 5650
Wire Wire Line
	11100 5650 10900 5650
Wire Wire Line
	10900 5300 11100 5300
Wire Wire Line
	11100 5300 11100 5650
Connection ~ 11100 5650
Wire Wire Line
	10900 4950 11100 4950
Wire Wire Line
	11100 4950 11100 5300
Connection ~ 11100 5300
Wire Wire Line
	10900 4600 11100 4600
Wire Wire Line
	11100 4600 11100 4950
Connection ~ 11100 4950
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
Text GLabel 10500 4950 0    50   Input ~ 0
R_Bumper
Text GLabel 10500 5300 0    50   Input ~ 0
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
Text GLabel 3350 2400 1    50   Input ~ 0
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
$Comp
L Interface:PCA9306 U8
U 1 1 5CA9EA73
P 1400 4200
F 0 "U8" H 800 3950 50  0000 C CNN
F 1 "PCA9306" H 800 3850 50  0000 C CNN
F 2 "" H 1000 4550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/pca9306.pdf" H 1100 4650 50  0001 C CNN
	1    1400 4200
	1    0    0    -1  
$EndComp
Text GLabel 1350 7350 0    50   Input ~ 0
+3.3V
Text GLabel 1500 3550 1    50   Input ~ 0
3.3V
Text GLabel 6925 4525 2    50   Input ~ 0
+5V
Text GLabel 5800 6300 1    50   Input ~ 0
+5V
Text GLabel 1300 3550 1    50   Input ~ 0
+5V
Text GLabel 1800 4300 2    50   Input ~ 0
RX_ESP32
Text GLabel 1800 4200 2    50   Input ~ 0
TX_ESP32
Text GLabel 1000 4300 0    50   Input ~ 0
TX_Atmega
Text GLabel 1000 4200 0    50   Input ~ 0
RX_Atmega
Wire Wire Line
	1300 3700 1300 3550
$Comp
L Device:R R4
U 1 1 5CAEC44C
P 1900 3850
F 0 "R4" H 1830 3804 50  0000 R CNN
F 1 "200K" H 1830 3895 50  0000 R CNN
F 2 "" V 1830 3850 50  0001 C CNN
F 3 "~" H 1900 3850 50  0001 C CNN
	1    1900 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	1500 3550 1500 3650
Wire Wire Line
	1900 3700 1900 3650
Wire Wire Line
	1900 3650 1500 3650
Connection ~ 1500 3650
Wire Wire Line
	1500 3650 1500 3700
Wire Wire Line
	1800 4100 1900 4100
Wire Wire Line
	1900 4100 1900 4000
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
Text GLabel 5800 4225 0    50   Input ~ 0
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
	500  6050 7600 6050
Wire Wire Line
	1625 1975 1625 2625
Wire Wire Line
	1625 2625 2250 2625
Text GLabel 2250 2625 2    50   Output ~ 0
+10V
Text GLabel 4850 2200 0    50   Input ~ 0
+10V
Wire Notes Line
	2675 475  2675 4950
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5CA7532E
P 775 5225
F 0 "#FLG0101" H 775 5300 50  0001 C CNN
F 1 "PWR_FLAG" H 775 5399 50  0000 C CNN
F 2 "" H 775 5225 50  0001 C CNN
F 3 "~" H 775 5225 50  0001 C CNN
	1    775  5225
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5CA753AE
P 1175 5225
F 0 "#FLG0102" H 1175 5300 50  0001 C CNN
F 1 "PWR_FLAG" H 1175 5399 50  0000 C CNN
F 2 "" H 1175 5225 50  0001 C CNN
F 3 "~" H 1175 5225 50  0001 C CNN
	1    1175 5225
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5CA77741
P 1575 5225
F 0 "#FLG0103" H 1575 5300 50  0001 C CNN
F 1 "PWR_FLAG" H 1575 5399 50  0000 C CNN
F 2 "" H 1575 5225 50  0001 C CNN
F 3 "~" H 1575 5225 50  0001 C CNN
	1    1575 5225
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5CA79B65
P 1975 5225
F 0 "#FLG0104" H 1975 5300 50  0001 C CNN
F 1 "PWR_FLAG" H 1975 5399 50  0000 C CNN
F 2 "" H 1975 5225 50  0001 C CNN
F 3 "~" H 1975 5225 50  0001 C CNN
	1    1975 5225
	1    0    0    -1  
$EndComp
Text GLabel 1575 5225 3    50   Input ~ 0
+3.3V
Text GLabel 1175 5225 3    50   Input ~ 0
+5V
Text GLabel 775  5225 3    50   Input ~ 0
+10V
$Comp
L power:GND #PWR0102
U 1 1 5C816B1D
P 1975 5225
F 0 "#PWR0102" H 1975 4975 50  0001 C CNN
F 1 "GND" H 1980 5052 50  0000 C CNN
F 2 "" H 1975 5225 50  0001 C CNN
F 3 "" H 1975 5225 50  0001 C CNN
	1    1975 5225
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5CB04B27
P 1400 4700
F 0 "#PWR0116" H 1400 4450 50  0001 C CNN
F 1 "GND" H 1405 4527 50  0000 C CNN
F 2 "" H 1400 4700 50  0001 C CNN
F 3 "" H 1400 4700 50  0001 C CNN
	1    1400 4700
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
P 8800 6150
F 0 "#PWR0108" H 8800 5900 50  0001 C CNN
F 1 "GND" H 8805 5977 50  0000 C CNN
F 2 "" H 8800 6150 50  0001 C CNN
F 3 "" H 8800 6150 50  0001 C CNN
	1    8800 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5C81DD4B
P 9900 6150
F 0 "#PWR0109" H 9900 5900 50  0001 C CNN
F 1 "GND" H 9905 5977 50  0000 C CNN
F 2 "" H 9900 6150 50  0001 C CNN
F 3 "" H 9900 6150 50  0001 C CNN
	1    9900 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5C9E80F4
P 11100 5750
F 0 "#PWR0113" H 11100 5500 50  0001 C CNN
F 1 "GND" H 11105 5577 50  0000 C CNN
F 2 "" H 11100 5750 50  0001 C CNN
F 3 "" H 11100 5750 50  0001 C CNN
	1    11100 5750
	1    0    0    -1  
$EndComp
Connection ~ 7750 5400
$Comp
L power:GND #PWR0104
U 1 1 5C817E41
P 7750 5400
F 0 "#PWR0104" H 7750 5150 50  0001 C CNN
F 1 "GND" H 7755 5227 50  0000 C CNN
F 2 "" H 7750 5400 50  0001 C CNN
F 3 "" H 7750 5400 50  0001 C CNN
	1    7750 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 5400 8300 5550
$Comp
L power:GND #PWR0106
U 1 1 5C8190CD
P 8300 5550
F 0 "#PWR0106" H 8300 5300 50  0001 C CNN
F 1 "GND" H 8305 5377 50  0000 C CNN
F 2 "" H 8300 5550 50  0001 C CNN
F 3 "" H 8300 5550 50  0001 C CNN
	1    8300 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2750 7900 2750
Connection ~ 7900 2750
$Comp
L power:GND #PWR0105
U 1 1 5C818469
P 7900 2750
F 0 "#PWR0105" H 7900 2500 50  0001 C CNN
F 1 "GND" H 7905 2577 50  0000 C CNN
F 2 "" H 7900 2750 50  0001 C CNN
F 3 "" H 7900 2750 50  0001 C CNN
	1    7900 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2750 8450 2900
$Comp
L power:GND #PWR0107
U 1 1 5C819881
P 8450 2900
F 0 "#PWR0107" H 8450 2650 50  0001 C CNN
F 1 "GND" H 8455 2727 50  0000 C CNN
F 2 "" H 8450 2900 50  0001 C CNN
F 3 "" H 8450 2900 50  0001 C CNN
	1    8450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2100 4850 2100
Wire Wire Line
	4500 2200 4500 2100
$Comp
L power:GND #PWR0114
U 1 1 5CA7EA37
P 4500 2200
F 0 "#PWR0114" H 4500 1950 50  0001 C CNN
F 1 "GND" H 4505 2027 50  0000 C CNN
F 2 "" H 4500 2200 50  0001 C CNN
F 3 "" H 4500 2200 50  0001 C CNN
	1    4500 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5675 4375 5825 4375
$Comp
L power:GND #PWR0103
U 1 1 5C816DC7
P 5675 4375
F 0 "#PWR0103" H 5675 4125 50  0001 C CNN
F 1 "GND" H 5680 4202 50  0000 C CNN
F 2 "" H 5675 4375 50  0001 C CNN
F 3 "" H 5675 4375 50  0001 C CNN
	1    5675 4375
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
	475  2850 2675 2850
Wire Notes Line
	450  4950 2675 4950
Wire Wire Line
	975  1125 1075 1125
Wire Wire Line
	1475 1125 1625 1125
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
Text GLabel 5825 3175 0    50   Output ~ 0
Calib
Text GLabel 10500 5650 0    50   Input ~ 0
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
F 2 "" H 1800 7000 50  0001 C CNN
F 3 "" H 1800 7000 50  0001 C CNN
	1    1800 7000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
