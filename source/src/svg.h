#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <optional>
#include <variant>

// external (out of transport catalogue) svg library - declaration

namespace ext_libs {

    namespace svg {

        // Red Green Blue

        struct RGB {

            RGB() = default;
            RGB(int red, int green, int blue) : red(red), green(green), blue(blue) {}

            int red = 0;
            int green = 0;
            int blue = 0;
        };

        // Red Green Blue Opacity

        struct RGBO : public RGB {

            RGBO(int red, int green, int blue, double opacity) : RGB(red, green, blue), opacity(opacity) {}

            double opacity = 1.0;
        };

        using Color = std::variant<std::monostate, std::string, RGB, RGBO>;

        inline const Color NoneColor{ std::monostate() };

        std::ostream& operator<<(std::ostream& out, Color& color);

        struct OutputColor {
            std::ostream& out;
            void operator() (std::monostate   ) const { out << "none"; }
            void operator() (std::string color) const { out << color ; }
            void operator() (RGB color        ) const {
                out << "rgb(" << static_cast<int>(color.red) 
                    << ","    << static_cast<int>(color.green) 
                    << ","    << static_cast<int>(color.blue) 
                    << ")";
            }
            void operator()(RGBO color) const {
                out << "rgba(" << static_cast<int>(color.red) 
                    << ","     << static_cast<int>(color.green) 
                    << ","     << static_cast<int>(color.blue) 
                    << ","     << color.opacity 
                    << ")";
            }
        };

        enum class StrokeLineCap { BUTT, ROUND, SQUARE };
        enum class StrokeLineJoin { ARCS, BEVEL, MITER, MITER_CLIP, ROUND };

        std::ostream& operator<<(std::ostream& out, StrokeLineCap line_cap);
        std::ostream& operator<<(std::ostream& out, StrokeLineJoin line_join);

        struct Point {
            Point() = default;
            Point(double x, double y) : x(x), y(y) {}
            double x = 0;
            double y = 0;
        };

        struct OutputContext {

            OutputContext(std::ostream& out) : out(out) {}

            OutputContext(std::ostream& out, int indent_step, int indent = 0)
                : out(out)
                , indent_step(indent_step)
                , indent(indent) {
            }

            OutputContext Indented() const {
                return { out, indent_step, indent + indent_step };
            }

            void OutputIndent() const {
                for (int i = 0; i < indent; ++i) {
                    out.put(' ');
                }
            }

            std::ostream& out;
            int indent_step = 0;
            int indent = 0;
        };

        class Object {
        public:

            void Output (const OutputContext& ctx) const;

            virtual ~Object() = default;

        private:

            virtual void OutputObj(const OutputContext& ctx) const = 0;
        };

        class ObjectContainer {
        public:

            template <typename DrawableObj>
            void Add(DrawableObj obj) { AddPtr(std::make_unique<DrawableObj>(std::move(obj))); }
            virtual void AddPtr(std::unique_ptr<Object>&& obj) = 0;

        protected:
            ~ObjectContainer() = default;
        };

        class Drawable {
        public:
            virtual ~Drawable() = default;
            virtual void Draw(ObjectContainer& container) const = 0;
        };

        template <typename ChainingObj>
        class PathProps {
        public:
            ChainingObj& SetFillColor(Color color) {
                fill_color_ = std::move(color);
                return ChainingProps();
            }
            ChainingObj& SetStrokeColor(Color color) {
                stroke_color_ = std::move(color);
                return ChainingProps();
            }
            ChainingObj& SetStrokeWidth(double width) {
                width_ = std::move(width);
                return ChainingProps();
            }
            ChainingObj& SetStrokeLineCap(StrokeLineCap line_cap) {
                line_cap_ = line_cap;
                return ChainingProps();
            }
            ChainingObj& SetStrokeLineJoin(StrokeLineJoin line_join) {
                line_join_ = line_join;
                return ChainingProps();
            }

        protected:
            ~PathProps() = default;

            void OutputPathProps(std::ostream& out) const {
                using namespace std::literals;

                if (fill_color_) {
                    out << " fill=\""sv;
                    std::visit(OutputColor{ out }, *fill_color_);
                    out << "\""sv;
                }
                if (line_cap_) {
                    out << " stroke-linecap=\""sv << *line_cap_ << "\""sv;
                }
                if (line_join_) {
                    out << " stroke-linejoin=\""sv << *line_join_ << "\""sv;
                }
                if (stroke_color_) {
                    out << " stroke=\""sv;
                    std::visit(OutputColor{ out }, *stroke_color_);
                    out << "\""sv;
                }
                if (width_) {
                    out << " stroke-width=\""sv << *width_ << "\""sv;
                }
            }

        private:
            ChainingObj& ChainingProps() {
                return static_cast<ChainingObj&>(*this);
            }

            std::optional<Color> fill_color_;
            std::optional<Color> stroke_color_;
            std::optional<double> width_;
            std::optional<StrokeLineCap> line_cap_;
            std::optional<StrokeLineJoin> line_join_;
        };

        class Circle final : public Object, public PathProps<Circle> {
        public:
            Circle& SetCenter(Point center);
            Circle& SetRadius(double radius);

        private:
            void OutputObj(const OutputContext& ctx) const override;

            Point center_;
            double radius_ = 1.0;
        };

        class Polyline final : public Object, public PathProps<Polyline> {
        public:
            Polyline& AddPoint(Point point);

        private:
            void OutputObj(const OutputContext& ctx) const override;
            std::vector<Point> points_;
        };

        class Text final : public Object, public PathProps<Text> {
        public:

            Text& SetPosition(Point pos);
            Text& SetOffset(Point offset);
            Text& SetFontSize(uint32_t size);
            Text& SetFontFamily(std::string font_family);
            Text& SetFontWeight(std::string font_weight);
            Text& SetData(std::string data);

        private:
            void OutputObj(const OutputContext& ctx) const override;

            Point pos_ = { 0.0, 0.0 };
            Point offset_ = { 0.0, 0.0 };
            uint32_t size_ = 1;
            std::string font_family_;
            std::string font_weight_;
            std::string data_;
        };

        class Document : public ObjectContainer {
        public:
            void AddPtr(std::unique_ptr<Object>&& obj) override;
            void Output(std::ostream& out) const;

        private:
            std::vector<std::unique_ptr<Object>> objects_;
        };

    }  // namespace svg - end
} // namespace ext_libs - end