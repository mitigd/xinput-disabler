#include "stdafx.h"
#include "xinput1_3.h"

bool WINAPI DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	static HMODULE xinput13 = nullptr;
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{

		char path[MAX_PATH];

		GetSystemDirectory(path, MAX_PATH);
		strcat_s(path, "\\xinput1_3.dll");
		xinput13 = LoadLibrary(path);

		og_ordinal100 = (ORDINATE0)GetProcAddress(xinput13, (const char*)100);
		og_ordinal101 = (ORDINATE1)GetProcAddress(xinput13, (const char*)101);
		og_ordinal102 = (ORDINATE2)GetProcAddress(xinput13, (const char*)102);
		og_ordinal103 = (ORDINATE3)GetProcAddress(xinput13, (const char*)103);

		og_xinputgetstate = (XInputGS)GetProcAddress(xinput13, "XInputGetState");
		og_xinputsetstate = (XInputSS)GetProcAddress(xinput13, "XInputSetState");
		og_xinputgetcapabilities = (XInputGC)GetProcAddress(xinput13, "XInputGetCapabilities");
		og_xinputenable = (XInputEN)GetProcAddress(xinput13, "XInputEnable");
		og_xinputgetdsoundaudiodeviceguids = (XInputGG)GetProcAddress(xinput13, "XInputGetDSoundAudioDeviceGuids");
		og_xinputgetbatteryinformation = (XInputGB)GetProcAddress(xinput13, "XInputGetBatteryInformation");
		og_xinputgetkeystroke = (XInputGK)GetProcAddress(xinput13, "XInputGetKeystroke");

	}
	case DLL_PROCESS_DETACH:
		FreeLibrary(hModule);
		break;
	}
	return true;
}

DWORD WINAPI Detour_XInputGetStateEx(DWORD index, XINPUT_STATE *state) {			// 100

	DWORD result = og_ordinal100(index, state);

	return result;

}

DWORD WINAPI Detour_XInputWaitForGuideButton(DWORD dwUserIndex, DWORD dwFlag, LPVOID pVoid) {			// 101

	DWORD result = og_ordinal101(dwUserIndex, dwFlag, pVoid);

	return result;

}

DWORD WINAPI Detour_XInputCancelGuideButtonWait(DWORD dwUserIndex) {			// 102

	DWORD result = og_ordinal102(dwUserIndex);

	return result;

}

DWORD WINAPI Detour_XInputPowerOffController(DWORD dwUserIndex) {			// 103

	DWORD result = og_ordinal103(dwUserIndex);

	return result;
}

DWORD WINAPI Detour_XInputGetState(DWORD dwUserIndex, XINPUT_STATE* pState) {

	return ERROR_DEVICE_NOT_CONNECTED;

}

DWORD WINAPI Detour_XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) {

	DWORD result = og_xinputsetstate(dwUserIndex, pVibration);

	return result;

}

DWORD WINAPI Detour_XInputGetCapabilities(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES* pCapabilities) {

	return og_xinputgetcapabilities(dwUserIndex, dwFlags, pCapabilities);

}

VOID WINAPI Detour_XInputEnable(BOOL enable) {

	return og_xinputenable(enable);

}

DWORD WINAPI Detour_XInputGetDSoundAudioDeviceGuids(DWORD dwUserIndex, GUID* pDSoundRenderGuid, GUID* pDSoundCaptureGuid) {

	return og_xinputgetdsoundaudiodeviceguids(dwUserIndex, pDSoundRenderGuid, pDSoundCaptureGuid);

}

DWORD WINAPI Detour_XInputGetBatteryInformation(DWORD  dwUserIndex, BYTE devType, XINPUT_BATTERY_INFORMATION* pBatteryInformation) {

	return og_xinputgetbatteryinformation(dwUserIndex, devType, pBatteryInformation);

}

DWORD WINAPI Detour_XInputGetKeystroke(DWORD dwUserIndex, DWORD dwReserved, PXINPUT_KEYSTROKE pKeystroke) {

	return og_xinputgetkeystroke(dwUserIndex, dwReserved, pKeystroke);

}
