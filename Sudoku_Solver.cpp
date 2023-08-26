#include<iostream>
#include<vector>
using namespace std;

bool isvalid(char ch,vector<vector<char>>& board,int r, int c){
        //checking row
        for(int j=0; j<9; j++){
            if(board[r][j]==ch)return false;
        }
        //checking col
        for(int i=0; i<9; i++){
            if(board[i][c]==ch)return false;
        }
        //checking 3x3 box
        if(r>=0 && r<=2){
            if(c>=0 && c<=2){
                for(int i=0; i<=2; i++){
                    for(int j=0; j<=2; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
            else if(c>=3 && c<=5){
                for(int i=0; i<=2; i++){
                    for(int j=3; j<=5; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
            else{
                for(int i=0; i<=2; i++){
                    for(int j=6; j<=8; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
        }
        else if(r>=3 && r<=5){
            if(c>=0 && c<=2){
                for(int i=3; i<=5; i++){
                    for(int j=0; j<=2; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
            else if(c>=3 && c<=5){
                for(int i=3; i<=5; i++){
                    for(int j=3; j<=5; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
            else{
                for(int i=3; i<=5; i++){
                    for(int j=6; j<=8; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
        }
        else{
            if(c>=0 && c<=2){
                for(int i=6; i<=8; i++){
                    for(int j=0; j<=2; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
            else if(c>=3 && c<=5){
                for(int i=6; i<=8; i++){
                    for(int j=3; j<=5; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
            else{
                for(int i=6; i<=8; i++){
                    for(int j=6; j<=8; j++){
                        if(board[i][j]==ch)return false;
                    }
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int c=0; c<9; c++){
                if(board[i][c]=='.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isvalid(ch,board,i,c)){
                            board[i][c]=ch;
                            if(solve(board))return true;
                            else{
                                board[i][c]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        if(solve(board))return true;

        return false;
    }

int main(){

    vector<vector<char>> grid;

    
    grid.push_back({'5','3','.','.','7','.','.','.','.'});
    grid.push_back({'6','.','.','1','9','5','.','.','.'});
    grid.push_back({'.','9','8','.','.','.','.','6','.'});
    grid.push_back({'8','.','.','.','6','.','.','.','3'});
    grid.push_back({'4','.','.','8','.','3','.','.','1'});
    grid.push_back({'7','.','.','.','2','.','.','.','6'});
    grid.push_back({'.','6','.','.','.','.','2','8','.'});
    grid.push_back({'.','.','.','4','1','9','.','.','5'});
    grid.push_back({'.','.','.','.','8','.','.','.','9'});


    if (solveSudoku(grid)){

        cout<<endl;
        
        cout<< " YES ! Solution exists"<<endl;

        cout<<endl;

        for(int i=0; i<9; i++){

            for(int j=0; j<9 ; j++){
                cout<<"  "<<"---"<<"  ";
            }
            cout<<endl;
            
            for(int j=0; j<9 ; j++){
                cout<<" | "<<grid[i][j]<<" | ";
            }
            cout<<endl;
        }
        for(int j=0; j<9 ; j++){
            cout<<"  "<<"---"<<"  ";
        }
    }
    else
      cout << "No solution exists";
}



