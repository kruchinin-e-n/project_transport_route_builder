// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: svg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_svg_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_svg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_svg_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_svg_2eproto;
namespace map_pb {
class ColorVar;
class ColorVarDefaultTypeInternal;
extern ColorVarDefaultTypeInternal _ColorVar_default_instance_;
class Point;
class PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
class RGB;
class RGBDefaultTypeInternal;
extern RGBDefaultTypeInternal _RGB_default_instance_;
class RGBO;
class RGBODefaultTypeInternal;
extern RGBODefaultTypeInternal _RGBO_default_instance_;
}  // namespace map_pb
PROTOBUF_NAMESPACE_OPEN
template<> ::map_pb::ColorVar* Arena::CreateMaybeMessage<::map_pb::ColorVar>(Arena*);
template<> ::map_pb::Point* Arena::CreateMaybeMessage<::map_pb::Point>(Arena*);
template<> ::map_pb::RGB* Arena::CreateMaybeMessage<::map_pb::RGB>(Arena*);
template<> ::map_pb::RGBO* Arena::CreateMaybeMessage<::map_pb::RGBO>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace map_pb {

// ===================================================================

class RGB PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:map_pb.RGB) */ {
 public:
  inline RGB() : RGB(nullptr) {};
  virtual ~RGB();

  RGB(const RGB& from);
  RGB(RGB&& from) noexcept
    : RGB() {
    *this = ::std::move(from);
  }

