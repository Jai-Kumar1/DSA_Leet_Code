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
    void createMapping(unordered_map<int,int>&valueToIndex,vector<int>&inorder){
        for(int i = 0;i<inorder.size();i++){
            int element = inorder[i];
            int index = i;
            valueToIndex[element] = index;
        }
    }
    TreeNode* createTree(unordered_map<int,int>&valMap,vector<int>&inorder ,vector<int>&postorder,int &postorderIndex ,int inorderStart , int inorderEnd){
        if(postorderIndex < 0){
            return NULL;
        }
        if(inorderStart > inorderEnd){
            return NULL;
        }
        int element = postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder =valMap[element];
        root->right = createTree(valMap,inorder,postorder,postorderIndex,elementIndexInsideInorder +1,inorderEnd);
        root->left = createTree(valMap,inorder,postorder,postorderIndex,inorderStart ,elementIndexInsideInorder -1);
        
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        unordered_map<int,int>valMap;
        createMapping(valMap,inorder);
        TreeNode* root = createTree(valMap,inorder,postorder,postorderIndex,inorderStart,inorderEnd);
        return root;
    }
};