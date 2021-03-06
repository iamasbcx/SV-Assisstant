#pragma once

enum DIMMType
{
	DIMM_UNKNOWN = 0,
	SDRAM = 4,
	ROM = 5,
	DDR = 6,
	DDR2 = 8,
	DDR3 = 0xB,
	DDR4 = 0xC,
	DDR4E = 0x0E,
	LPDDR3 = 0x0F,
	LPDDR4 = 0x10
};

#pragma pack(push,1)
typedef struct _DDR3_INFO
{
	union 
	{
		struct  
		{
			union
			{
				struct 
				{
					BYTE Byte_Used : 4; // SPD Bytes Used
					BYTE Byte_Total : 3; // SPD Bytes Total
					BYTE CRC_Coverage : 1; //CRC Coverage
				}bits;
				BYTE SPD_Bytes_info; //BYTE0 Value
			}sSPDinfo;// Byte 0: Number of Bytes Used / Number of Bytes in SPD Device / CRC Coverage
			BYTE sSPDRevision; // Byte 1: SPD Revision
			BYTE sDRAMType; // Byte 2: Key Byte / DRAM Device Type
			union
			{
				struct
				{
					BYTE Module_Type : 4; // Module Type
					BYTE Reserve : 4; // Reserve
				}bits;
				BYTE ModuleType; // BYTE3 Value
			}sModuleType;// Byte 3: Key Byte / Module Type
			union
			{
				struct
				{
					BYTE Capacity : 4; // Total SDRAM capacity, in megabits
					BYTE Bank : 3; // Bank Address Bits
					BYTE Reserved : 1; // Reserved
				}bits;
				BYTE SDRAMBank_Density; //BYTE4 Value
			}sSDRAMBank_Density;// Byte 4 : SDRAM Density and Banks
			union
			{
				struct
				{
					BYTE Column_Address : 3; // Column Address Bits
					BYTE Row_Address : 3; // Row Address Bits
					BYTE Reserved : 2; // Reserved
				}bits;
				BYTE SDRAMAddr; //BYTE5 Value
			}sSDRAMAddr;// Byte 5: SDRAM Addressing
			union
			{
				struct
				{
					BYTE VDD_1_5 : 1; // 1.5 V operable 0 = 1.5 V operable 1 = NOT 1.5 V operable
					BYTE VDD_1_35 : 1; // 1.35 V operable 0 = NOT 1.35 V operable 1 = 1.35 V operable
					BYTE VDD_1_2X : 1; // 1.2X V operable 0 = NOT 1.2X V operable 1 = 1.2X V operable
					BYTE Reserved : 5; // Reserved
				}bits;
				BYTE VDD; // BYTE6 Value
			}sModuleNominalVoltage;// Byte 6: Module Nominal Voltage, VDD
			union
			{
				struct
				{
					BYTE SDRAM_Depth_Width : 3; // SDRAM Device Width
					BYTE Number_of_Ranks : 3; // Number of Ranks
					BYTE Reserved : 2; // Reserved
				}bits;
				BYTE ModuleOrganization; //BYTE7 Value
			}sModuleOrganization;// Byte 7: Module Organization
			union
			{
				struct
				{
					BYTE Primary_bus_width : 3; // Primary bus width, in bits
					BYTE Bus_width_extension : 2; // Bus width extension, in bits
					BYTE Reserved : 3; // Reserved
				}bits;
				BYTE BusWidth; //BYTE8 Value
			}sBusWidth;// Byte 8: Module Memory Bus Width
			union
			{
				struct
				{
					BYTE FTB_Divisor : 4; // Fine Timebase (FTB) Divisor
					BYTE FTB_Dividend : 4; // Values defined from 1 to 15
				}bits;
				BYTE FTB; //BYTE9 Value
			}sFTB;// Byte 9: Fine Timebase (FTB) Dividend / Divisor
			BYTE MTB_Dividend; // Byte 10: Medium Timebase (MTB) Dividend
			BYTE MTB_Divisor; // Byte 11: Medium Timebase (MTB) Divisor
			BYTE sTCKmin;// Byte 12: SDRAM Minimum Cycle Time (tCKmin) Results(ns) = Tckmin(MTB units) * Timebase(ns) 
			BYTE Reserved13; // Byte 13: Reserved
			union
			{
				struct
				{
					BYTE CL4 : 1; // CL = 4
					BYTE CL5 : 1; // CL = 5
					BYTE CL6 : 1; // CL = 6
					BYTE CL7 : 1; // CL = 7
					BYTE CL8 : 1; // CL = 8
					BYTE CL9 : 1; // CL = 9
					BYTE CL10 : 1; // CL = 10
					BYTE CL11 : 1; // CL = 11
				}bits;
				BYTE LeastSignificant; //BYTE14 Value
			}sCASLeastSignificant;// Byte 14: CAS Latencies Supported, Least Significant Byte
			union
			{
				struct
				{
					BYTE CL12 : 1; // CL = 12
					BYTE CL13 : 1; // CL = 13
					BYTE CL14 : 1; // CL = 14
					BYTE CL15 : 1; // CL = 15
					BYTE CL16 : 1; // CL = 16
					BYTE CL17 : 1; // CL = 17
					BYTE CL18 : 1; // CL = 18
					BYTE Reserved : 1; // Reserved
				}bits;
				BYTE MostSignificant; //BYTE15 Value
			}sCASMostSignificant;// Byte 15: CAS Latencies Supported, Most Significant Byte
			BYTE sTAAmin; // Byte 16: Minimum CAS Latency Time (tAAmin) tAAmin Result(ns) = tAAmin(MTB units) * Timebase(ns)
			BYTE sTWRmin; // Byte 17: Minimum Write Recovery Time (tWRmin) tWRmin Result(ns) = tWRmin(MTB units) * Timebase(ns)
			BYTE sTRCDmin; // Byte 18: Minimum RAS# to CAS# Delay Time (tRCDmin) tRCDmin Result(ns) = tRCDmin(MTB units) * Timebase(ns)
			BYTE sTRDDmin; // Byte 19: Minimum Row Active to Row Active Delay Time (tRRDmin) tRRDmin Result(ns) = tRRDmin(MTB units) * Timebase(ns)
			BYTE sTRPmin; // Byte 20: Minimum Row Precharge Delay Time (tRPmin) tRPmin Result(ns) = tRPmin(MTB units) * Timebase(ns)
			union
			{
				struct
				{
					BYTE tRASmin_Most : 4; // tRAS Most Significant Nibble
					BYTE tRCmin_Most : 4; // tRC Most Significant Nibble
				}bits;
				BYTE Upper_TRAS_TRCmin; //BYTE21 Value
			}sUpper_TRAS_TRCmin; // Byte 21: Upper Nibbles for tRAS and tRC
			BYTE sTRASminLeast; // Byte 22: Minimum Active to Precharge Delay Time (tRASmin), Least Significant Byte
			BYTE sTRCminLeast; // Byte 23: Minimum Active to Active/Refresh Delay Time (tRCmin), Least Significant Byte
			BYTE sTRFCminLeast; // Byte 24: Minimum Refresh Recovery Delay Time (tRFCmin), Least Significant Byte
			BYTE sTRFCminMost; // Byte 25: Minimum Refresh Recovery Delay Time (tRFCmin), Most Significant Byte
			BYTE sTWTRmin; // Byte 26: Minimum Internal Write to Read Command Delay Time (tWTRmin)
			BYTE sTRTPmin; // Byte 27: Minimum Internal Read to Precharge Command Delay Time (tRTPmin)
			union
			{
				struct
				{
					BYTE tFAWmin_Most : 4; // tFAW Most Significant Nibble
					BYTE Reserved : 4; // Reserved
				}bits;
				BYTE TFAWminMost; //BYTE28 Value
			}sTFAWminMost; // Byte 28: Upper Nibble for tFAW
			BYTE sTFAWminMeast; // Byte 29: Minimum Four Activate Window Delay Time (tFAWmin), Least Significant Byte
			union
			{
				struct
				{
					BYTE RZQ_6 : 1; // RZQ / 6 0 = Not Supported 1 = Supported
					BYTE RZQ_7 : 1; // RZQ / 7 0 = Not Supported 1 = Supported
					BYTE Reserved : 5; // Reserved
					BYTE DLL_Off_Mode : 1; // DLL-Off Mode Support 0 = Not Supported 1 = Supported
				}bits;
				BYTE SDRAMOptional; //BYTE30 Value
			}sSDRAMOptional; // Byte 30: SDRAM Optional Features
			union
			{
				struct
				{
					BYTE ExtendedTemRange : 1; // Extended Temperature Range 1 = Normal and	extended operating temperature range 0 - 95 ��C supported 0 = Normal operating temperature range	0 - 85 ��C supported
					BYTE ExtendedTemRefreshRate : 1; // Extended Temperature Refresh Rate 1 = Extended operating temperature range from 85 - 95 ��C supported with standard 1X refresh rate	0 = Use in extended	operating temperature range from 85 - 95 ��C requires 2X refresh	rate
					BYTE ASR : 1; //Auto Self Refresh 1 = ASR is supported and the SDRAM will determine the proper refresh rate for any supported	temperature 0 = ASR is not supported
					BYTE ODTS : 1; // On-die Thermal Sensor(ODTS) Readout 1 = On - die thermal sensor readout is supported 0 = On - die thermal sensor readout is not supported(pending ballot of ODTS)
					BYTE Reserved : 3; // Reserved
					BYTE PASR : 1; // Partial Array Self Refresh 1 = Supported 0 = Not supported
				}bits;
				BYTE ThermalRefresh; //BYTE31 Value
			}sThermalRefresh;// Byte 31: SDRAM Thermal and Refresh Options
			union
			{
				struct
				{
					BYTE ThermalSensorAccuracy : 7; // 0 = Undefined All others settings to be defined.
					BYTE ThermalSensor : 1; // 0 = Thermal sensor not incorporated onto this assembly 1 = Thermal sensor incorporated onto this assembly
				}bits;
				BYTE ThermalSensor; //BYTE32 Value Note : Thermal sensor compliant with TSE2002 specifications.
			}sThermalSensor; // Byte 32: Module Thermal Sensor
			union
			{
				struct
				{
					BYTE NonStandardDescription : 7; // Non-Standard Device Description 0 = Undefined All others settings to be defined.
					BYTE SDRAMDeviceType : 1; //0 = Standard Monolithic DRAM Device 1 = Non-Standard Device (This includes Dual Die, Quad Die, Multi-Die and Physical stacked devices - anything that is outside the standard monolithic device.)	
				}bits;
				BYTE SDRAMDeviceType; //BYTE33 Value
			}sSDRAMDeviceType; // Byte 33: SDRAM Device Type
			BYTE Reserved34[26]; // Byte 34 ~ 59: Reserved, General Section
								 // Module-Specific Section: Bytes 60 ~ 116
			BYTE Module_Specific[57];
			// Unique Module ID: Bytes 117 ~ 125
			BYTE ModuleManufacturerIDLeast; // Byte 117: Module Manufacturer ID Code, Least Significant Byte
			BYTE ModuleManufacturerIDMost; // Byte 118: Module Manufacturer ID Code, Most Significant Byte
			BYTE ManufacturingLocation; // Byte 119: Module Manufacturing Location
			BYTE ManufacturingDate[2]; // Bytes 120 ~ 121: Module Manufacturing Date
			BYTE SerialNumber[4]; // Bytes 122 ~ 125: Module Serial Number
			BYTE CRC[2]; // Bytes 126 ~ 127: SPD Cyclical Redundancy Code (CRC)
			BYTE PartNumber[18]; // Bytes 128 ~ 145: Module Part Number
			BYTE RevisionCode[2]; // Bytes 146 ~ 147: Module Revision Code
			BYTE DRAMManufacturerIDLeast; // Byte 148: DRAM Manufacturer ID Code, Least Significant Byte
			BYTE DRAMManufacturerIDMost; // Byte 149: DRAM Manufacturer ID Code, Most Significant Byte
			BYTE ManufacturerSpecificData[26]; // Bytes 150 ~ 175: Manufacturer��s Specific Data
			BYTE CustomerUse[80]; // Open for Customer Use
		}DDR3_Detail;
		BYTE DDR3_Bits[0x100];
	};
} DDR3_INFO, *PDDR3_INFO;

