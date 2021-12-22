#include<bits/stdc++.h>

using namespace std;
int visited[8];
void initialize() // declared in this way to use multiple times
{ // if static is used in the recursive function then it can be used only once
    for(int i = 0; i <8;i++)
        visited[i] =0;
}

void DFS(int vertex,int G[][8],int n) // We can also pass the double pointer for the graph
{
    int i;
    if(visited[vertex] == 0)
    {
        cout << vertex << " " << flush;
        visited[vertex] = 1;
        for( i = 1;i< n;i++)
        {
            if(G[vertex][i] == 1 && visited[i] == 0)
            {
                DFS(i,G,n);
            }
        }
    }
}

int main (){
 
    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    initialize();
    cout << "Vertex: 1 -> " << flush;
    DFS(1, G, 8);
 
   cout << "\nVertex: 4 -> " << flush;
   initialize();
    DFS(4, G, 8);
    cout << endl;
 
    return 0;
}