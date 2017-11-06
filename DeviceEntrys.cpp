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
	TCHAR*	DevName = NULL;
	LONG	Index;

	hDevs = SetupDiGetClassDevs(NULL,NULL,NULL,4);
	if(hDevs != INVALID_HANDLE_VALUE)
	{
		DevInfo.cbSize = sizeof;
		Index = 0;

		if(::SetDiEnumDeviceInfo(hDevs,Index,DevInfo))
		{
			do
			{
				NeedSize = 0;
				if(SetupDiGetDeviceRegistryProperty(hDevs,
													DevInfo,
													1,
													PropertyDataType,
													0,
													0,
													NeedSize))
				{
					Error = GetLastError();
				}
				else
				{
				
				}

				if(Error != 13)
				{
					// compare device name for device to remove
					
				

					LocalFree(DevName);
				}


				Index ++;
			}
			while(SetupDiEnumDeviceInfo(hDevs,Index,DevInfo));
		
		}

	}





}

DeviceRemove::~DeviceRemove()
{

}
