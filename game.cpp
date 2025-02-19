#include "game.h"
#include "obstacle.h"

#include <QKeyEvent>

Game::Game(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setupScene();

    player = new Player();
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);  // Allow the item to receive focus
    player->setFocus();                                 // Set the focus on the player item
    player->setPos(50, scene->height() - 128);
    frameManager = new FrameManager(player);
    frameManager->setAction(Action::Jumping);

    addObstacles();

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    gameTimer->start(16); // 60 FPS
}

void Game::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        player->jump();
    }
    QGraphicsView::keyPressEvent(event);  // Call base class if needed
}

void Game::setupScene() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    scene->setSceneRect(0, 0, 800, 400);
    setFixedSize(800, 400);
}

void Game::addObstacles() {
    for (int i = 1; i <= 3; i++) {
        Obstacle *obstacle = new Obstacle();
        obstacle->setPos(300 * i, scene->height() - 50);
        scene->addItem(obstacle);
    }
}
