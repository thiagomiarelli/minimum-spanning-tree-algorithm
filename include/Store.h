#include <math.h>
class Store{
    public:
        Store(int id, int x, int y);
        float calcDistance(Store* a);
        int id;
        int x;
        int y;
        int pi;
};