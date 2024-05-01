#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <variant>

// external (out of transport catalogue) json library - implementation

namespace ext_libs {
namespace json {

class Node;

using Dict = std::map<std::string, Node>;
using Array = std::vector<Node>;

class ParsingError : public std::runtime_error {
  public:
  using runtime_error::runtime_error;
};

class Node : private std::variant
    <std::nullptr_t, std::string, int, size_t, double, bool, Array, Dict> {
  public:

  using variant::variant;
  using Value = variant;

  bool IsNull() const;

  bool IsString() const;

  bool IsInt() const;

  bool IsBool() const;

  bool IsArray() const;

  bool IsMap() const;

  bool IsDouble() const;

  bool IsPureDouble() const;

  const std::string& AsString() const;

  int AsInt() const;

  bool AsBool() const;

  const Array& AsArray() const;

  const Dict& AsMap() const;

  double AsDouble() const;

  const Value& GetValue() const;

  Value& GetValue();

  bool operator==(const Node& rhs) const;

  private:
  Value value_;
};

  bool operator!=(const Node & lhs, const Node & rhs);

class Document {
  public:
  explicit Document(Node root);
  const Node& GetRoot() const;

  private:
  Node root_;
};

  bool operator==(const Document& lhs, const Document& rhs);

  bool operator!=(const Document& lhs, const Document& rhs);

  Document Parse(std::istream& input);

  Node ParseNode(std::istream& input);

  Node ParseNumber(std::istream& input);

  Node ParseNull(std::istream& input);

  Node ParseBool(std::istream& input);

  Node ParseArray(std::istream& input);

  Node ParseDict(std::istream& input);

  Node ParseNode(std::istream& input);

  std::string ParseString(std::istream& input);

  std::string ParseLiteral(std::istream& input);

struct OutputContext {
  std::ostream& out;
  int indent_step = 4;
  int indent = 0;

  void OutputIndent() const {
    for (int i = 0; i < indent; ++i) { out.put(' '); }
  }

  OutputContext Indented() const {
    return { out, indent_step, indent_step + indent };
  }
};

template <typename Value>
void OutputValue(const Value& value, const OutputContext& ctx) {
  ctx.out << value;
}

void OutputValue(std::nullptr_t value, const OutputContext& ctx);

void OutputValue(std::string value, const OutputContext& ctx);

void OutputValue(bool value, const OutputContext& ctx);

void OutputValue(Array value, const OutputContext& ctx);

void OutputValue(Dict value, const OutputContext& ctx);

void OutputNode(const Node& value, const OutputContext& ctx);

void Output(const Document& doc, std::ostream& output);

} // namespace json - end
} // namespace external_libraries - end
