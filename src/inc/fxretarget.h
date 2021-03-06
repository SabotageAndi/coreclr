// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

// ==++==
// 

//   
//   This header file contains the .NET Framework unification list. It is included by
//   fusion\binder\fxretarget.cpp for clr.dll, and dlls\mscorsvc\taskhelper.cpp for mscorsvc.dll.
// 
// ==--==


// 


// Automatically roll forward FX 2.0/3.0/3.5 -> 4.0
#define NDP4_AUTO_VERSION_ROLLFORWARD

#define VER_VS_ASSEMBLYVERSION_STR_L            L"10.0.0.0"
#define VER_VC_STLCLR_ASSEMBLYVERSION_STR_L     L"2.0.0.0"


// Working set optimization: using file:..\..\bin\OptimizeFxRetarget.cs (.exe) to generate condensed tables with less string data and less pointers

#include "fixedsizestring.h"

namespace FxPolicyHelper
{
    // Forward declarations from file:fxretarget_generated.hpp
    extern LPCSTR   const g_rgAssemblyNamePartStrings[];
    extern LPCWSTR  const g_rgAssemblyKeyVersionStrings[];
    
    enum AppXBinderSupport
    {
        AppXBinder_Blocked    = 0, 
        AppXBinder_Supported  = 1
    };
};

struct FrameworkConfig
{
    // Working set optimization, store assembly name as 4-bytes, PKT/Version as 1-byte; long assembly names broken into parts stored in ANSI
    unsigned char m_compressedName[4];
    unsigned char m_nPKT;
    unsigned char m_nNewVersion : 7;
    unsigned char m_fSupportedInAppXBinder : 1;
    
    const LPCWSTR GetPKT() const
    {
        return FxPolicyHelper::g_rgAssemblyKeyVersionStrings[m_nPKT];
    }

    const LPCWSTR GetNewVersion() const
    {
        return FxPolicyHelper::g_rgAssemblyKeyVersionStrings[m_nNewVersion];
    }

    BOOL IsSupportedInAppXBinder() const
    {
        _ASSERTE((m_fSupportedInAppXBinder == FxPolicyHelper::AppXBinder_Blocked) || 
                 (m_fSupportedInAppXBinder == FxPolicyHelper::AppXBinder_Supported));
        
        return (m_fSupportedInAppXBinder == FxPolicyHelper::AppXBinder_Supported);
    }
    
    // Using template to avoid converting it to UNICODE when possible, 
    // more important avoid converting the ANSI string it's going to be compared with to be converted to UNICODE
    template<typename T>
    void GetFxAssemblyName(FixedSizeString<T> & output) const
    {
        output.DecodeName(_countof(m_compressedName), m_compressedName, FxPolicyHelper::g_rgAssemblyNamePartStrings);
    }
};

#define StringHashIterator(name, table, asmName)  StringHashEnumerator name(asmName, table ## _Hash, _countof(table ## _Hash), table ## _HashCollision);

#ifdef NEEDDATA

// This file is auto generated by file:..\..\bin\OptimizeFxRetarget.cs (.exe), saved in intermediate directory
#include "fxretarget_generated.hpp"

#endif

#ifdef ORIGINAL_SOURCE

typedef struct tagFrameworkConfig
{
    LPCWSTR pwzName;
//  culture by default is NULL/Neutral
//    LPCWSTR pwzCulture;
    LPCWSTR pwzPKT;
    LPCWSTR pwzNewVersion;
    FxPolicyHelper::AppXBinderSupport fSupportedInAppXBinder;
} FrameworkConfig;

