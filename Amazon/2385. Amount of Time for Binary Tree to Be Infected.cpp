/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void graph(map<int, list<int>>& mp, TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            graph(mp, root->left);
        }
        if (root->right) {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            graph(mp, root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if (!root->left && !root->right)
            return 0;

        map<int, list<int>> mp;
        graph(mp, root);
        map<int, bool> vis;
        queue<int> q;
        int count = -1;
        q.push(start);
        vis[start] = 1;
        while (!q.empty()) {
            int sz = q.size();
            count++;

            for (int i = 0; i < sz; i++) {
                int front =q.front();q.pop();
                for (auto nbr : mp[front]) {
                    if (!vis[nbr]) {
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
        }

        return count;
    }
};
