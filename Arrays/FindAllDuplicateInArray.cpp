class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i < n;i++) {
            int num = abs(nums[i]);

            if (nums[num-1] < 0) res.push_back(num);
            else nums[num-1] *= -1;
        }
        
        return res;
    }
};
