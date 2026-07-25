class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,
               vector<bool>& used, vector<int>& curr) {

        // Base case
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Skip duplicate
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // Choose
            used[i] = true;
            curr.push_back(nums[i]);

            // Recursion
            solve(nums, ans, used, curr);

            // Backtracking
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        solve(nums, ans, used, curr);

        return ans;
    }
};