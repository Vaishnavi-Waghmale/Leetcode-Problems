class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<matches.size(); i++){
            if(mp.find(matches[i][0]) != mp.end()){
                mp[matches[i][0]][0] += 1;
            }else{
                mp[matches[i][0]] = {1,0};
            }

            if(mp.find(matches[i][1]) != mp.end()){
                mp[matches[i][1]][1] +=1;
            }else{
                mp[matches[i][1]] = {0,1};
            }
        }

        vector<vector<int>> ans;
        vector<int> winners;
        vector<int> runner;

        for(auto it: mp){
            if(it.second[1] == 0) winners.push_back(it.first);
            if(it.second[1] == 1) runner.push_back(it.first);
        }
        sort(winners.begin(), winners.end());
        sort(runner.begin(), runner.end());

        ans.push_back(winners);
        ans.push_back(runner);
        return ans;
    }
};
