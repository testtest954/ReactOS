#ifndef __DSCONF_INCLUDED__
#define __DSCONF_INCLUDED__

#ifndef __DSOUND_INCLUDED__
#error dsound.h not included
#endif

#ifdef __cplusplus
extern "C" {
#endif

DEFINE_GUID(CLSID_DirectSoundPrivate,      0x11AB3EC0, 0x25EC, 0x11D1, 0xA4, 0xD8, 0x0, 0xC0, 0x4F, 0xC2, 0x8A, 0xCA);
DEFINE_GUID(DSPROPSETID_DirectSoundDevice, 0x84624F82, 0x25EC, 0x11D1, 0xA4, 0xD8, 0x0, 0xC0, 0x4F, 0xC2, 0x8A, 0xCA);

typedef enum
{
    DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A = 1,
    DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1 = 2,
    DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1 = 3,
    DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W = 4,
    DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A = 5,
    DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W = 6,
    DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A = 7,
    DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W = 8,
} DSPROPERTY_DIRECTSOUNDDEVICE;

typedef enum
{
    DIRECTSOUNDDEVICE_TYPE_EMULATED,
    DIRECTSOUNDDEVICE_TYPE_VXD,
    DIRECTSOUNDDEVICE_TYPE_WDM
} DIRECTSOUNDDEVICE_TYPE;

typedef enum
{
    DIRECTSOUNDDEVICE_DATAFLOW_RENDER,
    DIRECTSOUNDDEVICE_DATAFLOW_CAPTURE
} DIRECTSOUNDDEVICE_DATAFLOW;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA
{
    LPSTR DeviceName;
    DIRECTSOUNDDEVICE_DATAFLOW DataFlow;
    GUID DeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA
{
    LPWSTR DeviceName;
    DIRECTSOUNDDEVICE_DATAFLOW  DataFlow;
    GUID DeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA
{
    GUID DeviceId;
    CHAR DescriptionA[0x100];
    WCHAR DescriptionW[0x100];
    CHAR ModuleA[MAX_PATH];
    WCHAR ModuleW[MAX_PATH];
    DIRECTSOUNDDEVICE_TYPE Type;
    DIRECTSOUNDDEVICE_DATAFLOW DataFlow;
    ULONG WaveDeviceId;
    ULONG Devnode;
} DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA
{
    DIRECTSOUNDDEVICE_TYPE Type;
    DIRECTSOUNDDEVICE_DATAFLOW DataFlow;
    GUID DeviceId;
    LPSTR Description;
    LPSTR Module;
    LPSTR Interface;
    ULONG WaveDeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA
{
    DIRECTSOUNDDEVICE_TYPE Type;
    DIRECTSOUNDDEVICE_DATAFLOW DataFlow;
    GUID DeviceId;
    LPWSTR Description;
    LPWSTR Module;
    LPWSTR Interface;
    ULONG WaveDeviceId;
} DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA;

#if DIRECTSOUND_VERSION >= 0x0700
    #ifdef UNICODE
        #define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W
        #define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W
        #define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W
        #define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA
        #define PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA
    #else
        #define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A
        #define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A
        #define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A
        #define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA
        #define PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA
    #endif
#else
    #define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A
    #define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1
    #define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1
    #define DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA
#define PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA
#endif

#ifdef UNICODE
    #define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA
    #define PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_W_DATA
#else
    #define DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA DSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA
    #define PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_WAVEDEVICEMAPPING_A_DATA
#endif

typedef BOOL (CALLBACK *LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK1)(PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_1_DATA, LPVOID);
typedef BOOL (CALLBACK *LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKA)(PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_A_DATA, LPVOID);
typedef BOOL (CALLBACK *LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKW)(PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_W_DATA, LPVOID);

#if DIRECTSOUND_VERSION >= 0x0700
    #ifdef UNICODE
        #define LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKW
    #else
        #define LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKA
    #endif
#else
    #define LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK1
#endif

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA
{
    LPFNDIRECTSOUNDDEVICEENUMERATECALLBACK1 Callback;
    LPVOID Context;
} DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA
{
    LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKA Callback;
    LPVOID Context;
} DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA;

typedef struct _DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA
{
    LPFNDIRECTSOUNDDEVICEENUMERATECALLBACKW Callback;
    LPVOID Context;
} DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA, *PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA;

#if DIRECTSOUND_VERSION >= 0x0700
    #ifdef UNICODE
        #define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA
        #define PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_W_DATA
    #else
        #define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA
        #define PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_A_DATA
    #endif
#else
    #define DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA DSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA
    #define PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_DATA PDSPROPERTY_DIRECTSOUNDDEVICE_ENUMERATE_1_DATA
#endif

#ifdef __cplusplus
}
#endif

#endif
