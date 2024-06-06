#include "PrintableCString.h"

using namespace RTGFX;

size_t PrintableCString::write(uint8_t c) {
  if (capacityRemaining() > 0) {
     uint8_t len = length();
     if (c > 0 && c < 128) {
       stringBuf_[len] = c;
       return 1;
     }
     else {
       return 0;
     }

  }
}

size_t PrintableCString::write(const uint8_t* buffer, size_t size) {
  return 0;
}

int PrintableCString::availableForWrite() {
  return 0;
}