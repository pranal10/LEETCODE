class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                cnt1++;
            } else {
                sum += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                cnt2++;
            } else {
                sum -= num[i] - '0';
            }
        }

        // Equal number of '?' on both sides
        if (cnt1 == cnt2) {
            return sum != 0;
        }

        // Difference in number of '?' is odd
        if (abs(cnt1 - cnt2) % 2 == 1) {
            return true;
        }

        int required = 9 * (cnt2 - cnt1) / 2;

        return sum != required;
    }
};