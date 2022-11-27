#define ll long long

class Solution
{
public:
  int numberOfArithmeticSlices(vector<int> &nums)
  {
    int ret = 0;
    int n = nums.size();
    vector<unordered_map<ll, int>> dp(n);
    for (int i = 1; i < n; i++)
      for (int j = 0; j < i; j++)
      {
        ll diff = (ll)nums[i] - (ll)nums[j];
        int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
        dp[i][diff] += cnt + 1;
        ret += cnt;
      }
    return ret;
  }
};
