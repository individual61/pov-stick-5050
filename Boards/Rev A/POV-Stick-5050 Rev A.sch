EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLedger 17000 11000
encoding utf-8
Sheet 1 1
Title "POV Stick Rev A"
Date "2017-12-28"
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L POV-Stick-5050-Rev-A-rescue:ATTINY85-20SU U1
U 1 1 5A452C23
P 5250 4350
F 0 "U1" H 4100 4750 50  0000 C CNN
F 1 "ATTINY85-20SU" H 6250 3950 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 6200 4350 50  0001 C CIN
F 3 "" H 5250 4350 50  0001 C CNN
	1    5250 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR01
U 1 1 5A453228
P 7850 3650
F 0 "#PWR01" H 7850 3500 50  0001 C CNN
F 1 "+BATT" H 7850 3790 50  0000 C CNN
F 2 "" H 7850 3650 50  0001 C CNN
F 3 "" H 7850 3650 50  0001 C CNN
	1    7850 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5A4532D4
P 7850 4800
F 0 "#PWR02" H 7850 4550 50  0001 C CNN
F 1 "GND" H 7850 4650 50  0000 C CNN
F 2 "" H 7850 4800 50  0001 C CNN
F 3 "" H 7850 4800 50  0001 C CNN
	1    7850 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5A45751E
P 4050 2700
F 0 "#PWR03" H 4050 2450 50  0001 C CNN
F 1 "GND" H 4050 2550 50  0000 C CNN
F 2 "" H 4050 2700 50  0001 C CNN
F 3 "" H 4050 2700 50  0001 C CNN
	1    4050 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR04
U 1 1 5A457610
P 4050 2500
F 0 "#PWR04" H 4050 2350 50  0001 C CNN
F 1 "+BATT" H 4050 2640 50  0000 C CNN
F 2 "" H 4050 2500 50  0001 C CNN
F 3 "" H 4050 2500 50  0001 C CNN
	1    4050 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5A457E63
P 9900 5350
F 0 "#PWR05" H 9900 5100 50  0001 C CNN
F 1 "GND" H 9900 5200 50  0000 C CNN
F 2 "" H 9900 5350 50  0001 C CNN
F 3 "" H 9900 5350 50  0001 C CNN
	1    9900 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR06
U 1 1 5A457EA9
P 9150 3600
F 0 "#PWR06" H 9150 3450 50  0001 C CNN
F 1 "+BATT" H 9150 3740 50  0000 C CNN
F 2 "" H 9150 3600 50  0001 C CNN
F 3 "" H 9150 3600 50  0001 C CNN
	1    9150 3600
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR07
U 1 1 5A458741
P 1750 2050
F 0 "#PWR07" H 1750 1900 50  0001 C CNN
F 1 "+BATT" H 1750 2190 50  0000 C CNN
F 2 "" H 1750 2050 50  0001 C CNN
F 3 "" H 1750 2050 50  0001 C CNN
	1    1750 2050
	1    0    0    -1  
$EndComp
Text Notes 8600 3300 0    60   ~ 0
NOTE:  TURN SWITCH OFF \nTO PROGRAM WITH ISP
$Comp
L power:GND #PWR08
U 1 1 5A45B73C
P 1750 3250
F 0 "#PWR08" H 1750 3000 50  0001 C CNN
F 1 "GND" H 1750 3100 50  0000 C CNN
F 2 "" H 1750 3250 50  0001 C CNN
F 3 "" H 1750 3250 50  0001 C CNN
	1    1750 3250
	1    0    0    -1  
$EndComp
Text Notes 4800 4800 0    60   ~ 0
ATTINY85 SOIC-8
$Comp
L power:GND #PWR09
U 1 1 5A461618
P 2100 7650
F 0 "#PWR09" H 2100 7400 50  0001 C CNN
F 1 "GND" H 2100 7500 50  0000 C CNN
F 2 "" H 2100 7650 50  0001 C CNN
F 3 "" H 2100 7650 50  0001 C CNN
	1    2100 7650
	1    0    0    -1  
