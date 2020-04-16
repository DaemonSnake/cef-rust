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
// $hash=50b66fea70f0b25aec23a1c24edeac8ae6b9915c$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_V8VALUE_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_V8VALUE_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_v8_capi.h"
#include "include/cef_v8.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefV8ValueCppToC
    : public CefCppToCRefCounted<CefV8ValueCppToC, CefV8Value, cef_v8value_t> {
 public:
  CefV8ValueCppToC();
  virtual ~CefV8ValueCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_V8VALUE_CPPTOC_H_
