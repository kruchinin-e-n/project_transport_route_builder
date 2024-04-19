// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graph.proto

#include "graph.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_graph_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Edge_graph_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_graph_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_VertexToEdgeIds_graph_2eproto;
namespace graph_pb {
class EdgeDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Edge> _instance;
} _Edge_default_instance_;
class VertexToEdgeIdsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<VertexToEdgeIds> _instance;
} _VertexToEdgeIds_default_instance_;
class GraphDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Graph> _instance;
} _Graph_default_instance_;
}  // namespace graph_pb
static void InitDefaultsscc_info_Edge_graph_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::graph_pb::_Edge_default_instance_;
    new (ptr) ::graph_pb::Edge();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::graph_pb::Edge::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Edge_graph_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Edge_graph_2eproto}, {}};

static void InitDefaultsscc_info_Graph_graph_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::graph_pb::_Graph_default_instance_;
    new (ptr) ::graph_pb::Graph();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::graph_pb::Graph::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_Graph_graph_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_Graph_graph_2eproto}, {
      &scc_info_Edge_graph_2eproto.base,
      &scc_info_VertexToEdgeIds_graph_2eproto.base,}};

static void InitDefaultsscc_info_VertexToEdgeIds_graph_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::graph_pb::_VertexToEdgeIds_default_instance_;
    new (ptr) ::graph_pb::VertexToEdgeIds();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::graph_pb::VertexToEdgeIds::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_VertexToEdgeIds_graph_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_VertexToEdgeIds_graph_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_graph_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_graph_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_graph_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_graph_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::graph_pb::Edge, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::graph_pb::Edge, from_),
  PROTOBUF_FIELD_OFFSET(::graph_pb::Edge, to_),
  PROTOBUF_FIELD_OFFSET(::graph_pb::Edge, weight_),
  PROTOBUF_FIELD_OFFSET(::graph_pb::Edge, span_count_),
  PROTOBUF_FIELD_OFFSET(::graph_pb::Edge, stop_or_route_name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::graph_pb::VertexToEdgeIds, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::graph_pb::VertexToEdgeIds, edge_ids_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::graph_pb::Graph, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::graph_pb::Graph, edges_),
  PROTOBUF_FIELD_OFFSET(::graph_pb::Graph, vertexes_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::graph_pb::Edge)},
  { 10, -1, sizeof(::graph_pb::VertexToEdgeIds)},
  { 16, -1, sizeof(::graph_pb::Graph)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::graph_pb::_Edge_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::graph_pb::_VertexToEdgeIds_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::graph_pb::_Graph_default_instance_),
};

const char descriptor_table_protodef_graph_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013graph.proto\022\010graph_pb\"`\n\004Edge\022\014\n\004from\030"
  "\001 \001(\005\022\n\n\002to\030\002 \001(\005\022\016\n\006weight\030\003 \001(\001\022\022\n\nspa"
  "n_count\030\004 \001(\005\022\032\n\022stop_or_route_name\030\005 \001("
  "\t\"#\n\017VertexToEdgeIds\022\020\n\010edge_ids\030\001 \003(\005\"S"
  "\n\005Graph\022\035\n\005edges\030\001 \003(\0132\016.graph_pb.Edge\022+"
  "\n\010vertexes\030\002 \003(\0132\031.graph_pb.VertexToEdge"
  "Idsb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_graph_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_graph_2eproto_sccs[3] = {
  &scc_info_Edge_graph_2eproto.base,
  &scc_info_Graph_graph_2eproto.base,
  &scc_info_VertexToEdgeIds_graph_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_graph_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_graph_2eproto = {
  false, false, descriptor_table_protodef_graph_2eproto, "graph.proto", 251,
  &descriptor_table_graph_2eproto_once, descriptor_table_graph_2eproto_sccs, descriptor_table_graph_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_graph_2eproto::offsets,
  file_level_metadata_graph_2eproto, 3, file_level_enum_descriptors_graph_2eproto, file_level_service_descriptors_graph_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_graph_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_graph_2eproto)), true);
namespace graph_pb {

// ===================================================================

void Edge::InitAsDefaultInstance() {
}
class Edge::_Internal {
 public:
};

Edge::Edge(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:graph_pb.Edge)
}
Edge::Edge(const Edge& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  stop_or_route_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_stop_or_route_name().empty()) {
    stop_or_route_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_stop_or_route_name(),
      GetArena());
  }
  ::memcpy(&from_, &from.from_,
    static_cast<size_t>(reinterpret_cast<char*>(&span_count_) -
    reinterpret_cast<char*>(&from_)) + sizeof(span_count_));
  // @@protoc_insertion_point(copy_constructor:graph_pb.Edge)
}

