//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    
    void DFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited){
        if(visited[u]==true){
            return;
        }
        visited[u]=true;
        ans.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }    
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,vector<int>> adjacency_list;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                adjacency_list[i].push_back(adj[i][j]);
            }
        }
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            DFS(adjacency_list,i,visited);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends