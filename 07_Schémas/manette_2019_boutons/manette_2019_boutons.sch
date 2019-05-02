EESchema Schematic File Version 4
LIBS:manette_2019_boutons-cache
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
U 1 1 5CC90DC1
P 4825 1775
F 0 "SW1" H 4825 2160 50  0000 C CNN
F 1 "Bouton_1" H 4825 2069 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 4825 2075 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4825 2075 50  0001 C CNN
	1    4825 1775
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G_LED SW2
U 1 1 5CC90E5A
P 4825 2300
F 0 "SW2" H 4825 2685 50  0000 C CNN
F 1 "Bouton_2" H 4825 2594 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 4825 2600 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4825 2600 50  0001 C CNN
	1    4825 2300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G_LED SW3
U 1 1 5CC90E81
P 4825 2850
F 0 "SW3" H 4825 3235 50  0000 C CNN
F 1 "Bouton_3" H 4825 3144 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 4825 3150 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4825 3150 50  0001 C CNN
	1    4825 2850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_MEC_5G_LED SW4
U 1 1 5CC90EA9
P 4825 3375
F 0 "SW4" H 4825 3760 50  0000 C CNN
F 1 "Bouton_4" H 4825 3669 50  0000 C CNN
F 2 "Button_Switch_THT:Bouton_MEC" H 4825 3675 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 4825 3675 50  0001 C CNN
	1    4825 3375
	1    0    0    -1  
$EndComp
Wire Wire Line
	4625 1675 4525 1675
Wire Wire Line
	4525 1675 4525 1775
Wire Wire Line
	4525 1775 4625 1775
Connection ~ 4525 1775
Wire Wire Line
	4525 2200 4625 2200
Connection ~ 4525 2200
Wire Wire Line
	4525 2200 4525 1775
Wire Wire Line
	4525 2300 4625 2300
Wire Wire Line
	4525 2300 4525 2750
Wire Wire Line
	4525 2750 4625 2750
Connection ~ 4525 2300
Wire Wire Line
	4525 2750 4525 2850
Wire Wire Line
	4525 2850 4625 2850
Connection ~ 4525 2750
Wire Wire Line
	4525 2850 4525 3275
Wire Wire Line
	4525 3275 4625 3275
Connection ~ 4525 2850
Wire Wire Line
	4525 3275 4525 3375
Wire Wire Line
	4525 3375 4625 3375
Connection ~ 4525 3275
Wire Wire Line
	4525 2200 4525 2300
Text GLabel 3375 2800 2    50   Output ~ 0
Vcc_LED
Text GLabel 3375 2700 2    50   Output ~ 0
GND
Text GLabel 3375 2600 2    50   Input ~ 0
Bouton_1
Text GLabel 3375 2500 2    50   Input ~ 0
Bouton_2
Text GLabel 3375 2400 2    50   Input ~ 0
Bouton_3
Text GLabel 3375 2300 2    50   Input ~ 0
Bouton_4
$Comp
L Device:R R1
U 1 1 5CC91A3A
P 5175 1775
F 0 "R1" V 5275 1775 50  0000 C CNN
F 1 "R" V 5350 1775 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5105 1775 50  0001 C CNN
F 3 "~" H 5175 1775 50  0001 C CNN
	1    5175 1775
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5CC91B1E
P 5175 2300
F 0 "R2" V 5275 2300 50  0000 C CNN
F 1 "R" V 5350 2300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5105 2300 50  0001 C CNN
F 3 "~" H 5175 2300 50  0001 C CNN
	1    5175 2300
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5CC91BD0
P 5175 2850
F 0 "R3" V 5275 2850 50  0000 C CNN
F 1 "R" V 5350 2850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5105 2850 50  0001 C CNN
F 3 "~" H 5175 2850 50  0001 C CNN
	1    5175 2850
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5CC91C85
P 5175 3375
F 0 "R4" V 5275 3375 50  0000 C CNN
F 1 "R" V 5350 3375 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5105 3375 50  0001 C CNN
F 3 "~" H 5175 3375 50  0001 C CNN
	1    5175 3375
	0    1    1    0   
$EndComp
Text GLabel 4525 3475 3    50   Input ~ 0
GND
Wire Wire Line
	4525 3475 4525 3375
Connection ~ 4525 3375
Text GLabel 5325 3375 2    50   Input ~ 0
Vcc_LED
Text GLabel 5325 2850 2    50   Input ~ 0
Vcc_LED
Text GLabel 5325 2300 2    50   Input ~ 0
Vcc_LED
Text GLabel 5325 1775 2    50   Input ~ 0
Vcc_LED
Text GLabel 5025 1675 2    50   Output ~ 0
Bouton_1
Text GLabel 5025 2200 2    50   Output ~ 0
Bouton_2
Text GLabel 5025 2750 2    50   Output ~ 0
Bouton_3
Text GLabel 5025 3275 2    50   Output ~ 0
Bouton_4
$Comp
L Connector:Screw_Terminal_01x03 J1
U 1 1 5CC930DA
P 3175 2700
F 0 "J1" H 3300 2650 50  0000 C CNN
F 1 "Conn_bouton_1" H 3525 2725 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 3175 2700 50  0001 C CNN
F 3 "~" H 3175 2700 50  0001 C CNN
	1    3175 2700
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J2
U 1 1 5CC93321
P 3175 2400
F 0 "J2" H 3300 2350 50  0000 C CNN
F 1 "Conn_bouton_2" H 3525 2425 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 3175 2400 50  0001 C CNN
F 3 "~" H 3175 2400 50  0001 C CNN
	1    3175 2400
	-1   0    0    1   
$EndComp
Text Notes 5975 2300 0    50   ~ 0
Ce PCB sera produit en 2 exemplaires par manette,\nl'un d'eux comportera les boutons A B X et Y, alors\nque l'autre aura le pad directionnel.\n
$EndSCHEMATC
