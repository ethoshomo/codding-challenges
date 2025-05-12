#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

/* Resolve - Tempo de execução O(n²), mas complexidade de espaço é O(n) e não usa pilha */
vector<int> nextGreaterElements_(vector<int>& nums) {

    int INF = numeric_limits<int>::min();
    vector<int> maximum(nums.size(), INF);
    
    int n = nums.size(), j = 0;
    for(int i = n-1; i >= 0; i--){
        
        j = (i+1)%n;
        while(i != j) {

            if(maximum[j] != INF && nums[j] < maximum[i]){
                maximum[i] = maximum[j];
                break;
            }
            
            if(nums[j] > nums[i]){
                maximum[i] = nums[j];
                break;
            }
            j += 1;
            j %= n;
        }

        if(i == j) 
            maximum[i] = -1;
    }
    return maximum;
        
}


/* OTIMIZADO - O(n): tempo e espaço

    A ideia do algoritmo é dar duas voltas no vetor. 
    A primeira volta (2*n-1 até n) serve para preencher
    a pilha com os valores maiores. 

    A segunda volta (n até 0) serve para preencher 
    o vetor de maximum (ou corrigir os valores equivocados).

    O(2n) = O(n)
*/
vector<int> nextGreaterElements(vector<int>& nums) {

    vector<int> maximum(nums.size(), -1);
    stack<int> st;
    
    int n = nums.size(), j = 0;
    for(int i = 2*n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums[i%n]) st.pop();
        if(i < n) maximum[i] = st.empty() ? -1 : st.top();
        st.push(nums[i%n]);
    }
    return maximum;
        
}


int main(){

    //vector<int> n1 = {1,2,3,4,3};
    vector<int> n1 = {1,2,1};

    auto it = nextGreaterElements(n1);

    for(auto i: it) cout << i << ' ';

    return 0;
}