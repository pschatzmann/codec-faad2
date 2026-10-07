// Opens the faad2 AAC decoder and prints its version and capabilities
#include "neaacdec.h"

void setup() {
  Serial.begin(115200);
  while (!Serial);

  char *id = nullptr;
  char *copyright = nullptr;
  NeAACDecGetVersion(&id, &copyright);
  Serial.print("faad2 version: ");
  Serial.println(id);
  Serial.print("capabilities: 0x");
  Serial.println(NeAACDecGetCapabilities(), HEX);

  NeAACDecHandle decoder = NeAACDecOpen();
  if (decoder == nullptr) {
    Serial.println("NeAACDecOpen failed");
    return;
  }
  NeAACDecConfigurationPtr cfg = NeAACDecGetCurrentConfiguration(decoder);
  cfg->outputFormat = FAAD_FMT_16BIT;
  NeAACDecSetConfiguration(decoder, cfg);
  Serial.println("decoder ready");
  NeAACDecClose(decoder);
}

void loop() {}
