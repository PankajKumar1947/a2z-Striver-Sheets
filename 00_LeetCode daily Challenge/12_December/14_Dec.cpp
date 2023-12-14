//2482. Difference Between Ones and Zeros in Row and Column
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();

        vector<int> row,col;
        //pushing number of ones in row
        for(int i=0;i<grid.size();i++){
            int cntOne=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    cntOne++;
            }
            row.push_back(cntOne);
        }
        //pushing number of ons in column
        for(int i=0;i<grid[0].size();i++){
            int cntOne=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1)
                    cntOne++;
            }
            col.push_back(cntOne);
        }

        //Now finding the required 
        vector<vector<int>>ans(rowSize);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int rowZero=rowSize-row[i];
                int colZero=colSize-col[j];
                int temp=row[i] + col[j] - rowZero - colZero;
                ans[i].push_back(temp);
            }
        }

        return ans;

    }
};