class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>mp ;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])) return true ;
            mp.insert(nums[i]);
            

        }
        return false ;
        
    }
};