#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
    {
        v.push_back(-1);
        return v;
    }
    vector<int> v1 = inorderTraversal(root->left);
    v.insert(v.end(), v1.begin(), v1.end());
    v.push_back(root->val);
    vector<int> v2 = inorderTraversal(root->right);
    v.insert(v.end(), v2.begin(), v2.end());
    return v;
}

vector<int> inorderTraversal1(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
    {
        v.push_back(-1);
        return v;
    }
    vector<int> v2 = inorderTraversal(root->right);
    v.insert(v.end(), v2.begin(), v2.end());

    v.push_back(root->val);
    vector<int> v1 = inorderTraversal(root->left);
    v.insert(v.end(), v1.begin(), v1.end());
    return v;
}

bool isSymmetric(TreeNode *root)
{
    vector<int> l = inorderTraversal(root->left);
    vector<int> r = inorderTraversal1(root->right);
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : r)
    {
        cout << i << " ";
    }
    return l == r;
}

int totalnode(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1+totalnode(root->left)+totalnode(root->right);
    return ans;
}

bool iscbt(TreeNode *root, int i, int &nodecount)
{

    if (root == NULL)
    {
        return true;
    }
    nodecount++;
    if (i > nodecount)
    {
        return false;
    }

    bool left = iscbt(root->left, 2 * i, nodecount);
    if (left == false)
        return false;
    bool right = iscbt(root->right, 2 * i + 1, nodecount);
    return (left & right);
}
