// DeviceEntrys.h: interface for the DeviceEntrys class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEVICEENTRYS_H__D57995E3_8BCC_48C7_9F69_990AF64359C9__INCLUDED_)
#define AFX_DEVICEENTRYS_H__D57995E3_8BCC_48C7_9F69_990AF64359C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DeviceRemove
{
public:
	DeviceRemove();
	virtual ~DeviceRemove();

	BOOL Remove(TCHAR* Name,DWORD HardwareId);
};

#endif // !defined(AFX_DEVICEENTRYS_H__D57995E3_8BCC_48C7_9F69_990AF64359C9__INCLUDED_)
