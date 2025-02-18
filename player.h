#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>


class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    ~Player();
    void advance(int step) override;
    void jump();

private slots:
    void nextFrame();

private:
    QPixmap spriteSheet;
    QTimer *animationTimer;
    int currentFrame;
    int totalFrames;
    int frameWidth;
    int frameHeight;
    bool jumping;
    int velocityY;
};


#endif // PLAYER_H
