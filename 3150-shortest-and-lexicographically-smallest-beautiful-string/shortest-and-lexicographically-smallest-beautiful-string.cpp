class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;

        // Store positions of all 1s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        // Not enough 1s
        if (pos.size() < k)
            return "";

        string ans = "";
        int bestLen = INT_MAX;

        // Take every group of k consecutive 1s
        for (int i = 0; i + k - 1 < pos.size(); i++) {

            int start = pos[i];
            int end = pos[i + k - 1];

            int len = end - start + 1;

            string cur = s.substr(start, len);

            if (len < bestLen) {
                bestLen = len;
                ans = cur;
            }
            else if (len == bestLen && cur < ans) {
                ans = cur;
            }
        }

        return ans;
    }
};