const FrameworkConfig g_arFxPolicy[] = 
{
// This table is parsed and processed by file:..\..\bin\OptimizeFxRetarget.cs (.exe):
// STARTDICTIONARY(FxPolicyHelper,AssemblyNamePart,AssemblyKeyVersion,FrameworkConfig,g_arFxPolicy)
    {L"Accessibility", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                FxPolicyHelper::AppXBinder_Blocked},
    {L"CustomMarshalers", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,             FxPolicyHelper::AppXBinder_Supported},
    {L"ISymWrapper", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                  FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.JScript", MICROSOFT_PUBLICKEY_STR_L, VER_VS_ASSEMBLYVERSION_STR_L,         FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.VisualBasic", MICROSOFT_PUBLICKEY_STR_L, VER_VS_ASSEMBLYVERSION_STR_L,     FxPolicyHelper::AppXBinder_Supported},
    {L"Microsoft.VisualBasic.Compatibility", MICROSOFT_PUBLICKEY_STR_L, VER_VS_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.VisualBasic.Compatibility.Data", MICROSOFT_PUBLICKEY_STR_L, VER_VS_ASSEMBLYVERSION_STR_L,  FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.VisualC", MICROSOFT_PUBLICKEY_STR_L, VER_VS_ASSEMBLYVERSION_STR_L,         FxPolicyHelper::AppXBinder_Blocked},
    {L"mscorlib", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                          FxPolicyHelper::AppXBinder_Supported},
    {L"System", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                            FxPolicyHelper::AppXBinder_Supported},
    {L"System.Configuration", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,         FxPolicyHelper::AppXBinder_Supported},
    {L"System.Configuration.Install", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                       FxPolicyHelper::AppXBinder_Supported},
    {L"System.Data.OracleClient", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data.SqlXml", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                FxPolicyHelper::AppXBinder_Supported},
    {L"System.Deployment", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,            FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Design", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                FxPolicyHelper::AppXBinder_Blocked},
    {L"System.DirectoryServices", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,     FxPolicyHelper::AppXBinder_Supported},
    {L"System.DirectoryServices.Protocols", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Drawing", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,               FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Drawing.Design", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked},
    {L"System.EnterpriseServices", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,    FxPolicyHelper::AppXBinder_Supported},
    {L"System.Management", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,            FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Messaging", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,             FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Runtime.Remoting", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Serialization.Formatters.Soap", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Security", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,              FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceProcess", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Transactions", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,               FxPolicyHelper::AppXBinder_Supported},
    {L"System.Web", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                   FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Mobile", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,            FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.RegularExpressions", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Services", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Supported}, // Has to be supported in AppX, because it is in transitive closure of supported assemblies
    {L"System.Windows.Forms", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,              FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Xml", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                        FxPolicyHelper::AppXBinder_Supported},

#ifdef NDP4_AUTO_VERSION_ROLLFORWARD
    
    // Post-Everett FX 2.0 assemblies:
    {L"AspNetMMCExt", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                 FxPolicyHelper::AppXBinder_Blocked},
    {L"sysglobl", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                     FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Build.Engine", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Build.Framework", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,    FxPolicyHelper::AppXBinder_Blocked},

    // FX 3.0 assemblies:
    // Note: we shipped .NET 4.0 with entries in this list for PresentationCFFRasterizer and System.ServiceModel.Install
    // even though these assemblies did not ship with .NET 4.0. To maintain 100% compatibility with 4.0 we will keep
    // these in .NET 4.5, but we should remove them in a future SxS version of the Framework.
    {L"PresentationCFFRasterizer", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked}, // See note above
    {L"PresentationCore", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                 FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,            FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework.Aero", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework.Classic", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,    FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework.Luna", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework.Royale", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,     FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationUI", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                   FxPolicyHelper::AppXBinder_Blocked},
    {L"ReachFramework", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                   FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Printing", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                  FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Speech", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                    FxPolicyHelper::AppXBinder_Blocked},
    {L"UIAutomationClient", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,               FxPolicyHelper::AppXBinder_Blocked},
    {L"UIAutomationClientsideProviders", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,  FxPolicyHelper::AppXBinder_Blocked},
    {L"UIAutomationProvider", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,             FxPolicyHelper::AppXBinder_Blocked},
    {L"UIAutomationTypes", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                FxPolicyHelper::AppXBinder_Blocked},
    {L"WindowsBase", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                      FxPolicyHelper::AppXBinder_Blocked},
    {L"WindowsFormsIntegration", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"SMDiagnostics", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                         FxPolicyHelper::AppXBinder_Supported},
    {L"System.IdentityModel", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                  FxPolicyHelper::AppXBinder_Supported},
    {L"System.IdentityModel.Selectors", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Supported},    
    {L"System.IO.Log", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                    FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Runtime.Serialization", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                   FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Install", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Blocked}, // See note above
    {L"System.ServiceModel.WasHosting", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Workflow.Activities", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Workflow.ComponentModel", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,   FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Workflow.Runtime", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Transactions.Bridge", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,    FxPolicyHelper::AppXBinder_Supported},
    {L"Microsoft.Transactions.Bridge.Dtc", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},

    // FX 3.5 assemblies:
    {L"System.AddIn", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                      FxPolicyHelper::AppXBinder_Blocked},
    {L"System.AddIn.Contract", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ComponentModel.Composition", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported}, // Shipping out-of-band
    {L"System.Core", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                       FxPolicyHelper::AppXBinder_Supported},
    {L"System.Data.DataSetExtensions", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,     FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data.Linq", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                  FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Xml.Linq", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                   FxPolicyHelper::AppXBinder_Supported},
    {L"System.DirectoryServices.AccountManagement", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Management.Instrumentation", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Net", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                   FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Web", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,      FxPolicyHelper::AppXBinder_Supported}, // Needed for portable libraries
    {L"System.Web.Extensions", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Extensions.Design", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Windows.Presentation", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"System.WorkflowServices", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,      FxPolicyHelper::AppXBinder_Blocked},
    // Microsoft.Data.Entity.Build.Tasks.dll should not be unified on purpose - it is supported SxS, i.e. both 3.5 and 4.0 versions can be loaded into CLR 4.0+.
    // {L"Microsoft.Data.Entity.Build.Tasks", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L},

    // FX 3.5 SP1 assemblies:
    {L"System.ComponentModel.DataAnnotations", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Data.Entity", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,            FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data.Entity.Design", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,     FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data.Services", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data.Services.Client", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,   FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Data.Services.Design", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,   FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Abstractions", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,  FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.DynamicData", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,   FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.DynamicData.Design", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Entity", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,             FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Entity.Design", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,      FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.Routing", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},

    // FX 4.0 assemblies:
    {L"Microsoft.Build", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,  FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.CSharp", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Dynamic", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,   FxPolicyHelper::AppXBinder_Supported},
    {L"System.Numerics", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Supported},
    {L"System.Xaml", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Supported},
    // Microsoft.Workflow.Compiler.exe:
    // System.Workflow.ComponentModel.dll started to depend on Microsoft.Workflow.Compiler.exe in 4.0 RTM
    {L"Microsoft.Workflow.Compiler", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},

    // FX 4.5 assemblies:
    {L"Microsoft.Activities.Build", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Build.Conversion.v4.0", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,      FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Build.Tasks.v4.0", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Build.Utilities.v4.0", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Internal.Tasks.Dataflow", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.VisualBasic.Activities.Compiler", MICROSOFT_PUBLICKEY_STR_L, VER_VS_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.VisualC.STLCLR", MICROSOFT_PUBLICKEY_STR_L, VER_VC_STLCLR_ASSEMBLYVERSION_STR_L,   FxPolicyHelper::AppXBinder_Blocked},
    {L"Microsoft.Windows.ApplicationServer.Applications", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationBuildTasks", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,               FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework.Aero2", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework.AeroLite", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework-SystemCore", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework-SystemData", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework-SystemDrawing", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework-SystemXml", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Blocked},
    {L"PresentationFramework-SystemXmlLinq", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Activities", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                    FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Activities.Core.Presentation", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,  FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Activities.DurableInstancing", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,  FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Activities.Presentation", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ComponentModel.Composition.Registration", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Device", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                         FxPolicyHelper::AppXBinder_Blocked},
    {L"System.IdentityModel.Services", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,         FxPolicyHelper::AppXBinder_Blocked},
    {L"System.IO.Compression", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                 FxPolicyHelper::AppXBinder_Supported},
    {L"System.IO.Compression.FileSystem", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,      FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Net.Http", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                  FxPolicyHelper::AppXBinder_Supported},
    {L"System.Net.Http.WebRequest", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,       FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection.Context", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,             FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Caching", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,           FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Runtime.DurableInstancing", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.WindowsRuntime", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.WindowsRuntime.UI.Xaml", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Activation", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ServiceModel.Activities", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ServiceModel.Channels", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ServiceModel.Discovery", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ServiceModel.Internals", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Routing", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.ServiceModel.ServiceMoniker40", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.ApplicationServices", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported}, // Has to be supported in AppX, because it is in transitive closure of supported assemblies
    {L"System.Web.DataVisualization", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Web.DataVisualization.Design", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Windows.Controls.Ribbon", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,        FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Windows.Forms.DataVisualization", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Windows.Forms.DataVisualization.Design", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Windows.Input.Manipulations", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,    FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Xaml.Hosting", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,              FxPolicyHelper::AppXBinder_Blocked},
    {L"XamlBuildTask", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                    FxPolicyHelper::AppXBinder_Blocked},
    {L"XsdBuildTask", SHAREDLIB_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,                     FxPolicyHelper::AppXBinder_Blocked},
    {L"System.Numerics.Vectors", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L,          FxPolicyHelper::AppXBinder_Supported},

    // FX 4.5 facade assemblies:
    {L"System.Collections", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Collections.Concurrent", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ComponentModel", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ComponentModel.Annotations", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ComponentModel.EventBasedAsync", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Diagnostics.Contracts", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Diagnostics.Debug", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Diagnostics.Tools", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Diagnostics.Tracing", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Dynamic.Runtime", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Globalization", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.IO", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Linq", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Linq.Expressions", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Linq.Parallel", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Linq.Queryable", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Net.Http.Rtc", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Net.NetworkInformation", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Net.Primitives", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Net.Requests", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Net.WebHeaderCollection", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ObjectModel", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection.Emit", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection.Emit.ILGeneration", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection.Emit.Lightweight", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection.Extensions", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Reflection.Primitives", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Resources.ResourceManager", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Extensions", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Handles", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.InteropServices", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.InteropServices.WindowsRuntime", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Numerics", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Serialization.Json", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Serialization.Primitives", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Runtime.Serialization.Xml", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Security.Principal", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Duplex", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Http", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.NetTcp", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Primitives", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.ServiceModel.Security", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Text.Encoding", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Text.Encoding.Extensions", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Text.RegularExpressions", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Threading", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Threading.Tasks", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Threading.Tasks.Parallel", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Threading.Timer", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Xml.ReaderWriter", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Xml.XDocument", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Xml.XmlSerializer", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    // Manually added facades
    {L"System.Windows", MICROSOFT_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},
    {L"System.Xml.Serialization", ECMA_PUBLICKEY_STR_L, VER_ASSEMBLYVERSION_STR_L, FxPolicyHelper::AppXBinder_Supported},

#endif // NDP4_AUTO_VERSION_ROLLFORWARD

// ENDDICTIONARY
};  //g_arFxPolicy

#endif //ORIGINAL_SOURCE
