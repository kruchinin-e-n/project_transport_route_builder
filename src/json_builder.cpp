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
			auto* parent_node = nodes_.back();                                                  // get parent node

			if (parent_node->IsMap()) {
				if (!aux_key_) throw std::logic_error("Error: nested dictionary without key");  // check key
				auto& dict = std::get<Dict>(parent_node->GetValue());                           // get parent node as dictionary
				auto [it, bool_] = dict.emplace(std::move(aux_key_.value()), Dict());           // receive arguments
				aux_key_ = std::nullopt;                                                        // reset aux_key_
				nodes_.emplace_back(&it->second);                                               // update parent node
			}
			else if (parent_node->IsArray()) {
				auto& array = std::get<Array>(parent_node->GetValue());                         // get parent node as array
				array.emplace_back(Dict());                                                     // add dictionary to array
				nodes_.emplace_back(&array.back());                                             // update parent node
			}
			else if (parent_node->IsNull()) parent_node->GetValue() = Dict();                   // start build
			else throw std::logic_error("Error: wrong parent node");                            // building error

			return *this;
		}

		Builder& Builder::EndDict() {
			auto* parent_node = nodes_.back();                                                              // get parent node

			if (!parent_node->IsMap()) throw std::logic_error("Error: parent node is not a dictionary");    // check parent node is dictionary
			nodes_.pop_back();                                                                              // update nodes stack closing dictionary

			return *this;
		}

		ArrValCtx Builder::StartArray() {
			auto* parent_node = nodes_.back();                                              // get parent node

			if (parent_node->IsMap()) {
				if (!aux_key_) throw std::logic_error("Error: nested array without key");   // check key
				auto& dict = std::get<Dict>(parent_node->GetValue());                       // get parent node as dictionary
				auto [it, bool_] = dict.emplace(std::move(aux_key_.value()), Array());      // receive arguments
				aux_key_ = std::nullopt;                                                    // reset aux_key_
				nodes_.emplace_back(&it->second);                                           // update parent node
			}
			else if (parent_node->IsArray()) {
				auto& array = std::get<Array>(parent_node->GetValue());                     // get parent node as array
				array.emplace_back(Array());                                                // add array to array 
				nodes_.emplace_back(&array.back());                                         // update parent node
			}
			else if (parent_node->IsNull()) { parent_node->GetValue() = Array(); }          // start build
			else throw std::logic_error("Error: wrong parent node");                        // building error

			return *this;
		}

		Builder& Builder::EndArray() {
			auto* parent_node = nodes_.back();                                                          // get parent node

			if (!parent_node->IsArray()) throw std::logic_error("Error: parent node is not an Array");  // check parent node is array
			nodes_.pop_back();                                                                          // update nodes stack closing array

			return *this;
		}

		Builder& Builder::Value(Node::Value value) {
			auto* parent_node = nodes_.back();                                          // get parent node

			if (parent_node->IsMap()) {
				if (!aux_key_) throw std::logic_error("Error: value without key");      // check key
				auto& dict = std::get<Dict>(parent_node->GetValue());                   // get parent node as dictionary
				auto [it, bool_] = dict.emplace(std::move(aux_key_.value()), Node{ });   // receive arguments
				aux_key_ = std::nullopt;                                                // reset aux_key_
				parent_node = &it->second;                                              // update parent node
				parent_node->GetValue() = std::move(value);                             // value for parent node
			}
			else if (parent_node->IsArray()) {
				auto& array = std::get<Array>(parent_node->GetValue());                 // get parent node as array
				array.emplace_back(GetTypeOfNode(value));                               // add value to array
				parent_node = &array.back();                                            // update parent node
			}
			else if (root_.IsNull()) { root_.GetValue() = std::move(value); }           // start build
			else throw std::logic_error("Error: wrong parent node");                    // building error

			return *this;
		}

		DicKeyCtx Builder::Key(std::string key) {
			auto* parent_node = nodes_.back();                                                                          // get parent node
			parent_node->IsMap() && !aux_key_ ? aux_key_ = std::move(key) : throw std::logic_error("Error: wrong key"); // check parent node is dictionary
			return *this;                                                                                               // return key
		}

		Node Builder::Build() {
			if (root_.IsNull() || nodes_.size() > 1) throw std::logic_error("Error: wrong object building");    // building error
			return root_;                                                                                       // start build
		}

		Node Builder::GetTypeOfNode(Node::Value value) {
			if (std::holds_alternative <std::nullptr_t> (value)) return Node(std::get <std::nullptr_t> (value));
			if (std::holds_alternative <std::string   > (value)) return Node(std::get <std::string   > (value));
			if (std::holds_alternative <int           > (value)) return Node(std::get <int           > (value));
			if (std::holds_alternative <double        > (value)) return Node(std::get <double        > (value));
			if (std::holds_alternative <bool          > (value)) return Node(std::get <bool          > (value));
			if (std::holds_alternative <Dict          > (value)) return Node(std::get <Dict          > (value));
			if (std::holds_alternative <Array         > (value)) return Node(std::get <Array         > (value));
			return {};
		}

		// --- Class DicValCtx ---

		          DicValCtx::DicValCtx (Builder& builder) : builder_(builder) {}
		DicKeyCtx DicValCtx::Key       (std::string key ) {return builder_.Key(key) ;}
		Builder&  DicValCtx::EndDict   (                ) {return builder_.EndDict();}

		// --- Class ArrValCtx ---

		          ArrValCtx::ArrValCtx  (Builder& builder ) : builder_(builder) {}
		ArrValCtx ArrValCtx::Value      (Node::Value value) {return ArrValCtx(builder_.Value(value));}
		DicValCtx ArrValCtx::StartDict  (                 ) {return builder_.StartDict()            ;}
		ArrValCtx ArrValCtx::StartArray (                 ) {return builder_.StartArray()           ;}
		Builder&  ArrValCtx::EndArray   (                 ) {return builder_.EndArray()             ;}

		// --- Class DicKeyCtx ---

		          DicKeyCtx::DicKeyCtx  (Builder& builder ) : builder_(builder) {}
		DicValCtx DicKeyCtx::Value      (Node::Value value) {return DicValCtx(builder_.Value(value));}
		ArrValCtx DicKeyCtx::StartArray (                 ) {return builder_.StartArray()           ;}
		DicValCtx DicKeyCtx::StartDict  (                 ) {return builder_.StartDict()            ;}

	} // namespace infrastructure - end
} // namespace json - end