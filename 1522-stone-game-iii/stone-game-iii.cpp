class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            dp[i] = INT_MIN;

            int sum = 0;

            // Try taking 1, 2, or 3 stones
            for (int j = i; j < min(n, i + 3); j++) {

                sum += stoneValue[j];

                // Current player takes i...j
                // Opponent starts from j+1
                dp[i] = max(dp[i],
                            sum - dp[j + 1]);
            }
        }

        if (dp[0] > 0) {
            return "Alice";
        }

        if (dp[0] < 0) {
            return "Bob";
        }

        return "Tie";
    }
};