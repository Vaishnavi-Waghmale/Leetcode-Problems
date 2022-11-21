class Solution {
public:
    int arri[4] = {-1, 0, 1, 0};
    int arrj[4] = {0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = 1;

        while(q.size()){
            pair<int, int> temp = q.front(); q.pop();

            for(int k=0; k<4; k++){
                int i = arri[k] + temp.first;
                int j = arrj[k] + temp.second;

                if(i>=0 && j>=0 && i<n && j<m && !visited[i][j] && maze[i][j] == '.'){
                    visited[i][j] = visited[temp.first][temp.second]+1;
                    q.push({i, j});
                    // if exit cell found
                    if(i == 0 || j == 0 || i == n-1 || j == m-1) return visited[i][j]-1;
                }
            }
        }

        // if reached here it means no exit found
        return -1;

    }
};
