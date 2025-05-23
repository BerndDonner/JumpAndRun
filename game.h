#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "gamescene.h"


class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    GameScene *scene;
    Player *player;
    QTimer *gameTimer;
    void setupScene();
    void addObstacles();
};

#endif // GAME_H
