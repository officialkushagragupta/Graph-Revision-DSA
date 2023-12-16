/*
Done through both DFS and BFS.
*/



class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // bool bfs(int i,vector<bool> &visited, vector<int> adj[]){
    //     queue<int> q;
    //     q.push(i);
    //     visited[i]=true;
        
    //     while(!q.empty()){
            
    //         int u = q.front();
    //         q.pop();
            
    //         for(int neighbour:adj[u]){
    //             if(!visited[neighbour]){
    //                 visited[neighbour] = true;
    //                 q.push(neighbour);
    //             }
    //             else if(neighbour!=i){
    //                 return true;
    //             }
    //         }
            
    //     }
    //     return false;
    // }
    
    bool bfs(int i, vector<bool> &visited, vector<int> adj[]) {
        queue<pair<int,int>> q;
        q.push(make_pair(i,-1));
        visited[i] = true;
    
        while (!q.empty()) {
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
    
            for (int neighbour : adj[u]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(make_pair(neighbour,u));
                } else if (neighbour != parent) {
                    // If the neighbor is already visited and not the parent, there is a cycle.
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int parent, vector<bool> &visited, vector<int> adj[]) {
        visited[i] = true;
        for (int &neighbour : adj[i]) {
            if (neighbour == parent) {
                continue;
            }
            if (visited[neighbour]) {
                return true;
            }
            if (dfs(neighbour, i, visited, adj)) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && bfs(i,visited, adj)) {
                return true;
            }
        }

        return false;
    }
};