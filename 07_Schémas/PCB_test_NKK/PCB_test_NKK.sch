EESchema Schematic File Version 4
LIBS:PCB_test_NKK-cache
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
L NKK_Smartswitch:NKK_Smartswitch U1
U 1 1 5C90D744
P 6075 2175
F 0 "U1" H 6050 2900 50  0000 C CNN
F 1 "NKK_Smartswitch" H 6050 2809 50  0000 C CNN
F 2 "NKK:NKK_Switch" H 6075 1925 50  0001 C CNN
F 3 "" H 6075 1925 50  0001 C CNN
	1    6075 2175
	1    0    0    -1  
$EndComp
$Comp
L NKK_Smartswitch:NKK_Smartswitch U2
U 1 1 5CACB44C
P 6125 3525
F 0 "U2" H 6100 4250 50  0000 C CNN
F 1 "NKK_Smartswitch" H 6100 4159 50  0000 C CNN
F 2 "NKK:NKK_Switch" H 6125 3275 50  0001 C CNN
F 3 "" H 6125 3275 50  0001 C CNN
	1    6125 3525
	1    0    0    -1  
$EndComp
Text GLabel 3075 1200 2    50   Output ~ 0
GND
Text GLabel 6075 2275 3    50   Output ~ 0
GND
Text GLabel 6125 3625 3    50   Output ~ 0
GND
Text GLabel 5675 3225 0    50   Output ~ 0
GND
Text GLabel 5625 1875 0    50   Output ~ 0
GND
$Comp
L Regulator_Switching:R-783.3-0.5 U3
U 1 1 5CACD8C0
P 3550 2850
F 0 "U3" H 3550 3092 50  0000 C CNN
F 1 "R-783.3-0.5" H 3550 3001 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 3600 2600 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78xx-0.5.pdf" H 3550 2850 50  0001 C CNN
	1    3550 2850
	1    0    0    -1  
$EndComp
Text GLabel 3550 3150 3    50   Output ~ 0
GND
$Comp
L Device:C C1
U 1 1 5CACDAC0
P 2975 3000
F 0 "C1" H 3090 3046 50  0000 L CNN
F 1 "C" H 3090 2955 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W3.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 3013 2850 50  0001 C CNN
F 3 "~" H 2975 3000 50  0001 C CNN
	1    2975 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2825 2850 2975 2850
Connection ~ 2975 2850
Wire Wire Line
	2975 2850 3250 2850
Text GLabel 2975 3150 3    50   Output ~ 0
GND
$Comp
L Device:C C2
U 1 1 5CACDE75
P 3450 1450
F 0 "C2" H 3565 1496 50  0000 L CNN
F 1 "C" H 3565 1405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 3488 1300 50  0001 C CNN
F 3 "~" H 3450 1450 50  0001 C CNN
	1    3450 1450
	1    0    0    -1  
$EndComp
Text GLabel 3450 1600 3    50   Output ~ 0
GND
Text GLabel 3625 1300 2    50   Output ~ 0
+16V
Text GLabel 2825 2850 0    50   Input ~ 0
+16V
Text GLabel 3850 2850 2    50   Output ~ 0
+3.3V
Text GLabel 5675 3425 0    50   Input ~ 0
+16V
Text GLabel 5625 2075 0    50   Input ~ 0
+16V
Text GLabel 5675 3325 0    50   Input ~ 0
+3.3V
Text GLabel 5625 1975 0    50   Input ~ 0
+3.3V
Wire Wire Line
	3625 1300 3450 1300
Connection ~ 3450 1300
Wire Wire Line
	3450 1300 3075 1300
Text GLabel 3075 1500 2    50   Output ~ 0
SCK
Text GLabel 6525 3325 2    50   Input ~ 0
SCK
Text GLabel 6475 1975 2    50   Input ~ 0
SCK
Text GLabel 3075 1600 2    50   Output ~ 0
SDI
Text GLabel 6525 3425 2    50   Input ~ 0
SDI
Text GLabel 6475 2075 2    50   Input ~ 0
SDI
Text GLabel 5625 1775 0    50   Input ~ 0
SW1
Text GLabel 5675 3125 0    50   Input ~ 0
SW2
Text GLabel 3075 1900 2    50   Output ~ 0
SW1
Text GLabel 3075 2200 2    50   Output ~ 0
SW2
Text GLabel 6525 3225 2    50   Input ~ 0
DC2
Text GLabel 6475 1875 2    50   Input ~ 0
DC1
Text GLabel 6475 1775 2    50   Input ~ 0
Rst
Text GLabel 6525 3125 2    50   Input ~ 0
Rst
Text GLabel 6525 3025 2    50   Input ~ 0
SS2
Text GLabel 6475 1675 2    50   Input ~ 0
SS1
Text GLabel 3075 1700 2    50   Output ~ 0
DC1
Text GLabel 3075 1400 2    50   Output ~ 0
Rst
Text GLabel 3075 1800 2    50   Output ~ 0
SS1
Text GLabel 3075 2000 2    50   Output ~ 0
SS2
Text GLabel 3075 2100 2    50   Output ~ 0
DC2
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5CACFF0B
P 2875 1500
F 0 "J1" H 3025 1475 50  0000 C CNN
F 1 "Conn_01x03" H 3200 1575 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 2875 1500 50  0001 C CNN
F 3 "~" H 2875 1500 50  0001 C CNN
	1    2875 1500
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5CACFF86
P 2875 1800
F 0 "J2" H 3000 1750 50  0000 C CNN
F 1 "Conn_01x03" H 3175 1850 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 2875 1800 50  0001 C CNN
F 3 "~" H 2875 1800 50  0001 C CNN
	1    2875 1800
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5CACFFAE
P 2875 2100
F 0 "J3" H 3025 2075 50  0000 C CNN
F 1 "Conn_01x03" H 3175 2175 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-3-2.54_1x03_P2.54mm_Horizontal" H 2875 2100 50  0001 C CNN
F 3 "~" H 2875 2100 50  0001 C CNN
	1    2875 2100
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5CAD0039
P 2875 1300
F 0 "J4" H 3025 1225 50  0000 C CNN
F 1 "Conn_01x02" H 3175 1325 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-2-2.54_1x02_P2.54mm_Horizontal" H 2875 1300 50  0001 C CNN
F 3 "~" H 2875 1300 50  0001 C CNN
	1    2875 1300
	-1   0    0    1   
$EndComp
$EndSCHEMATC
