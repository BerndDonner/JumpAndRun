#include "player.h"
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QPen>
#include <QBitmap>


Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem{parent}, jumping{false}, velocityY{0} {
    frameManager = new FrameManager(this);
    frameManager->setAction(Action::Walking);
}


Player::~Player() {
}


void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // Call base class to draw the pixmap
    QGraphicsPixmapItem::paint(painter, option, widget);

    // Draw bounding box
    painter->setPen(QPen(Qt::red, 2)); // Red bounding box with 2px thickness
    painter->drawRect(boundingRect());
}


QPainterPath Player::shape() const {
    QPainterPath path;
    path.addRegion(pixmap().mask());  // Use pixmap mask as collision shape
    return path;
}


void Player::advance(int step) {
    if (!step) return;

    if (jumping) {
        velocityY += 1; // Schwerkraft
        moveBy(0, velocityY);
        size_t h = frameManager->getFrameSize().height();
        if (y() >= 400-h) {
            jumping = false;
            frameManager->setAction(Action::Walking);
            velocityY = 0;
            setY(400-h);
        }
    }
}


QSize Player::getFrameSize() const {
    return frameManager->getFrameSize();
}


void Player::jump() {
    if (!jumping) {
        jumping = true;
        frameManager->setAction(Action::Jumping);
        velocityY = -15; // Sprunghöhe
    }
}


void Player::handleCollision(QGraphicsItem *item, QList<QGraphicsItem *> collidingObjects) {
    if (this == item) {
        qDebug() << "Collision detected!";
        frameManager->setAction(Action::Dead);
    }
}