typedef struct _DDR4_INFO
{
	union
	{
		struct 
		{
			union
			{
				struct
				{
					BYTE Byte_Used : 4; // SPD Bytes Used
					BYTE Byte_Total : 3; // SPD Bytes Total
					BYTE CRC_Coverage : 1; //CRC Coverage
				}bits;
				BYTE SPD_Bytes_info; //BYTE0 Value
			}sSPDinfo;// Byte 0: Number of Bytes Used / Number of Bytes in SPD Device / CRC Coverage
			BYTE sSPDRevision; // Byte 1: SPD Revision
			BYTE sDRAMType; // Byte 2: Key Byte / DRAM Device Type
			union
			{
				struct
				{
					BYTE Module_Type : 4; // Module Type
					BYTE HybridMedia : 3; // Hybrid Media
					BYTE Hybrid 	 : 1; //Hybrid
				}bits;
				BYTE ModuleType; // BYTE3 Value
			}sModuleType;// Byte 3: Key Byte / Module Type
			union
			{
				struct
				{
					BYTE Capacity 		 : 4; // Total SDRAM capacity, in megabits
					BYTE BankAddressBits : 2; // Bank Address Bits
					BYTE BankGroupBits 	 : 2; // Bank Group Bits
				}bits;
				BYTE SDRAMBank_Density; //BYTE4 Value
			}sSDRAMBank_Density;// Byte 4 : SDRAM Density and Banks
			union
			{
				struct
				{
					BYTE Column_Address : 3; // Column Address Bits
					BYTE Row_Address : 3; // Row Address Bits
					BYTE Reserved : 2; // Reserved
				}bits;
				BYTE SDRAMAddr; //BYTE5 Value
			}sSDRAMAddr;// Byte 5: SDRAM Addressing
			union
			{
				struct
				{
					BYTE SignalLoading : 2; // Refers to loading on signals at the SDRAM balls. Loading on certain signals (CKE, ODT, etc.) per specification of device stacking as defined in JESD79-4.
					BYTE Reserved : 2; // Reserved
					BYTE DieCount : 3; // Die Count
					BYTE PackageTypeBit : 1; // Primary SDRAM Package Type
				}bits;
				BYTE PackageTypel; // BYTE6 Value
			}sPackageType;// Byte 6: Primary SDRAM Package Type
			union
			{
				struct
				{
					BYTE MAC : 4; // Maximum Activate Count
					BYTE tMAW : 2; // Maximum Activate Window
					BYTE Reserved : 2; // Reserved
				}bits;
				BYTE OptionalFeatures; //BYTE7 Value
			}sOptionalFeatures;// Byte 7: SDRAM Optional Features
			BYTE sThermalandRefreshOptions; //Byte8 : Thermal and Refresh Options
			union
			{
				struct
				{
					BYTE Reserved : 5; // Reserved
					BYTE tMAW : 1; // Soft PPR
					BYTE PPR : 2; // Post Package Repair (PPR)
				}bits;
				BYTE OtherOptionalFeatures; //BYTE9 Value
			}sOtherOptionalFeatures;// Byte 9:Other SDRAM Optional Features
			union
			{
				struct
				{
					BYTE SignalLoading : 2; // Refers to loading on signals at the SDRAM balls. Loading on certain signals (CKE, ODT, etc.) per specification of device stacking as defined in JESD79-4.
					BYTE DRAMDensityRatio2 : 2; // DRAM Density Ratio2
					BYTE DieCount : 3; // Die Count
					BYTE PackageType : 1; // Primary SDRAM Package Type
				}bits;
				BYTE SecondaryPackageType; // BYTE10 Value
			}sSecondaryPackageType;// Byte 10: Secondary SDRAM Package Type
			union
			{
				struct
				{
					BYTE DRAMVDD1_2VBit0 : 1; // A value on bits 1~0 of 11 defines DRAM support of a nominal operable voltage of 1.2 V only.
					BYTE DRAMVDD1_2VBit1 : 1; // A value on bits 1~0 of 11 defines DRAM support of a nominal operable voltage of 1.2 V only.
					BYTE Reserved : 6; // Reserved
				}bits;
				BYTE VDD; // BYTE11 Value
			}sModuleNominalVoltage;// Byte 11: Module Nominal Voltage, VDD
			union
			{
				struct
				{
					BYTE SDRAM_Depth_Width : 3; // SDRAM Device Width
					BYTE Number_of_Ranks_per_DIMM : 3; // Number of Package Ranks per DIMM
					BYTE Rank_Mix : 1; // Rank Mix
					BYTE Reserved : 1; // Reserved
				}bits;
				BYTE ModuleOrganization; //BYTE12 Value
			}sModuleOrganization;// Byte 12: Module Organization
			union
			{
				struct
				{
					BYTE Primary_bus_width : 3; // Primary bus width, in bits
					BYTE Bus_width_extension : 2; // Bus width extension, in bits
					BYTE Reserved : 3; // Reserved
				}bits;
				BYTE BusWidth; //BYTE13 Value
			}sBusWidth;// Byte 13: Module Memory Bus Width
			union
			{
				struct
				{
					BYTE Reserved : 7; // Reserved
					BYTE ThermalSensorBit : 1; // Thermal sensor compliant with TSE2004av specifications
				}bits;
				BYTE ThermalSensor; //BYTE14 Value
			}sThermalSensor;// Byte 14: Module Thermal Sensor
			union
			{
				struct
				{
					BYTE Extended_Base_Module_Type : 4; // Extended Base Module Type
					BYTE Reserved : 4; // Reserved
				}bits;
				BYTE ExtendedModuleType; //BYTE15 Value
			}sExtendedModuleType;// Byte 15: Extended Module Type
			BYTE Reserved16; // Byte16 Reserved16
			union
			{
				struct
				{
					BYTE FTB : 2; // Fine Timebase (FTB)
					BYTE MTB : 2; // Medium Timebase (MTB)
					BYTE Reserved : 4; // Reserved
				}bits;
				BYTE Timebases; //BYTE17 Value
			}sTimebases;// Byte 17: Timebases
			BYTE sTCKmin;// Byte 18: SDRAM Minimum Cycle Time (tCKAVGmin)
			BYTE sTCKmax;// Byte 19: SDRAM Maximum Cycle Time (tCKAVGmax))
			BYTE CASFirstByte;//Byte 20 (0x014): CAS Latencies Supported, First Byte
			BYTE CASSecondByte;//Byte 21 (0x015): CAS Latencies Supported, Second Byte
			BYTE CASThirdByte;//Byte 22 (0x016): CAS Latencies Supported, Third Byte
			BYTE CASFourthByte;//Byte 23 (0x017): CAS Latencies Supported, Fourth Byte
			BYTE sTAAmin; //Byte 24 (0x018): Minimum CAS Latency Time (tAAmin)
			BYTE sTRCDmin; //Byte 25 (0x019): Minimum RAS to CAS Delay Time (tRCDmin)
			BYTE sTRPmin;// Byte 26 (0x01A): Minimum Row Precharge Delay Time (tRPmin)
			union
			{
				struct
				{
					BYTE tRASmin_Most : 4; // tRAS Most Significant Nibbl
					BYTE tRCmin_Most : 4; // tRC Most Significant Nibblee
				}bits;
				BYTE Upper_TRAS_TRCmin; //BYTE27 Value
			}sUpper_TRAS_TRCmin; // Byte 27: Upper Nibbles for tRASmin and tRCmin
			BYTE sTRASminLeast; // Byte 28 (0x01C): Minimum Active to Precharge Delay Time (tRASmin), Least Significant Byte
			BYTE sTRCminLeast; // Byte 29 (0x01D): Minimum Active to Active/Refresh Delay Time (tRCmin), Least Significant Byte
			BYTE sTRFC1minLeast; // Byte 30 (0x01E): Minimum Refresh Recovery Delay Time (tRFC1min), LSB(Least)
			BYTE sTRFC1minMost; // Byte 31 (0x01F): Minimum Refresh Recovery Delay Time (tRFC1min), MSB(Most)
			BYTE sTRFC2minLeast; // Byte 32 (0x020): Minimum Refresh Recovery Delay Time (tRFC2min), LSB(Least)
			BYTE sTRFC2minMost; // Byte 33 (0x021): Minimum Refresh Recovery Delay Time (tRFC2min), MSB(Most)
			BYTE sTRFC4minLeast; //Byte 34 (0x022): Minimum Refresh Recovery Delay Time (tRFC4min), LSB
			BYTE sTRFC4minMost; //Byte 35 (0x023): Minimum Refresh Recovery Delay Time (tRFC4min), MSB
			union
			{
				struct
				{
					BYTE tFAWmin_Most : 4; // tFAW Most Significant Nibble
					BYTE Reserved : 4; // Reserved
				}bits;
				BYTE TFAWminMost; //BYTE36 Value
			}sTFAWminMost; // Byte 36 (0x024): Upper Nibble for tFAW
			BYTE sTFAWminMeast; // Byte 37 (0x025): Minimum Four Activate Window Delay Time (tFAWmin), Least Significant Byte
			BYTE sTRDD_Smin; // Byte 38 (0x026): Minimum Activate to Activate Delay Time (tRRD_Smin), different bank group
			BYTE sTRDD_Lmin; // Byte 39 (0x027): Minimum Activate to Activate Delay Time (tRRD_Lmin), same bank group
			BYTE sTCCD_Lmin; // Byte 40 (0x028): Minimum CAS to CAS Delay Time (tCCD_Lmin), same bank group
			union
			{
				struct
				{
					BYTE tWRmin_Most : 4; // tWR Most Significant Nibble
					BYTE Reserved : 4; // Reserved
				}bits;
				BYTE TWRminMost; //BYTE41 Value
			}sTWRminMost; // Byte 41 (0x029): Upper Nibble for tWRmin
			BYTE sTWRmin; // Byte 42 (0x02A): Minimum Write Recovery Time (tWRmin)
			union
			{
				struct
				{
					BYTE tWTR_S_Most : 4; // tWTR_Smin Most Significant Nibble
					BYTE tWTR_L_Most : 4; // tWTR_Lmin Most Significant Nibble
				}bits;
				BYTE Upper_TWTR_L_TWTR_Smin; //BYTE43 Value
			}sUpper_TWTR_L_TWTR_Smin; // Byte 43 (0x029): Upper Nibbles for tWTRmin
			BYTE sTWTR_Smin; // Byte 44 (0x02C): Minimum Write to Read Time (tWTR_Smin), different bank group
			BYTE sTWTR_Lmin; // Byte 45 (0x02D): Minimum Write to Read Time (tWTR_Lmin), same bank group
			BYTE Reserved46[14]; // Byte 46~59 (0x02E~0x03B): Reserved, Base Configuration Section
			BYTE sBitMapping[18]; // Bytes 60~77 (0x03C~0x04D): Connector to SDRAM Bit Mapping
			BYTE Reserved78[39]; // Bytes 78~116 (0x04E~0x074): Reserved, Base Configuration Section
			BYTE sTCCD_Lmin117; // Byte 117 (0x075): Fine Offset for Minimum CAS to CAS Delay Time (tCCD_Lmin), same bank group
			BYTE sTRRD_Lmin118; // Byte 118 (0x076): Fine Offset for Minimum Activate to Activate Delay Time (tRRD_Lmin), same bank group
			BYTE sTRRD_Smin119; // Byte 119 (0x077): Fine Offset for Minimum Activate to Activate Delay Time (tRRD_Smin), different bank group
			BYTE sTRCmin120;// Byte 120 (0x078): Fine Offset for Minimum Active to Active/Refresh Delay Time (tRCmin)
			BYTE sTRPmin121;// Byte 121 (0x079): Fine Offset for Minimum Row Precharge Delay Time (tRPmin)		
			BYTE sTRCDmin122; // Byte 122 (0x07A): Fine Offset for Minimum RAS to CAS Delay Time (tRCDmin)
			BYTE sTAAmin123; // Byte 123 (0x07B): Fine Offset for Minimum CAS Latency Time (tAAmin)
			BYTE sTCKmax124; // Byte 124 (0x07C): Fine Offset for SDRAM Maximum Cycle Time (tCKAVGmax)
			BYTE sTCKmin125; // Byte 125 (0x07D): Fine Offset for SDRAM Minimum Cycle Time (tCKAVGmin)
			BYTE sCRCLeast; // Byte 126 (0x07E): Cyclical Redundancy Code (CRC) for Base Configuration Section, LSB
			BYTE sCRCMost; // Byte 127 (0x07F): Cyclical Redundancy Code (CRC) for Base Configuration Section, MSB
			BYTE sModule_Specific_Section[64]; // Module-Specific Section: Bytes 128~191 (0x080~0x0BF)
			BYTE sHybrid_Memory_Architecture_Specific[64]; //Hybrid Memory Architecture Specific Parameters: Bytes 192~255
			BYTE sExtended_Function[64]; // Extended Function Parameters Block: Bytes 256~319
			BYTE ModuleManufacturerIDLeast; // Byte 320: Module Manufacturer ID Code, Least Significant Byte
			BYTE ModuleManufacturerIDMost; // Byte 321: Module Manufacturer ID Code, Most Significant Byte
			BYTE ManufacturingLocation; // Byte 322: Module Manufacturing Location
			BYTE ManufacturingDate[2]; // Bytes 323 ~ 324: Module Manufacturing Date
			BYTE SerialNumber[4]; // Bytes 325 ~ 328: Module Serial Number
			BYTE PartNumber[20]; // Bytes 329 ~ 348: Module Part Number
			BYTE RevisionCode; // Bytes 349: Module Revision Code
			BYTE DRAMManufacturerIDLeast; // Byte 350: DRAM Manufacturer ID Code, Least Significant Byte
			BYTE DRAMManufacturerIDMost; // Byte 351: DRAM Manufacturer ID Code, Most Significant Byte
			BYTE DRAMStepping; // Byte 352 (0x160): DRAM Stepping
			BYTE ManufacturerSpecificData[29]; // Bytes 353~381 (0x161~0x17D): Manufacturer�s Specific Data
			BYTE Reserved382[2]; //Byte 382~383 (0x17E~0x17F): Reserved

		}DDR4_Detail;
		BYTE DDR4_Bits[384];
	};
}DDR4_INFO, *PDDR4_INFO;
#pragma pack(pop)

struct MemoryData
{
	MemoryData();
	std::string ModuleType;
	bool SupportsECC;
	size_t ModuleSize;
	std::string Ranks_Banks;
	std::string Voltages;
	std::string MaxBandWidth;
	std::string DataBits;
	std::string ModuleManufacturer;
	std::string DRAMManufacturer;
	std::string PartNumber;
	std::string SerialNumber;
	std::string ProductDate;
};