/*621. Task Scheduler

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

Constraints:
1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    A explicação do algoritmo leva em consideração
    a maior frequência, que, segundo a lógica de 
    resolução, é o fator limitante do problema. 
    Isto é, elas determinam a quantidade de blocos 
    em que devemos distribuir as tarefas. 

    Por exemplo: 

    ['A', 'A', 'A', 'B', 'B', 'B'] e n = 2
    #A = 3;
    #B = 3;
    maxCount = 3;

    A ideia é separar em blocos: 

        Interval    Interval
           1           2
    A _ _  |   A _ _   |  A _ _ 
    A B _  |   A B _   |  A B
    1 2 3  |   4 5 6   |  7 8
    
      B1      B2      B3
    A _ _ | A _ _ | A _ _

    Tempo mínimo = (maxCount - 1) * (n + 1)
                 = (3-1)*(n+1) = 6

    - (maxCount-1): numero de intervalos entre as
    execuções da tarefa mais frequente (Interval 1
    e Interval 2).

    -(n+1): é o tamanho total ocupado pela unidade
    mais frequente considerando os blocos de cooldown 
    (B1, B2 e B3). 

    Pois bem, seguindo a lógica, cada tarefa com 
    frequência máxima precisa ainda de mais uma 
    unidade de tempo. Como #A e #B possuem frequências 
    iguais a maxCount, acrescentamos 1 para cada tarefa:
    6+2 = 8. Logo, o tempo mínimo calculado é 8.

    Vale dizer que, ao final, ainda precisamos fazer uma
    consideração importante. Se o total de tarefas for
    maior que o tempo calculado, devemos entender que
    o tempo mínimo de processamento de todas as tarefas
    será o tempo de passar uma a uma; mas, se o tempo
    calculado for maior que o número de tarefas mínimas,
    significa que temos eventos cooldown (iddle)
    intercalados e ociosos, o que leva a um tempo maior. 

    Assim: max(6,8) = 8. Essa é a resposta.

*/
int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {0};
    int maxCount = 0;

    for (char task : tasks) {
        freq[task - 'A']++;
        maxCount = max(maxCount, freq[task - 'A']);
    }
    
    int time = (maxCount - 1) * (n + 1);

    for (int f : freq) {
        if (f == maxCount) {
            time++; 
        }
    }
    return max((int)tasks.size(), time);
}


int main(){
    vector<char> tasks = {'A','A','A','B','B','B','C','C','C','D','D','E'};
    int n = 2;
    
    cout << leastInterval(tasks, n);
    
    return 0;
}