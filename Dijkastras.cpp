/*
Vertices,edges
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    //Create Adjacency List
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices,INT_MAX);
    dist[source] = 0;

    set<pair<int,int>> st;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //Fetch top node
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top node now
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                // if record found  -> erase it
                if(record!=st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 4;
    int edges = 5;
    int source = 0;

    vector<vector<int>> vec = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 2, 9},
        {1, 3, 2},
        {2, 3, 6}
    };

    vector<int> result = dijkstra(vec, vertices, edges, source);

    // Output the distances from the source
    for(int i = 0; i < vertices; i++) {
        cout << "Distance to vertex " << i << ": " << result[i] << endl;
    }

    return 0;
}