$EndComp
Text Label 3000 4200 0    60   ~ 0
PIN6/SCK
Text Label 3000 4500 0    60   ~ 0
PIN3/SW3
Text Label 4250 6400 0    60   ~ 0
MOSI/WS2812Data
Text Label 4250 6500 0    60   ~ 0
SCK/WS2812Clock
$Comp
L MyResistors:R_vert R1
U 1 1 5A49A0CB
P 1750 2200
F 0 "R1" H 1850 2300 50  0000 L CNN
F 1 "4.7k" H 1850 2200 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1680 2200 50  0001 C CNN
F 3 "" H 1750 2200 50  0001 C CNN
F 4 "0603" H 1850 2100 50  0000 L CNN "Field4"
F 5 "CR0603-FX-4701ELF" H 1850 2000 50  0000 L CNN "MFR P/N"
	1    1750 2200
	1    0    0    -1  
$EndComp
$Comp
L MyCapacitors:C_Small_vert C1
U 1 1 5A49BA0E
P 1750 2950
F 0 "C1" H 1850 3050 50  0000 L CNN
F 1 "0.1uF" H 1850 2950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1750 2925 50  0001 L CNN
F 3 "" H 1850 3025 50  0001 L CNN
F 4 "0603" H 1850 2750 50  0000 L CNN "Package Size"
F 5 "50V" H 1850 2850 50  0000 L CNN "Voltage Rating"
F 6 "06035C104KAZ2A" H 1850 2650 50  0000 L CNN "MFR P/N"
	1    1750 2950
	1    0    0    -1  
$EndComp
$Comp
L MyCapacitors:C_Small_vert C4
U 1 1 5A49BCDB
P 7850 4300
F 0 "C4" H 7950 4400 50  0000 L CNN
F 1 "10uF" H 7950 4300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7850 4275 50  0001 L CNN
F 3 "" H 7950 4375 50  0001 L CNN
F 4 "0805" H 7950 4100 50  0000 L CNN "Package Size"
F 5 "16V" H 7950 4200 50  0000 L CNN "Voltage Rating"
F 6 "GRM21BR61C106KE15L" H 7950 4000 50  0000 L CNN "MFR P/N"
	1    7850 4300
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R3
U 1 1 5A49C261
P 2100 7250
F 0 "R3" H 2200 7350 50  0000 L CNN
F 1 "1.5k" H 2200 7250 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2030 7250 50  0001 C CNN
F 3 "" H 2100 7250 50  0001 C CNN
F 4 "0603" H 2200 7150 50  0000 L CNN "Package Size"
F 5 "RC0603FR-071K5L" H 2200 7050 50  0000 L CNN "MFR P/N"
	1    2100 7250
	1    0    0    -1  
$EndComp
$Comp
L MyLEDs:LED_ALT_vert D1
U 1 1 5A4A524A
P 2100 6750
F 0 "D1" H 2300 6850 50  0000 C CNN
F 1 "Heartbeat LED" H 2250 6750 50  0000 L CNN
F 2 "LEDs:LED_0603_HandSoldering" H 2200 6750 50  0001 C CNN
F 3 "file:///Users/durandal/Documents/Projects/KiCAD%20tutorials/ATTiny85%201%20pixel%20RGB/datasheets/Power%20LED/Osram-LS_L29K-G1J2-1-Z-datasheet.pdf" H 2300 6850 50  0001 C CNN
F 4 "0603" H 2250 6650 50  0000 L CNN "Package Size"
F 5 "LS L29K-G1J2-1-Z" H 2250 6550 50  0000 L CNN "MFR P/N"
	1    2100 6750
	1    0    0    -1  
$EndComp
$Comp
L MyConnectors:ISP_Header J1
U 1 1 5A4A569D
P 2900 2500
F 0 "J1" H 3100 2700 50  0000 C CNN
F 1 "ISP_Header" H 3050 2600 50  0000 L CNN
F 2 "MyConnectors:ISP_Header_Pogo_2x03_Pitch2.54mm" H 3150 2150 50  0001 C CNN
F 3 "" H 3150 2150 50  0001 C CNN
F 4 "N/S, pogo pin" H 3050 2200 50  0000 L CNN "PN"
	1    2900 2500
	1    0    0    -1  
