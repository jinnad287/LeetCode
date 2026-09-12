class Solution {
public:
    void DFS(int u, bool& isComponent, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[u] == true){
            return;
        }

        isComponent = true;// new component

        visited[u] = true;

        for(int &v: adj[u]){
            if(!visited[v]){
                DFS(v, isComponent, adj, visited);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // adjacency list
        vector<vector<int>> adj(n);
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int no_of_components = 0;
        vector<bool> visited(n, false);
        for(int u = 0; u<n; ++u){
            bool isComponent = false;
            DFS(u, isComponent, adj, visited);

            if(isComponent){
                no_of_components++;
            }
            
        }

        return no_of_components;
    }
};