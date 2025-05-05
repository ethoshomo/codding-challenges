#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
    O exercício pede apenas para contar a quantidade
    de caminhos únicos. Se formos considerar que podemos
    fazer movimentos para baixo ou para o lado direito,
    teremos m-1 movimentos para baixo e n-1 movimentos
    para a direita. Permutando todos eles, descontando
    as repetições, chegamos na seguinte fórmula:
    
        P(m+n-2;m-1,n-1) = (m+n-2)!/((m-1)!*(n-1)!)
*/
int uniquePaths(int m, int n) {
    long long res = 1;
    int k = min(m - 1, n - 1);
    for (int i = 1; i <= k; ++i)
        res = res * (m + n - 1 - i) / i;
    return static_cast<int>(res);
}

int main(){
    int m = 23, n = 12;
    cout << uniquePaths(m, n);
    return 0;
}