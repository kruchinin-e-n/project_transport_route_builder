// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graph.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_graph_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_graph_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_graph_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_graph_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_graph_2eproto;
namespace graph_pb {
class Edge;
class EdgeDefaultTypeInternal;
extern EdgeDefaultTypeInternal _Edge_default_instance_;
class Graph;
class GraphDefaultTypeInternal;
extern GraphDefaultTypeInternal _Graph_default_instance_;
class VertexToEdgeIds;
class VertexToEdgeIdsDefaultTypeInternal;
extern VertexToEdgeIdsDefaultTypeInternal _VertexToEdgeIds_default_instance_;
}  // namespace graph_pb
PROTOBUF_NAMESPACE_OPEN
template<> ::graph_pb::Edge* Arena::CreateMaybeMessage<::graph_pb::Edge>(Arena*);
template<> ::graph_pb::Graph* Arena::CreateMaybeMessage<::graph_pb::Graph>(Arena*);
template<> ::graph_pb::VertexToEdgeIds* Arena::CreateMaybeMessage<::graph_pb::VertexToEdgeIds>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace graph_pb {

// ===================================================================

class Edge PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:graph_pb.Edge) */ {
 public:
  inline Edge() : Edge(nullptr) {};
  virtual ~Edge();

  Edge(const Edge& from);
  Edge(Edge&& from) noexcept
    : Edge() {
    *this = ::std::move(from);
  }

