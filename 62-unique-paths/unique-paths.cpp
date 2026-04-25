class Solution {
public:

    int getId(int i, int j, int n){
        return i * n + j;
    }

    int dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& dp){
        if(node == dest) return 1;

        if(dp[node] != -1) return dp[node];

        int ways = 0;
        for(int nxt : adj[node]){
            ways += dfs(nxt, dest, adj, dp);
        }

        return dp[node] = ways;
    }

    int uniquePaths(int m, int n) {
        int total = m * n;
        vector<vector<int>> adj(total);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int u = getId(i, j, n);

                if(i + 1 < m)
                    adj[u].push_back(getId(i + 1, j, n));

                if(j + 1 < n)
                    adj[u].push_back(getId(i, j + 1, n));
            }
        }

        vector<int> dp(total, -1);

        int src = 0;
        int dest = getId(m - 1, n - 1, n);

        return dfs(src, dest, adj, dp);
    }
};