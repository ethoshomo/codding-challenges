/* 84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
 
Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Usando programação dinâmica estoura limite de memória, mas resolve quase todos.
int largestRectangleArea_(vector<int>& heights) {
    int n = heights.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int maxArea = 0, area = 0, minHeight = 0, j = 0;

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            j = i + len - 1;

            minHeight = heights[i];
            for (int k = i; k <= j; k++)
                minHeight = min(minHeight, heights[k]);

            area = minHeight * (j - i + 1);
            if (len == 1)
                dp[i][j] = area;
            else 
                dp[i][j] = max({area, dp[i][j - 1], dp[i + 1][j]});
            
            maxArea = max(maxArea, dp[i][j]);
        }
    }

    return maxArea;
}


/* VERSÃO OTIMIZADA - O(n)

    A ideia do algoritmo está centrada no crescimento monotonico das barras
    do histograma. Isto é, enquanto for surgindo barras maiores, os indices
    das barras serão armazenados na pilha. Caso estejamos diante de uma barra
    com valor menor que o topo da pilha, precisamos calcular os valores
    intermediários com base na barra da esquerda. Isto é, vamos desempilhando e 
    calculando os valores dos intervalos anteriores com base na barra anterior. 

    A lógica é um pouco confusa porque mistura valores de altura, indexexes na pilha 
    e posições subtraídas de uma unidade (porque a posição da barra à esquerda é 
    sempre um valor menor que a atual (i-st.top()-1).
    
*/
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        // Se a pilha está vazia ou a altura atual é maior que a altura da barra no topo da pilha
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];  // Altura do topo da pilha
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;  // Largura do retângulo
            maxArea = max(maxArea, h * width);  // Atualiza a maior área
        }
        st.push(i);  // Adiciona o índice atual à pilha
    }

    // Após o loop, ainda podem existir barras na pilha
    while (!st.empty()) {
        int h = heights[st.top()];  // Altura do topo da pilha
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;  // Largura do retângulo
        maxArea = max(maxArea, h * width);  // Atualiza a maior área
    }

    return maxArea;
}



int main(){

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(heights);

    return 0;
}