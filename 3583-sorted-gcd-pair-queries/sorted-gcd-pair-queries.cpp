class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1, 0);

        // count pairs divisible by d
        for (int d = 1; d <= mx; d++) {
            long long cnt = 0;
            for (int j = d; j <= mx; j += d)
                cnt += freq[j];
            exact[d] = cnt * (cnt - 1) / 2;
        }

        // inclusion exclusion
        for (int d = mx; d >= 1; d--) {
            for (int j = d + d; j <= mx; j += d)
                exact[d] -= exact[j];
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {
            int x = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(x);
        }

        return ans;
    }
};