EESchema Schematic File Version 4
LIBS:Manette_2019_PCB_Central-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Boutons Centraux"
Date "2019-05-09"
Rev ""
Comp "CPNV MCT"
Comment1 "AKC"
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
P 2475 2400
F 0 "#PWR0101" H 2475 2150 50  0001 C CNN
F 1 "GND" H 2480 2227 50  0000 C CNN
F 2 "" H 2475 2400 50  0001 C CNN
F 3 "" H 2475 2400 50  0001 C CNN
	1    2475 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2475 2275 2475 2400
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
Text GLabel 2150 2475 2    50   Output ~ 0
+5V
Text GLabel 2150 2775 2    50   Input ~ 0
button_START
Text GLabel 2150 2975 2    50   Input ~ 0
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
+5V
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
Text GLabel 2150 2875 2    50   Output ~ 0
Conn_LED_On
Wire Wire Line
	3725 2875 3725 3175
Text GLabel 4400 2975 0    50   Input ~ 0
Conn_LED_On
Text GLabel 5100 2975 2    50   Input ~ 0
+5V
Wire Wire Line
	3725 2300 4400 2300
Wire Wire Line
	3725 2875 4400 2875
Wire Wire Line
	3725 2400 4400 2400
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 5CD02BF6
P 1950 2675
F 0 "J1" H 1870 2050 50  0000 C CNN
F 1 "Conn_Middle_PCB" H 1870 2141 50  0000 C CNN
F 2 "manette_2019:Conn_8" H 1950 2675 50  0001 C CNN
F 3 "~" H 1950 2675 50  0001 C CNN
	1    1950 2675
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 2275 2475 2275
NoConn ~ 2150 2675
NoConn ~ 2150 2575
NoConn ~ 2150 2375
$EndSCHEMATC
