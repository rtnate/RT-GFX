#pragma once

#include "Printable.h"
#include "Print.h"
#include <cstring>

namespace RTGFX {
  class PrintableCString: public Print {
    public:
      PrintableCString(char* buffer, size_t bufferLength): Print(), 
        stringBuf_(buffer), bufferLen_(bufferLength)
        {};

      virtual size_t write(uint8_t) override;

      virtual size_t write(const uint8_t* buffer, size_t size) override;

      virtual int availableForWrite() override;

      size_t length() {
        return strlen(stringBuf_);
      }

      size_t capacity() {
        return bufferLen_;
      }

      size_t capacityRemaining() {
        return capacity() - length();
      }
      protected:
        char* stringBuf_;
        size_t bufferLen_;
  };
}