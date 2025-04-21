// https://leetcode.com/problems/super-egg-drop/description/

// Time Complexity: O(n*n*k)
// Space Complexity: O(n*k)


class Solution {
    public:
        int superEggDrop(int k, int n) {
            vector<vector<int>> dp(k+1, vector<int>(n+1,0));
            for (int j = 1; j <= n; j++) {
                dp[1][j] = j;      
            }
            for(int i=2; i<=k; i++){
                for(int j=1; j<=n; j++){
                    dp[i][j] = INT_MAX;
                    for(int a=1; a<=j; a++){
                        int temp = 1 + max(dp[i-1][a-1], dp[i][j-a]);
                        dp[i][j] = min(dp[i][j],temp);
                    }
                }
            }
            return dp[k][n];
        }
    };


// Time Complexity: O(k log n)
// Space Complexity: O(n*k)


class Solution {
    public:
        int superEggDrop(int k, int n) {
            vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
            int m = 0;
            while(dp[m][k] < n){
                m++;
                for(int j=1; j<=k; j++){
                    dp[m][j] = 1+dp[m-1][j-1]+dp[m-1][j];
                }
            }
    
            return m;
        }
    };
