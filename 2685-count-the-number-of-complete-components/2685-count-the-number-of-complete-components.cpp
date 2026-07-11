class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // 1. Build Adjacency List
        vector<vector<int>> adj(n);
        for(auto& vertex: edges){
            int u = vertex[0];
            int v = vertex[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2. Track Visited Node
            vector<bool> visited(n, false);
            int complete_components = 0;

        // 3. Loop + BFS 
        for(int i = 0; i<n; ++i){
            if(!visited[i]){
                int vertex = 0;
                int degree_sum = 0;

                //BFS
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    vertex++;
                    degree_sum += adj[curr].size();
                    // Visit all the neighbour of of curr node
                    for(int& neighbor : adj[curr]){
                        if(!visited[neighbor]){
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Verify if the component is complete --> HandShaking Theorem
                // sum of degree of all vertices = 2 * Emax
                if(degree_sum == vertex * (vertex - 1)){
                        complete_components++;
                }

            }
        }

        return complete_components;

    }
        
};