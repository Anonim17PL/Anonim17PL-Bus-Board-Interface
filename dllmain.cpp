
#include "pch.h"

#include <Windows.h>
#include "Serial.h"
#include <string>
#include <ctime>
#include <iostream>

CSerial serial;

using namespace std;

// Omnibus2.cpp : Defines the exported functions for the DLL application.
//

extern "C" __declspec(dllexport)void __stdcall PluginStart(void* aOwner);
extern "C" __declspec(dllexport)void __stdcall AccessVariable(unsigned short varindex, float* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall AccessTrigger(unsigned short triggerindex, bool* active);
extern "C" __declspec(dllexport)void __stdcall AccessSystemVariable(unsigned short varindex, float* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall AccessStringVariable(unsigned short varindex, char* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall PluginFinalize();


void __stdcall PluginStart(void* aOwner)
{
	if (serial.Open(4, 115200))
		MessageBox(0, "Port opened successfully", "OMSI Plugin", MB_OK);
	else
		MessageBox(0, "Failed to open port!", "OMSI Plugin", MB_OK);
}


void __stdcall AccessVariable(unsigned short varindex, float* value, bool* write)
{

			char szMessage[64];
			sprintf(szMessage, "f%u,%f\n", varindex, *value);
			serial.SendData(szMessage, strlen(szMessage));

}


void __stdcall AccessTrigger(unsigned short triggerindex, bool* active)
{
	//Place your trigger code here
	//int msgbox = MessageBox(0,(LPCWSTR)L"Trigger",(LPCWSTR)L"Message",MB_OK );
}

void __stdcall AccessSystemVariable(unsigned short varindex, float* value, bool* write)
{
			char szMessage[64];
			sprintf(szMessage, "S%u,%f\n", varindex, *value);
			serial.SendData(szMessage, strlen(szMessage));

}

void __stdcall AccessStringVariable(unsigned short varindex, char* value, bool* write)
{

			TCHAR szMsg[] = TEXT("Text als Platzhalter");
			wsprintf(szMsg, "%S", value);
			char szMessage[64];
			snprintf(szMessage, sizeof szMessage, "s%u,%s\n", varindex, szMsg);
			serial.SendData(szMessage, strlen(szMessage));
}

void __stdcall PluginFinalize()
{
	//Place your cleanup code here
	//int msgbox = MessageBox(0,L"Stop",L"Message",MB_OK );
}
