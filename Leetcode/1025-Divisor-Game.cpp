#include <iostream>
#include <vector>

using namespace std;


/* FUNÇÃO ÓTIMA
    A interpretação do problema é um pouco custosa, 
    mas seu código é fácil. A ideia parte da simulação
    de jogadas: 

    n = 0 -> não temos jogadas nem jogo. 
    n = 1 -> ou seja, 0<x<1, perde, pois não número x válido.
    n = 2 -> Alice: 2%1 == 0 => 2-1 = 1 (próximo jogador perde) => GANHA
    n = 3 -> Alice: 3%1 == 0 => 3-1=2 => PERDE (Bob - n=2).
    n = 4 -> Alice: 4%1 == 0 (força o impar) => 4-1 = 3 => GANHA (Bob - n=3).
    n = 5 -> Alice: 5%1 == 0 (unica opção) => 5-1 = 4 => PERDE (Bob - n=4).
    
    (...)

    Se n == par, Alice pode escolher 1 (divide n) e
    deixar n-1, que é impar para Bob. 

    Na vez de Bob, todas as jogadas deixam um número
    par para Alice, deixando-a em vantagem. 

    Logo:
        - Se n=par, Alice vence. 
        - Se n=impar, Bob vence.
*/
bool divisorGame_(int n) {
    return n%2 == 0;
}

// PROGRAMAÇÃO DINÂMICA
bool divisorGame(int n) {
    // Vetor de memo
    vector<bool> dp(n+1, false);

    // Casos bases
    dp[0] = false; // não há jogo, nem vitória
    dp[1] = false; // não existe divisor válido

    //Calcular casos
    for(int i = 2; i <= n; ++i)
        for(int x = 1; x < i; ++x)
            if(i%x == 0 && !dp[i-x]){
                dp[i] = true;
                break;
            }

    return dp[n];
}

int main(){
    
    int n = 11;

    cout << (divisorGame(n) ? "TRUE" : "FALSE");

    return 0;
}