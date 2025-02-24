#include "player.h"
#include <QGraphicsPixmapItem>


Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem{parent}, jumping{false}, velocityY{0} {
}


Player::~Player() {
}


void Player::advance(int step) {
    if (!step) return;

    if (jumping) {
        velocityY += 1; // Schwerkraft
        moveBy(0, velocityY);
        if (y() >= 400-128) {         //TODO: scene->height() - 128
            jumping = false;          //TODO: signal that the jump is finished
            velocityY = 0;
            setY(400-128);            // Bodenposition TODO scene->height() - 128
        }
    }
}

void Player::jump() {
    if (!jumping) {
        jumping = true;
        velocityY = -15; // Sprunghöhe
    }
}
