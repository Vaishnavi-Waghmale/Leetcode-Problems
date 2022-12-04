class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        long long sum=nums[0];
        for(int i=1;i<n;i++){
            prefix[i-1]=sum;
            sum+=nums[i];
        }
        prefix[n-1]=sum;
        long long ind=0,minAvg=1000000000;
        for(int i=0;i<n-1;i++){
            long long sum1=prefix[i],sum2=sum-prefix[i];
            long long avg1=sum1/(i+1),avg2=sum2/(n-i-1);
            long long avg=abs(avg1-avg2);
            if(minAvg>avg){
                minAvg=avg;
                ind=i;
            }
        }
        int avg = sum/n;
        if(minAvg>avg){
            minAvg=avg;
            ind=n-1;
        }
        return ind;
    }
};
