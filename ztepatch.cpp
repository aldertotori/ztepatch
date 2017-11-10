// ztepatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ServiceBase.h"
#include "ZTEPatchService.h"
#include "ServiceInstaller.h"

// 
// Settings of the service
// 

// Internal name of the service
#define SERVICE_NAME             _T("ZTEPatch")

// Displayed name of the service
#define SERVICE_DISPLAY_NAME     _T("ZTE MU350/MU351 3G wireless dongle win8 and later patch")

// Service start options.
#define SERVICE_START_TYPE       SERVICE_AUTO_START

// List of service dependencies - "dep1\0dep2\0\0"
#define SERVICE_DEPENDENCIES     _T("")

// The name of the account under which the service should run
#define SERVICE_ACCOUNT          _T("NT AUTHORITY\\LocalService")

// The password to the service account name
#define SERVICE_PASSWORD         NULL


int main(int argc, char* argv[])
{
    if ((argc > 1) && ((*argv[1] == _T('-') || (*argv[1] == _T('/')))))
    {
        if (_tcsicmp(_T("install"), argv[1] + 1) == 0)
        {
            // Install the service when the command is 
            // "-install" or "/install".
            InstallService(
                SERVICE_NAME,               // Name of service
                SERVICE_DISPLAY_NAME,       // Name to display
                SERVICE_START_TYPE,         // Service start type
                SERVICE_DEPENDENCIES,       // Dependencies
                SERVICE_ACCOUNT,            // Service running account
                SERVICE_PASSWORD            // Password of the account
                );
        }
        else if (_tcsicmp(_T("remove"), argv[1] + 1) == 0)
        {
            // Uninstall the service when the command is 
            // "-remove" or "/remove".
            UninstallService(SERVICE_NAME);
        }
    }
    else
    {
        _tprintf(_T("Parameters:\n"));
        _tprintf(_T(" -install  to install the service.\n"));
        _tprintf(_T(" -remove   to remove the service.\n"));

        CZTEPatchService service(SERVICE_NAME);
        if (!CServiceBase::Run(service))
        {
            _tprintf(_T("Service failed to run w/err 0x%08lx\n"), GetLastError());
        }
    }
	
	return 0;
}

