
#include "pch.h"

#include <Windows.h>
#include "Serial.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

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
	//AllocConsole();
	//freopen("CONOUT$", "w", stdout);

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


			char* lpBuffer = new char[20];
			int nBytesRead = serial.ReadData(lpBuffer, 20);
			stringstream ss;
			ss << string(lpBuffer);
			string output;
			getline(ss, output);
			delete[]lpBuffer;
			int indeksnowejlinii = output.find("\n");
			int indeksprecinka = output.find(",");
			string strf = output.substr(0, 1);
			string str1 = output.substr(1, indeksprecinka - 1);
			string str2 = output.substr(indeksprecinka + 1, indeksnowejlinii - 1);

			if (strf == "w") {
				//*write = TRUE;
				varindex = stoi(str1);
				*write = TRUE;
				bool vOut = stoi(str2) != 0;
				*value = vOut;
				char szMessage[64];
				//sprintf(szMessage, "%d,%f\n", varindex, *value);
				//std::cout << szMessage << std::endl;
			}


}


void __stdcall AccessTrigger(unsigned short triggerindex, bool* active)
{
	char* lpBuffer = new char[20];
	int nBytesRead = serial.ReadData(lpBuffer, 20);
	stringstream ss;
	ss << string(lpBuffer);
	string output;
	getline (ss, output);
	delete[]lpBuffer;
	int indeksnowejlinii = output.find("\n");
	int indeksprecinka = output.find(",");
	string strf = output.substr(0, 1);
	string str1 = output.substr(1, indeksprecinka-1);
	string str2 = output.substr(indeksprecinka + 1, indeksnowejlinii-1);

	if (strf == "t") {
		triggerindex = stoi(str1);
		bool vOut = stoi(str2) != 0;
		*active = vOut;
		char szMessage[64];
		//sprintf(szMessage, "%d,%d\n", triggerindex, *active);
		//std::cout << szMessage << std::endl;
	}
	
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
