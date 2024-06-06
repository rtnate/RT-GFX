#pragma once


#include <stdint.h>

namespace RTGFX {
  struct Point {
    public:
      constexpr Point(int16_t cX, int16_t cY): x(cX), y(cY){};
      constexpr Point(): x(0), y(0){};
      int16_t x;
      int16_t y;

      void translateX(int16_t amount) {
        x += amount;
      }

      void translateY(int16_t amount) {
        y += amount;
      }

      void translate(int16_t amountX, int16_t amountY) {
        translateX(amountX);
        translateY(amountY);
      }

      void translate(Point p) {
        translate(p.x, p.y);
      }

      Point& operator += (const Point& other) {
        translate(other);
        return *this;
      }

      friend Point operator +(const Point& lhs, const Point& rhs) {
          return Point(lhs.x + rhs.x, lhs.y + rhs.y);
      }

      Point& operator -= (const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
      }

      friend Point operator -(const Point& lhs, const Point& rhs) {
        return Point(lhs.x - rhs.x, lhs.y - rhs.y);
      }
    protected:
  };

  struct Rect {
    public:
      constexpr Rect(uint16_t w, uint16_t h): x(0), y(0), w(w), h(h){};
      constexpr Rect(Point p) : x(p.x), y(p.y), w(0x0), h(0x0) {}      constexpr Rect(Point p, uint16_t rW, uint16_t rH) : x(p.x), y(p.y), w(rW), h(rH) {};
      constexpr Rect(int16_t rX, int16_t rY, uint16_t rW, uint16_t rH) : x(rX), y(rY), w(rW), h(rH){};
      constexpr Rect() : x(0), y(0), w(0x0), h(0x0){};

      int16_t x;
      int16_t y;
      uint16_t w;
      uint16_t h;

      int16_t left() const {
        return x;
      }

      int16_t top() const {
        return y;
      }

      int16_t right() const {
        return x + w;
      }

      int16_t bottom() const {
        return y + h;
      }

      Point topLeft() const {
        return Point(left(), top());
      }

      Point topRight() const {
        return Point(right(), top());
      }

      Point bottomRight() const {
        return Point(right(), bottom());
      }

      Point bottomLeft() const {
        return Point(left(), bottom());
      }

      void setLeftKeepingSize(int16_t ptLeft) {
        x = ptLeft;
      }

      void setTopKeepingSize(int16_t ptTop) {
        y = ptTop;
      }

      void setRightKeepingSize(int16_t ptRight) {
        x = ptRight - w;
      }

      void setBottomKeepingSize(int16_t ptBot) {
        y = ptBot - h;
      }

      void setCenterX(int16_t cX) {
        this->x = (cX - w/2);
      }

      void setCenterY(int16_t cY) {
        this->y = (cY - h / 2);
      }

      void setCenter(int16_t x, int16_t y) {
        this->x = (x - w/2);
        this->y = (y - h/2);
      }

      void setCenter(Point p) {
        setCenter(p.x, p.y);
      }

      int16_t centerX() {
        return x + (w / 2);
      }

      int16_t centerY() {
        return y + (h / 2);
      }

      Point center() {
        return Point(centerX(), centerY());
      }

      void translateX(int16_t amount) {
        x += amount;
      }

      void translateY(int16_t amount) {
        y += amount;
      }

      void translate(int16_t amountX, int16_t amountY) {
        translateX(amountX);
        translateY(amountY);
      }

      void translate(Point p) {
        translate(p.x, p.y);
      }

      static Rect withCenter(int16_t x, int16_t y, uint16_t w, uint16_t h) {
        return Rect(x - (w/2), y - (h/2), w, h);
      }
  };
}