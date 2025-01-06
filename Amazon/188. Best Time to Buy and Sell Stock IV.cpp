
class Solution {
public:
    int solve(vector<int>& prices, int idx, int buy, int limit,
              vector<vector<vector<int>>>& dp) {
        if (idx >= prices.size())
            return 0;
        if (limit == 0)
            return 0;
        int profit = 0;
        if (dp[idx][buy][limit] != -1)
            return dp[idx][buy][limit];
        if (buy) {
            int pick = -prices[idx] + solve(prices, idx + 1, false, limit, dp);
            int skip = solve(prices, idx + 1, true, limit, dp);
            profit = max(pick, skip);
        } else {
            int pick =
                prices[idx] + solve(prices, idx + 1, true, limit - 1, dp);
            int skip = solve(prices, idx + 1, false, limit, dp);
            profit = max(pick, skip);
        }
        return dp[idx][buy][limit] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};
