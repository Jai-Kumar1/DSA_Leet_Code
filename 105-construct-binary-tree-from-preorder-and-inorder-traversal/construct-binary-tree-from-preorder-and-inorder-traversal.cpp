/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getIndexInorder(vector<int>&inorder ,int target){
        for(int i =0;i< inorder.size();i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* ConstructTree(vector<int>&preorder ,vector<int>&inorder ,int &preorderIndex ,int inorderStart , int inorderEnd , int size){
        if(preorderIndex >= size){
            return NULL;
        }
        if(inorderStart > inorderEnd){
            return NULL;
        }
        int element = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = getIndexInorder(inorder , element);
        root->left = ConstructTree(preorder,inorder,preorderIndex ,inorderStart , elementIndexInsideInorder - 1,size);
        root->right = ConstructTree(preorder,inorder,preorderIndex,elementIndexInsideInorder + 1,inorderEnd , size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int size = inorder.size();
        TreeNode* root = ConstructTree(preorder,inorder,preorderIndex,inorderStart,inorderEnd,size);
        return root;
    }
};