$EndComp
$Comp
L MyConnectors:01x02_Connector J2
U 1 1 5A4A618A
P 10100 4950
F 0 "J2" H 10200 5000 50  0000 L CNN
F 1 "Batt Conn" H 10200 4900 50  0000 L CNN
F 2 "Connectors_JST:JST_PH_S2B-PH-K_02x2.00mm_Angled" H 10100 4950 50  0001 C CNN
F 3 "" H 10100 4950 50  0001 C CNN
F 4 "S2B-PH-K-S" H 10200 4800 50  0000 L CNN "Part Number"
	1    10100 4950
	1    0    0    -1  
$EndComp
$Comp
L MyCapacitors:CP1_Small_vert C2
U 1 1 5A4A67A2
P 5650 7350
F 0 "C2" H 5750 7500 50  0000 L CNN
F 1 "100uF" H 5750 7400 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-C_EIA-6032-28_Reflow" H 5650 7350 50  0001 C CNN
F 3 "" H 5660 7420 50  0001 C CNN
F 4 "10V" H 5750 7300 50  0000 L CNN "Voltage Rating"
F 5 "2312" H 5750 7200 50  0000 L CNN "Package Size"
F 6 "TAJC107K010RNJ" H 5750 7100 50  0000 L CNN "MFR P/N"
	1    5650 7350
	1    0    0    -1  
$EndComp
$Comp
L MyCapacitors:C_Small_vert C3
U 1 1 5A4A69CF
P 6750 4300
F 0 "C3" H 6850 4400 50  0000 L CNN
F 1 "0.1uF" H 6850 4300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6750 4275 50  0001 L CNN
F 3 "" H 6850 4375 50  0001 L CNN
F 4 "0603" H 6850 4100 50  0000 L CNN "Package Size"
F 5 "50V" H 6850 4200 50  0000 L CNN "Voltage Rating"
F 6 "06035C104KAZ2A" H 6850 4000 50  0000 L CNN "MFR P/N"
	1    6750 4300
	1    0    0    -1  
$EndComp
Text Notes 950  6300 0    60   ~ 0
Vf = 1.8V, 2 mA Ityp\n5V-1.8 = 3.2V\n3.2V/1.5k = 2.1 mA
$Comp
L power:+BATT #PWR011
U 1 1 5A4AE4C2
P 1900 4050
F 0 "#PWR011" H 1900 3900 50  0001 C CNN
F 1 "+BATT" H 1900 4190 50  0000 C CNN
F 2 "" H 1900 4050 50  0001 C CNN
F 3 "" H 1900 4050 50  0001 C CNN
	1    1900 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5A4AE4C8
P 1900 5050
F 0 "#PWR012" H 1900 4800 50  0001 C CNN
F 1 "GND" H 1900 4900 50  0000 C CNN
F 2 "" H 1900 5050 50  0001 C CNN
F 3 "" H 1900 5050 50  0001 C CNN
	1    1900 5050
	1    0    0    -1  
$EndComp
$Comp
L MyResistors:R_vert R2
U 1 1 5A4AE4CF
P 1900 4250
F 0 "R2" H 2000 4350 50  0000 L CNN
F 1 "10k" H 2000 4250 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1830 4250 50  0001 C CNN
F 3 "" H 1900 4250 50  0001 C CNN
F 4 "0603" H 2000 4150 50  0000 L CNN "Field4"
F 5 "RC0603FR-0710KL" H 2000 4050 50  0000 L CNN "MFR P/N"
	1    1900 4250
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:10-XX_vert S1
U 1 1 5A4AE4D6
P 1800 4750
F 0 "S1" H 1950 4900 50  0000 L BNN
F 1 "Button" H 1950 4800 50  0000 L BNN
F 2 "Buttons_Switches_THT:SW_TH_Tactile_Omron_B3F-10xx" H 1950 5050 50  0001 L CNN
F 3 "" H 1800 4750 60  0001 C CNN
F 4 "B3F-1000" H 1950 4700 50  0000 L CNN "Part Number"
	1    1800 4750
	1    0    0    -1  
