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
// $hash=d83e342a1d94a14e39b1eba174e0b8892fd52728$
//

#include "libcef_dll/cpptoc/binary_value_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_binary_value_t* cef_binary_value_create(const void* data,
                                                       size_t data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return NULL;

  // Execute
  CefRefPtr<CefBinaryValue> _retval = CefBinaryValue::Create(data, data_size);

  // Return type: refptr_same
  return CefBinaryValueCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK binary_value_is_valid(struct _cef_binary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBinaryValueCppToC::Get(self)->IsValid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK binary_value_is_owned(struct _cef_binary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBinaryValueCppToC::Get(self)->IsOwned();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK binary_value_is_same(struct _cef_binary_value_t* self,
                                      struct _cef_binary_value_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that)
    return 0;

  // Execute
  bool _retval = CefBinaryValueCppToC::Get(self)->IsSame(
      CefBinaryValueCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK binary_value_is_equal(struct _cef_binary_value_t* self,
                                       struct _cef_binary_value_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that)
    return 0;

  // Execute
  bool _retval = CefBinaryValueCppToC::Get(self)->IsEqual(
      CefBinaryValueCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

struct _cef_binary_value_t* CEF_CALLBACK
binary_value_copy(struct _cef_binary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefBinaryValue> _retval = CefBinaryValueCppToC::Get(self)->Copy();

  // Return type: refptr_same
  return CefBinaryValueCppToC::Wrap(_retval);
}

size_t CEF_CALLBACK binary_value_get_size(struct _cef_binary_value_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefBinaryValueCppToC::Get(self)->GetSize();

  // Return type: simple
  return _retval;
}

size_t CEF_CALLBACK binary_value_get_data(struct _cef_binary_value_t* self,
                                          void* buffer,
                                          size_t buffer_size,
                                          size_t data_offset) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: buffer; type: simple_byaddr
  DCHECK(buffer);
  if (!buffer)
    return 0;

  // Execute
  size_t _retval = CefBinaryValueCppToC::Get(self)->GetData(buffer, buffer_size,
                                                            data_offset);

  // Return type: simple
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefBinaryValueCppToC::CefBinaryValueCppToC() {
  GetStruct()->is_valid = binary_value_is_valid;
  GetStruct()->is_owned = binary_value_is_owned;
  GetStruct()->is_same = binary_value_is_same;
  GetStruct()->is_equal = binary_value_is_equal;
  GetStruct()->copy = binary_value_copy;
  GetStruct()->get_size = binary_value_get_size;
  GetStruct()->get_data = binary_value_get_data;
}

// DESTRUCTOR - Do not edit by hand.

CefBinaryValueCppToC::~CefBinaryValueCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefBinaryValue>
CefCppToCRefCounted<CefBinaryValueCppToC, CefBinaryValue, cef_binary_value_t>::
    UnwrapDerived(CefWrapperType type, cef_binary_value_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefBinaryValueCppToC,
                                   CefBinaryValue,
                                   cef_binary_value_t>::kWrapperType =
    WT_BINARY_VALUE;
