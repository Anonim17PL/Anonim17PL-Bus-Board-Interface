

// Omnibus2.cpp : Defines the exported functions for the DLL application.
//



#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "Serial.h"
#include <assert.h>

int dlugie, mijania, migaczl, migaczr;
int migacz;

CSerial serial;

float aktualnyCzas = 0;
float zapamietanyCzas = 0;
float roznicaCzasu = 0;

extern "C" __declspec(dllexport)void __stdcall PluginStart(void* aOwner);
extern "C" __declspec(dllexport)void __stdcall AccessVariable(unsigned short varindex, float* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall AccessTrigger(unsigned short triggerindex, bool* active);
extern "C" __declspec(dllexport)void __stdcall AccessSystemVariable(unsigned short varindex, float* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall AccessStringVariable(unsigned short varindex, char* value, bool* write);
extern "C" __declspec(dllexport)void __stdcall PluginFinalize();



HANDLE mhStdOutput;
struct VarStruct
{
float speed, pedal, tank;
int dlugie, mijania, migaczl, migaczr;
int migacz;
};


VarStruct variables;



BOOL APIENTRY DllMain( HANDLE hModule,
DWORD ul_reason_for_call,
LPVOID lpReserved
)
{
return TRUE;
}

	void main(void)
		{

	}


void __stdcall PluginStart(void* aOwner)
{
//Place your initialisation code here
//int msgbox = MessageBox(0,(LPCWSTR)L"Start",(LPCWSTR)L"Message",MB_OK );
AllocConsole();
freopen("CONOUT$", "w", stdout);

}


void __stdcall datasend(char szMessage[]) 
{
		serial.Open(4, 76800);
		serial.SendData(szMessage, strlen(szMessage));
		//serial.Close();

}


void __stdcall AccessVariable(unsigned short varindex, float* value, bool* write)
{
//Place your variables code here
char* cpOutputBuffer = new char[1024];
unsigned long numWritten;
switch(varindex)
{
case 0:
	dlugie = *value;
case 1:
	mijania = *value;
case 2:
	migaczl = *value;
case 3:
	migaczr = *value;
}


if (migaczl || migaczr) {
	migacz=1;
	
}
else{
	migacz=0;
	
}

	if (dlugie) {
		datasend("001\n");
	}
	else{
		datasend("000\n");
	}
	if (migacz) {
		datasend("231\n");
	}
	else{
		datasend("230\n");
	};


//int msgbox = MessageBox(0,(LPCWSTR)L"Variables",(LPCWSTR)L"Message",MB_OK );
//std::cout << system("cls") << std::endl;
//sprintf(cpOutputBuffer, "Velocity: %.3f, Throttle: %.3f, Tank: %.3f\n", variables.speed, variables.pedal, variables.tank);
sprintf(cpOutputBuffer, "dlugie: %1i, mijania: %1i, migacz: %1i\n", dlugie, mijania, migacz);
std::cout << cpOutputBuffer << std::endl;
}





void __stdcall AccessTrigger(unsigned short triggerindex, bool* active)
{
//Place your trigger code here
//int msgbox = MessageBox(0,(LPCWSTR)L"Trigger",(LPCWSTR)L"Message",MB_OK );
switch(triggerindex)
{
case 0: //1st trigger in OMSIDLL.opl
;//do something with *active;
//*active = 1;
};

}

void __stdcall AccessSystemVariable(unsigned short varindex, float* value, bool* write)
{
}

void __stdcall AccessStringVariable(unsigned short varindex, char* value, bool* write)
{
}

void __stdcall PluginFinalize()
{
//Place your cleanup code here
//int msgbox = MessageBox(0,L"Stop",L"Message",MB_OK );
FreeConsole();
}