$EndComp
NoConn ~ 9700 4200
NoConn ~ 9700 4550
$Comp
L power:+BATT #PWR013
U 1 1 5A4E96E2
P 5650 7100
F 0 "#PWR013" H 5650 6950 50  0001 C CNN
F 1 "+BATT" H 5650 7240 50  0000 C CNN
F 2 "" H 5650 7100 50  0001 C CNN
F 3 "" H 5650 7100 50  0001 C CNN
	1    5650 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5A4E9726
P 5650 7550
F 0 "#PWR014" H 5650 7300 50  0001 C CNN
F 1 "GND" H 5650 7400 50  0000 C CNN
F 2 "" H 5650 7550 50  0001 C CNN
F 3 "" H 5650 7550 50  0001 C CNN
	1    5650 7550
	1    0    0    -1  
$EndComp
$Comp
L MySwitchesButtons:SW_DPDT_x2_horiz SW1
U 1 1 5A4B2CB7
P 9500 4100
F 0 "SW1" H 9400 4550 50  0000 L CNN
F 1 "Power Switch" H 9400 4450 50  0000 L CNN
F 2 "MySwitches:E-Switch_EG1390" H 9525 4125 50  0001 C CNN
F 3 "" H 9525 4125 50  0001 C CNN
F 4 "AYZ0202AGRLC" H 9400 4350 50  0000 L CNN "Part Number"
	1    9500 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5A796B1D
P 6150 6750
F 0 "#PWR015" H 6150 6500 50  0001 C CNN
F 1 "GND" H 6150 6600 50  0000 C CNN
F 2 "" H 6150 6750 50  0001 C CNN
F 3 "" H 6150 6750 50  0001 C CNN
	1    6150 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5A796BBC
P 7100 6750
F 0 "#PWR016" H 7100 6500 50  0001 C CNN
F 1 "GND" H 7100 6600 50  0000 C CNN
F 2 "" H 7100 6750 50  0001 C CNN
F 3 "" H 7100 6750 50  0001 C CNN
	1    7100 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5A79742F
P 11850 6750
F 0 "#PWR017" H 11850 6500 50  0001 C CNN
F 1 "GND" H 11850 6600 50  0000 C CNN
F 2 "" H 11850 6750 50  0001 C CNN
F 3 "" H 11850 6750 50  0001 C CNN
	1    11850 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5A79747F
P 12800 6750
F 0 "#PWR018" H 12800 6500 50  0001 C CNN
F 1 "GND" H 12800 6600 50  0000 C CNN
F 2 "" H 12800 6750 50  0001 C CNN
F 3 "" H 12800 6750 50  0001 C CNN
	1    12800 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5A79769B
P 13750 6750
F 0 "#PWR019" H 13750 6500 50  0001 C CNN
F 1 "GND" H 13750 6600 50  0000 C CNN
F 2 "" H 13750 6750 50  0001 C CNN
F 3 "" H 13750 6750 50  0001 C CNN
	1    13750 6750
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR020
U 1 1 5A79904F
P 7000 6150
F 0 "#PWR020" H 7000 6000 50  0001 C CNN
F 1 "+BATT" H 7000 6290 50  0000 C CNN
F 2 "" H 7000 6150 50  0001 C CNN
F 3 "" H 7000 6150 50  0001 C CNN
	1    7000 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5A7971A8
P 10900 6750
F 0 "#PWR021" H 10900 6500 50  0001 C CNN
F 1 "GND" H 10900 6600 50  0000 C CNN
F 2 "" H 10900 6750 50  0001 C CNN
F 3 "" H 10900 6750 50  0001 C CNN
	1    10900 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5A796FD1
P 9950 6750
F 0 "#PWR022" H 9950 6500 50  0001 C CNN
F 1 "GND" H 9950 6600 50  0000 C CNN
F 2 "" H 9950 6750 50  0001 C CNN
F 3 "" H 9950 6750 50  0001 C CNN
	1    9950 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5A796E11
P 9000 6750
F 0 "#PWR023" H 9000 6500 50  0001 C CNN
F 1 "GND" H 9000 6600 50  0000 C CNN
F 2 "" H 9000 6750 50  0001 C CNN
F 3 "" H 9000 6750 50  0001 C CNN
	1    9000 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5A796DC1
