#include <iostream>
#include <vector>

using namespace std;

void visited(int x, int y, vector<vector<char>> &grid){
    
    // Garante limites para a recursão
    if(
        x < 0 || x >= static_cast<int>(grid.size()) ||    // Limites da linha
        y < 0 || y >= static_cast<int>(grid[0].size()) || // Limites da coluna
        grid[x][y] == '0'                                 // Limite de valor
    ) return; 

    grid[x][y] = '0';

    visited(x-1, y, grid);
    visited(x+1, y, grid);
    visited(x, y+1, grid);
    visited(x, y-1, grid);
}

int numIslands(vector<vector<char>>& grid) {

    int m = grid.size();
    int n = grid[0].size();
    int total = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1'){
                total += 1;
                visited(i, j, grid);
            }
        }
    }

    return total;
}

int main(){
    vector<vector<char>> m1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> m2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << numIslands(m1);
    return 0;
}