#include "Store.h"

Store::Store(int id, int x, int y){
    this->id = id;
    this->x = x;
    this->y = y;
    this->pi = INFINITY;
}

float Store::calcDistance(Store* a){
    return sqrt(pow(this->x - a->x, 2) + pow(this->y - a->y, 2));
}