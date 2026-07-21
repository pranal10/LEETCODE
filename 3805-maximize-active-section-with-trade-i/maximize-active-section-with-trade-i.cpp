class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int ones = 0;
        int prevZero = -1;
        int maxGain = 0;

        int i = 0;

        while (i < n) {
            int j = i;

            // Find length of current group
            while (j < n && s[j] == s[i]) {
                j++;
            }

            int len = j - i;

            if (s[i] == '1') {
                ones += len;
            }
            else {
                // Current group is zeros
                if (prevZero != -1) {
                    maxGain = max(maxGain, prevZero + len);
                }

                prevZero = len;
            }

            i = j;
        }

        return ones + maxGain;
    }
};