#include "obstacle.h"
#include <QBrush>
#include <QPen>

Obstacle::Obstacle() {
    setBrush(QBrush(Qt::blue));
    setPen(QPen(Qt::black));
    setRect(0, 0, 30, 30);
}

void Obstacle::advance(int step) {
    if (!step) return;

    moveBy(-5, 0); // Bewegung nach links
    if (x() < -30) {
        setX(800); // Zurücksetzen des Hindernisses
    }
}
