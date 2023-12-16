#include<bits/stdc++.h>
using namespace std;

int bellmanFord(int n,int m,int src,int dest,vector<vector<int>> &edges){
    vector<int> dist(n+1,1e9);
    dist[src] = 0;

    for(int i=1;i<=n;i++){
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
        

        if(dist[u] != 1e9 && (dist[u] + wt < dist[v])){
            dist[v] = dist[u] + wt;
        }
        
        
        }
    
    }
    

    //check for negative cycle
    bool flag=0;
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        
        if(dist[u] != 1e9 && (dist[u] + wt < dist[v])){
            flag=1;
        }
        

    }

    if(flag){
        return dist[dest];
    }
    else{
        return -1;
    }
}


int main() {
    int n = 5; // Number of vertices
    int m = 8; // Number of edges
    int src = 0;
    int dest = 4;

    // Edge list (u, v, wt)
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 2, 9},
        {1, 3, 2},
        {2, 3, 6},
        {3, 1, -7},  
        {2, 4, 4},
        {3, 4, 3}
    };

    int shortestPath = bellmanFord(n, m, src, dest, edges);

    if (shortestPath == -1) {
        cout << "Negative cycle detected." << endl;
    } else {
        cout << "Shortest Path from " << src << " to " << dest << ": " << shortestPath << endl;
    }

    return 0;
}