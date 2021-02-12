
#include "pch.h"
#include <Windows.h>
#include <WinUser.h>
#include "Serial.h"
#include <assert.h>
#include <stdio.h>

CSerial serial;

// Omnibus2.cpp : Defines the exported functions for the DLL application.
//

extern "C" __declspec(dllexport)void __stdcall PluginStart(void* aOwner);
extern "C" __declspec(dllexport)void __stdcall AccessVariable(unsigned short varindex, float* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall AccessTrigger(unsigned short triggerindex, bool* active);
extern "C" __declspec(dllexport)void __stdcall AccessSystemVariable(unsigned short varindex, float* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall AccessStringVariable(unsigned short varindex, char* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall PluginFinalize();




HANDLE mhStdOutput;
struct VarStruct
{

};


VarStruct variables;



BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
)
{
	return TRUE;
}



void __stdcall PluginStart(void* aOwner)
{
	if (serial.Open(4, 9600))
		MessageBox(0, "Port opened successfully", "OMSI Plugin", MB_OK);
	else
		MessageBox(0, "Failed to open port!", "OMSI Plugin", MB_OK);
}


void __stdcall AccessVariable(unsigned short varindex, float* value, bool* write)
{
	if (serial.Open(4, 9600))
	{
		char szMessage[64];
		snprintf(szMessage, sizeof szMessage, "f%u,%f\n", varindex, *value);
		serial.SendData(szMessage, strlen(szMessage));
	}
	else
		MessageBox(0, "Failed to open port!", "OMSI Plugin", MB_OK);
}


void __stdcall AccessTrigger(unsigned short triggerindex, bool* active)
{
	//Place your trigger code here
	//int msgbox = MessageBox(0,(LPCWSTR)L"Trigger",(LPCWSTR)L"Message",MB_OK );
}

void __stdcall AccessSystemVariable(unsigned short varindex, float* value, bool* write)
{
	if (serial.Open(4, 9600))
	{
		char szMessage[64];
		snprintf(szMessage, sizeof szMessage, "S%u,%f\n", varindex, *value);
		serial.SendData(szMessage, strlen(szMessage));
	}
	else
		MessageBox(0, "Failed to open port!", "OMSI Plugin", MB_OK);
}

void __stdcall AccessStringVariable(unsigned short varindex, char* value, bool* write)
{
	if (serial.Open(4, 9600))
	{
		char szMessage[64];
		snprintf(szMessage, sizeof szMessage, "s%u,%s\n", varindex, value);
		serial.SendData(szMessage, strlen(szMessage));
	}
	else
		MessageBox(0, "Failed to open port!", "OMSI Plugin", MB_OK);
}

void __stdcall PluginFinalize()
{
	//Place your cleanup code here
	//int msgbox = MessageBox(0,L"Stop",L"Message",MB_OK );
}
