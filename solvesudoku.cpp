#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "generatesudoku.cpp"
using namespace std;
const int N=9;

bool isSafe(int row,int col,vector<vector<int>> &board,int value){
    for(int i=0;i<N;i++){
        // row check
        if(board[row][i]==value)
        return false;
        // column check
        if(board[i][col]==value)
        return false;
        // 3*3 matrics check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value)
        return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(board[row][col]==0){
                for(int value=1;value<=9;value++){
                    if(isSafe(row,col,board,value)){
                        board[row][col]=value;
                        bool nextSol=solve(board);
                        if(nextSol){
                            return true;
                        }
                        else{
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// PRINTING SUDOKU

void print(vector<vector<int>>& sdk){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sdk[i][j]<<" ";
        }
        cout<<endl;
    }
}





