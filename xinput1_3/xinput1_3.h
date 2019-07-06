#pragma once

#include <Xinput.h>

typedef DWORD(WINAPI* ORDINATE0)(DWORD index, XINPUT_STATE *state);
typedef DWORD(WINAPI* ORDINATE1)(DWORD dwUserIndex, DWORD dwFlag, LPVOID pVoid);
typedef DWORD(WINAPI* ORDINATE2)(DWORD dwUserIndex);
typedef DWORD(WINAPI* ORDINATE3)(DWORD dwUserIndex);

typedef DWORD(WINAPI* XInputGS)(DWORD dwUserIndex, XINPUT_STATE* pState);
typedef DWORD(WINAPI* XInputSS)(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration);
typedef DWORD(WINAPI* XInputGC)(DWORD dwUserIndex, DWORD dwFlags, XINPUT_CAPABILITIES* pCapabilities);
typedef DWORD(WINAPI* XInputGG)(DWORD dwUserIndex, GUID* pDSoundRenderGuid, GUID* pDSoundCaptureGuid);
typedef DWORD(WINAPI* XInputGB)(DWORD  dwUserIndex, BYTE devType, XINPUT_BATTERY_INFORMATION* pBatteryInformation);
typedef DWORD(WINAPI* XInputGK)(DWORD dwUserIndex, DWORD dwReserved, PXINPUT_KEYSTROKE pKeystroke);

ORDINATE0 og_ordinal100;
ORDINATE1 og_ordinal101;
ORDINATE2 og_ordinal102;
ORDINATE3 og_ordinal103;

XInputGS og_xinputgetstate;
XInputSS og_xinputsetstate;
XInputGC og_xinputgetcapabilities;
XInputEN og_xinputenable;
XInputGG og_xinputgetdsoundaudiodeviceguids;
XInputGB og_xinputgetbatteryinformation;
XInputGK og_xinputgetkeystroke;
