// Copyright (c) 2020 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=dd4497ea885d54be767940af4148f3c7c9f22298$
//

#include "libcef_dll/cpptoc/print_dialog_callback_cpptoc.h"
#include "libcef_dll/cpptoc/print_settings_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK
print_dialog_callback_cont(struct _cef_print_dialog_callback_t* self,
                           struct _cef_print_settings_t* settings) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: settings; type: refptr_same
  DCHECK(settings);
  if (!settings)
    return;

  // Execute
  CefPrintDialogCallbackCppToC::Get(self)->Continue(
      CefPrintSettingsCppToC::Unwrap(settings));
}

void CEF_CALLBACK
print_dialog_callback_cancel(struct _cef_print_dialog_callback_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefPrintDialogCallbackCppToC::Get(self)->Cancel();
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefPrintDialogCallbackCppToC::CefPrintDialogCallbackCppToC() {
  GetStruct()->cont = print_dialog_callback_cont;
  GetStruct()->cancel = print_dialog_callback_cancel;
}

// DESTRUCTOR - Do not edit by hand.

CefPrintDialogCallbackCppToC::~CefPrintDialogCallbackCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefPrintDialogCallback> CefCppToCRefCounted<
    CefPrintDialogCallbackCppToC,
    CefPrintDialogCallback,
    cef_print_dialog_callback_t>::UnwrapDerived(CefWrapperType type,
                                                cef_print_dialog_callback_t*
                                                    s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefPrintDialogCallbackCppToC,
                                   CefPrintDialogCallback,
                                   cef_print_dialog_callback_t>::kWrapperType =
    WT_PRINT_DIALOG_CALLBACK;
