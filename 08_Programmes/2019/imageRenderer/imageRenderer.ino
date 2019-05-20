 #define COLOR_DEPTH 16
static int bufferSize = 0;
static int max_x = 0;
static int max_y = 0;
int * outputBuffer;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void setScreenSize(int size_x, int size_y) {
  max_x = size_x-1;
  max_y = size_y-1;
  bufferSize = size_x * size_y;
  int bufferInitializer[size_x * size_y * (COLOR_DEPTH/8)];
  outputBuffer = bufferInitializer;
}

void addImageToBufferXY(int x, int y, byte * image, int imageWidth, int imageSize) {
  //add an image to the output buffer
  if (max_x >= x+imageWidth && max_y >= y+imageSize/imageWidth) {
    for (int i = 0; i<imageSize/imageWidth; i++) {
      for (int j = 0; i<imageWidth*(COLOR_DEPTH/8); i++) {
        outputBuffer[((x+i)+((max_y+1)*(y+i)))*COLOR_DEPTH/8] = image[j+imageWidth*i];
      }
    }
  }
}

void writeBuffer() {
  /*for (int i = 0; i < bufferSize; i++) {
    spiCommand(outputBuffer[i]);
  }//*/
}
