class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            vector<int>temp(10,0);
            for(int j = 0;j<9;j++){
                if(board[i][j]!='.'){
                    temp[board[i][j]-'1']++;
                        if(temp[board[i][j]-'1']>1){
                            return false;
                        }
                }
            }
        }
        for(int i = 0;i<9;i++){
            vector<int>temp(10,0);
            for(int j = 0;j<9;j++){
                if(board[j][i]!='.'){
                    temp[board[j][i]-'1']++;
                        if(temp[board[j][i]-'1']>1){
                            return false;
                        }
                }
            }
        }
        for(int i = 0;i<9;i=i+3){
            for(int j = 0;j<9;j=j+3){
                vector<int>temp(10,0);
                for(int k = i;k<i+3;k++){
                    
                    for(int l = j;l<j+3;l++){
                        if(board[k][l]!='.'){
                        temp[board[k][l]-'1']++;
                        if(temp[board[k][l]-'1']>1){
                            return false;
                        }
                    }
                        
                    }
                }
            }
        }
        return true;
    }
};
