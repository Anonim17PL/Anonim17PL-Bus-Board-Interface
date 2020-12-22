

// Omnibus2.cpp : Defines the exported functions for the DLL application.
//



#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "Serial.h"
#include <assert.h>

int dlugie, mijania, migaczl, migaczr, nz1, nz2, nz3, nz4, nz5, nz6, door1, door2, door3, door4, door5, door6;
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
//float speed, pedal, tank;
//int dlugie, mijania, migaczl, migaczr;
//int migacz;
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
	//dlugie = *value;
	if (*value) {
		datasend("001\n");
	}
	else{
		datasend("000\n");
	}
	break;
case 1:
	if (*value) {
		datasend("011\n");
	}
	else{
		datasend("010\n");
	}
	break;
case 2:
	if (*value) {
		datasend("021\n");
	}
	else{
		datasend("020\n");
	}
	break;
case 3:
	if (*value) {
		datasend("031\n");
	}
	else{
		datasend("030\n");
	}
	break;
case 4:
	if (*value) {
		datasend("041\n");
	}
	else{
		datasend("040\n");
	}
	break;
case 5:
	if (*value) {
		datasend("051\n");
	}
	else{
		datasend("050\n");
	}
	break;
case 6:
	if (*value) {
		datasend("061\n");
	}
	else{
		datasend("060\n");
	}
	break;
case 7:
	if (*value) {
		datasend("071\n");
	}
	else{
		datasend("070\n");
	}
	break;
case 8:
	if (*value) {
		datasend("081\n");
	}
	else{
		datasend("080\n");
	}
	break;
case 9:
	if (*value) {
		datasend("091\n");
	}
	else{
		datasend("090\n");
	}
	break;
case 10:
	if (*value) {
		datasend("101\n");
	}
	else{
		datasend("100\n");
	}
	break;
case 11:
	if (*value) {
		datasend("111\n");
	}
	else{
		datasend("110\n");
	}
	break;
case 12:
	if (*value) {
		datasend("121\n");
	}
	else{
		datasend("120\n");
	}
	break;
case 13:
	if (*value) {
		datasend("131\n");
	}
	else{
		datasend("130\n");
	}
	break;
case 14:
	if (*value) {
		datasend("141\n");
	}
	else{
		datasend("140\n");
	}
	break;
case 15:
	if (*value) {
		datasend("151\n");
	}
	else{
		datasend("150\n");
	}
	break;
case 16:
	if (*value) {
		datasend("161\n");
	}
	else{
		datasend("160\n");
	}
	break;
case 17:
	if (*value) {
		datasend("171\n");
	}
	else{
		datasend("170\n");
	}
	break;
case 18:
	if (*value) {
		datasend("181\n");
	}
	else{
		datasend("180\n");
	}
	break;
case 19:
	if (*value) {
		datasend("191\n");
	}
	else{
		datasend("190\n");
	}
	break;
case 20:
	if (*value) {
		datasend("201\n");
	}
	else{
		datasend("200\n");
	}
	break;
}

/* OLD CODE
if (migaczl || migaczr) {
	migacz=1;
	
}
else{
	migacz=0;
	
}
//NORMAL CODES:

	if (mijania) {
		datasend("011\n");
	}
	else{
		datasend("010\n");
	}
	if (migaczl) {
		datasend("021\n");
	}
	else{
		datasend("020\n");
	};
	if (migaczr) {
		datasend("031\n");
	}
	else{
		datasend("030\n");
	};
	if (nz1) {
		datasend("041\n");
	}
	else{
		datasend("040\n");
	};
	if (nz2) {
		datasend("051\n");
	}
	else{
		datasend("050\n");
	};
	if (nz3) {
		datasend("051\n");
	}
	else{
		datasend("050\n");
	};
	if (nz4) {
		datasend("061\n");
	}
	else{
		datasend("060\n");
	};
	if (nz5) {
		datasend("071\n");
	}
	else{
		datasend("070\n");
	};
	if (nz6) {
		datasend("081\n");
	}
	else{
		datasend("080\n");
	};
*/

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

