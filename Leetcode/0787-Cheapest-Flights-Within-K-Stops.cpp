/* 787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

Constraints:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
#include <limits>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Grafo: origem -> lista de pares (destino, custo)
    unordered_map<int, vector<pair<int, int>>> graph;
    for (auto& f : flights)
        graph[f[0]].emplace_back(f[1], f[2]);

    // min-heap: (custo_total, cidade_atual, paradas)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, src, 0);

    // distâncias: [n][k+2] -> menor custo para chegar a `cidade` com `k` paradas
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
    dist[src][0] = 0;

    while (!pq.empty()) {
        auto [cost, u, stops] = pq.top();
        pq.pop();

        if (u == dst) return cost;
        if (stops > k) continue;

        for (auto& [v, price] : graph[u]) {
            if (cost + price < dist[v][stops + 1]) {
                dist[v][stops + 1] = cost + price;
                pq.emplace(cost + price, v, stops + 1);
            }
        }
    }

    return -1;
}

int main(){

    
    //int n = 4;      //Cidades
    //int src = 0;    //Origem
    //int dst = 3;    //Destino
    //int k = 1;      //Quantidade de paradas
    //vector<vector<int>> f = {
    //    {0,1,100},
    //    {1,2,100},
    //    {2,0,100},
    //    {1,3,600},
    //    {2,3,200}
    //};

    //int n = 3;      //Cidades
    //int src = 0;    //Origem
    //int dst = 2;    //Destino
    //int k = 1;      //Quantidade de paradas
    //vector<vector<int>> f = {
    //    {0,1,100},
    //    {1,2,100},
    //    {0,2,500},
    //};

    //int n = 3;      //Cidades
    //int src = 0;    //Origem
    //int dst = 2;    //Destino
    //int k = 0;      //Quantidade de paradas
    //vector<vector<int>> f = {
    //    {0,1,100},
    //    {1,2,100},
    //    {0,2,500}
    //};

    int n = 5;      //Cidades
    int src = 0;    //Origem
    int dst = 2;    //Destino
    int k = 2;      //Quantidade de paradas
    vector<vector<int>> f = {
        {0,1,5},
        {1,2,5},
        {0,3,2},
        {3,1,2},
        {1,4,1},
        {4,2,1}
    };
    
    cout << findCheapestPrice(n,f,src,dst,k);

    return 0;
}