class Solution {
public:
    void solve(string &s, int i, long long &ans) {
        // Base case
        if (i >= s.size() || !isdigit(s[i]))
            return;

        int digit = s[i] - '0';

        // Overflow check
        if (ans > INT_MAX / 10 ||
            (ans == INT_MAX / 10 && digit > 8)) {
            ans = (long long)INT_MAX + 1;
            return;
        }

        ans = ans * 10 + digit;

        solve(s, i + 1, ans);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Skip leading zeros
        while (i < n && s[i] == '0')
            i++;

        long long ans = 0;

        solve(s, i, ans);

        ans *= sign;

        if (ans > INT_MAX)
            return INT_MAX;

        if (ans < INT_MIN)
            return INT_MIN;

        return (int)ans;
    }
};