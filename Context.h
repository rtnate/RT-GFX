#pragma once

#include "Adafruit_GFX.h"
#include "Point.h"

namespace RTGFX {
class Context : public Adafruit_GFX {
  public:
    Context(int16_t w, int16_t h): Adafruit_GFX(w, h){};

    using Adafruit_GFX::drawPixel;
    void drawPixel(Point p, uint16_t color) {
      drawPixel(p.x, p.y, color);
    }

    using Adafruit_GFX::writePixel;
    void writePixel(Point p, uint16_t color) {
      writePixel(p.x, p.y, color);
    }

    using Adafruit_GFX::writeFillRect;

    void writeFillRect(Point p, int16_t w, int16_t h, uint16_t color) {
      Adafruit_GFX::writeFillRect(p.x, p.y, w, h, color);
    }

    void writeFillRect(Rect rect, uint16_t color) {
      Adafruit_GFX::writeFillRect(rect.x, rect.y, rect.w, rect.h, color);
    }

    using Adafruit_GFX::writeFastVLine;
    void writeFastVLine(Point p, int16_t h, uint16_t color) {
      Adafruit_GFX::writeFastVLine(p.x, p.y, h, color);
    }

    using Adafruit_GFX::writeFastHLine;
    void writeFastHLine(Point p, int16_t w, uint16_t color) {
      Adafruit_GFX::writeFastHLine(p.x, p.y, w, color);
    }

    using Adafruit_GFX::writeLine;
    void writeLine(Point p0, Point p1, uint16_t color) {
      Adafruit_GFX::writeLine(p0.x, p0.y, p1.x, p1.y, color);
    }

    using Adafruit_GFX::drawFastVLine;
    void drawFastVLine(Point p, int16_t h, uint16_t color) {
      Adafruit_GFX::drawFastVLine(p.x, p.y, h, color);
    }

    using Adafruit_GFX::drawFastHLine;
    void drawFastHLine(Point p, int16_t w, uint16_t color) {
      Adafruit_GFX::drawFastHLine(p.x, p.y, w, color);
    }

    using Adafruit_GFX::fillRect;
    void fillRect(Rect rect, uint16_t color) {
      Adafruit_GFX::fillRect(rect.x, rect.y, rect.w, rect.h, color);
    }

    using Adafruit_GFX::drawLine;
    void drawLine(Point p0, Point p1, uint16_t color) {
      Adafruit_GFX::drawLine(p0.x, p0.y, p1.x, p1.y, color);
    }

    using Adafruit_GFX::drawRect;
    void drawRect(Rect rect, uint16_t color) {
      Adafruit_GFX::drawRect(rect.x, rect.y, rect.w, rect.h, color);
    }

    // These exist only with Adafruit_GFX (no subclass overrides)
    //void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    //void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
    //  uint16_t color);
    //void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    //void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
    //  int16_t delta, uint16_t color);
    //void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2,
    //  int16_t y2, uint16_t color);
    //void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2,
    //  int16_t y2, uint16_t color);
    using Adafruit_GFX::drawRoundRect;
    void drawRoundRect(Rect rect, int16_t radius, uint16_t color) {
      Adafruit_GFX::drawRoundRect(rect.x, rect.y, rect.w, rect.h, radius, color);
    }

    using Adafruit_GFX::fillRoundRect;
    void fillRoundRect(Rect rect, int16_t radius, uint16_t color) {
      Adafruit_GFX::fillRoundRect(rect.x, rect.y, rect.w, rect.h, radius, color);
    }