P 8050 6750
F 0 "#PWR024" H 8050 6500 50  0001 C CNN
F 1 "GND" H 8050 6600 50  0000 C CNN
F 2 "" H 8050 6750 50  0001 C CNN
F 3 "" H 8050 6750 50  0001 C CNN
	1    8050 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2500 2650 2500
Wire Wire Line
	2650 2500 2650 4200
Wire Wire Line
	3800 2700 4050 2700
Wire Wire Line
	3800 2500 4050 2500
Wire Wire Line
	3800 4100 3900 4100
Wire Wire Line
	6600 4100 6750 4100
Wire Wire Line
	7850 3650 7850 4100
Connection ~ 7850 4100
Wire Wire Line
	9900 5050 9900 5350
Wire Wire Line
	9900 4000 9900 4400
Wire Wire Line
	9150 3600 9150 4100
Wire Wire Line
	1750 2400 1750 2700
Wire Wire Line
	2100 7100 2100 6900
Wire Wire Line
	2100 5600 2100 6600
Wire Wire Line
	3800 2600 3800 4100
Connection ~ 3800 4100
Wire Wire Line
	2850 4600 3900 4600
Wire Wire Line
	2750 4300 3700 4300
Wire Wire Line
	3700 4300 3700 6500
Connection ~ 3700 4300
Wire Wire Line
	2900 2600 2750 2600
Wire Wire Line
	2750 2600 2750 4300
Wire Wire Line
	3800 6400 5200 6400
Wire Wire Line
	3700 6500 5200 6500
Wire Wire Line
	1750 3100 1750 3250
Wire Wire Line
	6750 4100 6750 4250
Connection ~ 6750 4100
Wire Wire Line
	6750 4450 6750 4600
Connection ~ 6750 4600
Wire Wire Line
	2100 7450 2100 7650
Wire Wire Line
	1900 5050 1900 4950
Wire Wire Line
	1900 4950 1800 4950
Wire Wire Line
	1900 4550 1800 4550
Wire Wire Line
	1900 4450 1900 4500
Wire Wire Line
	1900 4100 1900 4050
Wire Wire Line
	1900 4500 3900 4500
Connection ~ 1900 4500
Wire Wire Line
	9150 4500 9300 4500
Connection ~ 9150 4100
Wire Wire Line
	9700 4400 9900 4400
Connection ~ 9900 4400
Wire Wire Line
	9150 4100 9300 4100
Wire Wire Line
	9700 4000 9900 4000
Wire Wire Line
	5650 7100 5650 7150
Connection ~ 5650 7150
Wire Wire Line
	6050 7150 5650 7150
Wire Wire Line
	5650 7450 5650 7500
Wire Wire Line
	5200 7500 5650 7500
Connection ~ 5650 7500
Wire Wire Line
	2650 4200 3900 4200
Wire Wire Line
	5200 6600 5200 7500
Wire Wire Line
	6050 6400 6150 6400
Wire Wire Line
	6050 6500 6150 6500
Wire Wire Line
	13750 6750 13750 6600
Wire Wire Line
	12800 6750 12800 6600
Wire Wire Line
	11850 6750 11850 6600
Wire Wire Line
	10900 6750 10900 6600
Wire Wire Line
	9950 6750 9950 6600
Wire Wire Line
	9000 6750 9000 6600
Wire Wire Line
	8050 6750 8050 6600
Wire Wire Line
	7100 6750 7100 6600
Wire Wire Line
	6150 6750 6150 6600
Wire Wire Line
	7000 6400 7100 6400
Wire Wire Line
	7000 6500 7100 6500
Wire Wire Line
	7950 6400 8050 6400
Wire Wire Line
	7950 6500 8050 6500
Wire Wire Line
	8900 6400 9000 6400
Wire Wire Line
	8900 6500 9000 6500
Wire Wire Line
	9850 6400 9950 6400
Wire Wire Line
	9850 6500 9950 6500
Wire Wire Line
	10800 6400 10900 6400
