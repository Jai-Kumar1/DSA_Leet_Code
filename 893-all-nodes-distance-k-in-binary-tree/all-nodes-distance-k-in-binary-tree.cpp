/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentMap){
        if(!root)return;
        if(root->left){
            parentMap[root->left]=root;
            mapParent(root->left,parentMap);
        }
        if(root->right){
            parentMap[root->right] = root;
            mapParent(root->right,parentMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentMap;
        parentMap[root]= nullptr;
        mapParent(root,parentMap);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]= true;
        int currentLevel = 0;
        while(!q.empty()){
            int size =q.size();
            if(currentLevel == k)break;
            currentLevel++;
            for(int i =0;i<size;i++){
                auto front = q.front();
                q.pop();
                if(front->left && visited.find(front->left) == visited.end()){
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && visited.find(front->right) == visited.end()){
                    q.push(front->right);
                    visited[front->right] = true;
                }
                auto parentNodeOfFront = parentMap[front];
                if(parentNodeOfFront && visited.find(parentNodeOfFront) == visited.end()){
                    q.push(parentNodeOfFront);
                    visited[parentNodeOfFront] =true;
                }
            }
        }
         vector<int>ans;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};