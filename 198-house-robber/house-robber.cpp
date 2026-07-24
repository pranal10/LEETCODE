class Solution {
public:
    int rob(vector<int>& nums) {
        int first_house=0 ;
        int second_house=0 ;
        for(int i=0;i<nums.size();i++){
            int robb=max(second_house,first_house+nums[i]);
            first_house=second_house ;
            second_house=robb ;
        }
        return second_house ;

        
    }
};