Wire Wire Line
	10800 6500 10900 6500
Wire Wire Line
	11750 6400 11850 6400
Wire Wire Line
	11750 6500 11850 6500
Wire Wire Line
	12700 6400 12800 6400
Wire Wire Line
	12700 6500 12800 6500
Wire Wire Line
	13650 6400 13750 6400
Wire Wire Line
	13650 6500 13750 6500
Wire Wire Line
	6050 6600 6050 7150
Wire Wire Line
	7000 6150 7000 6600
$Comp
L power:+BATT #PWR025
U 1 1 5A799F3A
P 7950 6150
F 0 "#PWR025" H 7950 6000 50  0001 C CNN
F 1 "+BATT" H 7950 6290 50  0000 C CNN
F 2 "" H 7950 6150 50  0001 C CNN
F 3 "" H 7950 6150 50  0001 C CNN
	1    7950 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR026
U 1 1 5A79A095
P 8900 6150
F 0 "#PWR026" H 8900 6000 50  0001 C CNN
F 1 "+BATT" H 8900 6290 50  0000 C CNN
F 2 "" H 8900 6150 50  0001 C CNN
F 3 "" H 8900 6150 50  0001 C CNN
	1    8900 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR027
U 1 1 5A79A0E5
P 9850 6150
F 0 "#PWR027" H 9850 6000 50  0001 C CNN
F 1 "+BATT" H 9850 6290 50  0000 C CNN
F 2 "" H 9850 6150 50  0001 C CNN
F 3 "" H 9850 6150 50  0001 C CNN
	1    9850 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR028
U 1 1 5A79A45A
P 10800 6150
F 0 "#PWR028" H 10800 6000 50  0001 C CNN
F 1 "+BATT" H 10800 6290 50  0000 C CNN
F 2 "" H 10800 6150 50  0001 C CNN
F 3 "" H 10800 6150 50  0001 C CNN
	1    10800 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR029
U 1 1 5A79A4AA
P 11750 6150
F 0 "#PWR029" H 11750 6000 50  0001 C CNN
F 1 "+BATT" H 11750 6290 50  0000 C CNN
F 2 "" H 11750 6150 50  0001 C CNN
F 3 "" H 11750 6150 50  0001 C CNN
	1    11750 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR030
U 1 1 5A79A4FA
P 12700 6150
F 0 "#PWR030" H 12700 6000 50  0001 C CNN
F 1 "+BATT" H 12700 6290 50  0000 C CNN
F 2 "" H 12700 6150 50  0001 C CNN
F 3 "" H 12700 6150 50  0001 C CNN
	1    12700 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR031
U 1 1 5A79A7CE
P 13650 6150
F 0 "#PWR031" H 13650 6000 50  0001 C CNN
F 1 "+BATT" H 13650 6290 50  0000 C CNN
F 2 "" H 13650 6150 50  0001 C CNN
F 3 "" H 13650 6150 50  0001 C CNN
	1    13650 6150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR032
U 1 1 5A79A81E
P 14750 6200
F 0 "#PWR032" H 14750 6050 50  0001 C CNN
F 1 "+BATT" H 14750 6340 50  0000 C CNN
F 2 "" H 14750 6200 50  0001 C CNN
F 3 "" H 14750 6200 50  0001 C CNN
	1    14750 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 6600 8900 6150
Wire Wire Line
	9850 6600 9850 6150
Wire Wire Line
	10800 6150 10800 6600
Wire Wire Line
	11750 6150 11750 6600
Wire Wire Line
	12700 6150 12700 6600
Wire Wire Line
	13650 6150 13650 6600
Wire Wire Line
	14600 6600 14750 6600
Wire Wire Line
	14750 6600 14750 6200
NoConn ~ 14600 6400
NoConn ~ 14600 6500
Wire Wire Line
	7950 6150 7950 6600
Wire Wire Line
	7850 4800 7850 4450
Wire Wire Line
	6600 4600 6750 4600
Wire Wire Line
	6750 4800 7850 4800
Connection ~ 1750 2700
Wire Wire Line
	1750 2700 2850 2700
Wire Wire Line
	2850 4600 2850 2700
