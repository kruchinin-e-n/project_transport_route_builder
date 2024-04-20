#include "svg.h"

// external (out of transport catalogue) svg library - implementation

namespace ext_libs {

    namespace svg {

        using namespace std::literals;

        std::ostream& operator<<(std::ostream& out, Color& color) {
            std::visit(OutputColor{ out }, color);
            return out;
        }

        std::ostream& operator<<(std::ostream& out, StrokeLineCap line_cap) {
            switch (line_cap) {
                case StrokeLineCap::BUTT:
                    out << "butt"sv;
                    break;
                case StrokeLineCap::ROUND:
                    out << "round"sv;
                    break;
                case StrokeLineCap::SQUARE:
                    out << "square"sv;
                    break;
                }
            return out;
        }

        std::ostream& operator<<(std::ostream& out, StrokeLineJoin line_join) {
            switch (line_join) {
                case StrokeLineJoin::ARCS:
                    out << "arcs"sv;
                    break;
                case StrokeLineJoin::BEVEL:
                    out << "bevel"sv;
                    break;
                case StrokeLineJoin::MITER:
                    out << "miter"sv;
                    break;
                case StrokeLineJoin::MITER_CLIP:
                    out << "miter-clip"sv;
                    break;
                case StrokeLineJoin::ROUND:
                    out << "round"sv;
                    break;
                }
            return out;
        }

        void Object::Output(const OutputContext& ctx) const {
            ctx.OutputIndent();
            OutputObj(ctx);
            ctx.out << std::endl;
        }
//      --- Circle ---

        Circle& Circle::SetCenter(Point center) { center_ = center; return *this; }
        Circle& Circle::SetRadius(double radius) { radius_ = radius; return *this; }

        void Circle::OutputObj(const OutputContext& ctx) const {
            auto& out = ctx.out;
            out << "<circle cx=\""sv << center_.x << "\" cy=\""sv << center_.y << "\" "sv << "r=\""sv << radius_ << "\""sv;
            OutputPathProps(ctx.out);
            out << "/>"sv;
        }

//      --- Polyline ---

        Polyline& Polyline::AddPoint(Point point) {
            points_.push_back(std::move(point));
            return *this;
        }

        void Polyline::OutputObj(const OutputContext& context) const {
            auto& out = context.out;
            out << "<polyline points=\""sv;
            bool is_first = true;
            for (auto& point : points_) {
                if (is_first) {
                    out << point.x << "," << point.y;
                    is_first = false;
                }
                else {
                    out << " "sv << point.x << "," << point.y;
                }
            }
            out << "\""sv;

            OutputPathProps(context.out);
            out << "/>"sv;
        }

//      --- Text ---

        Text& Text::SetPosition(Point pos) { pos_ = pos; return *this; }
        Text& Text::SetOffset(Point offset) { offset_ = offset; return *this; }
        Text& Text::SetFontSize(uint32_t size) { size_ = size; return *this; }
        Text& Text::SetFontFamily(std::string font_family) { font_family_ = std::move(font_family); return *this; }
        Text& Text::SetFontWeight(std::string font_weight) { font_weight_ = std::move(font_weight); return *this; }
        Text& Text::SetData(std::string data) { data_ = std::move(data); return *this; }

        void Text::OutputObj(const OutputContext& context) const {
            auto& out = context.out;
            out << "<text";

            OutputPathProps(context.out);
            out << " x=\""sv << pos_.x << "\" y=\""sv << pos_.y << "\" "sv;
            out << "dx=\""sv << offset_.x << "\" dy=\""sv << offset_.y << "\" "sv;
            out << "font-size=\""sv << size_ << "\""sv;
            if (!font_family_.empty()) out << " font-family=\""sv << font_family_ << "\" "sv;
            if (!font_weight_.empty()) out << "font-weight=\""sv << font_weight_ << "\""sv;
            out << ">"sv << data_ << "</text>"sv;
        }
     
//      --- Document ---

        void Document::AddPtr(std::unique_ptr<Object>&& obj) {
            objects_.emplace_back(std::move(obj));
        }

        void Document::Output(std::ostream& out) const {
            OutputContext ctx(out, 2, 2);
            out << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"sv << std::endl;
            out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">"sv << std::endl;
            for (const auto& obj : objects_) {
                obj->Output(ctx);
            }
            out << "</svg>"sv;
        }
    }  // namespace svg - end
} // namespace transport_catalogue - end