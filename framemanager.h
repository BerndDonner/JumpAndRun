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
    Jumping,
    Dead
};


class FrameManager : public QObject {
    Q_OBJECT
public:
    FrameManager(QGraphicsPixmapItem *player);
    ~FrameManager();
    QSize getFrameSize() const;
    void setAction(Action action);

private slots:
    void updateFrame();

private:
    QGraphicsPixmapItem *player;
    QTimer *animationTimer;
    QMap<Action, Sprite*> sprites;
    Action currentAction;
    const int frameDelayMs = 75;
    QSize frameSize;
};

#endif // FRAMEMANAGER_H
