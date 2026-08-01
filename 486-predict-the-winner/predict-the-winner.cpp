class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case:
        // Only one number is left
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Length of subarray
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                // Pick left
                int pickLeft = nums[i] - dp[i + 1][j];

                // Pick right
                int pickRight = nums[j] - dp[i][j - 1];

                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};