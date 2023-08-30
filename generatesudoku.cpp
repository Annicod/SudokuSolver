#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

const int N = 9;

// FUNCTION FOR CREATING SMAPLE SUDOKU

void generatesudoku(vector<vector<int>> &sdk)
{
    for (int i = 0; i < N; i += 3)
    {
        for (int j = 0; j < N; j += 3)
        {
            vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            random_shuffle(nums.begin(), nums.end());
            int numIndex = 0;
            for (int x = i; x < i + 3; x = x + 1)
            {
                for (int y = j; y < j + 3; y = y + 1)
                {
                    sdk[x][y] = nums[numIndex++];
                }
            }
        }
    }
}

// FUNCTION FOR CREATING EMPTY SPACES

void removeBlocks(vector<vector<int>>& sdk, int block){
   random_device rand;
   mt19937 gen(rand());
   uniform_int_distribution<int> dis(0, N - 1);

    while (block > 0) {
        int row = dis(gen);
        int col = dis(gen);
        if (sdk[row][col] != 0) {
            sdk[row][col] = 0;
            --block;
        }
    }
}

// FUNCTION FOR PRINTING SUDOKU

void print(vector<vector<int>>& sdk){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sdk[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
     vector<vector<int>> sudoku1(N, vector<int>(N, 0));
     generatesudoku(sudoku1);
     int block;
     cout<<"Enter the  desiered empty blocks : "<<endl;
     cin>>block;
     removeBlocks(sudoku1,block);
     print(sudoku1);


    return 0;
}