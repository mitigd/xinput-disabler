#pragma once

#include <Xinput.h>

typedef DWORD(WINAPI* XInputGS)(DWORD dwUserIndex, XINPUT_STATE* pState);
typedef DWORD(WINAPI* XInputSS)(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration);
typedef DWORD(WINAPI* XInputGC)(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES* pCapabilities);
typedef DWORD(WINAPI* XInputGG)(DWORD dwUserIndex, GUID* pDSoundRenderGuid, GUID* pDSoundCaptureGuid);

XInputGS og_xinputgetstate;
XInputSS og_xinputsetstate;
XInputGC og_xinputgetcapabilities;
XInputGG og_xinputgetdsoundaudiodeviceguids;
