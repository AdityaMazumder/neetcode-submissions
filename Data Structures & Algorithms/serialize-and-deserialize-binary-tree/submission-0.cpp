
class Codec {
public:
    void preorder(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    TreeNode* build(vector<string>& v, int &i) {
        if (v[i] == "#") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(v[i]));
        i++;

        root->left = build(v, i);
        root->right = build(v, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        vector<string> v;

        while (getline(ss, token, ',')) {
            v.push_back(token);
        }

        int i = 0;
        return build(v, i);
    }
};
