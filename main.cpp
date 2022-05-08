//
//  main.cpp
//  Test
//
//  Created by 林佩蓉 on 2022/4/30.
//  Copyright © 2022 Alisha. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <stack>
//#include <string>
#include<unordered_map>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
void CreateLeftNode(TreeNode *, vector<int>& , int , int );
void CreateRightNode(TreeNode *,vector<int>& , int , int );

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = new TreeNode{nums[nums.size()/2]};
    if((int) nums.size()/2-1 > -1)
        CreateLeftNode(root, nums, 0, (int) nums.size()/2-1);
    if((int) nums.size()/2+1 < (int) nums.size())
        CreateRightNode(root, nums, (int) nums.size()/2+1, (int) nums.size()-1);
    return root;
}
void CreateLeftNode(TreeNode *node, vector<int>& nums, int i, int j){
    cout << i << " " << j << endl;
    TreeNode* newNode = new TreeNode{nums[(i+j)/2]};
    node->left = newNode;
    if((i+j)/2-1 >= i)
        CreateLeftNode(node->left, nums, i, (i+j)/2-1);
    if((i+j)/2+1 <= j)
        CreateRightNode(node->left, nums, (i+j)/2+1, j);
}
void CreateRightNode(TreeNode *node,vector<int>& nums, int i, int j){
    TreeNode* newNode = new TreeNode{nums[(i+j)/2]};
    node->right = newNode;
    if((i+j)/2-1 >= i)
        CreateLeftNode(node->right, nums, i, (i+j)/2-1);
    if((i+j)/2+1 <= j)
        CreateRightNode(node->right, nums, (i+j)/2+1, j);
}
int main(){
    vector<int> nums = {0,1,2,3,4,5,6,7};
    TreeNode* t;
    t = sortedArrayToBST(nums);
//    TreeNode* tmp = t;
//    cout << endl;
//    cout << t << " ";
//    while(tmp != nullptr){
//        tmp->left->val <<
//    }
    return 0;
}
//    -1,0,1,2,-1,-4
//    -2,0,1,1,2
//    0,3,0,1,1,-1,-5,-5,3,-3,-3,0
// -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6
