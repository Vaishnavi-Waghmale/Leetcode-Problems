class Solution {
public:
    int reverse(int x) {
        int ans =0;
        int digit;
        while(x!=0){
            digit = x%10;  //getting remainder
            if((ans>INT_MAX/10) || (ans<INT_MIN/10)){  //Required for the Limit conditions
                return 0;
            }
            ans = (ans*10)+ digit;  //update ans
            x= x/10;   //update x
        }
        return ans;    //cout ans
    }
};
