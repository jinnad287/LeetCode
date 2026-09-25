class Solution {
public:
    // DFS
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state){
        if(state[node] != 0){
            return state[node] == 2;
        }

        state[node] = 1;
        
        for(int neighbor : graph[node]){
            // if any path leads to a cycle or an unsafe node, this node is also unsafe
            if(!dfs(neighbor, graph, state)){
                return false;
            }
        }
        
        // if no cycle dectected then ---> marking as safe node and returning "true"
        state[node] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // state array to track the status of each node
        // 0 = unvisited
        // 1 = visiting (currently in the recursion stack)
        // 2 = safe
        vector<int> state(n, 0); 
        vector<int> safe_nodes;
        
        // run dfs from every node
        for(int i = 0; i < n; ++i){
            if(dfs(i, graph, state)){
                safe_nodes.push_back(i);
            }
        }
        
        return safe_nodes;
    }
};