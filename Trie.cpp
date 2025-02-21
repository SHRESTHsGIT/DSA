#include "bits/stdc++.cpp"
using namespace std;
class trie;
/// 
class Trienode
{
    friend class trie;

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

class trie
{
public:
    Trienode *root;

    trie()
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
    void insertword(string &word)
    {
        inserttriesolver(root, word);
    }

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
    bool searchword(string word)
    {
        return searchtrie(root, word);
    }

    void delfromtrie(Trienode *root, string s)
    {
        if (s.length() == 0)
        {
            root->isterminal = false;
            return;
        }

        int index = s[0] - 'a';
        if (root->nextlet[index] == NULL)
        {
            return;
        }

        Trienode *child = root->nextlet[index];
        return delfromtrie(child, s.substr(1));
    }
    void deleteword(string word)
    {
        delfromtrie(root, word);
    }
    void clearrecusor(Trienode *root)
    {
        
        for(int i=0;i<26;i++)
        {
            if(root->nextlet[i]!=NULL )
            {
                clearrecusor(root->nextlet[i]);
                root->nextlet[i]=NULL;
            }
        }
        delete root;
    
    }
    void clear()
    {
        clearrecusor(root);
    }
};

int main()
{

    return 0;
}