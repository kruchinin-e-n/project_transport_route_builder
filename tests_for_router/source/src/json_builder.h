#pragma once

#include "json.h"

#include <optional>

// json builder - declaration

namespace transport_catalogue {

    namespace infrastructure {

        using namespace ext_libs::json;

        class Builder  ;
        class DicValCtx;
        class DicKeyCtx;
        class ArrValCtx;

        class Builder {
            public:
                      Builder       (                 );
            DicValCtx StartDict     (                 );
            Builder&  EndDict       (                 );
            ArrValCtx StartArray    (                 );
            Builder&  EndArray      (                 );
            Builder&  Value         (Node::Value value);
            DicKeyCtx Key           (std::string key  );
            Node      Build         (                 );
            Node      GetTypeOfNode (Node::Value value);

            private:
            Node root_{nullptr};
            std::vector<Node*> nodes_;
            std::optional<std::string> aux_key_ {std::nullopt};
        };

        class DicValCtx {
            public:
                      DicValCtx (Builder& builder);
            DicKeyCtx Key       (std::string key );
            Builder&  EndDict   (                );

            private:
            Builder& builder_;
        };

        class ArrValCtx {
            public:
                      ArrValCtx  (Builder& builder );
            ArrValCtx Value      (Node::Value value);
            DicValCtx StartDict  (                 );
            Builder&  EndArray   (                 );
            ArrValCtx StartArray (                 );

            private:
            Builder&  builder_;
        };

        class DicKeyCtx {
            public:
                      DicKeyCtx  (Builder& builder );
            DicValCtx Value      (Node::Value value);
            ArrValCtx StartArray (                 );
            DicValCtx StartDict  (                 );
    
            private:
            Builder& builder_;
        };

    } // namespace infrastructure - end
} // namespace json - end