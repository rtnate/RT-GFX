#ifndef RT_GFXCANVAS
#define RT_GFXCANVAS

#include "RT_GFX.h"

namespace RTGFX {
    class MonochromeCanvasBase : public RTGFX::Context {
    public:
        MonochromeCanvasBase(uint16_t w, uint16_t h): 
            RTGFX::Context(w, h){};

        void drawPixel(int16_t x, int16_t y, uint16_t color) override;
        void fillScreen(uint16_t color);
        void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
        void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
        bool getPixel(int16_t x, int16_t y) const;
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
            MonochromeCanvas() : MonochromeCanvasBase(W, H){};

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
}

#endif /* RT_GFXCANVAS */
