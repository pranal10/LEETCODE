class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        // Count frequency
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        string middle = "";

        // Build the first half
        for (int i = 0; i < 26; i++) {

            // Add half of each character
            for (int j = 0; j < freq[i] / 2; j++) {
                left += char('a' + i);
            }

            // Odd frequency character becomes middle
            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
            }
        }

        // Create reverse of left
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};