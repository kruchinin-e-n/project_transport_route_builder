#include "json.h"

// external (out of transport catalogue) json library - implementation

namespace ext_libs {

namespace json {

using namespace std::literals;

// --- Class Node ---

bool Node::IsNull() const {
  return std::holds_alternative<std::nullptr_t>(*this);
}

bool Node::IsString() const {
  return std::holds_alternative<std::string>(*this);
}

bool Node::IsInt() const {
  return std::holds_alternative<int>(*this);
}

bool Node::IsBool() const {
  return std::holds_alternative<bool>(*this);
}

bool Node::IsArray() const {
  return std::holds_alternative<Array>(*this);
}

bool Node::IsMap() const {
  return std::holds_alternative<Dict>(*this);
}

bool Node::IsPureDouble() const {
  return std::holds_alternative<double>(*this);
}

bool Node::IsDouble() const {
  return IsInt() || IsPureDouble();
}

const std::string& Node::AsString() const {
if (!IsString ()) { throw std::logic_error("Err: Type isnt string"); }
  return std::get<std::string>(*this);
}

int Node::AsInt() const {
  if (!IsInt()) { throw std::logic_error("Err: Type isnt int"); }
  return std::get<int>(*this);
}

bool Node::AsBool() const {
  if (!IsBool()) { throw std::logic_error("Err: Type isnt bool"); }
  return std::get<bool>(*this);
}

const Array& Node::AsArray() const {
  if (!IsArray()) { throw std::logic_error("Err: Type isnt array"); }
  return std::get<Array>(*this);
}

const Dict& Node::AsMap() const {
  if (!IsMap()) { throw std::logic_error("Err: Type isnt map"); }
  return std::get<Dict>(*this);
}

double Node::AsDouble() const {
  if (!IsDouble()) { throw std::logic_error("Err: Type isnt dbl / int"); }
  return IsPureDouble() ? std::get<double>(*this) : AsInt();
}

const Node::Value& Node::GetValue() const {
  return *this;
}

Node::Value& Node::GetValue() {
  return *this;
}

bool Node::operator==(const Node& rhs) const {
  return GetValue() == rhs.GetValue();
}

// --- Class Documemt ---

Document::Document(Node root)
  : root_(std::move(root)) {
}

const Node& Document::GetRoot() const { return root_; }

bool operator==(const Document& lhs, const Document& rhs) {
  return lhs.GetRoot () == rhs.GetRoot ();
}

bool operator!=(const Document& lhs, const Document& rhs) {
  return !(lhs == rhs);
}

// --- Parsing ---

Document Parse (std::istream& input) {
  return Document{ ParseNode(input) };
}

Node ParseNode(std::istream& input) {
  char c;
  input >> c;

  if (c == 'n') {
    input.putback(c);
    return ParseNull(input);

  } else if (c == '"') {
    return ParseString(input);

  } else if (c == 't' || c == 'f') {
    input.putback(c);
    return ParseBool(input);

  } else if (c == '[') {
    return ParseArray(input);

  } else if (c == '{') {
    return ParseDict(input);

  } else {
    input.putback(c);
    return ParseNumber(input);
  }
}

std::string ParseString(std::istream& input) {
  using namespace std::literals;

  auto it  = std::istreambuf_iterator<char>(input);
  auto end = std::istreambuf_iterator<char>();
  std::string result;
  while (true) {
    if (it == end) {
      throw ParsingError("String parsing error");
    }
    const char ch = *it;
    if (ch == '"') {
      ++it;
      break;
    } else if (ch == '\\') {
      ++it;
      if (it == end) { throw ParsingError("String parsing error"); }
      const char escaped_char = *it;
      switch (escaped_char) {
        case 'n' :
          result.push_back('\n');
          break;
        case 't' :
          result.push_back('\t');
          break;
        case 'r' :
          result.push_back('\r');
          break;
        case '"' :
          result.push_back('"');
          break;
        case '\\' :
          result.push_back('\\');
          break;
        default:
          throw ParsingError("Unrecognized escape sequence \\"s + escaped_char);
      }
    } else if (ch == '\n' || ch == '\r') {
      throw ParsingError("Unexpected end of line"s);
    } else {
      result.push_back(ch);
    }
    ++it;
  }
  return result;
}

Node ParseNumber(std::istream& input) {
  using namespace std::literals;
  std::string parsed_num;

  auto read_char =
      [&parsed_num, &input] {
        parsed_num += static_cast<char>(input.get());
        if (!input) {
          throw ParsingError("Failed to read number from stream"s);
        }
      };

  auto read_digits =
      [&input, read_char] {
        if (!std::isdigit(input.peek())) {
          throw ParsingError("A digit is expected"s);
        }
        while (std::isdigit(input.peek())) {
          read_char();
        }
      };

  if (input.peek( ) == '-') { read_char(); }
  input.peek( ) == '0' ? read_char() : read_digits();
  bool is_int = true;
  if (input.peek() == '.') {
    read_char();
    read_digits();
    is_int = false;
  }

  if (int ch = input.peek(); ch == 'e' || ch == 'E') {
    read_char();
    if (ch = input.peek(); ch == '+' || ch == '-') {
      read_char();
    }
    read_digits();
    is_int = false;
  }

  try {
    if (is_int) {
      try {
        return std::stoi(parsed_num);
      } catch (...) {}
    }
    return std::stod(parsed_num);
  } catch (...) {
    throw ParsingError("Failed to convert "s + parsed_num + " to number"s);
  }
}

Node ParseNull(std::istream& input) {
  const std::string null_name = "null";
  for (size_t i = 0; i < null_name.size(); i++) {
    if (null_name.at(i) == input.get()) {
      continue;
    } else { throw ParsingError("Null parsing error"); }
  }
  return {};
}

Node ParseBool(std::istream& input) {
  const std::string name_false = "false";
  const std::string name_true = "true";
  char c = input.get();
  bool value;

  (c == 't') ? value = true : value = false;
  std::string const* bool_name;
  value ? bool_name = &name_true : bool_name = &name_false;
  for (size_t i = 1; i < bool_name->size(); i++) {
    if (bool_name->at(i) == input.get()) {
      continue;
    } else { throw ParsingError("Bool parsing error"); }
  }
  return Node(value);
}

Node ParseArray(std::istream& input) {
  Array result;
  for (char c; input >> c && c != ']';) {
    if (c != ',') { input.putback(c); }
    result.push_back(ParseNode(input));
  }
  return Node(move(result));
}

Node ParseDict(std::istream& input) {
  Dict result;
  for (char c; input >> c && c != '}';) {
    if (c == ',') { input >> c; }
    std::string key = ParseString(input);
    input >> c;
    result.insert({ std::move(key), ParseNode(input) });
  }
  return Node(move(result));
}

std::string ParseLiteral(std::istream& input) {
  std::string result;
  while (std::isalpha(input.peek())) {
    result.push_back(static_cast<char>(input.get()));
  }
  return result;
}

// --- Output ---

using namespace std::literals;

void OutputValue(std::nullptr_t, const OutputContext& ctx) {
  ctx.out << "null"sv;
}

void OutputValue(std::string value, const OutputContext& ctx) {
  ctx.out << "\""sv;
  for (const char& liter : value) {
    if (liter == '\n') {
      ctx.out << "\\n"sv;
      continue;
    }

    if (liter == '\r') {
      ctx.out << "\\r"sv;
      continue;
    }

    if (liter == '\"') {
      ctx.out << "\\"sv ;
    }

    if (liter == '\t') {
      ctx.out << "\t"sv ;
      continue;
    }

    if (liter == '\\') {
      ctx.out << "\\"sv;
    }

    ctx.out << liter;
  }

  ctx.out << "\""sv;
}

void OutputValue(bool value, const OutputContext& ctx) {
  if (value) { ctx.out << "true"sv; }
  else { ctx.out << "false"sv; }
}

void OutputValue(Array array, const OutputContext& ctx) {
  ctx.out << "\n";
  auto inner_ctx = ctx.Indented();
  ctx.OutputIndent();
  ctx.out << "[\n";

  bool first = true;
  for (const auto& elem : array) {
    if (first) { first = false; }
    else {
      ctx.out << "\n"sv;
      inner_ctx.OutputIndent();
      ctx.out << ",\n"sv;
    }
    inner_ctx.OutputIndent();
    OutputNode(elem, inner_ctx);
  }
  ctx.out << "\n"s;
  ctx.OutputIndent();
  ctx.out << "]\n"sv;
  ctx.OutputIndent();
}

void OutputValue(Dict dict, const OutputContext& ctx) {
  ctx.out << "{\n"sv;
  auto inner_ctx = ctx.Indented();
  bool first = true;

  for (auto& [key, val] : dict) {
    if (first) { first = false; }
    else { ctx.out << ",\n"s; }
    inner_ctx.OutputIndent();
    OutputValue(key, ctx);
    ctx.out << ": ";
    OutputNode(val, inner_ctx);
  }

  ctx.out << "\n"s;
  ctx.OutputIndent();
  ctx.out << '}';
}

void OutputNode(const Node& node, const OutputContext& ctx) {
  std::visit([&ctx](const auto& value) {
               OutputValue(value, ctx);
             },
             node.GetValue());
}

void Output(const Document& doc, std::ostream& output) {
  OutputContext ctx{ output };
  OutputNode(doc.GetRoot(), ctx);
}

// --- Other ---
bool operator!=(const Node& lhs, const Node& rhs) {
  return !(lhs == rhs);
}

  }  // namespace json - end
} // namespace external_libraries - end
