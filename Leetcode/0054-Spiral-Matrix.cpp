#include <iostream>
#include <vector>

using namespace std;

// Versão que pega linha inteira sem iterar.
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;

    while (!matrix.empty() && !matrix[0].empty()) {
        // 1. Esquerda → Direita (linha de cima)
        result.insert(result.end(), matrix.front().begin(), matrix.front().end());
        matrix.erase(matrix.begin());

        // 2. Topo → Baixo (última coluna dos meios)
        for (auto &row : matrix) {
            if (!row.empty()) {
                result.push_back(row.back());
                row.pop_back();
            }
        }

        // 3. Direita → Esquerda (linha de baixo, se existir)
        if (!matrix.empty()) {
            result.insert(result.end(), matrix.back().rbegin(), matrix.back().rend());
            matrix.pop_back();
        }

        // 4. Baixo → Cima (primeira coluna dos meios)
        for (int i = matrix.size() - 1; i >= 0; --i) {
            if (!matrix[i].empty()) {
                result.push_back(matrix[i].front());
                matrix[i].erase(matrix[i].begin());
            }
        }
    }

    return result;
}

vector<int> spiralOrder_element_to_element(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // direita
        for (int j = left; j <= right; ++j)
            result.push_back(matrix[top][j]);
        ++top;

        // para baixo
        for (int i = top; i <= bottom; ++i)
            result.push_back(matrix[i][right]);
        --right;

        // esquerda
        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                result.push_back(matrix[bottom][j]);
            --bottom;
        }

        // para cima
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);
            ++left;
        }
    }

    return result;
}


vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;

    while (!matrix.empty() && !matrix[0].empty()) {
        // 1. Esquerda → Direita (linha de cima)
        result.insert(result.end(), matrix.front().begin(), matrix.front().end());
        matrix.erase(matrix.begin());

        // 2. Topo → Baixo (última coluna dos meios)
        for (auto &row : matrix) {
            if (!row.empty()) {
                result.push_back(row.back());
                row.pop_back();
            }
        }

        // 3. Direita → Esquerda (linha de baixo, se existir)
        if (!matrix.empty()) {
            result.insert(result.end(), matrix.back().rbegin(), matrix.back().rend());
            matrix.pop_back();
        }

        // 4. Baixo → Cima (primeira coluna dos meios)
        for (int i = matrix.size() - 1; i >= 0; --i) {
            if (!matrix[i].empty()) {
                result.push_back(matrix[i].front());
                matrix[i].erase(matrix[i].begin());
            }
        }
    }

    return result;
}


int main()
{

    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> r = spiralOrder(v);
    for (auto c : r)
        cout << c << ' ';

    return 0;
}