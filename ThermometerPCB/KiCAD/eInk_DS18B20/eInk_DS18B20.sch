EESchema Schematic File Version 4
EELAYER 30 0
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
L CDRH4D18NP-2R2NC:CDRH4D18NP-2R2NC L1
U 1 1 608BC474
P 950 2650
F 0 "L1" H 1350 2875 50  0000 C CNN
F 1 "CDRH4D18NP-10uH 1A" H 1350 2784 50  0000 C CNN
F 2 "CDRH4D18NP100NC" H 1600 2700 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/1/CDRH4D18NP-100NC.pdf" H 1600 2600 50  0001 L CNN
F 4 "Fixed Inductors 2.2uH 1.32A 30% SMD LP INDUCTOR" H 1600 2500 50  0001 L CNN "Description"
F 5 "2" H 1600 2400 50  0001 L CNN "Height"
F 6 "Sumida" H 1600 2300 50  0001 L CNN "Manufacturer_Name"
F 7 "CDRH4D18NP-2R2NC" H 1600 2200 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "851-CDRH4D18NP-2R2NC" H 1600 2100 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.com/Search/Refine.aspx?Keyword=851-CDRH4D18NP-2R2NC" H 1600 2000 50  0001 L CNN "Mouser Price/Stock"
F 10 "CDRH4D18NP-2R2NC" H 1600 1900 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/cdrh4d18np-2r2nc/sumida" H 1600 1800 50  0001 L CNN "Arrow Price/Stock"
	1    950  2650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x24 J1
U 1 1 608BE57C
P 4700 1850
F 0 "J1" H 4780 1842 50  0000 L CNN
F 1 "eInk" H 4780 1751 50  0000 L CNN
F 2 "" H 4700 1850 50  0001 C CNN
F 3 "~" H 4700 1850 50  0001 C CNN
	1    4700 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2150 4500 2250
Wire Wire Line
	4250 850  4500 850 
Wire Wire Line
	4250 950  4500 950 
Text Label 4250 850  0    50   ~ 0
GDR
Text Label 4250 950  0    50   ~ 0
RESE
$Comp
L Device:C C7
U 1 1 608C0151
P 3800 1150
F 0 "C7" V 3548 1150 50  0000 C CNN
F 1 "1uF" V 3639 1150 50  0000 C CNN
F 2 "" H 3838 1000 50  0001 C CNN
F 3 "~" H 3800 1150 50  0001 C CNN
	1    3800 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 1150 3950 1150
$Comp
L power:GND #PWR09
U 1 1 608C0F29
P 3650 1150
F 0 "#PWR09" H 3650 900 50  0001 C CNN
F 1 "GND" V 3655 1022 50  0000 R CNN
F 2 "" H 3650 1150 50  0001 C CNN
F 3 "" H 3650 1150 50  0001 C CNN
	1    3650 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 1450 3650 1450
Wire Wire Line
	3650 1450 3650 1150
Connection ~ 3650 1150
NoConn ~ 4500 750 
NoConn ~ 4500 1050
NoConn ~ 4500 1250
NoConn ~ 4500 1350
NoConn ~ 4500 2550
Wire Wire Line
	4250 1550 4500 1550
Wire Wire Line
	4250 1650 4500 1650
Wire Wire Line
	4250 1750 4500 1750
Wire Wire Line
	4250 1850 4500 1850
Wire Wire Line
	4250 1950 4500 1950
Wire Wire Line
	4250 2050 4500 2050
$Comp
L Device:C C4
U 1 1 608C285C
P 3600 2150
F 0 "C4" V 3348 2150 50  0000 C CNN
F 1 "1uF" V 3439 2150 50  0000 C CNN
F 2 "" H 3638 2000 50  0001 C CNN
F 3 "~" H 3600 2150 50  0001 C CNN
	1    3600 2150
	0    1    1    0   
