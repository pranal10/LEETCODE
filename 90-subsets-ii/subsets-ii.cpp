class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index, vector<int>& output) {

        // Every subset is a valid answer
        ans.push_back(output);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Choose
            output.push_back(nums[i]);

            // Explore
            solve(nums, i + 1, output);

            // Backtrack
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Important: Put duplicates together
        sort(nums.begin(), nums.end());

        vector<int> output;

        solve(nums, 0, output);

        return ans;
    }
};