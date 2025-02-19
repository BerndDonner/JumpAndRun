#include "sprite.h"

Sprite::Sprite(const QString &fileName, size_t totalFrames)
    : totalFrames(totalFrames), currentFrame(0) {

    QPixmap spriteSheet(fileName);

    // Preload all frames
    size_t frameWidth  = spriteSheet.width() / totalFrames;
    size_t frameHeight = spriteSheet.height();

    for (size_t i = 0; i < totalFrames; ++i) {
        size_t x = (i % totalFrames) * frameWidth;
        size_t y = 0;
        frames.append(spriteSheet.copy(x, y, frameWidth, frameHeight));
    }
}


QPixmap Sprite::getFirstFrame() {
    currentFrame = 0;
    return frames.first();
}


QPixmap Sprite::getNextFrame() {
    currentFrame = (currentFrame + 1) % totalFrames;
    return frames[currentFrame];
}
