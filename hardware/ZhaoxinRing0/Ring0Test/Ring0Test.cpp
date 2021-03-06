// Ring0Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "..\hardware assistant\driver\Driverdll.h"
#include "..\hardware assistant\cpu\CPU.h"
#include "..\hardware assistant\gpu\gpu.h"
#include "..\hardware assistant\acpi\ACPI.h"
#include "..\hardware assistant\Audio\CAudio.h"
#include "..\hardware assistant\network\NetworkLib.h"
#include "..\hardware assistant\edid\EDID.h"
#include "..\hardware assistant\smbios\smbiosdefination.h"
#include "..\hardware assistant\smbios\smbioslib.h"
#include "..\hardware assistant\usb\Iusb.h"
#include "..\hardware assistant\superio\Superio.h"
#include "..\hardware assistant\driver\Driverdll.h"
#include "..\hardware assistant\Memory\MemoryLib.h"
#include "..\hardware assistant\disk\DiskLib.h"
#include "..\hardware assistant\PCIE\PCI-E.h"

using namespace SV_ASSIST;
using namespace std;

int main()
{
	int te = 0;
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	while (true)
	{
		int cpuid[4] = {};
		CPU::GetCpuid(cpuid, 0, 0);
		USHORT base = 0;
		auto vendorid = Ring0::GetPCIVendorID();
		Ring0::GetSMbusBaseAddr(vendorid, base);
		ACPI::Excute();
		auto msfg = ACPI::GetMCFG();
		auto edidname = Display::GetMonitorName();
		auto pcieaddr = ACPI::GetPCIEBaseAddress();
		PVOID PCIEInfo = new BYTE[4096]{};

		WORD data = 0;
		Ring0::ReadSMbusByWord(base, 0x88, 0xD0, data);
		auto smbusdev = Ring0::Scan_SMBUS_DEVICE(base);
		auto bgrt = ACPI::GetBGRT();
		auto apic = ACPI::GetAPIC();
		auto optionrom = PCIE::GetPCIOptionROM();
		PCIE::GetPCIEConfigSpace(pcieaddr, 0, 5, 0, PCIEInfo, 4096);
		PCI_COMMON_CONFIG temp_pci = {};
		memcpy(&temp_pci, PCIEInfo, sizeof(temp_pci));
		auto memorydev = Memory::GetMemoryDeviceInfo();
		DWORD iodata = 0;
		Ring0::RdIOPort(0, 1, iodata);
		auto memoryspd = Memory::GetMemoryDDR3SPDInfo();
		auto memoryinfo = Memory::GetMemoryGlobalInfomation();
		int i = 4;
		while (i--)
		{
			GPU::UpdateDate();
			auto gpu = GPU::GetGpuInfo();
			cout << "Usage: " << gpu.at(0).second.GPUUsage << "	Video:" << gpu.at(0).second.GPUVideoEngineUsage << endl;
		}
		auto pci = Ring0::GetAllPciInfo();
		for (const auto& item : pci.pciconfig)
		{
			std::string Vendor, Device, classcode;
			PCIE::GetPCIDeviceName(item.second.VendorID, item.second.DeviceID, Vendor, Device);
			PCIE::ExecPCIClassCode(item.second, classcode);
			cout << hex << "Bus:" << std::get<0>(item.first)<< " Dev:" << std::get<1>(item.first) << " Func:" << std::get<2>(item.first) << "	" << Vendor << " " << Device << endl << classcode << endl;
		}
		i = 4;
		while (--i)
		{
			USB::UpdateData();
			auto usbinfo = USB::GetAllUsbinfo();
			auto usbdeviceinfo = USB::GetAllUsbDeviceInfo();
			auto usbhubinfo = USB::GetAllUsbHubInfo();
		}

		auto diskinfo = Storage::GetDiskSMARTInfo();
		Storage::UpdateData();

		AUDIO::UpdateData();
		auto audio = AUDIO::GetOutputAudio();

		auto sioid = SUPERIO::GetSuperIoChipId();

		auto siopage = SUPERIO::GetSioPage(sioid);
		auto siodata = SUPERIO::GetSioSensor();
		std::vector<Super_IO_Data> iqwe;
		SUPERIO::ReadSioPage(iqwe, siopage);

		auto cpuname = CPU::GetCPUName();
		auto busspeed = CPU::GetExtClock();
		auto cpucache = CPU::GetCache();
		auto south = CPU::GetSouthbridgeName();
		auto TDP = CPU::GetMaxTDP();
		auto SocketPackage = CPU::GetSocketDesignation();
		auto codename = CPU::GetCodeName();
		CPU::Updatedata();

		auto cpufre = CPU::GetCurrentClockSpeed();

		auto smbios = DMI_SMBIOS::GetSMBIOSinfo();
		i = 4;
		while (--i)
		{
			Net::Update();
			auto net = Net::GetData();
			SUPERIO::UpdateData();
			CPU::Updatedata();
			cout << CPU::GetExtClock() << endl;
		}
		auto edid = Display::GetEDID();
		delete[] PCIEInfo;
		Sleep(900);
	}
	return 0;
}