void Edge::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Edge_graph_2eproto.base);
  stop_or_route_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&from_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&span_count_) -
      reinterpret_cast<char*>(&from_)) + sizeof(span_count_));
}

Edge::~Edge() {
  // @@protoc_insertion_point(destructor:graph_pb.Edge)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Edge::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  stop_or_route_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Edge::ArenaDtor(void* object) {
  Edge* _this = reinterpret_cast< Edge* >(object);
  (void)_this;
}
void Edge::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Edge::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Edge& Edge::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Edge_graph_2eproto.base);
  return *internal_default_instance();
}


void Edge::Clear() {
// @@protoc_insertion_point(message_clear_start:graph_pb.Edge)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  stop_or_route_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&from_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&span_count_) -
      reinterpret_cast<char*>(&from_)) + sizeof(span_count_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Edge::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 from = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          from_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 to = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          to_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double weight = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 25)) {
          weight_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // int32 span_count = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          span_count_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string stop_or_route_name = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_stop_or_route_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "graph_pb.Edge.stop_or_route_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Edge::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:graph_pb.Edge)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 from = 1;
  if (this->from() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_from(), target);
  }

  // int32 to = 2;
  if (this->to() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_to(), target);
  }

  // double weight = 3;
  if (!(this->weight() <= 0 && this->weight() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_weight(), target);
  }

  // int32 span_count = 4;
  if (this->span_count() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_span_count(), target);
  }

  // string stop_or_route_name = 5;
  if (this->stop_or_route_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_stop_or_route_name().data(), static_cast<int>(this->_internal_stop_or_route_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "graph_pb.Edge.stop_or_route_name");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_stop_or_route_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:graph_pb.Edge)
  return target;
}

size_t Edge::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:graph_pb.Edge)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string stop_or_route_name = 5;
  if (this->stop_or_route_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_stop_or_route_name());
  }

  // int32 from = 1;
  if (this->from() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_from());
  }

  // int32 to = 2;
  if (this->to() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_to());
  }

  // double weight = 3;
  if (!(this->weight() <= 0 && this->weight() >= 0)) {
    total_size += 1 + 8;
  }

  // int32 span_count = 4;
  if (this->span_count() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_span_count());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Edge::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:graph_pb.Edge)
  GOOGLE_DCHECK_NE(&from, this);
  const Edge* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Edge>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:graph_pb.Edge)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:graph_pb.Edge)
    MergeFrom(*source);
  }
}

void Edge::MergeFrom(const Edge& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:graph_pb.Edge)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.stop_or_route_name().size() > 0) {
    _internal_set_stop_or_route_name(from._internal_stop_or_route_name());
  }
  if (from.from() != 0) {
    _internal_set_from(from._internal_from());
  }
  if (from.to() != 0) {
    _internal_set_to(from._internal_to());
  }
  if (!(from.weight() <= 0 && from.weight() >= 0)) {
    _internal_set_weight(from._internal_weight());
  }
  if (from.span_count() != 0) {
    _internal_set_span_count(from._internal_span_count());
  }
}

void Edge::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:graph_pb.Edge)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Edge::CopyFrom(const Edge& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:graph_pb.Edge)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Edge::IsInitialized() const {
  return true;
}

void Edge::InternalSwap(Edge* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  stop_or_route_name_.Swap(&other->stop_or_route_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Edge, span_count_)
      + sizeof(Edge::span_count_)
      - PROTOBUF_FIELD_OFFSET(Edge, from_)>(
          reinterpret_cast<char*>(&from_),
          reinterpret_cast<char*>(&other->from_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Edge::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void VertexToEdgeIds::InitAsDefaultInstance() {
}
class VertexToEdgeIds::_Internal {
 public:
};

VertexToEdgeIds::VertexToEdgeIds(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  edge_ids_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:graph_pb.VertexToEdgeIds)
}
VertexToEdgeIds::VertexToEdgeIds(const VertexToEdgeIds& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      edge_ids_(from.edge_ids_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:graph_pb.VertexToEdgeIds)
}

void VertexToEdgeIds::SharedCtor() {
}

VertexToEdgeIds::~VertexToEdgeIds() {
  // @@protoc_insertion_point(destructor:graph_pb.VertexToEdgeIds)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void VertexToEdgeIds::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void VertexToEdgeIds::ArenaDtor(void* object) {
  VertexToEdgeIds* _this = reinterpret_cast< VertexToEdgeIds* >(object);
  (void)_this;
}
void VertexToEdgeIds::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void VertexToEdgeIds::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const VertexToEdgeIds& VertexToEdgeIds::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_VertexToEdgeIds_graph_2eproto.base);
  return *internal_default_instance();
}


