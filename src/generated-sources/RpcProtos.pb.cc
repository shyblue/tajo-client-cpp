// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RpcProtos.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "RpcProtos.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* RpcRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RpcRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* RpcResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RpcResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_RpcProtos_2eproto() {
  protobuf_AddDesc_RpcProtos_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "RpcProtos.proto");
  GOOGLE_CHECK(file != NULL);
  RpcRequest_descriptor_ = file->message_type(0);
  static const int RpcRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcRequest, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcRequest, method_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcRequest, request_message_),
  };
  RpcRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RpcRequest_descriptor_,
      RpcRequest::default_instance_,
      RpcRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RpcRequest));
  RpcResponse_descriptor_ = file->message_type(1);
  static const int RpcResponse_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, response_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, error_class_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, error_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, error_trace_),
  };
  RpcResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RpcResponse_descriptor_,
      RpcResponse::default_instance_,
      RpcResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RpcResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_RpcProtos_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RpcRequest_descriptor_, &RpcRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RpcResponse_descriptor_, &RpcResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_RpcProtos_2eproto() {
  delete RpcRequest::default_instance_;
  delete RpcRequest_reflection_;
  delete RpcResponse::default_instance_;
  delete RpcResponse_reflection_;
}

void protobuf_AddDesc_RpcProtos_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017RpcProtos.proto\"F\n\nRpcRequest\022\n\n\002id\030\001 "
    "\002(\005\022\023\n\013method_name\030\002 \002(\t\022\027\n\017request_mess"
    "age\030\003 \001(\014\"t\n\013RpcResponse\022\n\n\002id\030\001 \002(\005\022\030\n\020"
    "response_message\030\002 \001(\014\022\023\n\013error_class\030\003 "
    "\001(\t\022\025\n\rerror_message\030\004 \001(\t\022\023\n\013error_trac"
    "e\030\005 \001(\tB \n\023org.apache.tajo.rpcB\tRpcProto"
    "s", 241);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "RpcProtos.proto", &protobuf_RegisterTypes);
  RpcRequest::default_instance_ = new RpcRequest();
  RpcResponse::default_instance_ = new RpcResponse();
  RpcRequest::default_instance_->InitAsDefaultInstance();
  RpcResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_RpcProtos_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_RpcProtos_2eproto {
  StaticDescriptorInitializer_RpcProtos_2eproto() {
    protobuf_AddDesc_RpcProtos_2eproto();
  }
} static_descriptor_initializer_RpcProtos_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RpcRequest::kIdFieldNumber;
const int RpcRequest::kMethodNameFieldNumber;
const int RpcRequest::kRequestMessageFieldNumber;
#endif  // !_MSC_VER

RpcRequest::RpcRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void RpcRequest::InitAsDefaultInstance() {
}

RpcRequest::RpcRequest(const RpcRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void RpcRequest::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  method_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  request_message_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RpcRequest::~RpcRequest() {
  SharedDtor();
}

void RpcRequest::SharedDtor() {
  if (method_name_ != &::google::protobuf::internal::kEmptyString) {
    delete method_name_;
  }
  if (request_message_ != &::google::protobuf::internal::kEmptyString) {
    delete request_message_;
  }
  if (this != default_instance_) {
  }
}

void RpcRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RpcRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RpcRequest_descriptor_;
}

const RpcRequest& RpcRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RpcProtos_2eproto();
  return *default_instance_;
}

RpcRequest* RpcRequest::default_instance_ = NULL;

RpcRequest* RpcRequest::New() const {
  return new RpcRequest;
}

void RpcRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    if (has_method_name()) {
      if (method_name_ != &::google::protobuf::internal::kEmptyString) {
        method_name_->clear();
      }
    }
    if (has_request_message()) {
      if (request_message_ != &::google::protobuf::internal::kEmptyString) {
        request_message_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RpcRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_method_name;
        break;
      }

      // required string method_name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_method_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_method_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->method_name().data(), this->method_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_request_message;
        break;
      }

      // optional bytes request_message = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_request_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_request_message()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void RpcRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string method_name = 2;
  if (has_method_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->method_name().data(), this->method_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->method_name(), output);
  }

  // optional bytes request_message = 3;
  if (has_request_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->request_message(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* RpcRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string method_name = 2;
  if (has_method_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->method_name().data(), this->method_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->method_name(), target);
  }

  // optional bytes request_message = 3;
  if (has_request_message()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->request_message(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int RpcRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required string method_name = 2;
    if (has_method_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->method_name());
    }

    // optional bytes request_message = 3;
    if (has_request_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->request_message());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RpcRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RpcRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RpcRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RpcRequest::MergeFrom(const RpcRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_method_name()) {
      set_method_name(from.method_name());
    }
    if (from.has_request_message()) {
      set_request_message(from.request_message());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RpcRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RpcRequest::CopyFrom(const RpcRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void RpcRequest::Swap(RpcRequest* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(method_name_, other->method_name_);
    std::swap(request_message_, other->request_message_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RpcRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RpcRequest_descriptor_;
  metadata.reflection = RpcRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RpcResponse::kIdFieldNumber;
const int RpcResponse::kResponseMessageFieldNumber;
const int RpcResponse::kErrorClassFieldNumber;
const int RpcResponse::kErrorMessageFieldNumber;
const int RpcResponse::kErrorTraceFieldNumber;
#endif  // !_MSC_VER

RpcResponse::RpcResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void RpcResponse::InitAsDefaultInstance() {
}

RpcResponse::RpcResponse(const RpcResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void RpcResponse::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  response_message_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  error_class_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  error_message_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  error_trace_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RpcResponse::~RpcResponse() {
  SharedDtor();
}

void RpcResponse::SharedDtor() {
  if (response_message_ != &::google::protobuf::internal::kEmptyString) {
    delete response_message_;
  }
  if (error_class_ != &::google::protobuf::internal::kEmptyString) {
    delete error_class_;
  }
  if (error_message_ != &::google::protobuf::internal::kEmptyString) {
    delete error_message_;
  }
  if (error_trace_ != &::google::protobuf::internal::kEmptyString) {
    delete error_trace_;
  }
  if (this != default_instance_) {
  }
}

void RpcResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RpcResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RpcResponse_descriptor_;
}

const RpcResponse& RpcResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RpcProtos_2eproto();
  return *default_instance_;
}

RpcResponse* RpcResponse::default_instance_ = NULL;

RpcResponse* RpcResponse::New() const {
  return new RpcResponse;
}

void RpcResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    if (has_response_message()) {
      if (response_message_ != &::google::protobuf::internal::kEmptyString) {
        response_message_->clear();
      }
    }
    if (has_error_class()) {
      if (error_class_ != &::google::protobuf::internal::kEmptyString) {
        error_class_->clear();
      }
    }
    if (has_error_message()) {
      if (error_message_ != &::google::protobuf::internal::kEmptyString) {
        error_message_->clear();
      }
    }
    if (has_error_trace()) {
      if (error_trace_ != &::google::protobuf::internal::kEmptyString) {
        error_trace_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RpcResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_response_message;
        break;
      }

      // optional bytes response_message = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_response_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_response_message()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_error_class;
        break;
      }

      // optional string error_class = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_error_class:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error_class()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->error_class().data(), this->error_class().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_error_message;
        break;
      }

      // optional string error_message = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_error_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->error_message().data(), this->error_message().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_error_trace;
        break;
      }

      // optional string error_trace = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_error_trace:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error_trace()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->error_trace().data(), this->error_trace().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void RpcResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional bytes response_message = 2;
  if (has_response_message()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->response_message(), output);
  }

  // optional string error_class = 3;
  if (has_error_class()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->error_class().data(), this->error_class().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->error_class(), output);
  }

  // optional string error_message = 4;
  if (has_error_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->error_message().data(), this->error_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->error_message(), output);
  }

  // optional string error_trace = 5;
  if (has_error_trace()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->error_trace().data(), this->error_trace().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->error_trace(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* RpcResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional bytes response_message = 2;
  if (has_response_message()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->response_message(), target);
  }

  // optional string error_class = 3;
  if (has_error_class()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->error_class().data(), this->error_class().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->error_class(), target);
  }

  // optional string error_message = 4;
  if (has_error_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->error_message().data(), this->error_message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->error_message(), target);
  }

  // optional string error_trace = 5;
  if (has_error_trace()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->error_trace().data(), this->error_trace().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->error_trace(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int RpcResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional bytes response_message = 2;
    if (has_response_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->response_message());
    }

    // optional string error_class = 3;
    if (has_error_class()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->error_class());
    }

    // optional string error_message = 4;
    if (has_error_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->error_message());
    }

    // optional string error_trace = 5;
    if (has_error_trace()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->error_trace());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RpcResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RpcResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RpcResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RpcResponse::MergeFrom(const RpcResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_response_message()) {
      set_response_message(from.response_message());
    }
    if (from.has_error_class()) {
      set_error_class(from.error_class());
    }
    if (from.has_error_message()) {
      set_error_message(from.error_message());
    }
    if (from.has_error_trace()) {
      set_error_trace(from.error_trace());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RpcResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RpcResponse::CopyFrom(const RpcResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void RpcResponse::Swap(RpcResponse* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(response_message_, other->response_message_);
    std::swap(error_class_, other->error_class_);
    std::swap(error_message_, other->error_message_);
    std::swap(error_trace_, other->error_trace_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RpcResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RpcResponse_descriptor_;
  metadata.reflection = RpcResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
