
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        int i = 0;
        while(inorder[i] != preorder[0]) {
            i++;
        }

        vector<int> leftIn(inorder.begin(), inorder.begin() + i);
        vector<int> rightIn(inorder.begin() + i + 1, inorder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> rightPre(preorder.begin() + i + 1, preorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
