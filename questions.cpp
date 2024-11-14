#include "bits/stdc++.cpp"
using namespace std;
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Trie;
class Trienode
{
    friend class Trie;

    char data;
    Trienode *nextlet[26];
    bool isterminal;

public:
    Trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            nextlet[i] = NULL;
        }
        isterminal = false;
    }
};
class Trie
{
    Trienode *root;

    

public:
    void inserttriesolver(Trienode *root, string s)
    {
        if (s.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = s[0] - 'a';
        if (root->nextlet[index] != NULL)
        {
            // ispresent
            inserttriesolver(root->nextlet[index], s.substr(1));
        }
        else
        {
            // not present
            root->nextlet[index] = new Trienode(s[0]);
            inserttriesolver(root->nextlet[index], s.substr(1));
        }
    }
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Trienode('\0');
    }
    void inserttriesolver(Trienode *root, string s)
    {
        if (s.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = s[0] - 'a';
        if (root->nextlet[index] != NULL)
        {
            // ispresent
            inserttriesolver(root->nextlet[index], s.substr(1));
        }
        else
        {
            // not present
            root->nextlet[index] = new Trienode(s[0]);
            inserttriesolver(root->nextlet[index], s.substr(1));
        }
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        inserttriesolver(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchtrie(Trienode *root, string s)
    {
        if (s.length() == 0)
        {
            return root->isterminal;
        }

        int index = s[0] - 'a';
        if (root->nextlet[index] == NULL)
        {
            return false;
        }

        Trienode *child = root->nextlet[index];
        return searchtrie(child, s.substr(1));
    }
    bool search(string word)
    {
        return searchtrie(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool searchtrie2(Trienode* root,string s)
    {
        if (s.length() == 0)
        {
            return true;
        }

        int index = s[0] - 'a';
        if (root->nextlet[index] == NULL)
        {
            return false;
        }

        Trienode *child = root->nextlet[index];
        return searchtrie2(child, s.substr(1));
    }
    bool startsWith(string prefix)
    {
        searchtrie2(root, prefix);
    }
};