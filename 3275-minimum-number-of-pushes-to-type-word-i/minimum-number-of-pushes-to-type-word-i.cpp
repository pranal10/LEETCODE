class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int ans = 0;
        int push = 1;

        // Every 8 characters can be placed
        // at the same push level
        while (n >= 8) {
            ans += 8 * push;
            n -= 8;
            push++;
        }

        // Remaining characters
        ans += n * push;

        return ans;
    }
};