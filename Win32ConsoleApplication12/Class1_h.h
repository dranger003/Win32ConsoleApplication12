

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Jun 10 23:04:05 2012
 */
/* Compiler settings for Class1.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Class1_h_h__
#define __Class1_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IClass1_FWD_DEFINED__
#define __IClass1_FWD_DEFINED__
typedef interface IClass1 IClass1;
#endif 	/* __IClass1_FWD_DEFINED__ */


#ifndef __Class1_FWD_DEFINED__
#define __Class1_FWD_DEFINED__

#ifdef __cplusplus
typedef class Class1 Class1;
#else
typedef struct Class1 Class1;
#endif /* __cplusplus */

#endif 	/* __Class1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IClass1_INTERFACE_DEFINED__
#define __IClass1_INTERFACE_DEFINED__

/* interface IClass1 */
/* [unique][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IClass1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B04669C0-2489-45AE-BA30-382D6BFC5899")
    IClass1 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Ping( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClass1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClass1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClass1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClass1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Ping )( 
            IClass1 * This);
        
        END_INTERFACE
    } IClass1Vtbl;

    interface IClass1
    {
        CONST_VTBL struct IClass1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClass1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClass1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClass1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClass1_Ping(This)	\
    ( (This)->lpVtbl -> Ping(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClass1_INTERFACE_DEFINED__ */



#ifndef __Win32ConsoleApplication12Lib_LIBRARY_DEFINED__
#define __Win32ConsoleApplication12Lib_LIBRARY_DEFINED__

/* library Win32ConsoleApplication12Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_Win32ConsoleApplication12Lib;

EXTERN_C const CLSID CLSID_Class1;

#ifdef __cplusplus

class DECLSPEC_UUID("3AF37B79-354A-4345-9D55-87E17C2A77AE")
Class1;
#endif
#endif /* __Win32ConsoleApplication12Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


