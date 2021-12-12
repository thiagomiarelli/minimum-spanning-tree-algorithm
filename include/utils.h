#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include "Vertex.h"
#include "Edge.h"

using namespace std;


const int V = 6;
void Prim(float graph[V][V], int V);
Vertex selectMinVertex(vector<Vertex>& non_included_vertex);
bool isIncluded(int index, vector<Vertex>& included);
int findNode(int index, vector<Vertex>& included);