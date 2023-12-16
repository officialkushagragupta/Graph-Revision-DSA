/*
Done through both DFS and BFS.
*/

#include <bits/stdc++.h>
using namespace std;


//DFS
class Solution {
  public:
    bool dfsCycleCheck(int i, vector<bool> &visited, vector<int> adj[], vector<bool> &inRecursion) {
        visited[i] = true;
        inRecursion[i] = true;

        for (int neighbour : adj[i]) {
            if (visited[neighbour]==false && dfsCycleCheck(neighbour, visited, adj, inRecursion)) {
                return true;
            } else if (inRecursion[neighbour]) {
                return true;
            }
        }

        inRecursion[i] = false; // backtracking
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfsCycleCheck(i, visited, adj, inRecursion)) {
                return true;
            }
        }
        return false;
    }
};

//BFS -> using Kahn's Algo

bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        vector<bool> visited(V,false);
        queue<int> q;
        
        for(int i=0;i<V;i++){
            for(int v:adj[i]){
                indegree[v]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int count=0;
        while(!q.empty()){
            int f=q.front();
            count++;
            q.pop();
            for(int &v:adj[f]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
            
        }
        
        if(count==V){
            return false;
        }
        else{
            return true;
        }
    }



int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends