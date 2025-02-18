#include "player.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem{parent}, currentFrame{0}, totalFrames{8}, frameWidth{128}, frameHeight{128}, jumping{false}, velocityY{0} {
    const int frameDelayMs = 50;

    QPixmap spriteSheet(":/sprites/sprites/Converted_Vampire/Walk.png");
    this->spriteSheet = spriteSheet;

    // Set the initial frame
    setPixmap(spriteSheet.copy(0, 0, frameWidth, frameHeight));

    // Setup the timer for animation
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Player::nextFrame);
    animationTimer->start(frameDelayMs);
}

Player::~Player() {
    if (animationTimer) {
        animationTimer->stop();
        delete animationTimer;
    }
}


void Player::nextFrame() {
    currentFrame = (currentFrame + 1) % totalFrames;

    // Calculate the position of the current frame on the sprite sheet
    int x = (currentFrame * frameWidth) % spriteSheet.width();
    int y = ((currentFrame * frameWidth) / spriteSheet.width()) * frameHeight;

    // Copy the current frame from the sprite sheet
    setPixmap(spriteSheet.copy(x, y, frameWidth, frameHeight));
}


void Player::advance(int step) {
    if (!step) return;

    if (jumping) {
        velocityY += 1; // Schwerkraft
        moveBy(0, velocityY);
        if (y() >= 400-128) {         //TODO scene->height() - 128
            jumping = false;
            velocityY = 0;
            setY(400-128); // Bodenposition TODO scene->height() - 128
        }
    }
}

void Player::jump() {
    if (!jumping) {
        jumping = true;
        velocityY = -15; // Sprunghöhe
    }
}
