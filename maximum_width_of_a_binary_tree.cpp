#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> width_map;
    int dfs(TreeNode* node, int depth, int index) {
        if (!node) {
            return 0;
        }
        // If no existing index add key with leftmost index (because dfs is left first)
        if (depth >= width_map.size()) {
            width_map.push_back(index);
        }
        int currentWidth = (index - width_map[depth]) + 1;
        int leftWidth = dfs(node->left, depth+1, index*2);
        int rightWidth = dfs(node->right, depth+1, index*2+1);
        return max(currentWidth, max(leftWidth, rightWidth));
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return dfs(root, 0, 1);
    }
};