void VertexToEdgeIds::Clear() {
// @@protoc_insertion_point(message_clear_start:graph_pb.VertexToEdgeIds)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  edge_ids_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* VertexToEdgeIds::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated int32 edge_ids = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_edge_ids(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8) {
          _internal_add_edge_ids(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* VertexToEdgeIds::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:graph_pb.VertexToEdgeIds)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int32 edge_ids = 1;
  {
    int byte_size = _edge_ids_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          1, _internal_edge_ids(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:graph_pb.VertexToEdgeIds)
  return target;
}

size_t VertexToEdgeIds::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:graph_pb.VertexToEdgeIds)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 edge_ids = 1;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->edge_ids_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _edge_ids_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void VertexToEdgeIds::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:graph_pb.VertexToEdgeIds)
  GOOGLE_DCHECK_NE(&from, this);
  const VertexToEdgeIds* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<VertexToEdgeIds>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:graph_pb.VertexToEdgeIds)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:graph_pb.VertexToEdgeIds)
    MergeFrom(*source);
  }
}

void VertexToEdgeIds::MergeFrom(const VertexToEdgeIds& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:graph_pb.VertexToEdgeIds)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  edge_ids_.MergeFrom(from.edge_ids_);
}

void VertexToEdgeIds::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:graph_pb.VertexToEdgeIds)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VertexToEdgeIds::CopyFrom(const VertexToEdgeIds& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:graph_pb.VertexToEdgeIds)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VertexToEdgeIds::IsInitialized() const {
  return true;
}

void VertexToEdgeIds::InternalSwap(VertexToEdgeIds* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  edge_ids_.InternalSwap(&other->edge_ids_);
}

::PROTOBUF_NAMESPACE_ID::Metadata VertexToEdgeIds::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Graph::InitAsDefaultInstance() {
}
class Graph::_Internal {
 public:
};

Graph::Graph(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  edges_(arena),
  vertexes_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:graph_pb.Graph)
}
Graph::Graph(const Graph& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      edges_(from.edges_),
      vertexes_(from.vertexes_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:graph_pb.Graph)
}

void Graph::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Graph_graph_2eproto.base);
}

Graph::~Graph() {
  // @@protoc_insertion_point(destructor:graph_pb.Graph)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Graph::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Graph::ArenaDtor(void* object) {
  Graph* _this = reinterpret_cast< Graph* >(object);
  (void)_this;
}
void Graph::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Graph::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Graph& Graph::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Graph_graph_2eproto.base);
  return *internal_default_instance();
}


void Graph::Clear() {
// @@protoc_insertion_point(message_clear_start:graph_pb.Graph)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  edges_.Clear();
  vertexes_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Graph::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .graph_pb.Edge edges = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_edges(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .graph_pb.VertexToEdgeIds vertexes = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_vertexes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Graph::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:graph_pb.Graph)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .graph_pb.Edge edges = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_edges_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_edges(i), target, stream);
  }

  // repeated .graph_pb.VertexToEdgeIds vertexes = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_vertexes_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_vertexes(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:graph_pb.Graph)
  return target;
}

size_t Graph::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:graph_pb.Graph)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .graph_pb.Edge edges = 1;
  total_size += 1UL * this->_internal_edges_size();
  for (const auto& msg : this->edges_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .graph_pb.VertexToEdgeIds vertexes = 2;
  total_size += 1UL * this->_internal_vertexes_size();
  for (const auto& msg : this->vertexes_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Graph::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:graph_pb.Graph)
  GOOGLE_DCHECK_NE(&from, this);
  const Graph* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Graph>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:graph_pb.Graph)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:graph_pb.Graph)
    MergeFrom(*source);
  }
}

void Graph::MergeFrom(const Graph& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:graph_pb.Graph)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  edges_.MergeFrom(from.edges_);
  vertexes_.MergeFrom(from.vertexes_);
}

void Graph::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:graph_pb.Graph)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Graph::CopyFrom(const Graph& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:graph_pb.Graph)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Graph::IsInitialized() const {
  return true;
}

void Graph::InternalSwap(Graph* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  edges_.InternalSwap(&other->edges_);
  vertexes_.InternalSwap(&other->vertexes_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Graph::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace graph_pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::graph_pb::Edge* Arena::CreateMaybeMessage< ::graph_pb::Edge >(Arena* arena) {
  return Arena::CreateMessageInternal< ::graph_pb::Edge >(arena);
}
template<> PROTOBUF_NOINLINE ::graph_pb::VertexToEdgeIds* Arena::CreateMaybeMessage< ::graph_pb::VertexToEdgeIds >(Arena* arena) {
  return Arena::CreateMessageInternal< ::graph_pb::VertexToEdgeIds >(arena);
}
template<> PROTOBUF_NOINLINE ::graph_pb::Graph* Arena::CreateMaybeMessage< ::graph_pb::Graph >(Arena* arena) {
  return Arena::CreateMessageInternal< ::graph_pb::Graph >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>