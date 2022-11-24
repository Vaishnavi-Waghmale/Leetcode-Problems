class Solution {
public:
    bool dfs(int i,int j,int count,string word,int n,int m,vector<vector<char>> &board){
        if(count==word.size())
        return true;
        if(i<0 || j<0 || i==n || j==m || word[count]!=board[i][j])
        return false;

        int delr[] = {-1,1,0,0};
        int delc[] = {0,0,-1,1};
        char temp = board[i][j];
        board[i][j] = '*';
        for(int k = 0;k<4;k++){
            int nrow  = i + delr[k];
            int ncol = j + delc[k];
            bool found = dfs(nrow,ncol,count+1,word,n,m,board);
            if(found)
            return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        char c = word[0];
        
        int wordSize = word.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]==c && dfs(i,j,0,word,n,m,board))
                return true;
            }
        }
       return false;
    }
};
