#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include "framemanager.h"


class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    ~Player();
    void advance(int step) override;
    QSize getFrameSize() const;
    void jump();
    QPainterPath shape() const override;

public slots:
    void handleCollision(QGraphicsItem *item, QList<QGraphicsItem *> collidingObjects);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    bool jumping;
    int velocityY;
    FrameManager *frameManager;
};


#endif // PLAYER_H
