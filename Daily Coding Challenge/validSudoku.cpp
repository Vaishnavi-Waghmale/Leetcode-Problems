class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10][10]={0},col[10][10]={0},box[10][10]={0};
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0';
                    if(row[i][num]||col[j][num]||box[(i/3)*3+j/3][num])
                        return false;
                    row[i][num]=col[j][num]=box[(i/3)*3+j/3][num]=1;
                }
            }
        }
        return true;
    }
};
