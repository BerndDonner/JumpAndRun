#include "framemanager.h"
#include <cassert>


FrameManager::FrameManager(QGraphicsPixmapItem *player)
    : player(player), currentAction(Action::Idle) {

    // Initialize Sprites for different actions
    sprites[Action::Idle]    = new Sprite(":/sprites/sprites/Converted_Vampire/Idle.png", 5);
    sprites[Action::Walking] = new Sprite(":/sprites/sprites/Converted_Vampire/Walk.png", 8);
    sprites[Action::Running] = new Sprite(":/sprites/sprites/Converted_Vampire/Run.png", 8);
    sprites[Action::Jumping] = new Sprite(":/sprites/sprites/Converted_Vampire/Jump.png", 7);

    assert(sprites[Action::Idle]->getFrameSize() == sprites[Action::Walking]->getFrameSize());
    assert(sprites[Action::Idle]->getFrameSize() == sprites[Action::Running]->getFrameSize());
    assert(sprites[Action::Idle]->getFrameSize() == sprites[Action::Jumping]->getFrameSize());

    // Set initial sprite
    player->setPixmap(sprites[currentAction]->getFirstFrame());

    // Timer for animation updates
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &FrameManager::updateFrame);
    animationTimer->start(frameDelayMs);
}

FrameManager::~FrameManager() {
    if (animationTimer) {
        animationTimer->stop();
        delete animationTimer;
    }
    qDeleteAll(sprites);
}

void FrameManager::setAction(Action action) {
    if (currentAction != action) {
        currentAction = action;
        player->setPixmap(sprites[currentAction]->getFirstFrame());
    }
}

void FrameManager::updateFrame() {
    if (sprites.contains(currentAction)) {
        player->setPixmap(sprites[currentAction]->getNextFrame());
    }
}
