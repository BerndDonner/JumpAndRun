#ifndef SPRITE_H
#define SPRITE_H


#include <QPixmap>
#include <QVector>
#include <QString>

class Sprite {
public:
    Sprite(const QString &fileName, size_t totalFrames);
    QPixmap getFirstFrame();
    QPixmap getNextFrame();
    QSize getFrameSize() const;

private:
    QVector<QPixmap> frames;  // Preloaded frames
    size_t currentFrame;
    size_t totalFrames;
    QSize frameSize;
};

#endif // SPRITE_H
