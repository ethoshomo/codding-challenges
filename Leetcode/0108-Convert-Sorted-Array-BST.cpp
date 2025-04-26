/* 108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 
    O algoritmo abaixo faz uma excelente construção da 
    árvore balanceada, calculando recursivamente o próximo
    vértice como sendo o elemento do meio do array à direita
    ou à esquerda do vértice central. Isso irá acontecer 
    até que não haja mais elementos a serem inseridos. 
    
    Ideia central: note que os cálculos consideram os
    indices do vetor original.
    
    -Construindo a raiz:
           | valor do nó (6/2 = 3)
    [0,1,2,3,4,5]

    -Construindo do lado esquerdo:
       
       | valor do nó (0+3/2 = 1)
    [0,1,2]
     
     | valor do nó (0+1/2 = 0)
    [0]

     | valor do nó (2+2/2 = 2)
    [2]
         3
       /
      1
     / \
    0   2

    - Construindo do lado direito: 

       | valor do nó (4+6/2 = 5)
    [4,5]

     | valor do nó (4+4 / 2 = 4)
    [4]
           3
         /   \
       1      5
     / \     /
    0   2   4

*/
TreeNode* sortedArrayToBST(vector<int>& nums, int l = 0, int r=-10) {
    if (r==-10)
        r = nums.size();
    if (r-l < 1)
        return nullptr;
 
    return new TreeNode(nums[(r+l)/2],
        sortedArrayToBST(nums, l, (r+l)/2),
        sortedArrayToBST(nums, (r+l)/2 +1, r));
    
}

void print(TreeNode* root){
    if(root->left) print(root->left);
    cout << root->val << ' ';
    if(root->right) print(root->right);
}

int main(){
    vector<int> v = {0,1,2,3,4,5};
    auto it = sortedArrayToBST(v);
    print(it);
    return 0;
}