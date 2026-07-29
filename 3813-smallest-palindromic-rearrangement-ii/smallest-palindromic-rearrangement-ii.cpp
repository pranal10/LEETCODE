class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Count characters available for left half
        vector<int> half(26, 0);
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
        }

        int n = 0;
        for (int x : half) {
            n += x;
        }

        // Calculate number of distinct permutations:
        // n! / (half[0]! * half[1]! * ...)
        //
        // We only need to know whether count >= k,
        // so cap the answer at k.
        auto countWays = [&](vector<int>& cnt) -> long long {
            long long ways = 1;
            int remaining = 0;

            for (int x : cnt) {
                remaining += x;
            }

            for (int x = 0; x < 26; x++) {
                for (int j = 1; j <= cnt[x]; j++) {
                    ways = ways * (remaining - cnt[x] + j) / j;

                    if (ways >= k) {
                        return k;
                    }
                }
                remaining -= cnt[x];
            }

            return ways;
        };

        // Check if total number of palindromes < k
        long long total = countWays(half);

        if (total < k) {
            return "";
        }

        string left = "";

        // Build left half one character at a time
        for (int pos = 0; pos < n; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) {
                    continue;
                }

                // Try placing character c
                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    // k-th permutation starts with c
                    left += char('a' + c);
                    break;
                }
                else {
                    // Skip all permutations starting with c
                    k -= ways;
                    half[c]++;
                }
            }
        }

        // Construct complete palindrome
        string right = left;
        reverse(right.begin(), right.end());

        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
                break;
            }
        }

        if (middle != 0) {
            return left + middle + right;
        }

        return left + right;
    }
};