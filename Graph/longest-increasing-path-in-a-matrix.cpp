class Solution {
public:
int delrow[4]={0,0,1,-1};
int delcol[4]={-1,1,0,0};
int n,m;
int dfs(int i, int j , vector<vector<int>>& matrix, vector<vector<int>>&dp){
      if(dp[i][j]!=-1) return dp[i][j];
      int maxi=1;
      for(int k=0 ;k<4;k++){
        int ni=i+delrow[k], nj=delcol[k]+j;
        if(ni>=0 && ni<n && nj>=0 && nj<m){
            if(matrix[ni][nj]>matrix[i][j]){
                maxi = max( maxi, 1+ dfs(ni,nj,matrix,dp));
            }
        }
      }
     return dp[i][j]=maxi;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(), m=matrix[0].size();
        int ans=1;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};