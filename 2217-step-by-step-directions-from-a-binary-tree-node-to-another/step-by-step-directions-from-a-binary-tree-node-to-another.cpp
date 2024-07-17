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
    TreeNode* lca(TreeNode* node, int p, int q)
    {
        if(node == nullptr)
            return nullptr;
        
        TreeNode* leftSide = lca(node->left,p,q);
        TreeNode* rightSide = lca(node->right,p,q);

        if((leftSide && rightSide) || (node->val == p) || (node->val == q))
            return node;
        
        return (leftSide == nullptr) ? rightSide : leftSide;
    }
    string lcaToStart, lcaToEnd;
    void dfs(TreeNode* node, string& currPath, int startValue, int destValue)
    {
        if(node == nullptr)
            return;
        
        if(node->val == startValue)
            lcaToStart = currPath;
        if(node->val == destValue)
            lcaToEnd = currPath;
        
        currPath.push_back('L');
        dfs(node->left,currPath,startValue,destValue);
        currPath.pop_back();

        currPath.push_back('R');
        dfs(node->right,currPath,startValue,destValue);
        currPath.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lca(root,startValue,destValue);
        string currPath = "";
        dfs(lcaNode, currPath, startValue, destValue);

        for(char& ch : lcaToStart)
            ch = 'U';
        
        return lcaToStart + lcaToEnd;
    }
};