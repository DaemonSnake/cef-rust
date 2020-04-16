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
// $hash=80cb1a6def2d011b59ebd72953d404bff04ba31c$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_ACCESSIBILITY_HANDLER_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_ACCESSIBILITY_HANDLER_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_accessibility_handler_capi.h"
#include "include/cef_accessibility_handler.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefAccessibilityHandlerCToCpp
    : public CefCToCppRefCounted<CefAccessibilityHandlerCToCpp,
                                 CefAccessibilityHandler,
                                 cef_accessibility_handler_t> {
 public:
  CefAccessibilityHandlerCToCpp();
  virtual ~CefAccessibilityHandlerCToCpp();

  // CefAccessibilityHandler methods.
  void OnAccessibilityTreeChange(CefRefPtr<CefValue> value) override;
  void OnAccessibilityLocationChange(CefRefPtr<CefValue> value) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_ACCESSIBILITY_HANDLER_CTOCPP_H_
