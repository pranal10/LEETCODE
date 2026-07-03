class Solution {
public:
    int reverse(int x) {
        int temp=0;
         int reverse=0;
       
        
         while(x!=0){
        temp=x%10;
         // Check for overflow
            if (reverse> INT_MAX / 10 || (reverse == INT_MAX / 10 &&temp > 7))
                return 0;

            // Check for underflow
            if (reverse < INT_MIN / 10 || (reverse== INT_MIN / 10 && temp < -8))
                return 0;
        reverse=reverse*10+temp;
       
        x=x/10;

         }
       
        
         return reverse;
        
    }
};