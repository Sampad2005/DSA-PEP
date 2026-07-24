class Solution {
    int f(int i, int j, vector<vector<int>>& tri, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || j > i) return 1e9;
        if (i == 0 && j == 0) return tri[i][j];
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int up = f(i-1, j, tri, dp);
        int diag = f(i-1, j-1, tri, dp);
        
        return dp[i][j] = min(up, diag) + tri[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        int minC = INT_MAX;
        
        for (int j = 0; j < m; j++) {
            minC = min(minC, f(m-1, j, triangle, dp));
        }
        return minC;
    }
};