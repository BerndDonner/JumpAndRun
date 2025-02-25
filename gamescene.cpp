#include "gamescene.h"

GameScene::GameScene(QObject *parent) : QGraphicsScene{parent} {
}

void GameScene::addMovingItem(QGraphicsItem *item) {
    addItem(item);
    movingItems.append(item);
}

void GameScene::advance() {
    QGraphicsScene::advance();
    checkCollisions();
}

void GameScene::checkCollisions() {
    for (QGraphicsItem  *item : movingItems) {
        QList<QGraphicsItem *> colliding = item->collidingItems();
        if (!colliding.isEmpty()) {
            emit collisionDetected(item, colliding);
        }
    }
}

