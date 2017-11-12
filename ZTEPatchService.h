// ZTEPatchService.h: interface for the CZTEPatchService class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZTEPATCHSERVICE_H__5D14639B_AE44_407F_9663_ED0DE87A2D93__INCLUDED_)
#define AFX_ZTEPATCHSERVICE_H__5D14639B_AE44_407F_9663_ED0DE87A2D93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ServiceBase.h"
#include "DeviceChangeNotify.h"

class CZTEPatchService  : public CServiceBase
{
public:
	CZTEPatchService(TCHAR* name);
	virtual ~CZTEPatchService();

	void OnStart(DWORD dwArgc, TCHAR* *pszArgv);
	void OnStop();
	void OnPause();
	void OnContinue();
	void OnDeviceEvent();

private:


};

#endif // !defined(AFX_ZTEPATCHSERVICE_H__5D14639B_AE44_407F_9663_ED0DE87A2D93__INCLUDED_)
