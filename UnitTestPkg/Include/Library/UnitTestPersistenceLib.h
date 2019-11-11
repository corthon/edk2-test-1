/** @file -- UnitTestPersistenceLib.h
  This header file describes a library that contains functions to save and
  restore unit test internal state, in case the test needs to pause and resume
  (eg. a reboot-based test).

  Copyright (C) 2016 Microsoft Corporation. All Rights Reserved.
  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _UNIT_TEST_PERSISTENCE_LIB_H_
#define _UNIT_TEST_PERSISTENCE_LIB_H_

#define UNIT_TEST_PERSISTENCE_LIB_VERSION   1


/**
  Determines whether a persistence cache already exists for
  the given framework.

  @param[in]  FrameworkHandle   A pointer to the framework that is being persisted.

  @retval     TRUE
  @retval     FALSE   Cache doesn't exist or an error occurred.

**/
BOOLEAN
EFIAPI
DoesCacheExist (
  IN  UNIT_TEST_FRAMEWORK_HANDLE  FrameworkHandle
  );


/**
  Will save the data associated with an internal Unit Test Framework
  state in a manner that can persist a Unit Test Application quit or
  even a system reboot.

  @param[in]  FrameworkHandle   A pointer to the framework that is being persisted.
  @param[in]  SaveData          A pointer to the buffer containing the serialized
                                framework internal state.

  @retval     EFI_SUCCESS   Data is persisted and the test can be safely quit.
  @retval     Others        Data is not persisted and test cannot be resumed upon exit.

**/
EFI_STATUS
EFIAPI
SaveUnitTestCache (
  IN  UNIT_TEST_FRAMEWORK_HANDLE  FrameworkHandle,
  IN  UNIT_TEST_SAVE_HEADER       *SaveData
  );


/**
  Will retrieve any cached state associated with the given framework.
  Will allocate a buffer to hold the loaded data.

  @param[in]  FrameworkHandle   A pointer to the framework that is being persisted.
  @param[in]  SaveData          A pointer pointer that will be updated with the address
                                of the loaded data buffer.

  @retval     EFI_SUCCESS       Data has been loaded successfully and SaveData is updated
                                with a pointer to the buffer.
  @retval     Others            An error has occurred and no data has been loaded. SaveData
                                is set to NULL.

**/
EFI_STATUS
EFIAPI
LoadUnitTestCache (
  IN  UNIT_TEST_FRAMEWORK_HANDLE  FrameworkHandle,
  OUT UNIT_TEST_SAVE_HEADER       **SaveData
  );

#endif // _UNIT_TEST_PERSISTENCE_LIB_H_
