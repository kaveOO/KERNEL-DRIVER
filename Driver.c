#include <ntddk.h>
#include <wdf.h>

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KmdfHelloWordDeviceAdd;

NTSTATUS
// Entry point of the Driver -> Main function
DriverEntry(
	_In_ PDRIVER_OBJECT		DriverObject,
	_In_ PUNICODE_STRING	RegistryPath
)
{
	// Variable to record success or failure from Windows API
	NTSTATUS status = STATUS_SUCCESS;

	// Allocate driver config object
	WDF_DRIVER_CONFIG config;

	// KdPrintEx is a macgit ro that sends string to the Kernel Debugger
	// DPFLTR_IHVDRIVER_ID -> Used to associate the print of Driver as a something not offical "Handmade Driver" (Thats help filter messages in Debuggers)
	// DPFLTR_INFO_LEVEL -> Means we are printing something at the Info Level (Thats help filter messages in Debuggers)
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Hello Kernel World: DriverEntry\n"));
	
	// Init the drivNew Computerer config allocated above
	// Add the entry point of Event Device Add callback	"KmdfHelloWordDeviceAdd"
	WDF_DRIVER_CONFIG_INIT(&config, KmdfHelloWordDeviceAdd);

	// WdfDriverCreate is used to create a Driver Object and Initialize it with specified attributes and configuration
	status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);

	return (status);
}

NTSTATUS
KmdfHelloWordDeviceAdd(
	_In_	WDFDRIVER		Driver,
	_Inout_ PWDFDEVICE_INIT	DeviceInit
)
{
	// Not using Driver object so we unreference it (void)
	UNREFERENCED_PARAMETER(Driver);

	NTSTATUS status;

	// Allocated device object like we did with Driver config above
	WDFDEVICE hDevice;

	// KdPrintEx is a macro that sends string to the Kernel Debugger
	// DPFLTR_IHVDRIVER_ID -> Used to associate the print of Driver as a something not offical "Handmade Driver" (Thats help filter messages in Debuggers)
	// DPFLTR_INFO_LEVEL -> Means we are printing something at the Info Level (Thats help filter messages in Debuggers)
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "Hello Kernel World: KmdfHelloWordDeviceAdd\n"));

	status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);
	
	return (status);
}