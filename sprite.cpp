#include "sprite.h"

Sprite::Sprite(const QString &fileName, size_t totalFrames, bool l)
    : totalFrames(totalFrames), currentFrame(0), loop(l) {

    QPixmap spriteSheet(fileName);

    // Preload all frames
    frameSize = QSize(spriteSheet.width() / totalFrames, spriteSheet.height());

    for (size_t i = 0; i < totalFrames; ++i) {
        size_t x = (i % totalFrames) * frameSize.width();
        size_t y = 0;
        frames.append(spriteSheet.copy(x, y, frameSize.width(), frameSize.height()));
    }
}


QPixmap Sprite::getFirstFrame() {
    currentFrame = 0;
    return frames.first();
}


QPixmap Sprite::getNextFrame() {
    currentFrame = currentFrame + 1;

    if (loop == true) currentFrame = currentFrame % totalFrames;
    else if (currentFrame >= totalFrames) currentFrame = (totalFrames - 1);

    return frames[currentFrame];
}

QSize Sprite::getFrameSize() const {
    return frameSize;
}