  inline RGB& operator=(const RGB& from) {
    CopyFrom(from);
    return *this;
  }
  inline RGB& operator=(RGB&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RGB& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RGB* internal_default_instance() {
    return reinterpret_cast<const RGB*>(
               &_RGB_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RGB& a, RGB& b) {
    a.Swap(&b);
  }
  inline void Swap(RGB* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RGB* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RGB* New() const final {
    return CreateMaybeMessage<RGB>(nullptr);
  }

  RGB* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RGB>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RGB& from);
  void MergeFrom(const RGB& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RGB* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "map_pb.RGB";
  }
  protected:
  explicit RGB(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_svg_2eproto);
    return ::descriptor_table_svg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRedFieldNumber = 1,
    kGreenFieldNumber = 2,
    kBlueFieldNumber = 3,
  };
  // int32 red = 1;
  void clear_red();
  ::PROTOBUF_NAMESPACE_ID::int32 red() const;
  void set_red(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_red() const;
  void _internal_set_red(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 green = 2;
  void clear_green();
  ::PROTOBUF_NAMESPACE_ID::int32 green() const;
  void set_green(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_green() const;
  void _internal_set_green(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 blue = 3;
  void clear_blue();
  ::PROTOBUF_NAMESPACE_ID::int32 blue() const;
  void set_blue(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_blue() const;
  void _internal_set_blue(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:map_pb.RGB)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 red_;
  ::PROTOBUF_NAMESPACE_ID::int32 green_;
  ::PROTOBUF_NAMESPACE_ID::int32 blue_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class RGBO PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:map_pb.RGBO) */ {
 public:
  inline RGBO() : RGBO(nullptr) {};
  virtual ~RGBO();

  RGBO(const RGBO& from);
  RGBO(RGBO&& from) noexcept
    : RGBO() {
    *this = ::std::move(from);
  }

  inline RGBO& operator=(const RGBO& from) {
    CopyFrom(from);
    return *this;
  }
  inline RGBO& operator=(RGBO&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RGBO& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RGBO* internal_default_instance() {
    return reinterpret_cast<const RGBO*>(
               &_RGBO_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(RGBO& a, RGBO& b) {
    a.Swap(&b);
  }
  inline void Swap(RGBO* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RGBO* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RGBO* New() const final {
    return CreateMaybeMessage<RGBO>(nullptr);
  }

  RGBO* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RGBO>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RGBO& from);
  void MergeFrom(const RGBO& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RGBO* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "map_pb.RGBO";
  }
  protected:
  explicit RGBO(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_svg_2eproto);
    return ::descriptor_table_svg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRedFieldNumber = 1,
    kGreenFieldNumber = 2,
    kOpacityFieldNumber = 4,
    kBlueFieldNumber = 3,
  };
  // int32 red = 1;
  void clear_red();
  ::PROTOBUF_NAMESPACE_ID::int32 red() const;
  void set_red(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_red() const;
  void _internal_set_red(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 green = 2;
  void clear_green();
  ::PROTOBUF_NAMESPACE_ID::int32 green() const;
  void set_green(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_green() const;
  void _internal_set_green(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // double opacity = 4;
  void clear_opacity();
  double opacity() const;
  void set_opacity(double value);
  private:
  double _internal_opacity() const;
  void _internal_set_opacity(double value);
  public:

  // int32 blue = 3;
  void clear_blue();
  ::PROTOBUF_NAMESPACE_ID::int32 blue() const;
  void set_blue(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_blue() const;
  void _internal_set_blue(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:map_pb.RGBO)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 red_;
  ::PROTOBUF_NAMESPACE_ID::int32 green_;
  double opacity_;
  ::PROTOBUF_NAMESPACE_ID::int32 blue_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class ColorVar PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:map_pb.ColorVar) */ {
 public:
  inline ColorVar() : ColorVar(nullptr) {};
  virtual ~ColorVar();

  ColorVar(const ColorVar& from);
  ColorVar(ColorVar&& from) noexcept
    : ColorVar() {
    *this = ::std::move(from);
  }

  inline ColorVar& operator=(const ColorVar& from) {
    CopyFrom(from);
    return *this;
  }
  inline ColorVar& operator=(ColorVar&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ColorVar& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ColorVar* internal_default_instance() {
    return reinterpret_cast<const ColorVar*>(
               &_ColorVar_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(ColorVar& a, ColorVar& b) {
    a.Swap(&b);
  }
  inline void Swap(ColorVar* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ColorVar* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ColorVar* New() const final {
    return CreateMaybeMessage<ColorVar>(nullptr);
  }

  ColorVar* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ColorVar>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ColorVar& from);
  void MergeFrom(const ColorVar& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ColorVar* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "map_pb.ColorVar";
  }
  protected:
  explicit ColorVar(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_svg_2eproto);
    return ::descriptor_table_svg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kColorFieldNumber = 1,
    kRgbFieldNumber = 2,
    kRgboFieldNumber = 3,
  };
  // string color = 1;
  void clear_color();
  const std::string& color() const;
  void set_color(const std::string& value);
  void set_color(std::string&& value);
  void set_color(const char* value);
  void set_color(const char* value, size_t size);
  std::string* mutable_color();
  std::string* release_color();
  void set_allocated_color(std::string* color);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_color();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_color(
      std::string* color);
  private:
  const std::string& _internal_color() const;
  void _internal_set_color(const std::string& value);
  std::string* _internal_mutable_color();
  public:

  // .map_pb.RGB rgb = 2;
  bool has_rgb() const;
  private:
  bool _internal_has_rgb() const;
  public:
  void clear_rgb();
  const ::map_pb::RGB& rgb() const;
  ::map_pb::RGB* release_rgb();
  ::map_pb::RGB* mutable_rgb();
  void set_allocated_rgb(::map_pb::RGB* rgb);
  private:
  const ::map_pb::RGB& _internal_rgb() const;
  ::map_pb::RGB* _internal_mutable_rgb();
  public:
  void unsafe_arena_set_allocated_rgb(
      ::map_pb::RGB* rgb);
  ::map_pb::RGB* unsafe_arena_release_rgb();

  // .map_pb.RGBO rgbo = 3;
  bool has_rgbo() const;
  private:
  bool _internal_has_rgbo() const;
  public:
  void clear_rgbo();
  const ::map_pb::RGBO& rgbo() const;
  ::map_pb::RGBO* release_rgbo();
  ::map_pb::RGBO* mutable_rgbo();
  void set_allocated_rgbo(::map_pb::RGBO* rgbo);
  private:
  const ::map_pb::RGBO& _internal_rgbo() const;
  ::map_pb::RGBO* _internal_mutable_rgbo();
  public:
  void unsafe_arena_set_allocated_rgbo(
      ::map_pb::RGBO* rgbo);
  ::map_pb::RGBO* unsafe_arena_release_rgbo();

  // @@protoc_insertion_point(class_scope:map_pb.ColorVar)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr color_;
  ::map_pb::RGB* rgb_;
  ::map_pb::RGBO* rgbo_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class Point PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:map_pb.Point) */ {
 public:
  inline Point() : Point(nullptr) {};
  virtual ~Point();

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Point& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Point* New() const final {
    return CreateMaybeMessage<Point>(nullptr);
  }

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Point& from);
  void MergeFrom(const Point& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Point* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "map_pb.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_svg_2eproto);
    return ::descriptor_table_svg_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:map_pb.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RGB

// int32 red = 1;
inline void RGB::clear_red() {
  red_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGB::_internal_red() const {
  return red_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGB::red() const {
  // @@protoc_insertion_point(field_get:map_pb.RGB.red)
  return _internal_red();
}
inline void RGB::_internal_set_red(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  red_ = value;
}
inline void RGB::set_red(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_red(value);
  // @@protoc_insertion_point(field_set:map_pb.RGB.red)
}

// int32 green = 2;
inline void RGB::clear_green() {
  green_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGB::_internal_green() const {
  return green_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGB::green() const {
  // @@protoc_insertion_point(field_get:map_pb.RGB.green)
  return _internal_green();
}
inline void RGB::_internal_set_green(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  green_ = value;
}
inline void RGB::set_green(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_green(value);
  // @@protoc_insertion_point(field_set:map_pb.RGB.green)
}

// int32 blue = 3;
inline void RGB::clear_blue() {
  blue_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGB::_internal_blue() const {
  return blue_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGB::blue() const {
  // @@protoc_insertion_point(field_get:map_pb.RGB.blue)
  return _internal_blue();
}
inline void RGB::_internal_set_blue(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  blue_ = value;
}
inline void RGB::set_blue(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_blue(value);
  // @@protoc_insertion_point(field_set:map_pb.RGB.blue)
}

// -------------------------------------------------------------------

// RGBO

// int32 red = 1;
inline void RGBO::clear_red() {
  red_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGBO::_internal_red() const {
  return red_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGBO::red() const {
  // @@protoc_insertion_point(field_get:map_pb.RGBO.red)
  return _internal_red();
}
inline void RGBO::_internal_set_red(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  red_ = value;
}
inline void RGBO::set_red(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_red(value);
  // @@protoc_insertion_point(field_set:map_pb.RGBO.red)
}

// int32 green = 2;
inline void RGBO::clear_green() {
  green_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGBO::_internal_green() const {
  return green_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGBO::green() const {
  // @@protoc_insertion_point(field_get:map_pb.RGBO.green)
  return _internal_green();
}
inline void RGBO::_internal_set_green(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  green_ = value;
}
inline void RGBO::set_green(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_green(value);
  // @@protoc_insertion_point(field_set:map_pb.RGBO.green)
}

// int32 blue = 3;
inline void RGBO::clear_blue() {
  blue_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGBO::_internal_blue() const {
  return blue_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RGBO::blue() const {
  // @@protoc_insertion_point(field_get:map_pb.RGBO.blue)
  return _internal_blue();
}
inline void RGBO::_internal_set_blue(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  blue_ = value;
}
inline void RGBO::set_blue(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_blue(value);
  // @@protoc_insertion_point(field_set:map_pb.RGBO.blue)
}

// double opacity = 4;
inline void RGBO::clear_opacity() {
  opacity_ = 0;
}
inline double RGBO::_internal_opacity() const {
  return opacity_;
}
inline double RGBO::opacity() const {
  // @@protoc_insertion_point(field_get:map_pb.RGBO.opacity)
  return _internal_opacity();
}
inline void RGBO::_internal_set_opacity(double value) {
  
  opacity_ = value;
}
inline void RGBO::set_opacity(double value) {
  _internal_set_opacity(value);
  // @@protoc_insertion_point(field_set:map_pb.RGBO.opacity)
}

// -------------------------------------------------------------------

// ColorVar

// string color = 1;
inline void ColorVar::clear_color() {
  color_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& ColorVar::color() const {
  // @@protoc_insertion_point(field_get:map_pb.ColorVar.color)
  return _internal_color();
}
inline void ColorVar::set_color(const std::string& value) {
  _internal_set_color(value);
  // @@protoc_insertion_point(field_set:map_pb.ColorVar.color)
}
inline std::string* ColorVar::mutable_color() {
  // @@protoc_insertion_point(field_mutable:map_pb.ColorVar.color)
  return _internal_mutable_color();
}
inline const std::string& ColorVar::_internal_color() const {
  return color_.Get();
}
inline void ColorVar::_internal_set_color(const std::string& value) {
  
  color_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ColorVar::set_color(std::string&& value) {
  
  color_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:map_pb.ColorVar.color)
}
inline void ColorVar::set_color(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  color_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:map_pb.ColorVar.color)
}
inline void ColorVar::set_color(const char* value,
    size_t size) {
  
  color_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:map_pb.ColorVar.color)
}
inline std::string* ColorVar::_internal_mutable_color() {
  
  return color_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ColorVar::release_color() {
  // @@protoc_insertion_point(field_release:map_pb.ColorVar.color)
  return color_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ColorVar::set_allocated_color(std::string* color) {
  if (color != nullptr) {
    
  } else {
    
  }
  color_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), color,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:map_pb.ColorVar.color)
}
inline std::string* ColorVar::unsafe_arena_release_color() {
  // @@protoc_insertion_point(field_unsafe_arena_release:map_pb.ColorVar.color)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return color_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void ColorVar::unsafe_arena_set_allocated_color(
    std::string* color) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (color != nullptr) {
    
  } else {
    
  }
  color_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      color, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:map_pb.ColorVar.color)
}

// .map_pb.RGB rgb = 2;
inline bool ColorVar::_internal_has_rgb() const {
  return this != internal_default_instance() && rgb_ != nullptr;
}
inline bool ColorVar::has_rgb() const {
  return _internal_has_rgb();
}
inline void ColorVar::clear_rgb() {
  if (GetArena() == nullptr && rgb_ != nullptr) {
    delete rgb_;
  }
  rgb_ = nullptr;
}
inline const ::map_pb::RGB& ColorVar::_internal_rgb() const {
  const ::map_pb::RGB* p = rgb_;
  return p != nullptr ? *p : *reinterpret_cast<const ::map_pb::RGB*>(
      &::map_pb::_RGB_default_instance_);
}
inline const ::map_pb::RGB& ColorVar::rgb() const {
  // @@protoc_insertion_point(field_get:map_pb.ColorVar.rgb)
  return _internal_rgb();
}
inline void ColorVar::unsafe_arena_set_allocated_rgb(
    ::map_pb::RGB* rgb) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(rgb_);
  }
  rgb_ = rgb;
  if (rgb) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:map_pb.ColorVar.rgb)
}
inline ::map_pb::RGB* ColorVar::release_rgb() {
  auto temp = unsafe_arena_release_rgb();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::map_pb::RGB* ColorVar::unsafe_arena_release_rgb() {
  // @@protoc_insertion_point(field_release:map_pb.ColorVar.rgb)
  
  ::map_pb::RGB* temp = rgb_;
  rgb_ = nullptr;
  return temp;
}
inline ::map_pb::RGB* ColorVar::_internal_mutable_rgb() {
  
  if (rgb_ == nullptr) {
    auto* p = CreateMaybeMessage<::map_pb::RGB>(GetArena());
    rgb_ = p;
  }
  return rgb_;
}
inline ::map_pb::RGB* ColorVar::mutable_rgb() {
  // @@protoc_insertion_point(field_mutable:map_pb.ColorVar.rgb)
  return _internal_mutable_rgb();
}
inline void ColorVar::set_allocated_rgb(::map_pb::RGB* rgb) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete rgb_;
  }
  if (rgb) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(rgb);
    if (message_arena != submessage_arena) {
      rgb = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, rgb, submessage_arena);
    }
    
  } else {
    
  }
  rgb_ = rgb;
  // @@protoc_insertion_point(field_set_allocated:map_pb.ColorVar.rgb)
}

// .map_pb.RGBO rgbo = 3;
inline bool ColorVar::_internal_has_rgbo() const {
  return this != internal_default_instance() && rgbo_ != nullptr;
}
inline bool ColorVar::has_rgbo() const {
  return _internal_has_rgbo();
}
inline void ColorVar::clear_rgbo() {
  if (GetArena() == nullptr && rgbo_ != nullptr) {
    delete rgbo_;
  }
  rgbo_ = nullptr;
}
inline const ::map_pb::RGBO& ColorVar::_internal_rgbo() const {
  const ::map_pb::RGBO* p = rgbo_;
  return p != nullptr ? *p : *reinterpret_cast<const ::map_pb::RGBO*>(
      &::map_pb::_RGBO_default_instance_);
}
inline const ::map_pb::RGBO& ColorVar::rgbo() const {
  // @@protoc_insertion_point(field_get:map_pb.ColorVar.rgbo)
  return _internal_rgbo();
}
inline void ColorVar::unsafe_arena_set_allocated_rgbo(
    ::map_pb::RGBO* rgbo) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(rgbo_);
  }
  rgbo_ = rgbo;
  if (rgbo) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:map_pb.ColorVar.rgbo)
}
inline ::map_pb::RGBO* ColorVar::release_rgbo() {
  auto temp = unsafe_arena_release_rgbo();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::map_pb::RGBO* ColorVar::unsafe_arena_release_rgbo() {
  // @@protoc_insertion_point(field_release:map_pb.ColorVar.rgbo)
  
  ::map_pb::RGBO* temp = rgbo_;
  rgbo_ = nullptr;
  return temp;
}
inline ::map_pb::RGBO* ColorVar::_internal_mutable_rgbo() {
  
  if (rgbo_ == nullptr) {
    auto* p = CreateMaybeMessage<::map_pb::RGBO>(GetArena());
    rgbo_ = p;
  }
  return rgbo_;
}
inline ::map_pb::RGBO* ColorVar::mutable_rgbo() {
  // @@protoc_insertion_point(field_mutable:map_pb.ColorVar.rgbo)
  return _internal_mutable_rgbo();
}
inline void ColorVar::set_allocated_rgbo(::map_pb::RGBO* rgbo) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete rgbo_;
  }
  if (rgbo) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(rgbo);
    if (message_arena != submessage_arena) {
      rgbo = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, rgbo, submessage_arena);
    }
    
  } else {
    
  }
  rgbo_ = rgbo;
  // @@protoc_insertion_point(field_set_allocated:map_pb.ColorVar.rgbo)
}

// -------------------------------------------------------------------

// Point

// double x = 1;
inline void Point::clear_x() {
  x_ = 0;
}
inline double Point::_internal_x() const {
  return x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:map_pb.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:map_pb.Point.x)
}

// double y = 2;
inline void Point::clear_y() {
  y_ = 0;
}
inline double Point::_internal_y() const {
  return y_;
}
inline double Point::y() const {
  // @@protoc_insertion_point(field_get:map_pb.Point.y)
  return _internal_y();
}
inline void Point::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Point::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:map_pb.Point.y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace map_pb

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