$EndComp
$Comp
L Device:C C8
U 1 1 608C318B
P 3850 2450
F 0 "C8" V 3598 2450 50  0000 C CNN
F 1 "1uF" V 3689 2450 50  0000 C CNN
F 2 "" H 3888 2300 50  0001 C CNN
F 3 "~" H 3850 2450 50  0001 C CNN
	1    3850 2450
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 608C3D16
P 3600 2750
F 0 "C5" V 3348 2750 50  0000 C CNN
F 1 "1uF" V 3439 2750 50  0000 C CNN
F 2 "" H 3638 2600 50  0001 C CNN
F 3 "~" H 3600 2750 50  0001 C CNN
	1    3600 2750
	0    1    1    0   
$EndComp
$Comp
L Device:C C10
U 1 1 608C4778
P 3850 3650
F 0 "C10" V 3598 3650 50  0000 C CNN
F 1 "1uF" V 3689 3650 50  0000 C CNN
F 2 "" H 3888 3500 50  0001 C CNN
F 3 "~" H 3850 3650 50  0001 C CNN
	1    3850 3650
	0    1    1    0   
$EndComp
$Comp
L Device:C C6
U 1 1 608C4EC8
P 3600 3350
F 0 "C6" V 3348 3350 50  0000 C CNN
F 1 "1uF" V 3439 3350 50  0000 C CNN
F 2 "" H 3638 3200 50  0001 C CNN
F 3 "~" H 3600 3350 50  0001 C CNN
	1    3600 3350
	0    1    1    0   
$EndComp
$Comp
L Device:C C9
U 1 1 608C574F
P 3850 3050
F 0 "C9" V 3598 3050 50  0000 C CNN
F 1 "1uF" V 3689 3050 50  0000 C CNN
F 2 "" H 3888 2900 50  0001 C CNN
F 3 "~" H 3850 3050 50  0001 C CNN
	1    3850 3050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 608CCF02
P 3450 2150
F 0 "#PWR08" H 3450 1900 50  0001 C CNN
F 1 "GND" V 3455 2022 50  0000 R CNN
F 2 "" H 3450 2150 50  0001 C CNN
F 3 "" H 3450 2150 50  0001 C CNN
	1    3450 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 3350 3450 3050
Connection ~ 3450 2150
Connection ~ 3450 2750
Wire Wire Line
	3450 2750 3450 2450
Wire Wire Line
	3700 3650 3450 3650
Wire Wire Line
	3450 3650 3450 3350
Connection ~ 3450 3350
Wire Wire Line
	4500 2150 3750 2150
Connection ~ 4500 2150
$Comp
L power:GND #PWR011
U 1 1 608CE6FF
P 4500 2350
F 0 "#PWR011" H 4500 2100 50  0001 C CNN
F 1 "GND" V 4505 2222 50  0000 R CNN
F 2 "" H 4500 2350 50  0001 C CNN
F 3 "" H 4500 2350 50  0001 C CNN
	1    4500 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 2450 4000 2450
Wire Wire Line
	3700 2450 3450 2450
Connection ~ 3450 2450
Wire Wire Line
	3450 2450 3450 2150
Wire Wire Line
	4500 2650 3750 2650
Wire Wire Line
	3750 2650 3750 2750
Wire Wire Line
	4250 2750 4500 2750
Wire Wire Line
	4500 2850 4000 2850
Wire Wire Line
	4000 2850 4000 3050
Wire Wire Line
	3700 3050 3450 3050
Connection ~ 3450 3050
Wire Wire Line
	3450 3050 3450 2750
Wire Wire Line
	4500 2950 4050 2950
Wire Wire Line
	4050 2950 4050 3350
Wire Wire Line
	4050 3350 3750 3350
Wire Wire Line
	4500 3050 4100 3050
Wire Wire Line
	4100 3050 4100 3650
Wire Wire Line
	4100 3650 4000 3650
Text Label 4250 1550 0    50   ~ 0
BUSY
Text Label 4250 1650 0    50   ~ 0
RES
Text Label 4250 1750 0    50   ~ 0
DC
Text Label 4250 1850 0    50   ~ 0
CS
Text Label 4250 1950 0    50   ~ 0
SCLK
Text Label 4250 2050 0    50   ~ 0
SDI
Text Label 4250 2750 0    50   ~ 0
PREVGH
Text Label 4250 2950 0    50   ~ 0
PREVGL
Text Label 4250 3050 0    50   ~ 0
VCOM
$Comp
L Device:C C1
U 1 1 608D3A9F
P 850 2800
F 0 "C1" H 735 2846 50  0000 R CNN
F 1 "4.7uF" H 735 2755 50  0000 R CNN
F 2 "" H 888 2650 50  0001 C CNN
F 3 "~" H 850 2800 50  0001 C CNN
	1    850  2800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 608D5C2F
