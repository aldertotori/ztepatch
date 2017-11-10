// DeviceChangeNotify.h: interface for the DeviceChangeNotify class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEVICECHANGENOTIFY_H__0FBE65A9_59C9_4B8B_B134_324C91389E0B__INCLUDED_)
#define AFX_DEVICECHANGENOTIFY_H__0FBE65A9_59C9_4B8B_B134_324C91389E0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DeviceChangeNotify  
{
public:
	DeviceChangeNotify();
	virtual ~DeviceChangeNotify();

	BOOL IsDeviceEvent(DWORD dwServiceControlId);
	VOID ServiceEvent(DWORD dwEventType,LPVOID lpEventData);

	BOOL Register(HANDLE hService);
	void UnRegister();
	
private:
	HDEVNOTIFY	m_h_notification;

};

#endif // !defined(AFX_DEVICECHANGENOTIFY_H__0FBE65A9_59C9_4B8B_B134_324C91389E0B__INCLUDED_)
