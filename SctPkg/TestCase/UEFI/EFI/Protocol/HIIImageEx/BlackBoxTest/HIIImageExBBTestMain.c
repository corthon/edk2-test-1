/*++
  The material contained herein is not a license, either        
  expressly or impliedly, to any intellectual property owned    
  or controlled by any of the authors or developers of this     
  material or to any contribution thereto. The material         
  contained herein is provided on an "AS IS" basis and, to the  
  maximum extent permitted by applicable law, this information  
  is provided AS IS AND WITH ALL FAULTS, and the authors and    
  developers of this material hereby disclaim all other         
  warranties and conditions, either express, implied or         
  statutory, including, but not limited to, any (if any)        
  implied warranties, duties or conditions of merchantability,  
  of fitness for a particular purpose, of accuracy or           
  completeness of responses, of results, of workmanlike         
  effort, of lack of viruses and of lack of negligence, all     
  with regard to this material and any contribution thereto.    
  Designers must not rely on the absence or characteristics of  
  any features or instructions marked "reserved" or             
  "undefined." The Unified EFI Forum, Inc. reserves any         
  features or instructions so marked for future definition and  
  shall have no responsibility whatsoever for conflicts or      
  incompatibilities arising from future changes to them. ALSO,  
  THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,  
  QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR            
  NON-INFRINGEMENT WITH REGARD TO THE TEST SUITE AND ANY        
  CONTRIBUTION THERETO.                                         
                                                                
  IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THIS MATERIAL OR  
  ANY CONTRIBUTION THERETO BE LIABLE TO ANY OTHER PARTY FOR     
  THE COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST      
  PROFITS, LOSS OF USE, LOSS OF DATA, OR ANY INCIDENTAL,        
  CONSEQUENTIAL, DIRECT, INDIRECT, OR SPECIAL DAMAGES WHETHER   
  UNDER CONTRACT, TORT, WARRANTY, OR OTHERWISE, ARISING IN ANY  
  WAY OUT OF THIS OR ANY OTHER AGREEMENT RELATING TO THIS       
  DOCUMENT, WHETHER OR NOT SUCH PARTY HAD ADVANCE NOTICE OF     
  THE POSSIBILITY OF SUCH DAMAGES.                              
                                                                
  Copyright 2006 - 2016 Unified EFI, Inc. All  
  Rights Reserved, subject to all existing rights in all        
  matters included within this Test Suite, to which United      
  EFI, Inc. makes no claim of right.                            
                                                                
  Copyright (c) 2010 - 2016, Intel Corporation. All rights reserved.<BR>   
   
  (C) Copyright 2017 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.
--*/
/*++

Module Name:

  HIIImageExBBTestMain.c

Abstract:

  Test Driver of HII ImageEX Protocol

--*/

#include "HIIImageExBBTestMain.h"

//
// Global variables
//
EFI_HANDLE mImageHandle;

EFI_BB_TEST_PROTOCOL *gBBTestProtocolInterface;

EFI_BB_TEST_PROTOCOL_FIELD gBBTestProtocolField = {
  EFI_HII_IMAGE_EX_PROTOCOL_TEST_REVISION,
  EFI_HII_IMAGE_EX_PROTOCOL_GUID,
  L"HII ImageEx Protocol Test",
  L"UEFI HII ImageEx Protocol Black-Box Test"
};

EFI_GUID gSupportProtocolGuid[] = {
  EFI_STANDARD_TEST_LIBRARY_GUID,
  EFI_NULL_GUID
};

