// ZTEPatchService.cpp: implementation of the CZTEPatchService class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ZTEPatchService.h"
#include "DeviceEntrys.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZTEPatchService::CZTEPatchService(TCHAR* name) : CServiceBase(name)
{

}

CZTEPatchService::~CZTEPatchService()
{

}

void CZTEPatchService::OnStart(DWORD dwArgc, TCHAR* *pszArgv)
{
}

void CZTEPatchService::OnStop()
{
}

void CZTEPatchService::OnDeviceEvent()
{

	DeviceRemove remove;
	remove.Remove(_T("USB\\VEN_&PID_"),0);
}

void CZTEPatchService::OnPause()
{	
}

void CZTEPatchService::OnContinue()
{	
}