P 850 2950
F 0 "#PWR02" H 850 2700 50  0001 C CNN
F 1 "GND" H 855 2777 50  0000 C CNN
F 2 "" H 850 2950 50  0001 C CNN
F 3 "" H 850 2950 50  0001 C CNN
	1    850  2950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR010
U 1 1 608D72F3
P 4500 2250
F 0 "#PWR010" H 4500 2100 50  0001 C CNN
F 1 "+3.3V" V 4515 2378 50  0000 L CNN
F 2 "" H 4500 2250 50  0001 C CNN
F 3 "" H 4500 2250 50  0001 C CNN
	1    4500 2250
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 608D78B6
P 850 2400
F 0 "#PWR01" H 850 2250 50  0001 C CNN
F 1 "+3.3V" H 865 2573 50  0000 C CNN
F 2 "" H 850 2400 50  0001 C CNN
F 3 "" H 850 2400 50  0001 C CNN
	1    850  2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  2650 850  2650
Wire Wire Line
	850  2400 850  2650
Connection ~ 850  2650
Connection ~ 4500 2250
$Comp
L Transistor_FET:AO3400A Q1
U 1 1 608DEA04
P 1750 2850
F 0 "Q1" H 1955 2896 50  0000 L CNN
F 1 "AO3400A" H 1955 2805 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 1950 2775 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3400A.pdf" H 1750 2850 50  0001 L CNN
	1    1750 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 608E4118
P 1850 3350
F 0 "R2" H 1920 3396 50  0000 L CNN
F 1 "3R" H 1920 3305 50  0000 L CNN
F 2 "" V 1780 3350 50  0001 C CNN
F 3 "~" H 1850 3350 50  0001 C CNN
	1    1850 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 608E4EF5
P 1400 3350
F 0 "R1" H 1470 3396 50  0000 L CNN
F 1 "10k" H 1470 3305 50  0000 L CNN
F 2 "" V 1330 3350 50  0001 C CNN
F 3 "~" H 1400 3350 50  0001 C CNN
	1    1400 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 608E5CD3
P 1600 3500
F 0 "#PWR05" H 1600 3250 50  0001 C CNN
F 1 "GND" H 1605 3327 50  0000 C CNN
F 2 "" H 1600 3500 50  0001 C CNN
F 3 "" H 1600 3500 50  0001 C CNN
	1    1600 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 2650 1750 2650
$Comp
L Device:C C2
U 1 1 608EA9FB
P 1850 2250
F 0 "C2" H 1735 2296 50  0000 R CNN
F 1 "4.7uF" H 1735 2205 50  0000 R CNN
F 2 "" H 1888 2100 50  0001 C CNN
F 3 "~" H 1850 2250 50  0001 C CNN
	1    1850 2250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1850 2400 1850 2650
Connection ~ 1850 2650
Wire Wire Line
	1400 3500 1600 3500
Wire Wire Line
	1550 2850 1400 2850
Text Label 1400 2850 0    50   ~ 0
GDR
Connection ~ 1600 3500
Wire Wire Line
	1600 3500 1850 3500
Wire Wire Line
	1400 2850 1400 3200
Wire Wire Line
	1850 3050 1850 3200
Text Label 1850 3150 0    50   ~ 0
RESE
$Comp
L Diode:MBR0530 D3
U 1 1 608F31BB
P 2350 2650
F 0 "D3" H 2350 2867 50  0000 C CNN
F 1 "MBR0530" H 2350 2776 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 2350 2475 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MBR0520~MBR0580(SOD123).pdf" H 2350 2650 50  0001 C CNN
	1    2350 2650
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 608F5B4E
P 2600 2800
F 0 "C3" H 2715 2846 50  0000 L CNN
F 1 "1uF" H 2715 2755 50  0000 L CNN
F 2 "" H 2638 2650 50  0001 C CNN
F 3 "~" H 2600 2800 50  0001 C CNN
	1    2600 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 608F7F21
