class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n),right(n);
        stack<pair<int,int>> st;
        int count = 0;
        for(int i=0;i<n;i++){
            count = 1;
            while(!st.empty() && st.top().first > arr[i]){
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i],count});
            left[i] = count;
        }
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--){
            count = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i],count});
            right[i] = count;
        }
        long long res=0;
        int mod = 1e9+7;
        for(int i=0;i<n;i++)
            res += left[i]*right[i]*(long)arr[i];
        return res%mod;
    }
};
