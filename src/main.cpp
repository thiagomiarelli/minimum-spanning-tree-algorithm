#include <iostream>
#include "Store.h"
#include "utils.h"
#include <vector>


using namespace std;

int main(void){

    /*====== VARIABLES =======*/
    float graph[6][6];
    Store* stores[6];
    int N, K, D, M, C;
    int x, y;
    cin >> N >> K >> D >> M >> C;

    for(int i = 0; i < N ; i++){
        cin >> x >> y;
        stores[i] = new Store(i, x, y);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            graph[i][j] = stores[i] ->calcDistance(stores[j]);
        }
    }

    


    // MST
    Prim(graph, 6);



    cout << "Hello, World!";
}