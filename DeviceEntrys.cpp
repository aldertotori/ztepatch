// DeviceEntrys.cpp: implementation of the DeviceEntrys class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DeviceEntrys.h"
#include <setupapi.h>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DeviceRemove::DeviceRemove()
{
}

BOOL DeviceRemove::Remove(TCHAR* Name,DWORD HardwareId)
{
	BOOL				ret		= FALSE;
	TCHAR*				DevName = NULL;
	DWORD				Index;
	HDEVINFO			hDevInfo;
	SP_DEVINFO_DATA		DevInfoData;
	DWORD				NeedSize;
	DWORD				Error;
	DWORD				PropertyDataType;

	hDevInfo = SetupDiGetClassDevs(NULL,NULL,NULL,DIGCF_ALLCLASSES);
	if(hDevInfo != INVALID_HANDLE_VALUE)
	{
		DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
		Index = 0;

		if(::SetDiEnumDeviceInfo(hDevInfo,Index,&DevInfoData))
		{
			do
			{
				NeedSize = 0;
				if(SetupDiGetDeviceRegistryProperty(hDevInfo,
													&DevInfoData,
													SPDRP_HARDWAREID,
													&PropertyDataType,
													0,
													0,
													&NeedSize))
				{
					Error = GetLastError();
				}
				else
				{
					DevName = (TCHAR*)LocalAlloc(NeedSize * sizeof(TCHAR) + sizeof(TCHAR));
					
					SetupDiGetDeviceRegistryProperty(hDevInfo,
						&DevInfoData,
						SPDRP_HARDWAREID,
						&PropertyDataType,
						(LPBYTE)(LPVOID)DevName,
						NeedSize * sizeof(TCHAR) + sizeof(TCHAR),
						&NeedSize);

					Error = GetLastError();
				
				}

				if(Error != ERROR_INVALID_DATA)
				{
					// compare device name for device to remove

					if (_tcsicmp(DevName,Name) == 0)
					{
						SetupDiCallClassInstaller(DIF_REMOVE,hDevInfo,&DevInfoData);
						LocalFree(DevName);
						ret = TRUE;
					}
					LocalFree(DevName);
				}

				Index ++;
			}
			while(SetupDiEnumDeviceInfo(hDevInfo,Index,&DevInfoData));
		
		}
	}

	return ret;
}

DeviceRemove::~DeviceRemove()
{

}
