
class Vertex{
    public:
        Vertex(int index, float key){this->index = index; this->key = key;};
        friend bool operator > (Vertex a, Vertex b){
            return a.key > b.key;
        }
        friend bool operator < (Vertex a, Vertex b){
            return a.key < b.key;
        }

        friend bool operator <= (Vertex a, Vertex b){
            return a.key <=  b.key;
        }

        friend bool operator >= (Vertex a, Vertex b){
            return a.key >=  b.key;
        }

        int index;
        float key;
        bool discovered = false;
        int parent = -1;
};