P 2600 2950
F 0 "#PWR07" H 2600 2700 50  0001 C CNN
F 1 "GND" H 2605 2777 50  0000 C CNN
F 2 "" H 2600 2950 50  0001 C CNN
F 3 "" H 2600 2950 50  0001 C CNN
	1    2600 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2650 2500 2650
Wire Wire Line
	2200 2650 1850 2650
Wire Wire Line
	2950 2650 2600 2650
Connection ~ 2600 2650
Text Label 2950 2650 2    50   ~ 0
PREVGH
$Comp
L Diode:MBR0530 D2
U 1 1 608FB392
P 2350 2050
F 0 "D2" H 2350 2267 50  0000 C CNN
F 1 "MBR0530" H 2350 2176 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 2350 1875 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MBR0520~MBR0580(SOD123).pdf" H 2350 2050 50  0001 C CNN
	1    2350 2050
	-1   0    0    -1  
$EndComp
$Comp
L Diode:MBR0530 D1
U 1 1 608FC892
P 2350 1600
F 0 "D1" H 2350 1817 50  0000 C CNN
F 1 "MBR0530" H 2350 1726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 2350 1425 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MBR0520~MBR0580(SOD123).pdf" H 2350 1600 50  0001 C CNN
	1    2350 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1600 1850 1600
Wire Wire Line
	1850 1600 1850 2050
Wire Wire Line
	2200 2050 1850 2050
Connection ~ 1850 2050
Wire Wire Line
	1850 2050 1850 2100
$Comp
L power:GND #PWR06
U 1 1 608FFF31
P 2500 2050
F 0 "#PWR06" H 2500 1800 50  0001 C CNN
F 1 "GND" V 2505 1922 50  0000 R CNN
F 2 "" H 2500 2050 50  0001 C CNN
F 3 "" H 2500 2050 50  0001 C CNN
	1    2500 2050
	0    -1   1    0   
$EndComp
Wire Wire Line
	2950 1600 2500 1600
Text Label 2950 1600 2    50   ~ 0
PREVGL
$Comp
L Connector_Generic:Conn_01x08 J2
U 1 1 60903E0C
P 900 1250
F 0 "J2" H 818 1767 50  0000 C CNN
F 1 "SPI" H 818 1676 50  0000 C CNN
F 2 "" H 900 1250 50  0001 C CNN
F 3 "~" H 900 1250 50  0001 C CNN
	1    900  1250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1350 950  1100 950 
Wire Wire Line
	1350 1050 1100 1050
Wire Wire Line
	1350 1150 1100 1150
Wire Wire Line
	1350 1250 1100 1250
Wire Wire Line
	1350 1350 1100 1350
Wire Wire Line
	1350 1450 1100 1450
Wire Wire Line
	1350 1550 1100 1550
Wire Wire Line
	1350 1650 1100 1650
Text Label 1350 950  2    50   ~ 0
BUSY
Text Label 1350 1050 2    50   ~ 0
RES
Text Label 1350 1150 2    50   ~ 0
DC
Text Label 1350 1250 2    50   ~ 0
CS
Text Label 1350 1350 2    50   ~ 0
SCLK
Text Label 1350 1450 2    50   ~ 0
SDI
$Comp
L power:GND #PWR03
U 1 1 60911295
P 1350 1550
F 0 "#PWR03" H 1350 1300 50  0001 C CNN
F 1 "GND" V 1355 1422 50  0000 R CNN
F 2 "" H 1350 1550 50  0001 C CNN
F 3 "" H 1350 1550 50  0001 C CNN
	1    1350 1550
	0    -1   1    0   
$EndComp
$Comp
L power:+3.3V #PWR04
U 1 1 60911B18
P 1350 1650
F 0 "#PWR04" H 1350 1500 50  0001 C CNN
F 1 "+3.3V" V 1365 1778 50  0000 L CNN
F 2 "" H 1350 1650 50  0001 C CNN
F 3 "" H 1350 1650 50  0001 C CNN
	1    1350 1650
	0    1    1    0   
$EndComp
$EndSCHEMATC