    //void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
    //  int16_t h, uint16_t color);
    //void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
    //  int16_t h, uint16_t color, uint16_t bg);
    //void drawBitmap(int16_t x, int16_t y, uint8_t* bitmap, int16_t w, int16_t h,
    //  uint16_t color);
    //void drawBitmap(int16_t x, int16_t y, uint8_t* bitmap, int16_t w, int16_t h,
    //  uint16_t color, uint16_t bg);
    //void drawXBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w,
    //  int16_t h, uint16_t color);
    //void drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
    //  int16_t w, int16_t h);
    //void drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t* bitmap, int16_t w,
    //  int16_t h);
    //void drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
    //  const uint8_t mask[], int16_t w, int16_t h);
    //void drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t* bitmap, uint8_t* mask,
    //  int16_t w, int16_t h);
    //void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w,
    //  int16_t h);
    //void drawRGBBitmap(int16_t x, int16_t y, uint16_t* bitmap, int16_t w,
    //  int16_t h);
    //void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[],
    //  const uint8_t mask[], int16_t w, int16_t h);
    //void drawRGBBitmap(int16_t x, int16_t y, uint16_t* bitmap, uint8_t* mask,
    //  int16_t w, int16_t h);
    //void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
    //  uint16_t bg, uint8_t size);
    //void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
    //  uint16_t bg, uint8_t size_x, uint8_t size_y);

    using Adafruit_GFX::getTextBounds;
    Rect getTextBounds(const char* string, Point p) {
      int16_t x, y;
      uint16_t w, h;
      Adafruit_GFX::getTextBounds(string, p.x, p.y, &x, &y, &w, &h);
      return Rect(x, y, w, h);
    }

    using Adafruit_GFX::setCursor;
    void setCursor(Point p) {
      Adafruit_GFX::setCursor(p.x, p.y);
    }

    Point getCursor() const {
      return Point(getCursorX(), getCursorY());
    }

    using Adafruit_GFX::drawTriangle;
    void drawTriangle(Point firstPt, Point secondPt, Point thirdPt, uint16_t color) {
      Adafruit_GFX::drawTriangle(firstPt.x, firstPt.y, secondPt.x, secondPt.y, thirdPt.x, thirdPt.y, color);
    }

    void drawUpTriangleInRect(Rect rect, uint16_t color) {
      drawTriangle(rect.left(), rect.bottom(), rect.centerX(), rect.top(), rect.right(), rect.bottom(), color);
    }

    void drawDownTriangleInRect(Rect rect, uint16_t color) {
      drawTriangle(rect.left(), rect.top(), rect.centerX(), rect.bottom(), rect.right(), rect.top(), color);
    }

    void drawLeftTriangleInRect(Rect rect, uint16_t color) {
      drawTriangle(rect.left(), rect.top(), rect.right(), rect.centerY(), rect.left(), rect.bottom(), color);
    }

    void drawRightTriangleInRect(Rect rect, uint16_t color) {
      drawTriangle(rect.right(), rect.top(), rect.left(), rect.centerY(), rect.right(), rect.bottom(), color);
    }

    using Adafruit_GFX::fillTriangle;
    void fillTriangle(Point firstPt, Point secondPt, Point thirdPt, uint16_t color) {
      Adafruit_GFX::drawTriangle(firstPt.x, firstPt.y, secondPt.x, secondPt.y, thirdPt.x, thirdPt.y, color);
    }

    void fillUpTriangleInRect(Rect rect, uint16_t color) {
      fillTriangle(rect.left(), rect.bottom(), rect.centerX(), rect.top(), rect.right(), rect.bottom(), color);
    }

    void fillDownTriangleInRect(Rect rect, uint16_t color) {
      fillTriangle(rect.left(), rect.top(), rect.centerX(), rect.bottom(), rect.right(), rect.top(), color);
    }

    void fillLeftTriangleInRect(Rect rect, uint16_t color) {
      fillTriangle(rect.left(), rect.top(), rect.right(), rect.centerY(), rect.left(), rect.bottom(), color);
    }

    void fillRightTriangleInRect(Rect rect, uint16_t color) {
      fillTriangle(rect.right(), rect.top(), rect.left(), rect.centerY(), rect.right(), rect.bottom(), color);
    }
  };
  }