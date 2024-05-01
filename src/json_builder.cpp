#include "json_builder.h"

// json builder - implementation

namespace transport_catalogue {

namespace infrastructure {

// --- Class Builder ---

Builder::Builder() {
  Node* root_ptr = &root_;
  nodes_.emplace_back(root_ptr);
}

DicValCtx Builder::StartDict() {
  // get parent node
  auto* parent_node = nodes_.back();

  if (parent_node->IsMap()) {
    // check key
    if (!aux_key_) {
      throw std::logic_error("Error: nested dictionary without key");
    }
    // get parent node as dictionary
    auto& dict = std::get<Dict>(parent_node->GetValue());
    // receive arguments
    auto [it, bool_] = dict.emplace(std::move(aux_key_.value()), Dict());
    // reset aux_key_
    aux_key_ = std::nullopt;
    // update parent node
    nodes_.emplace_back(&it->second);
  } else if (parent_node->IsArray()) {
    // get parent node as array
    auto& array = std::get<Array>(parent_node->GetValue());
    // add dictionary to array
    array.emplace_back(Dict());
    // update parent node
    nodes_.emplace_back(&array.back());
  } else if (parent_node->IsNull()) {
    parent_node->GetValue() = Dict();
  } else {
    throw std::logic_error("Error: wrong parent node");
  }

  return *this;
}

Builder& Builder::EndDict() {
  // get parent node
  auto* parent_node = nodes_.back();

  // check parent node is dictionary
  if (!parent_node->IsMap()) {
    throw std::logic_error("Error: parent node is not a dictionary");
  }
  // update nodes stack closing dictionary
  nodes_.pop_back();

  return *this;
}

ArrValCtx Builder::StartArray() {
  // get parent node
  auto* parent_node = nodes_.back();

  if (parent_node->IsMap()) {
    // check key
    if (!aux_key_) {
      throw std::logic_error("Error: nested array without key");
    }
    // get parent node as dictionary
    auto& dict = std::get<Dict>(parent_node->GetValue());
    // receive arguments
    auto [it, bool_] = dict.emplace(std::move(aux_key_.value()), Array());
    // reset aux_key_
    aux_key_ = std::nullopt;
    // update parent node
    nodes_.emplace_back(&it->second);
  } else if (parent_node->IsArray()) {
      // get parent node as array
      auto& array = std::get<Array>(parent_node->GetValue());
      // add array to array
      array.emplace_back(Array());
      // update parent node
      nodes_.emplace_back(&array.back());
  } else if (parent_node->IsNull()) {
      parent_node->GetValue() = Array();
  } else {
      throw std::logic_error("Error: wrong parent node");
  }

  return *this;
}

Builder& Builder::EndArray() {
  // get parent node
  auto* parent_node = nodes_.back();

  if (!parent_node->IsArray()) {
    throw std::logic_error("Error: parent node is not an Array");
  }
  // update nodes stack closing array
  nodes_.pop_back();
  return *this;
}

Builder& Builder::Value(Node::Value value) {
  // get parent node
  auto* parent_node = nodes_.back();

  if (parent_node->IsMap()) {
    // check key
    if (!aux_key_) { throw std::logic_error("Error: value without key"); }
    // get parent node as dictionary
    auto& dict = std::get<Dict>(parent_node->GetValue());
    // receive arguments
    auto [it, bool_] = dict.emplace(std::move(aux_key_.value()), Node{ });
    // reset aux_key_
    aux_key_ = std::nullopt;
    // update parent node
    parent_node = &it->second;
    // value for parent node
    parent_node->GetValue() = std::move(value);

  } else if (parent_node->IsArray()) {
    // get parent node as array
    auto& array = std::get<Array>(parent_node->GetValue());
    // add value to array
    array.emplace_back(GetTypeOfNode(value));
    // update parent node
    parent_node = &array.back();

  } else if (root_.IsNull()) {
    root_.GetValue() = std::move(value);

  } else {
    throw std::logic_error("Error: wrong parent node");
  }

  return *this;
}

DicKeyCtx Builder::Key(std::string key) {
  // get parent node
  auto* parent_node = nodes_.back();

  // check parent node is dictionary
  parent_node->IsMap() && !aux_key_
  ? aux_key_ = std::move(key)
  : throw std::logic_error("Error: wrong key");

  // return key
  return *this;
}

Node Builder::Build() {
  if (root_.IsNull() || nodes_.size() > 1) {
    throw std::logic_error("Error: wrong object building");
  }
  return root_;
}

Node Builder::GetTypeOfNode(Node::Value value) {
  if (std::holds_alternative<std::nullptr_t>(value)) {
    return Node(std::get <std::nullptr_t>(value));
  }

  if (std::holds_alternative<std::string>(value)) {
    return Node(std::get<std::string>(value));
  }

  if (std::holds_alternative<int>(value)) {
    return Node(std::get<int>(value));
  }

  if (std::holds_alternative<double>(value)) {
    return Node(std::get<double>(value));
  }

  if (std::holds_alternative<bool>(value)) {
    return Node(std::get<bool>(value));
  }

  if (std::holds_alternative<Dict>(value)) {
    return Node(std::get<Dict>(value));
  }

  if (std::holds_alternative<Array>(value)) {
    return Node(std::get<Array>(value));
  }

  return {};
}

    // --- Class DicValCtx ---

DicValCtx::DicValCtx (Builder& builder) : builder_(builder) {}

DicKeyCtx DicValCtx::Key(std::string key) { return builder_.Key(key); }

Builder&  DicValCtx::EndDict() { return builder_.EndDict(); }

    // --- Class ArrValCtx ---

ArrValCtx::ArrValCtx(Builder& builder ) : builder_(builder) {}

ArrValCtx ArrValCtx::Value(Node::Value value) {
  return ArrValCtx(builder_.Value(value));
}

DicValCtx ArrValCtx::StartDict() {
  return builder_.StartDict();
}

ArrValCtx ArrValCtx::StartArray() {
  return builder_.StartArray();
}

Builder&  ArrValCtx::EndArray() {
  return builder_.EndArray();
}

    // --- Class DicKeyCtx ---

DicKeyCtx::DicKeyCtx(Builder& builder ) : builder_(builder) {}

DicValCtx DicKeyCtx::Value(Node::Value value) {
  return DicValCtx(builder_.Value(value));
}

ArrValCtx DicKeyCtx::StartArray() { return builder_.StartArray(); }

DicValCtx DicKeyCtx::StartDict() { return builder_.StartDict(); }

} // namespace infrastructure - end
} // namespace json - end
