
#include "utils.h"

//fazer com heap
Vertex selectMinVertex(vector<Vertex>& non_included_vertex){
    make_heap(non_included_vertex.begin(), non_included_vertex.end(), greater<Vertex>());
    pop_heap(non_included_vertex.begin(), non_included_vertex.end(), greater<Vertex>());
    Vertex U = non_included_vertex.back();
    non_included_vertex.pop_back();
    return U;
}


void Prim(float graph[V][V], int V){
    //int parent[V];
    vector <Vertex> non_included_vertex;
    vector <Vertex> included_vertex;
    vector <Edge> solution;
    non_included_vertex.push_back(Vertex(0,0));
    for (int i = 1; i < V; i++)
    {
       non_included_vertex.push_back(Vertex(i,INT_MAX));
    }

    make_heap(non_included_vertex.begin(), non_included_vertex.end(), greater<Vertex>());


    while (!non_included_vertex.empty())
    {
        Vertex U = selectMinVertex(non_included_vertex);
        for (int i = 0; i < non_included_vertex.size(); i++)
    {
        cout << non_included_vertex[i].index << ", ";
    }
     cout << endl;

    
        included_vertex.push_back(U);

        //problema: dps do update, o heap nao eh refeito

        for (int i = 0; i < V; i++)
        {
            if(isIncluded(i, non_included_vertex)){
                int V = findNode(i,non_included_vertex); //retorna o lugar do vertice de indice i na lista
                if(graph[U.index][i] < non_included_vertex[V].key){
                    non_included_vertex[V].key = graph[U.index][i];
                    non_included_vertex[V].parent = U.index;
                }
            }
        }


    }

    for (int i = 0; i < included_vertex.size(); i++)
    {
        solution.push_back(Edge(included_vertex[i].index, included_vertex[i].parent, included_vertex[i].key));
    }

    for (int i = 0; i < solution.size(); i++)
    {
        cout << "Vertex: " << solution[i].a << "-> " << solution[i].b << " | " << solution[i].distance <<  endl;
    }
    

    /* vector <Edge> solution;
    vector <Vertex> included;
    value.push(Vertex(0, 0));
    for (int i = 1; i < V; i++)
    {
       value.push(Vertex(i, INT_MAX));
    }

    
    vector <bool> setMST (V, false); // no node is included in MST

    // start node
    parent[0] = -1; //no parent to start node


    while(!value.empty()){
        Vertex U = value.top();
        included.push_back(U);
        
        for (int i = 0; i < V; i++)
        {
            if(!isIncluded(i, included) && graph[U.index][i] < )
        }
        


    }

    for(int i=0; i < V - 1; i++){
        Vertex U = value.top();

        cout << "U is " << U << endl;
        setMST[U] = true;
        

        for(int j = 0; j < V; j++){
            if(graph[U][j] != 0 && setMST[j] == false && graph[U][j] < value[j]){
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }

    }

    //print
    for(int i=1; i<V; i++){
        cout << "U->V: " << parent[i] << "->"<<i<< " wt= " << graph[parent[i]][i] <<endl;
    }
    */
}

bool isIncluded(int index, vector<Vertex>& included){
    for (int i = 0; i < included.size(); i++)
    {
        if(included[i].index == index)
            return true;
    }
    return false;
}

int findNode(int index, vector<Vertex>& included){
    for (int i = 0; i < included.size(); i++)
    {
        if(included[i].index == index)
            return i;
    }
    return -1;
}