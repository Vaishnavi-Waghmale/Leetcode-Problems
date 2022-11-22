class Solution {
public:

    int ubks(vector<int> &sq,vector<vector<int>> &dp,int num,int sz){
        if(sz==0){
            if(num==0) return 0;
            return INT_MAX-1;
        }
        if(dp[sz][num] != -1) return dp[sz][num];

        if(num >= sq[sz-1]){
            return dp[sz][num] = min(1 + ubks(sq,dp,num-sq[sz-1],sz) , ubks(sq,dp,num,sz-1));
        }
        return dp[sz][num] = ubks(sq,dp,num,sz-1);
    }

    int numSquares(int n) {
        vector<int> sq;
        int hn = pow(n,0.5);
        for(int i=1;i<=hn;i++){
            sq.push_back(i*i);
        }
        int sz = sq.size();

        vector<vector<int>> dp(sz+1,vector<int>(n+1,-1));
        return ubks(sq,dp,n,sz);
    }
};
