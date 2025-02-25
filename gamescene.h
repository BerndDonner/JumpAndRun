#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>


class GameScene : public QGraphicsScene
{
    Q_OBJECT
signals:
    void collisionDetected(QGraphicsItem *item, QList<QGraphicsItem *> collidingObjects);
public:
    explicit GameScene(QObject *parent = nullptr);
    void addMovingItem(QGraphicsItem  *item);

public slots:
    void advance();

private:
    QList<QGraphicsItem  *> movingItems;

    void checkCollisions();
};

#endif // GAMESCENE_H
