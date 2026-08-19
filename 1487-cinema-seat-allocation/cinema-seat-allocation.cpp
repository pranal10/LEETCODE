class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask.
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 through 9 affect our answer.
            if (col >= 2 && col <= 9) {
                rows[row] |= (1 << col);
            }
        }

        // Initially every completely empty row can fit 2 groups.
        int ans = 2 * (n - rows.size());

        for (auto &[row, mask] : rows) {
            bool left = (mask & ((1 << 2) | (1 << 3) |
                                (1 << 4) | (1 << 5))) == 0;

            bool middle = (mask & ((1 << 4) | (1 << 5) |
                                  (1 << 6) | (1 << 7))) == 0;

            bool right = (mask & ((1 << 6) | (1 << 7) |
                                  (1 << 8) | (1 << 9))) == 0;

            if (left && right) {
                ans += 2;
            } 
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};