class Solution {
public:

bool f(int i, int j, int idx, string word, int m, int n,
       vector<vector<char>>& board) {

    if(idx == word.size()-1 && board[i][j]==word[idx])
        return true;

    if(board[i][j] != word[idx])
        return false;

    vector<int> x = {0, 0, 1, -1};
    vector<int> y = {1, -1, 0, 0};

    char temp = board[i][j];
    board[i][j] = '#';

    for(int k = 0; k < 4; k++) {
        int nx = i + x[k];
        int ny = j + y[k];

        if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
            if(f(nx, ny, idx + 1, word, m, n, board)) {
                board[i][j] = temp;
                return true;
            }
        }
    }

    board[i][j] = temp;
    return false;
}


    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>>start;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0]) {
                    if(f(i,j,0,word,m,n,board)) return true;
                }
            }
        }
        return false;

    }
};
