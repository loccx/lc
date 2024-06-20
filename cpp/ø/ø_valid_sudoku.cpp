class Solution {
private:
    bool checkrow(char num,int k,int i,vector<vector<char>>& board){
        for(int x=0;x<int(board.size());x++){
            if(x!=i && board[k][x] == num)return false;
        }
        return true;
    }

    bool checkcol(char num,int k,int i,vector<vector<char>>& board){
        for(int x=0;x<int(board.size());x++){
            if(x!=k && board[x][i] == num)return false;
        }
        return true;
    }

    bool checksq(char num,int k,int i,vector<vector<char>>& board){
        int kq=k/3;
        int iq=i/3;
        kq*=3;
        iq*=3;
        for(int x=kq;x<kq+3;x++){
            for(int y=iq;y<iq+3;y++){
                if(x!=k && y!=i && board[x][y] == num)return false;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int k=0;k<int(board.size());k++){
            for(int i=0;i<int(board[0].size());i++){
                char curr = board[k][i];
                if(curr!='.' && (!checkrow(curr,k,i,board)||!checkcol(curr,k,i,board)||!checksq(curr,k,i,board)))return false;
            }
        }
        return true;
    }
};
