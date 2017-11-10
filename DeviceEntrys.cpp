// DeviceEntrys.cpp: implementation of the DeviceEntrys class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <setupapi.h>
#include "DeviceEntrys.h"

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

	hDevInfo = SetupDiGetClassDevs(NULL,NULL,NULL,DIGCF_ALLCLASSES | DIGCF_PRESENT);
	if(hDevInfo != INVALID_HANDLE_VALUE)
	{
		DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
		Index = 0;

		if(::SetupDiEnumDeviceInfo(hDevInfo,Index,&DevInfoData))
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

					DevName = (TCHAR*)LocalAlloc(GPTR,NeedSize * sizeof(TCHAR) + sizeof(TCHAR));
					
					SetupDiGetDeviceRegistryProperty(hDevInfo,
						&DevInfoData,
						SPDRP_HARDWAREID,
						&PropertyDataType,
						(LPBYTE)(LPVOID)DevName,
						NeedSize * sizeof(TCHAR) + sizeof(TCHAR),
						&NeedSize);

					Error = GetLastError();

					if(Error != ERROR_INVALID_DATA)
					{
#ifdef _DEBUG
						OutStr(DevName);
						OutStr("\n");
#endif
						// compare device name for device to remove
						if (_tcsicmp(DevName,Name) == 0)
						{
							SetupDiCallClassInstaller(DIF_REMOVE,hDevInfo,&DevInfoData);
							LocalFree(DevName);
							ret = TRUE;
							break;
						}
					}

					LocalFree(DevName);
				}

				Index ++;
			}
			while(SetupDiEnumDeviceInfo(hDevInfo,Index,&DevInfoData));
		}

		SetupDiDestroyDeviceInfoList(hDevInfo);
	}

	return ret;
}

DeviceRemove::~DeviceRemove()
{

}
