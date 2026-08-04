class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int mn = INT_MAX;
        int mx = INT_MIN;

        // Find minimum and maximum
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        // Store existing numbers
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        vector<int> ans;

        // Check complete range
        for (int x = mn; x <= mx; x++) {
            if (st.find(x) == st.end()) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};