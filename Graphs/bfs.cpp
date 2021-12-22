#include<bits/stdc++.h>

using namespace std;

void BFS(int vertex,int A[][8],int n)
{
    queue<int>q; // initializing the queue data structure to track the vertex.
    int visited[8] = {0}; // means non of the vertex is visited by now.

    // inititalizing the visit from the given vertex
    cout << vertex << "," << flush;
    visited[vertex] = 1;
    q.emplace(vertex);

    // Now visting all other nodes in the graphs
    while(!q.empty())
    {
        int u = q.front(); // checking and exploring the vertices
        q.pop();
        for(int v = 1; v < n;v++)
        {
            if(A[u][v] == 1 && visited[v] == 0) // findig the adjacent vetices
            {
                cout << v << "," << flush;
                visited[v] = 1;
                q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main()
{
    int G[8][8] =  // the graph is same as the discussed in the lectures.
                {{0,0,0,0,0,0,0,0},
                {0,0,1,1,1,0,0,0},
                {0,1,0,1,0,0,0,0},
                {0,1,1,0,1,1,0,0},
                {0,1,0,1,0,1,0,0},
                {0,0,0,1,1,0,1,1},
                {0,0,0,0,0,1,0,0},
                {0,0,0,0,0,1,0,0}};

                cout << "BFS from vertex 1->-> " << flush;
                BFS(1,G,8);
                cout << "BFS from vertex 7->-> " << flush;
                BFS(7,G,8);
    return 0;
}