  inline Edge& operator=(const Edge& from) {
    CopyFrom(from);
    return *this;
  }
  inline Edge& operator=(Edge&& from) noexcept {
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
  static const Edge& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Edge* internal_default_instance() {
    return reinterpret_cast<const Edge*>(
               &_Edge_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Edge& a, Edge& b) {
    a.Swap(&b);
  }
  inline void Swap(Edge* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Edge* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Edge* New() const final {
    return CreateMaybeMessage<Edge>(nullptr);
  }

  Edge* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Edge>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Edge& from);
  void MergeFrom(const Edge& from);
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
  void InternalSwap(Edge* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "graph_pb.Edge";
  }
  protected:
  explicit Edge(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_graph_2eproto);
    return ::descriptor_table_graph_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStopOrRouteNameFieldNumber = 5,
    kFromFieldNumber = 1,
    kToFieldNumber = 2,
    kWeightFieldNumber = 3,
    kSpanCountFieldNumber = 4,
  };
  // string stop_or_route_name = 5;
  void clear_stop_or_route_name();
  const std::string& stop_or_route_name() const;
  void set_stop_or_route_name(const std::string& value);
  void set_stop_or_route_name(std::string&& value);
  void set_stop_or_route_name(const char* value);
  void set_stop_or_route_name(const char* value, size_t size);
  std::string* mutable_stop_or_route_name();
  std::string* release_stop_or_route_name();
  void set_allocated_stop_or_route_name(std::string* stop_or_route_name);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_stop_or_route_name();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_stop_or_route_name(
      std::string* stop_or_route_name);
  private:
  const std::string& _internal_stop_or_route_name() const;
  void _internal_set_stop_or_route_name(const std::string& value);
  std::string* _internal_mutable_stop_or_route_name();
  public:

  // int32 from = 1;
  void clear_from();
  ::PROTOBUF_NAMESPACE_ID::int32 from() const;
  void set_from(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_from() const;
  void _internal_set_from(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 to = 2;
  void clear_to();
  ::PROTOBUF_NAMESPACE_ID::int32 to() const;
  void set_to(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_to() const;
  void _internal_set_to(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // double weight = 3;
  void clear_weight();
  double weight() const;
  void set_weight(double value);
  private:
  double _internal_weight() const;
  void _internal_set_weight(double value);
  public:

  // int32 span_count = 4;
  void clear_span_count();
  ::PROTOBUF_NAMESPACE_ID::int32 span_count() const;
  void set_span_count(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_span_count() const;
  void _internal_set_span_count(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:graph_pb.Edge)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr stop_or_route_name_;
  ::PROTOBUF_NAMESPACE_ID::int32 from_;
  ::PROTOBUF_NAMESPACE_ID::int32 to_;
  double weight_;
  ::PROTOBUF_NAMESPACE_ID::int32 span_count_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// -------------------------------------------------------------------

class VertexToEdgeIds PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:graph_pb.VertexToEdgeIds) */ {
 public:
  inline VertexToEdgeIds() : VertexToEdgeIds(nullptr) {};
  virtual ~VertexToEdgeIds();

  VertexToEdgeIds(const VertexToEdgeIds& from);
  VertexToEdgeIds(VertexToEdgeIds&& from) noexcept
    : VertexToEdgeIds() {
    *this = ::std::move(from);
  }

  inline VertexToEdgeIds& operator=(const VertexToEdgeIds& from) {
    CopyFrom(from);
    return *this;
  }
  inline VertexToEdgeIds& operator=(VertexToEdgeIds&& from) noexcept {
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
  static const VertexToEdgeIds& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VertexToEdgeIds* internal_default_instance() {
    return reinterpret_cast<const VertexToEdgeIds*>(
               &_VertexToEdgeIds_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(VertexToEdgeIds& a, VertexToEdgeIds& b) {
    a.Swap(&b);
  }
  inline void Swap(VertexToEdgeIds* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(VertexToEdgeIds* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline VertexToEdgeIds* New() const final {
    return CreateMaybeMessage<VertexToEdgeIds>(nullptr);
  }

  VertexToEdgeIds* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<VertexToEdgeIds>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const VertexToEdgeIds& from);
  void MergeFrom(const VertexToEdgeIds& from);
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
  void InternalSwap(VertexToEdgeIds* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "graph_pb.VertexToEdgeIds";
  }
  protected:
  explicit VertexToEdgeIds(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_graph_2eproto);
    return ::descriptor_table_graph_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEdgeIdsFieldNumber = 1,
  };
  // repeated int32 edge_ids = 1;
  int edge_ids_size() const;
  private:
  int _internal_edge_ids_size() const;
  public:
  void clear_edge_ids();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_edge_ids(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_edge_ids() const;
  void _internal_add_edge_ids(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_edge_ids();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 edge_ids(int index) const;
  void set_edge_ids(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_edge_ids(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      edge_ids() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_edge_ids();

  // @@protoc_insertion_point(class_scope:graph_pb.VertexToEdgeIds)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > edge_ids_;
  mutable std::atomic<int> _edge_ids_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// -------------------------------------------------------------------

class Graph PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:graph_pb.Graph) */ {
 public:
  inline Graph() : Graph(nullptr) {};
  virtual ~Graph();

  Graph(const Graph& from);
  Graph(Graph&& from) noexcept
    : Graph() {
    *this = ::std::move(from);
  }

  inline Graph& operator=(const Graph& from) {
    CopyFrom(from);
    return *this;
  }
  inline Graph& operator=(Graph&& from) noexcept {
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
  static const Graph& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Graph* internal_default_instance() {
    return reinterpret_cast<const Graph*>(
               &_Graph_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Graph& a, Graph& b) {
    a.Swap(&b);
  }
  inline void Swap(Graph* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Graph* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Graph* New() const final {
    return CreateMaybeMessage<Graph>(nullptr);
  }

  Graph* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Graph>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Graph& from);
  void MergeFrom(const Graph& from);
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
  void InternalSwap(Graph* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "graph_pb.Graph";
  }
  protected:
  explicit Graph(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_graph_2eproto);
    return ::descriptor_table_graph_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEdgesFieldNumber = 1,
    kVertexesFieldNumber = 2,
  };
  // repeated .graph_pb.Edge edges = 1;
  int edges_size() const;
  private:
  int _internal_edges_size() const;
  public:
  void clear_edges();
  ::graph_pb::Edge* mutable_edges(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::Edge >*
      mutable_edges();
  private:
  const ::graph_pb::Edge& _internal_edges(int index) const;
  ::graph_pb::Edge* _internal_add_edges();
  public:
  const ::graph_pb::Edge& edges(int index) const;
  ::graph_pb::Edge* add_edges();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::Edge >&
      edges() const;

  // repeated .graph_pb.VertexToEdgeIds vertexes = 2;
  int vertexes_size() const;
  private:
  int _internal_vertexes_size() const;
  public:
  void clear_vertexes();
  ::graph_pb::VertexToEdgeIds* mutable_vertexes(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::VertexToEdgeIds >*
      mutable_vertexes();
  private:
  const ::graph_pb::VertexToEdgeIds& _internal_vertexes(int index) const;
  ::graph_pb::VertexToEdgeIds* _internal_add_vertexes();
  public:
  const ::graph_pb::VertexToEdgeIds& vertexes(int index) const;
  ::graph_pb::VertexToEdgeIds* add_vertexes();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::VertexToEdgeIds >&
      vertexes() const;

  // @@protoc_insertion_point(class_scope:graph_pb.Graph)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::Edge > edges_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::VertexToEdgeIds > vertexes_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_graph_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Edge

// int32 from = 1;
inline void Edge::clear_from() {
  from_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Edge::_internal_from() const {
  return from_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Edge::from() const {
  // @@protoc_insertion_point(field_get:graph_pb.Edge.from)
  return _internal_from();
}
inline void Edge::_internal_set_from(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  from_ = value;
}
inline void Edge::set_from(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_from(value);
  // @@protoc_insertion_point(field_set:graph_pb.Edge.from)
}

// int32 to = 2;
inline void Edge::clear_to() {
  to_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Edge::_internal_to() const {
  return to_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Edge::to() const {
  // @@protoc_insertion_point(field_get:graph_pb.Edge.to)
  return _internal_to();
}
inline void Edge::_internal_set_to(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  to_ = value;
}
inline void Edge::set_to(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_to(value);
  // @@protoc_insertion_point(field_set:graph_pb.Edge.to)
}

// double weight = 3;
inline void Edge::clear_weight() {
  weight_ = 0;
}
inline double Edge::_internal_weight() const {
  return weight_;
}
inline double Edge::weight() const {
  // @@protoc_insertion_point(field_get:graph_pb.Edge.weight)
  return _internal_weight();
}
inline void Edge::_internal_set_weight(double value) {
  
  weight_ = value;
}
inline void Edge::set_weight(double value) {
  _internal_set_weight(value);
  // @@protoc_insertion_point(field_set:graph_pb.Edge.weight)
}

// int32 span_count = 4;
inline void Edge::clear_span_count() {
  span_count_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Edge::_internal_span_count() const {
  return span_count_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Edge::span_count() const {
  // @@protoc_insertion_point(field_get:graph_pb.Edge.span_count)
  return _internal_span_count();
}
inline void Edge::_internal_set_span_count(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  span_count_ = value;
}
inline void Edge::set_span_count(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_span_count(value);
  // @@protoc_insertion_point(field_set:graph_pb.Edge.span_count)
}

// string stop_or_route_name = 5;
inline void Edge::clear_stop_or_route_name() {
  stop_or_route_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Edge::stop_or_route_name() const {
  // @@protoc_insertion_point(field_get:graph_pb.Edge.stop_or_route_name)
  return _internal_stop_or_route_name();
}
inline void Edge::set_stop_or_route_name(const std::string& value) {
  _internal_set_stop_or_route_name(value);
  // @@protoc_insertion_point(field_set:graph_pb.Edge.stop_or_route_name)
}
inline std::string* Edge::mutable_stop_or_route_name() {
  // @@protoc_insertion_point(field_mutable:graph_pb.Edge.stop_or_route_name)
  return _internal_mutable_stop_or_route_name();
}
inline const std::string& Edge::_internal_stop_or_route_name() const {
  return stop_or_route_name_.Get();
}
inline void Edge::_internal_set_stop_or_route_name(const std::string& value) {
  
  stop_or_route_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Edge::set_stop_or_route_name(std::string&& value) {
  
  stop_or_route_name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:graph_pb.Edge.stop_or_route_name)
}
inline void Edge::set_stop_or_route_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  stop_or_route_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:graph_pb.Edge.stop_or_route_name)
}
inline void Edge::set_stop_or_route_name(const char* value,
    size_t size) {
  
  stop_or_route_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:graph_pb.Edge.stop_or_route_name)
}
inline std::string* Edge::_internal_mutable_stop_or_route_name() {
  
  return stop_or_route_name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Edge::release_stop_or_route_name() {
  // @@protoc_insertion_point(field_release:graph_pb.Edge.stop_or_route_name)
  return stop_or_route_name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Edge::set_allocated_stop_or_route_name(std::string* stop_or_route_name) {
  if (stop_or_route_name != nullptr) {
    
  } else {
    
  }
  stop_or_route_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), stop_or_route_name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:graph_pb.Edge.stop_or_route_name)
}
inline std::string* Edge::unsafe_arena_release_stop_or_route_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:graph_pb.Edge.stop_or_route_name)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return stop_or_route_name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void Edge::unsafe_arena_set_allocated_stop_or_route_name(
    std::string* stop_or_route_name) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (stop_or_route_name != nullptr) {
    
  } else {
    
  }
  stop_or_route_name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      stop_or_route_name, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:graph_pb.Edge.stop_or_route_name)
}

// -------------------------------------------------------------------

// VertexToEdgeIds

// repeated int32 edge_ids = 1;
inline int VertexToEdgeIds::_internal_edge_ids_size() const {
  return edge_ids_.size();
}
inline int VertexToEdgeIds::edge_ids_size() const {
  return _internal_edge_ids_size();
}
inline void VertexToEdgeIds::clear_edge_ids() {
  edge_ids_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 VertexToEdgeIds::_internal_edge_ids(int index) const {
  return edge_ids_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 VertexToEdgeIds::edge_ids(int index) const {
  // @@protoc_insertion_point(field_get:graph_pb.VertexToEdgeIds.edge_ids)
  return _internal_edge_ids(index);
}
inline void VertexToEdgeIds::set_edge_ids(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  edge_ids_.Set(index, value);
  // @@protoc_insertion_point(field_set:graph_pb.VertexToEdgeIds.edge_ids)
}
inline void VertexToEdgeIds::_internal_add_edge_ids(::PROTOBUF_NAMESPACE_ID::int32 value) {
  edge_ids_.Add(value);
}
inline void VertexToEdgeIds::add_edge_ids(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_edge_ids(value);
  // @@protoc_insertion_point(field_add:graph_pb.VertexToEdgeIds.edge_ids)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
VertexToEdgeIds::_internal_edge_ids() const {
  return edge_ids_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
VertexToEdgeIds::edge_ids() const {
  // @@protoc_insertion_point(field_list:graph_pb.VertexToEdgeIds.edge_ids)
  return _internal_edge_ids();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
VertexToEdgeIds::_internal_mutable_edge_ids() {
  return &edge_ids_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
VertexToEdgeIds::mutable_edge_ids() {
  // @@protoc_insertion_point(field_mutable_list:graph_pb.VertexToEdgeIds.edge_ids)
  return _internal_mutable_edge_ids();
}

// -------------------------------------------------------------------

// Graph

// repeated .graph_pb.Edge edges = 1;
inline int Graph::_internal_edges_size() const {
  return edges_.size();
}
inline int Graph::edges_size() const {
  return _internal_edges_size();
}
inline void Graph::clear_edges() {
  edges_.Clear();
}
inline ::graph_pb::Edge* Graph::mutable_edges(int index) {
  // @@protoc_insertion_point(field_mutable:graph_pb.Graph.edges)
  return edges_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::Edge >*
Graph::mutable_edges() {
  // @@protoc_insertion_point(field_mutable_list:graph_pb.Graph.edges)
  return &edges_;
}
inline const ::graph_pb::Edge& Graph::_internal_edges(int index) const {
  return edges_.Get(index);
}
inline const ::graph_pb::Edge& Graph::edges(int index) const {
  // @@protoc_insertion_point(field_get:graph_pb.Graph.edges)
  return _internal_edges(index);
}
inline ::graph_pb::Edge* Graph::_internal_add_edges() {
  return edges_.Add();
}
inline ::graph_pb::Edge* Graph::add_edges() {
  // @@protoc_insertion_point(field_add:graph_pb.Graph.edges)
  return _internal_add_edges();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::Edge >&
Graph::edges() const {
  // @@protoc_insertion_point(field_list:graph_pb.Graph.edges)
  return edges_;
}

// repeated .graph_pb.VertexToEdgeIds vertexes = 2;
inline int Graph::_internal_vertexes_size() const {
  return vertexes_.size();
}
inline int Graph::vertexes_size() const {
  return _internal_vertexes_size();
}
inline void Graph::clear_vertexes() {
  vertexes_.Clear();
}
inline ::graph_pb::VertexToEdgeIds* Graph::mutable_vertexes(int index) {
  // @@protoc_insertion_point(field_mutable:graph_pb.Graph.vertexes)
  return vertexes_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::VertexToEdgeIds >*
Graph::mutable_vertexes() {
  // @@protoc_insertion_point(field_mutable_list:graph_pb.Graph.vertexes)
  return &vertexes_;
}
inline const ::graph_pb::VertexToEdgeIds& Graph::_internal_vertexes(int index) const {
  return vertexes_.Get(index);
}
inline const ::graph_pb::VertexToEdgeIds& Graph::vertexes(int index) const {
  // @@protoc_insertion_point(field_get:graph_pb.Graph.vertexes)
  return _internal_vertexes(index);
}
inline ::graph_pb::VertexToEdgeIds* Graph::_internal_add_vertexes() {
  return vertexes_.Add();
}
inline ::graph_pb::VertexToEdgeIds* Graph::add_vertexes() {
  // @@protoc_insertion_point(field_add:graph_pb.Graph.vertexes)
  return _internal_add_vertexes();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::graph_pb::VertexToEdgeIds >&
Graph::vertexes() const {
  // @@protoc_insertion_point(field_list:graph_pb.Graph.vertexes)
  return vertexes_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace graph_pb

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_graph_2eproto