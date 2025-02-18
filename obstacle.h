#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsRectItem>

class Obstacle : public QGraphicsRectItem {
public:
    Obstacle();
    void advance(int step) override;
};

#endif // OBSTACLE_H
