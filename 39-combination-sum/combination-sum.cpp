class Solution {
public:
void solve(vector<int>& candidates, int target,int index, vector<vector<int>>&ans,
        vector<int>&output) {
            if(target==0){
                ans.push_back(output) ;
                return ;
            }
            if(index==candidates.size()|| target<0){
                return ;
            }
            // ab include wla case ans to phele store krenge phir sare cases use krke excllude krdenge last me 
            output.push_back(candidates[index]) ;
            solve(candidates ,target-candidates[index],index,ans ,output) ;
            output.pop_back() ;
            // abb exclude wala case 
            solve(candidates,target,index+1,ans,output) ;
            

        }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans ;
        vector<int>output ;
        solve(candidates,target,0,ans,output) ;
        return ans ;
        
    }
};