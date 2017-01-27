// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: enum/enum_cz.proto

#ifndef PROTOBUF_enum_2fenum_5fcz_2eproto__INCLUDED
#define PROTOBUF_enum_2fenum_5fcz_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace PKENUM {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_enum_2fenum_5fcz_2eproto();
void protobuf_AssignDesc_enum_2fenum_5fcz_2eproto();
void protobuf_ShutdownFile_enum_2fenum_5fcz_2eproto();


enum CZPacketEnum {
  CZ_BEGIN = 200,
  CZ_MOVE = 201,
  CZ_STOP = 202,
  CZ_EVADE = 203,
  CZ_ENTER_GAME = 210,
  CZ_ATTACK = 211,
  CZ_ATTACK_HIT = 212,
  CZ_REVIVE = 213,
  CZ_USE_HP_POTION = 214,
  CZ_PING = 298,
  CZ_END = 299
};
bool CZPacketEnum_IsValid(int value);
const CZPacketEnum CZPacketEnum_MIN = CZ_BEGIN;
const CZPacketEnum CZPacketEnum_MAX = CZ_END;
const int CZPacketEnum_ARRAYSIZE = CZPacketEnum_MAX + 1;

const ::google::protobuf::EnumDescriptor* CZPacketEnum_descriptor();
inline const ::std::string& CZPacketEnum_Name(CZPacketEnum value) {
  return ::google::protobuf::internal::NameOfEnum(
    CZPacketEnum_descriptor(), value);
}
inline bool CZPacketEnum_Parse(
    const ::std::string& name, CZPacketEnum* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CZPacketEnum>(
    CZPacketEnum_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace PKENUM

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::PKENUM::CZPacketEnum> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::PKENUM::CZPacketEnum>() {
  return ::PKENUM::CZPacketEnum_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_enum_2fenum_5fcz_2eproto__INCLUDED
