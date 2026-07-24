class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // Find maximum value
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
        }

        // XOR values will be less than 2^(bits)
        int size = 1;
        while (size <= mx) {
            size <<= 1;
        }

        vector<bool> present(size, false);

        // Remove duplicates
        for (int x : nums) {
            present[x] = true;
        }

        vector<int> values;

        for (int i = 0; i < size; i++) {
            if (present[i]) {
                values.push_back(i);
            }
        }

        // All possible XOR of two numbers
        vector<bool> two(size, false);

        for (int x : values) {
            for (int y : values) {
                two[x ^ y] = true;
            }
        }

        // XOR third number
        vector<bool> three(size, false);

        for (int x = 0; x < size; x++) {
            if (!two[x])
                continue;

            for (int y : values) {
                three[x ^ y] = true;
            }
        }

        int ans = 0;

        for (bool x : three) {
            if (x)
                ans++;
        }

        return ans;
    }
};
