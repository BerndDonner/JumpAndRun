#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem {
public:
    Player(QGraphicsItem *parent = nullptr);
    ~Player();
    void advance(int step) override;
    void jump();

private:
    bool jumping;
    int velocityY;
};


#endif // PLAYER_H
