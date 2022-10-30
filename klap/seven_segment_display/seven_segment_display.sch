EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Seven Segment Display"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R5
U 1 1 614E8198
P 6100 2600
F 0 "R5" H 6170 2646 50  0000 L CNN
F 1 "2200" H 6170 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 6030 2600 50  0001 C CNN
F 3 "~" H 6100 2600 50  0001 C CNN
	1    6100 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 614E89AC
P 5050 2600
F 0 "R2" H 5120 2646 50  0000 L CNN
F 1 "2200" H 5120 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 4980 2600 50  0001 C CNN
F 3 "~" H 5050 2600 50  0001 C CNN
	1    5050 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 614E8AE7
P 4700 2600
F 0 "R1" H 4770 2646 50  0000 L CNN
F 1 "2200" H 4770 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 4630 2600 50  0001 C CNN
F 3 "~" H 4700 2600 50  0001 C CNN
	1    4700 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 614E8D33
P 5400 2600
F 0 "R3" H 5470 2646 50  0000 L CNN
F 1 "2200" H 5470 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 5330 2600 50  0001 C CNN
F 3 "~" H 5400 2600 50  0001 C CNN
	1    5400 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 614E902E
P 6450 2600
F 0 "R6" H 6520 2646 50  0000 L CNN
F 1 "2200" H 6520 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 6380 2600 50  0001 C CNN
F 3 "~" H 6450 2600 50  0001 C CNN
	1    6450 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 614E921B
P 7150 2600
F 0 "R8" H 7220 2646 50  0000 L CNN
F 1 "2200" H 7220 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 7080 2600 50  0001 C CNN
F 3 "~" H 7150 2600 50  0001 C CNN
	1    7150 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 614E9534
P 5750 2600
F 0 "R4" H 5820 2646 50  0000 L CNN
F 1 "2200" H 5820 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 5680 2600 50  0001 C CNN
F 3 "~" H 5750 2600 50  0001 C CNN
	1    5750 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 614E9622
P 6800 2600
F 0 "R7" H 6870 2646 50  0000 L CNN
F 1 "2200" H 6870 2555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P25.40mm_Horizontal" V 6730 2600 50  0001 C CNN
F 3 "~" H 6800 2600 50  0001 C CNN
	1    6800 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 614E9B37
P 3500 2700
F 0 "J1" H 3580 2742 50  0000 L CNN
F 1 "Conn_01x05" H 3580 2651 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Horizontal" H 3500 2700 50  0001 C CNN
F 3 "~" H 3500 2700 50  0001 C CNN
	1    3500 2700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U1
U 1 1 614EAEA2
P 3450 3950
F 0 "U1" H 3450 4731 50  0000 C CNN
F 1 "74HC595" H 3450 4640 50  0000 C CNN
F 2 "Seven Segment Display:DIP16-2.54-20.32X5.84MM" H 3450 3950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3450 3950 50  0001 C CNN
	1    3450 3950
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:LTS-6980HR AFF1
U 1 1 614EC1C9
P 8050 3700
F 0 "AFF1" H 8050 4367 50  0000 C CNN
F 1 "LTS-6980HR" H 8050 4276 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 8050 3100 50  0001 C CNN
F 3 "http://datasheet.octopart.com/LTS-6960HR-Lite-On-datasheet-11803242.pdf" H 8050 3700 50  0001 C CNN
	1    8050 3700
	1    0    0    -1  
$EndComp
Text Label 3300 2900 2    50   ~ 0
DATA
Text Label 3300 2800 2    50   ~ 0
CLOCK
Text Label 3300 2700 2    50   ~ 0
LATCH
Text Label 3050 3550 2    50   ~ 0
LATCH
Text Label 3050 3750 2    50   ~ 0
DATA
Text Label 3050 4050 2    50   ~ 0
CLOCK
Wire Wire Line
	4700 2750 4700 4600
Wire Wire Line
	4700 4600 8550 4600
Wire Wire Line
	8550 4600 8550 4000
Wire Wire Line
	5050 2750 5050 3900
