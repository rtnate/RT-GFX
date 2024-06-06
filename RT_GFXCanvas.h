#ifndef RT_GFXCANVAS
#define RT_GFXCANVAS

#include "RT_GFX.h"

namespace RTGFX {
    class MonochromeCanvasBase : public RTGFX::Context {
    public:
        MonochromeCanvasBase(uint16_t w, uint16_t h): 
            RTGFX::Context(w, h){};

        using Context::drawPixel;
        void drawPixel(int16_t x, int16_t y, uint16_t color) override;

        void fillScreen(uint16_t color);

        using Context::drawFastVLine;
        void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;

        using Context::drawFastHLine;
        void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;

        bool getPixel(int16_t x, int16_t y) const;

        bool getPixel(Point p) {
          return getPixel(p.x, p.y);
        }
        /**********************************************************************/
        /*!
            @brief    Get a pointer to the internal buffer memory
            @returns  A pointer to the allocated buffer
        */
        /**********************************************************************/
        virtual const uint8_t* pixelBuffer(void) const = 0;
    protected:
        bool getRawPixel(int16_t x, int16_t y) const;
        void drawFastRawVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
        void drawFastRawHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
        virtual uint8_t* getBuffer(void) = 0;
    private:
    };

    template<uint16_t W, uint16_t H>
    class MonochromeCanvas: public MonochromeCanvasBase {
        public:
            MonochromeCanvas() : MonochromeCanvasBase(W, H), pixelBuffer_{}{};

            const uint8_t* pixelBuffer() const override {
                return this->pixelBuffer_;
            }
        protected:
            static constexpr uint32_t bufferSize_ = ((W + 7) / 8) * H;
            uint8_t pixelBuffer_[bufferSize_];

            uint8_t* getBuffer() override {
                return this->pixelBuffer_;
            }
    };

    class DisplayCanvasTrio : public MonochromeCanvas<128 * 3, 64>
    {
      public:
        using BaseClass = MonochromeCanvas<128 * 3, 64>;
        static constexpr unsigned int kNoDisplays = 3;
        static constexpr unsigned int kWidthDisplay = 128;
        static constexpr unsigned int kHeightDisplay = 64;
        static constexpr unsigned int kWidthTotal = kWidthDisplay * 3;
        static constexpr unsigned int kHeightTotal = kHeightDisplay;
        static constexpr uint16_t PIXEL_ON = 0xFFFF;
        static constexpr uint16_t PIXEL_OFF = 0x0000;

        enum DisplayIndex {
          DISPLAY_LEFT = 0,
          DISPLAY_CENTER = 1,
          DISPLAY_RIGHT = 2
        };

        DisplayCanvasTrio() : BaseClass(){};


        static constexpr size_t BufferSize = BaseClass::bufferSize_;

        static constexpr Point getDisplayOffset(DisplayIndex index) {
          return Point(kWidthDisplay * index, 0);
        }

        static constexpr Point getDisplayOffset(DisplayIndex index, int16_t x, int16_t y) {
          return Point(kWidthDisplay * index + x, y);
        }

        static constexpr Point getDisplayOffset(DisplayIndex index, Point p) {
          return Point(kWidthDisplay * index + p.x, p.y);
        }
    };

    class DisplayCanvasDuo : public MonochromeCanvas<128 * 2, 64>
    {
    public:
      using BaseClass = MonochromeCanvas<128 * 2, 64>;
      static constexpr unsigned int kNoDisplays = 2;
      static constexpr unsigned int kWidthDisplay = 128;
      static constexpr unsigned int kHeightDisplay = 64;
      static constexpr unsigned int kWidthTotal = kWidthDisplay * 2;
      static constexpr unsigned int kHeightTotal = kHeightDisplay;
      static constexpr uint16_t PIXEL_ON = 0xFFFF;
      static constexpr uint16_t PIXEL_OFF = 0x0000;

      enum DisplayIndex {
        DISPLAY_LEFT = 0,
        DISPLAY_RIGHT = 1
      };

      DisplayCanvasDuo() : BaseClass() {};

      static constexpr size_t BufferSize = BaseClass::bufferSize_;

      static constexpr Point getDisplayOffset(DisplayIndex index) {
        return Point(kWidthDisplay * index, 0);
      }

      static constexpr Point getDisplayOffset(DisplayIndex index, int16_t x, int16_t y) {
        return Point(kWidthDisplay * index + x, y);
      }

      static constexpr Point getDisplayOffset(DisplayIndex index, Point p) {
        return Point(kWidthDisplay * index + p.x, p.y);
      }
    protected:

    };
}

#endif /* RT_GFXCANVAS */
