// DeviceChangeNotify.cpp: implementation of the DeviceChangeNotify class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DeviceChangeNotify.h"
#include <dbt.h>
#include "DeviceEntrys.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DeviceChangeNotify::DeviceChangeNotify() : m_h_notification(INVALID_HANDLE_VALUE)
{


}

#ifndef DEVICE_NOTIFY_ALL_INTERFACE_CLASSES
#define DEVICE_NOTIFY_ALL_INTERFACE_CLASSES  0x4
#endif

BOOL DeviceChangeNotify::Register(HANDLE hService)
{
	DEV_BROADCAST_DEVICEINTERFACE Filter;
	
	memset(&Filter,0,sizeof(DEV_BROADCAST_DEVICEINTERFACE));
	Filter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	Filter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;

	m_h_notification = RegisterDeviceNotification(hService,&Filter,
			DEVICE_NOTIFY_ALL_INTERFACE_CLASSES | DEVICE_NOTIFY_SERVICE_HANDLE);
	
	return m_h_notification == INVALID_HANDLE_VALUE ? FALSE : TRUE;
}

void DeviceChangeNotify::UnRegister()
{
	if(m_h_notification != INVALID_HANDLE_VALUE)
	{
		UnregisterDeviceNotification(m_h_notification);
		m_h_notification = INVALID_HANDLE_VALUE;
	}
}

DeviceChangeNotify::~DeviceChangeNotify()
{
	UnRegister();
}

VOID DeviceChangeNotify::ServiceEvent(DWORD dwEventType,LPVOID lpEventData)
{
	PDEV_BROADCAST_HDR  hdr;

	switch(dwEventType)
	{
	case DBT_DEVICEARRIVAL:
		
		hdr = (PDEV_BROADCAST_HDR)lpEventData;
		
		switch(hdr->dbch_devicetype)
		{
		case DBT_DEVTYP_DEVICEINTERFACE:
			
			break;
		default:
			break;
		}
		
		break;
	case DBT_DEVICEREMOVECOMPLETE:
		
		break;
	case DBT_DEVICEQUERYREMOVE:
		
		break;
	default:
		break;
	}
}

BOOL DeviceChangeNotify::IsDeviceEvent(DWORD dwServiceControlId)
{
	if(dwServiceControlId == SERVICE_CONTROL_DEVICEEVENT)
		return TRUE;
	return FALSE;
}