class Solution {
public:
vector <string> ans ;
void solve(int open ,int close , int n ,string curr){
// base case 
if(curr.length()==2*n){
    ans.push_back(curr);
    return ;
}
// length se bada open bracket hojaye
if(open<n){
    solve(open+1,close , n ,curr+'(') ;
}
// close  open se bada na ho 
if(close<open){
    solve(open ,close+1,n,curr+')');

}
}
    
    
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return ans ;

        
        
    }
};