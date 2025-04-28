#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    vector<char> task;
    
    for(auto m: tasks){
        task.resize(task.size()+1);
        task[m] = n;
    }
   
    int index = 0, counter = 0;
    char curr = ' ';
    while(!tasks.empty()){
        
        for(int i = index; i < static_cast<int>(task.size()); i++){
            task[i] += 1;
        }

        for(int i = index; i < static_cast<int>(task.size()); i++){
            index = -1;
            if(task[i] >= n){
                index = i;
                curr = task[i];
                break;
            }
            index += 1;
            index %= n;       
        }

        if(index != -1){
            auto it = find(tasks.begin(), tasks.end(), curr);
            if(it != tasks.end()){
                tasks.erase(it);
            }
            else{
                task.erase(find(task.begin(), task.end(), curr));
            }
        }
        counter += 1;
    }          
    
    return counter;
}

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    
    cout << leastInterval(tasks, n);
    
    return 0;
}