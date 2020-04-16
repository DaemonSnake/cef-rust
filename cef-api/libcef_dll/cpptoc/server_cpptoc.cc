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
// $hash=0a1970879ddc0bd40f5a564542ab8b11414a6b0a$
//

#include "libcef_dll/cpptoc/server_cpptoc.h"
#include "libcef_dll/cpptoc/task_runner_cpptoc.h"
#include "libcef_dll/ctocpp/server_handler_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"
#include "libcef_dll/transfer_util.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT void cef_server_create(const cef_string_t* address,
                                  uint16 port,
                                  int backlog,
                                  struct _cef_server_handler_t* handler) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: address; type: string_byref_const
  DCHECK(address);
  if (!address)
    return;
  // Verify param: handler; type: refptr_diff
  DCHECK(handler);
  if (!handler)
    return;

  // Execute
  CefServer::CreateServer(CefString(address), port, backlog,
                          CefServerHandlerCToCpp::Wrap(handler));
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

struct _cef_task_runner_t* CEF_CALLBACK
server_get_task_runner(struct _cef_server_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefTaskRunner> _retval =
      CefServerCppToC::Get(self)->GetTaskRunner();

  // Return type: refptr_same
  return CefTaskRunnerCppToC::Wrap(_retval);
}

void CEF_CALLBACK server_shutdown(struct _cef_server_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefServerCppToC::Get(self)->Shutdown();
}

int CEF_CALLBACK server_is_running(struct _cef_server_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefServerCppToC::Get(self)->IsRunning();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
server_get_address(struct _cef_server_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefServerCppToC::Get(self)->GetAddress();

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK server_has_connection(struct _cef_server_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefServerCppToC::Get(self)->HasConnection();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK server_is_valid_connection(struct _cef_server_t* self,
                                            int connection_id) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefServerCppToC::Get(self)->IsValidConnection(connection_id);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK server_send_http200response(struct _cef_server_t* self,
                                              int connection_id,
                                              const cef_string_t* content_type,
                                              const void* data,
                                              size_t data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: content_type; type: string_byref_const
  DCHECK(content_type);
  if (!content_type)
    return;
  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return;

  // Execute
  CefServerCppToC::Get(self)->SendHttp200Response(
      connection_id, CefString(content_type), data, data_size);
}

void CEF_CALLBACK server_send_http404response(struct _cef_server_t* self,
                                              int connection_id) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefServerCppToC::Get(self)->SendHttp404Response(connection_id);
}

void CEF_CALLBACK
server_send_http500response(struct _cef_server_t* self,
                            int connection_id,
                            const cef_string_t* error_message) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: error_message; type: string_byref_const
  DCHECK(error_message);
  if (!error_message)
    return;

  // Execute
  CefServerCppToC::Get(self)->SendHttp500Response(connection_id,
                                                  CefString(error_message));
}

void CEF_CALLBACK
server_send_http_response(struct _cef_server_t* self,
                          int connection_id,
                          int response_code,
                          const cef_string_t* content_type,
                          int64 content_length,
                          cef_string_multimap_t extra_headers) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: content_type; type: string_byref_const
  DCHECK(content_type);
  if (!content_type)
    return;
  // Unverified params: extra_headers

  // Translate param: extra_headers; type: string_map_multi_byref_const
  std::multimap<CefString, CefString> extra_headersMultimap;
  transfer_string_multimap_contents(extra_headers, extra_headersMultimap);

  // Execute
  CefServerCppToC::Get(self)->SendHttpResponse(
      connection_id, response_code, CefString(content_type), content_length,
      extra_headersMultimap);
}

void CEF_CALLBACK server_send_raw_data(struct _cef_server_t* self,
                                       int connection_id,
                                       const void* data,
                                       size_t data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return;

  // Execute
  CefServerCppToC::Get(self)->SendRawData(connection_id, data, data_size);
}

void CEF_CALLBACK server_close_connection(struct _cef_server_t* self,
                                          int connection_id) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefServerCppToC::Get(self)->CloseConnection(connection_id);
}

void CEF_CALLBACK server_send_web_socket_message(struct _cef_server_t* self,
                                                 int connection_id,
                                                 const void* data,
                                                 size_t data_size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return;

  // Execute
  CefServerCppToC::Get(self)->SendWebSocketMessage(connection_id, data,
                                                   data_size);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefServerCppToC::CefServerCppToC() {
  GetStruct()->get_task_runner = server_get_task_runner;
  GetStruct()->shutdown = server_shutdown;
  GetStruct()->is_running = server_is_running;
  GetStruct()->get_address = server_get_address;
  GetStruct()->has_connection = server_has_connection;
  GetStruct()->is_valid_connection = server_is_valid_connection;
  GetStruct()->send_http200response = server_send_http200response;
  GetStruct()->send_http404response = server_send_http404response;
  GetStruct()->send_http500response = server_send_http500response;
  GetStruct()->send_http_response = server_send_http_response;
  GetStruct()->send_raw_data = server_send_raw_data;
  GetStruct()->close_connection = server_close_connection;
  GetStruct()->send_web_socket_message = server_send_web_socket_message;
}

// DESTRUCTOR - Do not edit by hand.

CefServerCppToC::~CefServerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefServer>
CefCppToCRefCounted<CefServerCppToC, CefServer, cef_server_t>::UnwrapDerived(
    CefWrapperType type,
    cef_server_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefServerCppToC, CefServer, cef_server_t>::
    kWrapperType = WT_SERVER;