Wire Wire Line
	5050 3900 7550 3900
Wire Wire Line
	5400 2750 5400 3800
Wire Wire Line
	5400 3800 7550 3800
Wire Wire Line
	5750 2750 5750 3700
Wire Wire Line
	5750 3700 7550 3700
Wire Wire Line
	6100 2750 6100 3600
Wire Wire Line
	6100 3600 7550 3600
Wire Wire Line
	6450 2750 6450 3500
Wire Wire Line
	6450 3500 7550 3500
Wire Wire Line
	6800 2750 6800 3400
Wire Wire Line
	6800 3400 7550 3400
Wire Wire Line
	7150 2750 7150 3300
Wire Wire Line
	7150 3300 7550 3300
Wire Wire Line
	8550 3400 9100 3400
$Comp
L power:VCC #PWR0101
U 1 1 61505171
P 9100 3150
F 0 "#PWR0101" H 9100 3000 50  0001 C CNN
F 1 "VCC" H 9115 3323 50  0000 C CNN
F 2 "" H 9100 3150 50  0001 C CNN
F 3 "" H 9100 3150 50  0001 C CNN
	1    9100 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3300 9100 3300
Wire Wire Line
	2750 2600 2750 2650
$Comp
L power:GND #PWR0102
U 1 1 61506A62
P 2750 2800
F 0 "#PWR0102" H 2750 2550 50  0001 C CNN
F 1 "GND" H 2755 2627 50  0000 C CNN
F 2 "" H 2750 2800 50  0001 C CNN
F 3 "" H 2750 2800 50  0001 C CNN
	1    2750 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2500 2750 2500
Wire Wire Line
	2750 2500 2750 2350
$Comp
L power:VCC #PWR0103
U 1 1 615067E3
P 2750 2350
F 0 "#PWR0103" H 2750 2200 50  0001 C CNN
F 1 "VCC" H 2765 2523 50  0000 C CNN
F 2 "" H 2750 2350 50  0001 C CNN
F 3 "" H 2750 2350 50  0001 C CNN
	1    2750 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 4150 2800 4350
$Comp
L power:GND #PWR0104
U 1 1 614F0BE4
P 2800 4350
F 0 "#PWR0104" H 2800 4100 50  0001 C CNN
F 1 "GND" H 2805 4177 50  0000 C CNN
F 2 "" H 2800 4350 50  0001 C CNN
F 3 "" H 2800 4350 50  0001 C CNN
	1    2800 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4150 2800 4150
Wire Wire Line
	3050 3850 2450 3850
$Comp
L power:VCC #PWR0105
U 1 1 614F20E3
P 2450 4350
F 0 "#PWR0105" H 2450 4200 50  0001 C CNN
F 1 "VCC" H 2465 4523 50  0000 C CNN
F 2 "" H 2450 4350 50  0001 C CNN
F 3 "" H 2450 4350 50  0001 C CNN
	1    2450 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 3850 2450 4350
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 614F3D30
P 2750 2500
F 0 "#FLG0101" H 2750 2575 50  0001 C CNN
F 1 "PWR_FLAG" V 2750 2627 50  0000 L CNN
F 2 "" H 2750 2500 50  0001 C CNN
F 3 "~" H 2750 2500 50  0001 C CNN
	1    2750 2500
	0    -1   -1   0   
$EndComp
Connection ~ 2750 2500
Wire Wire Line
	2750 2600 3300 2600
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 614F466F
P 2750 2650
F 0 "#FLG0102" H 2750 2725 50  0001 C CNN
F 1 "PWR_FLAG" V 2750 2777 50  0000 L CNN
F 2 "" H 2750 2650 50  0001 C CNN
F 3 "~" H 2750 2650 50  0001 C CNN
	1    2750 2650
	0    -1   -1   0   
$EndComp
Connection ~ 2750 2650
Wire Wire Line
	2750 2650 2750 2800
