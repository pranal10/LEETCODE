class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort by start ascending; if starts are equal, by end DESCENDING
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int count = 0;
        int maxEnd = 0;
        
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            if (end > maxEnd) {
                count++;
                maxEnd = end;
            }
            // else: this interval is covered, skip it
        }
        
        return count;
    }
};