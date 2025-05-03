/* 146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:
1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
        
    // <key> : <value>
    list<pair<int, int>> lru;

    // map-> <key> : <list iterator>
    unordered_map<int, list<pair<int,int>>::iterator> map;

    // <capacity>
    int cap;

    public:
        LRUCache(int capacity) : cap(capacity) {}
        
        int get(int key) {
            if(map.find(key) == map.end())
                return -1;
            
            // Move to first splice(<position>, <list>, <iterator element>)
            lru.splice(lru.begin(), lru, map[key]);

            // Return value(second)
            return map[key]->second;
        }
        
        void put(int key, int value) {
            
            // Check if exists. If not, add.
            if(map.find(key) != map.end()){
                map[key]->second = value; // map new value
                lru.splice(lru.begin(), lru, map[key]); // most recently used
                return;
            }

            // If exists, update.

            // Check capacity
            if(static_cast<int>(lru.size()) == cap){
                int less_used = lru.back().first;
                lru.pop_back();
                map.erase(less_used);
            }

            // Update
            lru.emplace_front(key, value);
            map[key] = lru.begin();
        }
};

int main(){

    LRUCache lruCache(2);

    lruCache.put(1, 1);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl;  // 1
    lruCache.put(3, 3);               // remove key 2
    cout << lruCache.get(2) << endl;  // -1
    lruCache.put(4, 4);               // remove key 1
    cout << lruCache.get(1) << endl;  // -1
    cout << lruCache.get(3) << endl;  // 3
    cout << lruCache.get(4) << endl;  // 4

    return 0;
}