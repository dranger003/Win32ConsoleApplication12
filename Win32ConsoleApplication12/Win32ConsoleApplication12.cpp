// Win32ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

#include "Class1_h.h"

class CAtlExeModuleEx :
    public CAtlExeModuleT<CAtlExeModuleEx>
{ };

CAtlExeModuleEx _AtlModule;

class ATL_NO_VTABLE Class1 :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<Class1, &CLSID_Class1>,
    public IClass1
{
public:
    Class1()
    { }

    DECLARE_REGISTRY_RESOURCEID(IDR_CLASS1)

    BEGIN_COM_MAP(Class1)
        COM_INTERFACE_ENTRY(IClass1)
    END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

    STDMETHOD(Ping)()
    {
        ::_tprintf(_T("[%ld] [0x%X] Ping()\n"), ::GetCurrentThreadId(), this);
        return S_OK;
    }
};

//OBJECT_ENTRY_AUTO(__uuidof(Class1), Class1)

DWORD WINAPI ThreadProc(PVOID pv)
{
    ::_tprintf(_T("[%ld] ThreadProc()\n"), ::GetCurrentThreadId());

    ::MessageBox(NULL, _T("Click \"OK\" to continue."), _T("Win32ConsoleApplication12"), MB_OK | MB_ICONINFORMATION);

    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    HRESULT hr;

    if (argc == 2)
    {
     //   CString szModule;
	    //::GetModuleFileName(_AtlBaseModule.GetModuleInstance(), CStrBuf(szModule, MAX_PATH), MAX_PATH);

     //   CRegObject ro;

     //   ::_tprintf(_T("[%s]\n"), szModule);

        if (!::_tcsicmp(argv[1] + 1, _T("Register")))
        {
            //hr = ro.ResourceRegister(szModule, IDR_CLASS1, _T("REGISTRY"));
            //::_tprintf(_T("CRegObject::ResourceRegister(): %s\n"), _com_error(hr).ErrorMessage());
            //ATLASSERT(SUCCEEDED(hr));

            hr = Class1::UpdateRegistry(TRUE);
            ::_tprintf(_T("Class1::UpdateRegistry(): %s\n"), _com_error(hr).ErrorMessage());
            ATLASSERT(SUCCEEDED(hr));

            ::MessageBox(NULL, _T("Registered."), _T("Win32ConsoleApplication12"), MB_OK | MB_ICONINFORMATION);
        }
        else if (!::_tcsicmp(argv[1] + 1, _T("Unregister")))
        {
            hr = Class1::UpdateRegistry(FALSE);
            ::_tprintf(_T("Class1::UpdateRegistry(): %s\n"), _com_error(hr).ErrorMessage());
            ATLASSERT(SUCCEEDED(hr));

            ::MessageBox(NULL, _T("Unregistered."), _T("Win32ConsoleApplication12"), MB_OK | MB_ICONINFORMATION);
        }
    }
    else
    {
        ::_tprintf(_T("[%ld] _tmain()\n"), ::GetCurrentThreadId());

        {
            hr = ::CoInitialize(NULL);

            {
                CComPtr<IClassFactory> spcf;
                hr = CComCreator<CComObject<CComClassFactory>>::CreateInstance(CComCreator<CComObject<Class1>>::CreateInstance, IID_IClassFactory, (PVOID*)&spcf);
                ::_tprintf(_T("CComCreator::CreateInstance(): %s\n"), _com_error(hr).ErrorMessage());
                ATLASSERT(SUCCEEDED(hr));

                DWORD dwRegister = 0;
                hr = ::CoRegisterClassObject(CLSID_Class1, spcf, CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE, &dwRegister);
                ::_tprintf(_T("::CoRegisterClassObject(): %s\n"), _com_error(hr).ErrorMessage());

                DWORD dwThreadId = 0;
                CHandle hThread = (CHandle)::CreateThread(NULL, 0, &ThreadProc, NULL, 0, &dwThreadId);

                while (::MsgWaitForMultipleObjects(1, (PHANDLE)&hThread, FALSE, INFINITE, QS_ALLINPUT) != WAIT_OBJECT_0)
                {
                    MSG msg = { 0 };
                    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                    {
                        ::TranslateMessage(&msg);
                        ::DispatchMessage(&msg);
                    }
                }

                hr = ::CoRevokeClassObject(dwRegister);
                dwRegister = 0;
            }

            ::CoUninitialize();
        }
    }

    return 0;
}
