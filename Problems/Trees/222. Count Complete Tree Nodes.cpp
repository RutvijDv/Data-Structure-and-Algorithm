#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
TreeNode *left;
TreeNode *right;
int val;
TreeNode(int x)
{
val = x;
left = right =  NULL;
}
};

int left_height(TreeNode* node){
        
        if(!node) return 0;
        
       int ht = 0;
        while (node) {
            ht++;
            node = node->left;
        }
        
        return ht-1;
        
    }
    
    int right_height(TreeNode* node){
        
        if(!node) return 0;
        
        int ht = 0;
        while (node) {
            ht++;
            node = node->right;
        }
        
        return ht-1;
        
    }
    
    int countNodes(TreeNode* root) {
        
        if (root == NULL)
            return 0;
        
        int l = left_height(root);
        int r = right_height(root);
            
        if(l==r){
            return pow(2,l+1)-1;
        }
        
        int lc = countNodes(root->left);
        int rc = countNodes(root->right);
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }