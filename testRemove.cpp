// testRemove.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DeviceEntrys.h"
#pragma comment(lib,"setupapi.lib")

int main(int argc, char* argv[])
{
	DeviceRemove remove;
	
	remove.Remove(_T("USBSTOR\\CdRomZTE_CorpCD-ROM__________0.01"),0);
	
	return 0;
}

