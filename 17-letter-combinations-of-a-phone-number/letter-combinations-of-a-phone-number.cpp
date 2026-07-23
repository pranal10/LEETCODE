class Solution {
public:
vector<string>ans ;
vector<string>numbers ={
  "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
} ;
void solve(string &digits,int index,string output){
    //base case 
    if(index==digits.length()){
        ans.push_back(output) ;
        return ;
    }
    //now explore 
    int digit=digits[index]-'0' ;// for finding digit instead of string 
    // traverse whole loop 
    for(int i=0;i<numbers[digit].size();i++){
        output.push_back(numbers[digit][i]) ;
        //abb recurson se flow agge badhao 
        solve(digits,index+1,output);
        //abb backtracking se ek case ke baad naye case ko traverse krenge 
        output.pop_back() ;
    }
}

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {} ;
        solve(digits,0,"") ;
        return ans ;
        
    }
};