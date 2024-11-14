#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int d;
    node *left;
    node *right;
    node(int d)
    {
        this->d = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    int d;
    cout << "data for root node: ";
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    root = new node(d);
    cout << "enter the data for left of " << d << endl;
    root->left = buildtree(root->left);
    cout << "enter the data for right of " << d << endl;
    root->right = buildtree(root->right);
    return root;
}
void levelordertraversal(node *root)
{
    node *ti = NULL;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        ti = q.front();
        q.pop();

        if (ti == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << ti->d << " ";
            if (ti->left != NULL)
            {
                q.push(ti->left);
            }
            if (ti->right != NULL)
            {
                q.push(ti->right);
            }
        }
    }
}
node *buildtreelevel(node *root)
{
    queue<node *> q;
    int d;
    cout << "enter the data for root : ";
    cin >> d;
    root = new node(d);
    q.push(root);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        cout << "enter the data for left of " << t->d << "= ";
        cin >> d;
        if (d != -1)
        {
            t->left = new node(d);
            q.push(t->left);
        }
        cout << "enter the data for right of " << t->d << "= ";
        cin >> d;
        if (d != -1)
        {
            t->right = new node(d);
            q.push(t->right);
        }
    }
    return root;
}
void lnr(node *root) // preorder
{
    if (root == NULL)
    {
        return;
    }
    lnr(root->left);
    cout << root->d << " ";
    lnr(root->right);
}
void nlr(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->d << " ";
    nlr(root->left);
    nlr(root->right);
}
vector<vector<int>> zigzagLevelOrder(node *root)
{
    queue<node *> q;
    vector<vector<int>> v;
    if (root == NULL)
        return v;
    q.push(root);
    bool f = true;
    while (!q.empty())
    {
        vector<int> v1;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            node *t = q.front();
            q.pop();
            if (t->right != NULL)
                q.push(t->right);
            if (t->left != NULL)
                q.push(t->left);
            if (f)
                v1[s - 1] = t->d;
            else
                v1[i] = t->d;
        }
        f = !(f);
        v.push_back(v1);
    }
    return v;
}
vector<int> leafnode(node *root, vector<int> v)
{
    if (root == NULL)
        return v;
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->d);
    }
    leafnode(root->left, v);
    leafnode(root->right, v);
    return v;
}
vector<int> boundryt(node *root)
{
    vector<int> v;
    node *t = root;
    while (t != NULL)
    {
        v.push_back(t->d);
        t = t->left;
    }
    t = root;
    vector<int> v1;
    v1 = leafnode(root, v1);
    v.insert(v.end(), v1.begin(), v1.end());
    t = root;
    while (t != NULL)
    {
        v.push_back(t->d);
    }
    return v;
}
vector<vector<int>> reverseordertraversal(node *root)
{
    vector<vector<int>> v;
    if (root == NULL)
        return v;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> v1;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            node *t = q.front();
            if (t->left != NULL)
                q.push(t->left);
            if (t->right != NULL)
                q.push(t->right);
            v1.push_back(t->d);
            q.pop();
        }
        v.push_back(v1);
    }
    reverse(v.begin(), v.end());
    return v;
}
int height(node *root)
{
    int l = 0, r = 0;
    if (root == NULL)
        return 0;
    l = height(root->left);
    r = height(root->right);
    return max(r, l) + 1;
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int o1 = diameter(root->left);
    int o2 = diameter(root->right);
    int o3 = diameter(root->left) + diameter(root->right);
    return max(o3, max(o1, o2));
}
pair<bool, int> checkbaltree(node *root) //<isbal,height>
{
    pair<bool, int> p;
    if (root == NULL)
    {
        p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> l = checkbaltree(root->left);
    pair<bool, int> r = checkbaltree(root->right);
    if (l.first && l.first)
    {
        if (abs(l.second - r.second) <= 1)
        {
            int t = max(l.second, l.second);
            p = make_pair(true, (t + 1));
        }
        else
        {
            int t = max(l.second, l.second);
            p = make_pair(false, (t + 1));
        }
    }
    else
    {
        p = make_pair(false, max(l.second, l.second) + 1);
    }
    return p;
}
pair<bool, int> issumtree(node *root) // root=left+right
{
    pair<bool, int> p;
    if (root == NULL)
    {
        p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> l = issumtree(root->left);
    pair<bool, int> r = issumtree(root->right);
    bool ps = ((l.second + r.second) == root->d);
    p.first = (l.first && r.first && ps);
    p.second = root->d + r.second + l.second;
    return p;
}
// verticle order travercle
vector<int> verticleotra(node *root)
{
    map<int, map<int, vector<int>>> nodes; // hd,(lvl,(list of nodes))
    queue<pair<node *, pair<int, int>>> q; // node,(hd,lvl)
    vector<int> ans;
    if (root == NULL)
        return ans;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *fn = temp.first;
        int hd = temp.second.first; // horizontal distance
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(fn->d);
        if (fn->left != NULL)
            q.push(make_pair(fn->left, make_pair(hd - 1, lvl + 1)));
        if (fn->right != NULL)
            q.push(make_pair(fn->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// top view
vector<int> topview(node *root)
{
    vector<int> ans;
    map<int, int> m;                       // hd,node
    queue<pair<node *, pair<int, int>>> q; // node,(hd,lvl)
    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int>> f = q.front();
        q.pop();
        node *fn = f.first;
        int hd = f.second.first;
        int lvl = f.second.second;
        if (m.find(hd) == m.end())
        {
            m[hd] = f.first->d;
        }
        if (fn->left != NULL)
            q.push(make_pair(fn->left, make_pair(hd - 1, lvl + 1)));
        if (fn->right != NULL)
            q.push(make_pair(fn->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
// bottom view
vector<int> bottomview(node *root)
{
    map<int, int> m;
    queue<pair<node *, int>> q; // node,hd
    vector<int> ans;
    if (root == NULL)
        return ans;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> fr = q.front();
        q.pop();
        node *fn = fr.first;
        int hd = fr.second;
        m[hd] = fn->d;
        if (fn->left != NULL)
            q.push(make_pair(fn->left, hd - 1));
        if (fn->right != NULL)
            q.push(make_pair(fn->right, hd + 1));
    }
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
// Sum of nodes on the longest path from root to leaf node
pair<int, int> lsum(node *root) // sum,pathlen
{
    pair<int, int> ans;
    if (root == NULL)
    {
        ans = make_pair(0, 0);
        return ans;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans = make_pair(root->d, 1);
        return ans;
    }

    pair<int, int> l = lsum(root->left);
    pair<int, int> r = lsum(root->right);
    if (l.second > r.second)
        ans = make_pair(l.first + root->d, l.second + 1);
    else if (l.second == r.second)
        ans = make_pair(max(l.first, r.first) + root->d, l.second + 1);
    else
        ans = make_pair(r.first + root->d, r.second + 1);
    return ans;
}
// LEAST COMMON ANCESTOR
node *lca(node *p, node *q, node *root)
{
    node *an = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root == p || root == q)
    {
        if (root == p)
            return p;
        else
            return q;
    }
    node *l = lca(p, q, root->left);
    node *r = lca(p, q, root->right);
    if (r != NULL && l != NULL)
        return root;
    if (l != NULL)
    {
        return l;
    }
    if (r != NULL)
        return r;
    return an;
}
// K SUM PATHS
void psum(node *root, long long targetSum, int &co, vector<int> v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->d);
    psum(root->left, targetSum, co, v);
    psum(root->right, targetSum, co, v);
    int s = v.size();
    long long sum = 0;
    for (int i = s - 1; i >= 0; i--)
    {
        sum = sum + v[i];
        if (sum == targetSum)
        {
            co++;
        }
    }
    v.pop_back();
}
int pathSum(node *root, long long targetSum)
{
    int co = 0;
    vector<int> v;
    psum(root, targetSum, co, v);
    return co;
}
int sum(node *root)
{
    pair<int, int> p = lsum(root);
    return p.first;
}

// CONSTRUCT TREE USING INORDER AND PREORDER
node *solve2(vector<int> &pre, vector<int> &ino, int hi, int lo)
{
    if (!(hi <= lo))
    {
        return NULL;
    }
    node *root = new node(pre[lo]);
    int npos = 0;
    for (int i = lo; i < hi + 1; i++)
    {
        if (ino[i] == pre[lo])
        {
            npos = i;
            break;
        }
    }
    root->left = solve2(pre, ino, npos, lo + 1);
    root->right = solve2(pre, ino, hi, npos + 1);
    return root;
}
node *buildTree(vector<int> &pre, vector<int> &ino)
{
    node *root = solve2(pre, ino, ino.size() - 1, 0);
    return root;
}
// time to burn a tree
node *mapi(node *root, unordered_map<node *, node *> &m, int start, unordered_map<node *, bool> &visited)
{
    if (root == NULL)
        return NULL;

    if (root->left != NULL)
        m[root->left] = root;
    if (root->right != NULL)
        m[root->right] = root;
    visited[root] = false;
    node *l = mapi(root->left, m, start, visited);
    node *r = mapi(root->right, m, start, visited);
    if (root->d == start)
        return root;
    else if (l != NULL || r != NULL)
    {
        if (l != NULL)
        {
            return l;
        }
        else
            return r;
    }
    return NULL;
}
int amountOfTime(node *root, int start)
{
    int time = 0;
    unordered_map<node *, bool> visited;
    unordered_map<node *, node *> parent; // child to parent
    node *tnode = mapi(root, parent, start, visited);
    queue<node *> q;
    q.push(tnode);
    visited[tnode] = true;
    while (!(q.empty()))
    {
        int s = q.size();
        int f = 0;
        for (int i = 0; i < s; i++)
        {
            tnode = q.front();
            q.pop();

            if (tnode->left != NULL && !(visited[tnode->left]))
            {
                q.push(tnode->left);
                visited[tnode->left] = true;
                f = 1;
            }
            if (tnode->right != NULL && !(visited[tnode->right]))
            {
                q.push(tnode->right);
                visited[tnode->right] = true;
                f = 1;
            }
            if (parent.find(tnode) != parent.end() && !(visited[parent[tnode]]))
            {
                q.push(parent[tnode]);
                visited[parent[tnode]] = true;
                f = 1;
            }
        }
        if (f)
            time++;
    }
    return time;
}
// 
// 
// 
// 
// 
// 
// 
// 
// 
//
int main()
{
    node *root = NULL;
    root = buildtreelevel(root);
    cout << endl;
    return 0;
}
