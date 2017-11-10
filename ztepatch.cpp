// ztepatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DeviceEntrys.h"

int main(int argc, char* argv[])
{
	DeviceRemove remove;

	remove.Remove(_T("test"),0);
	
	return 0;
}

