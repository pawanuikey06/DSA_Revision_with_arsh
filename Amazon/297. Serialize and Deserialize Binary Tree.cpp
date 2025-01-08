/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "M"; // If the tree is empty, return "M" as the marker for null.

        queue<TreeNode*> q;
        string s = "";
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                s += to_string(node->val) + ","; // Add the value of the node.
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "M,"; // Use "M" for null nodes.
            }
        }
        
        // Remove trailing comma (optional but cleaner).
        if (!s.empty()) s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "M") return nullptr; // If the data represents an empty tree.

        queue<TreeNode*> q;
        stringstream ss(data);
        string item;

        // Get the root value.
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Get the left child.
            if (getline(ss, item, ',')) {
                if (item != "M") {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Get the right child.
            if (getline(ss, item, ',')) {
                if (item != "M") {
                    TreeNode* rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
