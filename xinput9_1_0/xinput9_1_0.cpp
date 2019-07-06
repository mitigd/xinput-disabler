#include "stdafx.h"
#include "xinput9_1_0.h"

bool WINAPI DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	static HMODULE xinput910 = nullptr;
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{

		char path[MAX_PATH];

		GetSystemDirectory(path, MAX_PATH);
		strcat_s(path, "\\xinput9_1_0.dll");
		xinput910 = LoadLibrary(path);

		og_xinputgetstate = (XInputGS)GetProcAddress(xinput910, "XInputGetState");
		og_xinputsetstate = (XInputSS)GetProcAddress(xinput910, "XInputSetState");
		og_xinputgetcapabilities = (XInputGC)GetProcAddress(xinput910, "XInputGetCapabilities");
		og_xinputgetdsoundaudiodeviceguids = (XInputGG)GetProcAddress(xinput910, "XInputGetDSoundAudioDeviceGuids");

	}
	case DLL_PROCESS_DETACH:
		FreeLibrary(hModule);
		break;
	}
	return true;
}

DWORD WINAPI Detour_XInputGetState(DWORD dwUserIndex, XINPUT_STATE* pState) {

	return ERROR_SUCCESS;

}

DWORD WINAPI Detour_XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) {

	return ERROR_DEVICE_NOT_CONNECTED;

}

DWORD WINAPI Detour_XInputGetCapabilities(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES* pCapabilities) {

	return ERROR_DEVICE_NOT_CONNECTED;

}

DWORD WINAPI Detour_XInputGetDSoundAudioDeviceGuids(DWORD dwUserIndex, GUID* pDSoundRenderGuid, GUID* pDSoundCaptureGuid) {

	return ERROR_DEVICE_NOT_CONNECTED;

}
