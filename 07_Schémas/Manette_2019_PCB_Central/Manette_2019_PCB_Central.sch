EESchema Schematic File Version 4
LIBS:Manette_2019_PCB_Central-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_MEC_5G_LED SW1
U 1 1 5CCA9747
P 4600 2400
F 0 "SW1" H 4600 2785 50  0000 C CNN
F 1 "Button_Start" H 4600 2694 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 4600 2700 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4600 2700 50  0001 C CNN
	1    4600 2400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G_LED SW2
U 1 1 5CCA9816
P 4600 2975
F 0 "SW2" H 4600 3360 50  0000 C CNN
F 1 "Button_Select" H 4600 3269 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 4600 3275 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4600 3275 50  0001 C CNN
	1    4600 2975
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CCA9DD4
P 2250 2800
F 0 "#PWR0101" H 2250 2550 50  0001 C CNN
F 1 "GND" H 2255 2627 50  0000 C CNN
F 2 "" H 2250 2800 50  0001 C CNN
F 3 "" H 2250 2800 50  0001 C CNN
	1    2250 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2675 2250 2675
Wire Wire Line
	2250 2675 2250 2800
$Comp
L power:GND #PWR0102
U 1 1 5CCA9DF9
P 3725 3175
F 0 "#PWR0102" H 3725 2925 50  0001 C CNN
F 1 "GND" H 3730 3002 50  0000 C CNN
F 2 "" H 3725 3175 50  0001 C CNN
F 3 "" H 3725 3175 50  0001 C CNN
	1    3725 3175
	1    0    0    -1  
$EndComp
Text GLabel 2150 2375 2    50   Output ~ 0
Vcc
Text GLabel 2150 2475 2    50   Input ~ 0
button_START
Text GLabel 2150 2575 2    50   Input ~ 0
button_SELECT
Text GLabel 4800 2875 2    50   Output ~ 0
button_SELECT
Wire Wire Line
	3725 2400 3725 2875
Text GLabel 4800 2300 2    50   Output ~ 0
button_START
Connection ~ 3725 2875
Wire Wire Line
	3725 2300 3725 2400
Connection ~ 3725 2400
Text GLabel 5100 2400 2    50   Input ~ 0
Vcc
$Comp
L Device:R R2
U 1 1 5CCAA43B
P 4950 2975
F 0 "R2" V 5050 2975 50  0000 C CNN
F 1 "R" V 5150 2975 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 2975 50  0001 C CNN
F 3 "~" H 4950 2975 50  0001 C CNN
	1    4950 2975
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5CCAA564
P 4950 2400
F 0 "R1" V 5050 2400 50  0000 C CNN
F 1 "R" V 5150 2400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 2400 50  0001 C CNN
F 3 "~" H 4950 2400 50  0001 C CNN
	1    4950 2400
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5CCAAA90
P 1950 2375
F 0 "J1" H 2100 2250 50  0000 C CNN
F 1 "Button_OUT" H 2250 2375 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-2-2.54_1x02_P2.54mm_Horizontal" H 1950 2375 50  0001 C CNN
F 3 "~" H 1950 2375 50  0001 C CNN
	1    1950 2375
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J2
U 1 1 5CCAB7AA
P 1950 2575
F 0 "J2" H 2075 2525 50  0000 C CNN
F 1 "Button_In" H 2200 2625 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 1950 2575 50  0001 C CNN
F 3 "~" H 1950 2575 50  0001 C CNN
	1    1950 2575
	-1   0    0    1   
$EndComp
Text GLabel 2150 2275 2    50   Output ~ 0
Conn_LED_On
Wire Wire Line
	3725 2875 3725 3175
Text GLabel 4400 2975 0    50   Input ~ 0
Conn_LED_On
Text GLabel 5100 2975 2    50   Input ~ 0
Vcc
Wire Wire Line
	3725 2300 4400 2300
Wire Wire Line
	3725 2875 4400 2875
Wire Wire Line
	3725 2400 4400 2400
$EndSCHEMATC