EFI_BB_TEST_ENTRY_FIELD gBBTestEntryField[] = {
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0101,
    L"NewImageExFunction",
    L"Function auto test for HII Image Ex Protocol NewImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestNewImageExFunctionTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0102,
    L"GetImageExFunction",
    L"Function auto test for HII Image Ex Protocol GetImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestGetImageExFunctionTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0103,
    L"SetImageExFunction",
    L"Function auto test for HII Image Ex Protocol SetImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestSetImageExFunctionTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0104,
    L"DrawImageExFunction",
    L"Function auto test for HII Image Ex Protocol DrawImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestDrawImageExFunctionTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0105,
    L"DrawImageIdExFunction",
    L"Function auto test for HII Image Ex Protocol DrawImageIdEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestDrawImageIdExFunctionTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0106,
    L"GetImageInfoFunction",
    L"Function auto test for HII Image Ex Protocol GetImageInfo().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestGetImageInfoFunctionTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0201,
    L"NewImageExConformance",
    L"Conformance auto test for HII Image Ex Protocol NewImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestNewImageExConformanceTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0202,
    L"GetImageExConformance",
    L"Conformance auto test for HII Image Ex Protocol GetImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestGetImageExConformanceTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0203,
    L"SetImageExConformance",
    L"Conformance auto test for HII Image Ex Protocol SetImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestSetImageExConformanceTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0204,
    L"DrawImageExConformance",
    L"Conformance auto test for HII Image Ex Protocol DrawImageEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestDrawImageExConformanceTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0205,
    L"DrawImageIdExConformance",
    L"Conformance auto test for HII Image Ex Protocol DrawImageIdEx().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestDrawImageIdExConformanceTest
  },
  {
    EFI_HII_IMAGE_EX_PROTOCOL_TEST_ENTRY_GUID0206,
    L"GetImageInfoConformance",
    L"Conformance auto test for HII Image Ex Protocol GetImageInfo().",
    EFI_TEST_LEVEL_MINIMAL,
    gSupportProtocolGuid,
    EFI_TEST_CASE_AUTO,
    BBTestGetImageInfoConformanceTest
  },
  0
};

//
//
//

EFI_STATUS
InitializeHIIImageExBBTest (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_SYSTEM_TABLE             *SystemTable
  )
{
  EfiInitializeTestLib (ImageHandle, SystemTable);

  //
  // initialize test utility lib
  //

  SctInitializeLib (ImageHandle, SystemTable);

  mImageHandle = ImageHandle;

  return EfiInitAndInstallBBTestInterface (
           &ImageHandle,
           &gBBTestProtocolField,
           gBBTestEntryField,
           UnloadHIIImageExBBTest,
           &gBBTestProtocolInterface
           );
}


EFI_STATUS
UnloadHIIImageExBBTest (
  IN EFI_HANDLE                   ImageHandle
  )
{
  return EfiUninstallAndFreeBBTestInterface (
           ImageHandle,
           gBBTestProtocolInterface
           );
}

EFI_STATUS
GetGraphicsOutputInterface (
  OUT EFI_GRAPHICS_OUTPUT_PROTOCOL    **GraphicsOutput
  )
{
  UINTN                 NoHandles;
  EFI_HANDLE            *HandleBuffer;
  EFI_STATUS            Status;
  
  Status = gtBS->LocateHandleBuffer (
                        ByProtocol,
                        &gBlackBoxEfiGraphicsOutputProtocolGuid,
                        NULL,
                        &NoHandles,
                        &HandleBuffer
                        );
  if ( EFI_ERROR(Status) ) {
    return Status;
  }
  
  if ( NoHandles <= 0 ) {
    return EFI_UNSUPPORTED;
  }
  
  Status = gtBS->HandleProtocol (
             HandleBuffer[0],
             &gBlackBoxEfiGraphicsOutputProtocolGuid,
             (VOID **) GraphicsOutput
             );
  if ( EFI_ERROR(Status) ) {
    gtBS->FreePool ( HandleBuffer );
    return Status;
  }
  
  gtBS->FreePool ( HandleBuffer );
  
  return EFI_SUCCESS;
}

EFI_STATUS
GetHIIDatabaseInterface (
  OUT EFI_HII_DATABASE_PROTOCOL    **HIIDatabase
  )
{
  UINTN                                 NoHandles;
  EFI_HANDLE                            *HandleBuffer;
  EFI_STATUS                            Status;
  
  //
  // Get the HII Database Protocol interface
  //
  Status = gtBS->LocateHandleBuffer (
                        ByProtocol,
                        &gBlackBoxEfiHIIDatabaseProtocolGuid,
                        NULL,
                        &NoHandles,
                        &HandleBuffer
                        );
  if ( EFI_ERROR(Status) ) {
    return Status;
  }
  
  if ( NoHandles <= 0 ) {
    return EFI_DEVICE_ERROR;
  }
  
  Status = gtBS->HandleProtocol (
             HandleBuffer[0],
             &gBlackBoxEfiHIIDatabaseProtocolGuid,
             (VOID **) HIIDatabase
             );
  if ( EFI_ERROR(Status) ) {
    gtBS->FreePool ( HandleBuffer );
    return Status;
  }
  
  gtBS->FreePool ( HandleBuffer );
  
  return EFI_SUCCESS;
}
