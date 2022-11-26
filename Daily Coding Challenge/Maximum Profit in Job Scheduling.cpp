class Solution {
private:
	typedef struct Interval {
		int start;
		int end;
		int profit;
	} Interval;
	static bool comp(Interval &A, Interval &B) {
		return A.start < B.start;
	}
public:
	int binary_search(vector<Interval> &intervals, int l, int h, int target) {
		int ans = h + 1;
		while(l <= h) {
			int m = l + (h - l) / 2;
			if(target > intervals[m].start) {
				l = m + 1;
			} else {
				ans = min(ans, m);
				h = m - 1;
			}
		}
		return ans;
	}
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();
		vector<Interval> intervals(n);
		for(int i = 0; i < n; i++) {
			intervals[i].start = startTime[i];
			intervals[i].end = endTime[i];
			intervals[i].profit = profit[i];
		}
		sort(intervals.begin(), intervals.end(), comp);
		vector<int> DP(n + 1, 0);
		for(int i = n - 1; i >= 0; i--) {
			int index = binary_search(intervals, i + 1, n - 1, intervals[i].end);
			DP[i] = max(DP[i + 1], intervals[i].profit + DP[index]);
		}
		return DP[0];
	}
};
