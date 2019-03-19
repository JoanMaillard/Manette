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
P 4550 3400
F 0 "U1" H 4525 4125 50  0000 C CNN
F 1 "NKK_Smartswitch" H 4525 4034 50  0000 C CNN
F 2 "NKK:NKK_Switch" H 4550 3150 50  0001 C CNN
F 3 "" H 4550 3150 50  0001 C CNN
	1    4550 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J2
U 1 1 5C90E962
P 5300 3100
F 0 "J2" H 5380 3142 50  0000 L CNN
F 1 "Conn_01x05" H 5380 3051 50  0000 L CNN
F 2 "NKK:conn_01x05" H 5300 3100 50  0001 C CNN
F 3 "~" H 5300 3100 50  0001 C CNN
	1    5300 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3300 5100 3300
Wire Wire Line
	5100 3200 4950 3200
Wire Wire Line
	4950 3100 5100 3100
Wire Wire Line
	5100 3000 4950 3000
Wire Wire Line
	4950 2900 5100 2900
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 5C90EAF2
P 3700 3200
F 0 "J1" H 3620 2775 50  0000 C CNN
F 1 "Conn_01x05" H 3620 2866 50  0000 C CNN
F 2 "NKK:conn_01x05" H 3700 3200 50  0001 C CNN
F 3 "~" H 3700 3200 50  0001 C CNN
	1    3700 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4550 3600 4100 3600
Wire Wire Line
	4100 3600 4100 3400
Wire Wire Line
	4100 3400 3900 3400
Wire Wire Line
	4550 3500 4550 3600
Wire Wire Line
	4100 3300 3900 3300
Wire Wire Line
	3900 3200 4100 3200
Wire Wire Line
	4100 3100 3900 3100
Wire Wire Line
	3900 3000 4100 3000
$EndSCHEMATC