$Comp
L power:GND #PWR0106
U 1 1 614F6591
P 3450 4800
F 0 "#PWR0106" H 3450 4550 50  0001 C CNN
F 1 "GND" H 3455 4627 50  0000 C CNN
F 2 "" H 3450 4800 50  0001 C CNN
F 3 "" H 3450 4800 50  0001 C CNN
	1    3450 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 4650 3450 4800
$Comp
L power:VCC #PWR0107
U 1 1 614F80E9
P 3150 3350
F 0 "#PWR0107" H 3150 3200 50  0001 C CNN
F 1 "VCC" V 3165 3477 50  0000 L CNN
F 2 "" H 3150 3350 50  0001 C CNN
F 3 "" H 3150 3350 50  0001 C CNN
	1    3150 3350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3450 3350 3150 3350
Wire Wire Line
	9100 3150 9100 3300
$Comp
L power:VCC #PWR0108
U 1 1 614FA373
P 9100 3550
F 0 "#PWR0108" H 9100 3400 50  0001 C CNN
F 1 "VCC" H 9115 3723 50  0000 C CNN
F 2 "" H 9100 3550 50  0001 C CNN
F 3 "" H 9100 3550 50  0001 C CNN
	1    9100 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	9100 3550 9100 3400
Entry Wire Line
	4600 2250 4700 2350
Entry Wire Line
	5300 2250 5400 2350
Entry Wire Line
	5650 2250 5750 2350
Entry Wire Line
	6000 2250 6100 2350
Entry Wire Line
	6350 2250 6450 2350
Entry Wire Line
	6700 2250 6800 2350
Entry Wire Line
	7050 2250 7150 2350
Wire Wire Line
	4700 2350 4700 2450
Entry Wire Line
	4950 2250 5050 2350
Wire Wire Line
	5050 2350 5050 2450
Wire Wire Line
	5400 2350 5400 2450
Wire Wire Line
	5750 2350 5750 2450
Wire Wire Line
	6100 2350 6100 2450
Wire Wire Line
	6450 2350 6450 2450
Wire Wire Line
	6800 2350 6800 2450
Wire Wire Line
	7150 2350 7150 2450
Text Label 7150 2350 0    50   ~ 0
SG0
Text Label 6800 2350 0    50   ~ 0
SG1
Text Label 6450 2350 0    50   ~ 0
SG2
Text Label 6100 2350 0    50   ~ 0
SG3
Text Label 5750 2350 0    50   ~ 0
SG4
Text Label 5400 2350 0    50   ~ 0
SG5
Text Label 5050 2350 0    50   ~ 0
SG6
Text Label 4700 2350 0    50   ~ 0
SG7
Entry Wire Line
	4150 3650 4050 3550
Entry Wire Line
	4150 3750 4050 3650
Entry Wire Line
	4150 3850 4050 3750
Entry Wire Line
	4150 3950 4050 3850
Entry Wire Line
	4150 4050 4050 3950
Entry Wire Line
	4150 4150 4050 4050
Entry Wire Line
	4150 4250 4050 4150
Entry Wire Line
	4150 4350 4050 4250
Wire Wire Line
	3850 3550 4050 3550
Wire Wire Line
	3850 3650 4050 3650
Wire Wire Line
	3850 3750 4050 3750
Wire Wire Line
	3850 3850 4050 3850
Wire Wire Line
	3850 3950 4050 3950
Wire Wire Line
	3850 4050 4050 4050
Wire Wire Line
	3850 4150 4050 4150
Wire Wire Line
	3850 4250 4050 4250
Text Label 3900 3550 0    50   ~ 0
SG0
Text Label 3900 3650 0    50   ~ 0
SG1
Text Label 3900 3750 0    50   ~ 0
SG2
Text Label 3900 3850 0    50   ~ 0
SG3
Text Label 3900 3950 0    50   ~ 0
SG4
Text Label 3900 4050 0    50   ~ 0
SG5
Text Label 3900 4150 0    50   ~ 0
SG6
Text Label 3900 4250 0    50   ~ 0
SG7
NoConn ~ 3850 4450
Wire Bus Line
	4150 2250 7300 2250
Wire Bus Line
	4150 2250 4150 5050
$EndSCHEMATC
