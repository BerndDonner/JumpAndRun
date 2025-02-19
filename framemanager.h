#ifndef FRAMEMANAGER_H
#define FRAMEMANAGER_H

#include "sprite.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMap>

enum class Action {
    Idle,
    Walking,
    Running,
    Jumping
};


class FrameManager : public QObject {
    Q_OBJECT
public:
    FrameManager(QGraphicsPixmapItem *player);
    ~FrameManager();
    void setAction(Action action);

private slots:
    void updateFrame();

private:
    QGraphicsPixmapItem *player;
    QTimer *animationTimer;
    QMap<Action, Sprite*> sprites;
    Action currentAction;
    const int frameDelayMs = 75;
};

#endif // FRAMEMANAGER_H