Connection ~ 2850 2700
$Comp
L apa102c:APA102C U2
U 1 1 5AF3EA7D
P 5600 6650
F 0 "U2" H 5450 7006 60  0000 C CNN
F 1 "APA102C" H 5600 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 5600 6600 60  0001 C CNN
F 3 "" H 5600 6600 60  0001 C CNN
	1    5600 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U3
U 1 1 5AF3EB9C
P 6550 6650
F 0 "U3" H 6400 7006 60  0000 C CNN
F 1 "APA102C" H 6550 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 6550 6600 60  0001 C CNN
F 3 "" H 6550 6600 60  0001 C CNN
	1    6550 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U4
U 1 1 5AF3EC19
P 7500 6650
F 0 "U4" H 7350 7006 60  0000 C CNN
F 1 "APA102C" H 7500 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 7500 6600 60  0001 C CNN
F 3 "" H 7500 6600 60  0001 C CNN
	1    7500 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U5
U 1 1 5AF3EF8D
P 8450 6650
F 0 "U5" H 8300 7006 60  0000 C CNN
F 1 "APA102C" H 8450 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 8450 6600 60  0001 C CNN
F 3 "" H 8450 6600 60  0001 C CNN
	1    8450 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U6
U 1 1 5AF3F067
P 9400 6650
F 0 "U6" H 9250 7006 60  0000 C CNN
F 1 "APA102C" H 9400 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 9400 6600 60  0001 C CNN
F 3 "" H 9400 6600 60  0001 C CNN
	1    9400 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U7
U 1 1 5AF3F29F
P 10350 6650
F 0 "U7" H 10200 7006 60  0000 C CNN
F 1 "APA102C" H 10350 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 10350 6600 60  0001 C CNN
F 3 "" H 10350 6600 60  0001 C CNN
	1    10350 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U8
U 1 1 5AF3F4B6
P 11300 6650
F 0 "U8" H 11150 7006 60  0000 C CNN
F 1 "APA102C" H 11300 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 11300 6600 60  0001 C CNN
F 3 "" H 11300 6600 60  0001 C CNN
	1    11300 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U9
U 1 1 5AF3F6C4
P 12250 6650
F 0 "U9" H 12100 7006 60  0000 C CNN
F 1 "APA102C" H 12250 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 12250 6600 60  0001 C CNN
F 3 "" H 12250 6600 60  0001 C CNN
	1    12250 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U10
U 1 1 5AF3F8F7
P 13200 6650
F 0 "U10" H 13050 7006 60  0000 C CNN
F 1 "APA102C" H 13200 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 13200 6600 60  0001 C CNN
F 3 "" H 13200 6600 60  0001 C CNN
	1    13200 6650
	1    0    0    -1  
$EndComp
$Comp
L apa102c:APA102C U11
U 1 1 5AF3FAB9
P 14150 6650
F 0 "U11" H 14000 7006 60  0000 C CNN
F 1 "APA102C" H 14150 6600 60  0000 C CNN
F 2 "MyLEDs:LED_RGB_5050-6_Compact" H 14150 6600 60  0001 C CNN
F 3 "" H 14150 6600 60  0001 C CNN
	1    14150 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 4400 3600 4400
Wire Wire Line
	3600 5600 3600 4400
Wire Wire Line
	2100 5600 3600 5600
Text Notes 4650 3850 0    60   ~ 0
WRONG FOOTPRINT\n
Wire Wire Line
	7850 4100 7850 4250
Wire Wire Line
	3800 4100 3800 6400
Wire Wire Line
	3700 4300 3900 4300
Wire Wire Line
	6750 4100 7850 4100
Wire Wire Line
	6750 4600 6750 4800
Wire Wire Line
	1900 4500 1900 4550
Wire Wire Line
	9150 4100 9150 4500
Wire Wire Line
	9900 4400 9900 4950
Wire Wire Line
	5650 7150 5650 7250
Wire Wire Line
	5650 7500 5650 7550
Wire Wire Line
	1750 2700 1750 2900
Wire Wire Line
	2850 2700 2900 2700
$EndSCHEMATC
