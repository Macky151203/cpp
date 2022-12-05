#include <iostream>
using namespace std;
struct treenode
{
    treenode *left;
    treenode *right;
    int data;
};
struct bsttree
{
    int count;
    treenode *root;
};
class bst
{
    bsttree *head;

public:
    bst()
    {
        head = new bsttree;
        head->count = 0;
        head->root = NULL;
    }
    treenode *bstinsert(treenode *t, int datain, bool &success)
    {

        if (t == NULL)
        {
            treenode *x = new treenode;
            x->data = datain;
            x->right = x->left = NULL;
            success = true;
            return x;
        }
        else if (t->data > datain)
        {
            t->left = bstinsert(t->left, datain, success);
        }
        else if (t->data < datain)
        {
            t->right = bstinsert(t->right, datain, success);
        }
        else
        {
            success = false;
        }
        return t;

        cout << "inserted ";
    }
    treenode *deletenode(treenode *t, int key, bool &success)
    {
        int y;
        if (t == NULL)
        {
            cout << "element not found";
            success = false;
            return NULL;
        }
        else if (t->data > key)
        {
            t->left = deletenode(t->left, key, success);
        }
        else if (t->data < key)
        {
            t->right = deletenode(t->right, key, success);
        }
        else if (t->left == NULL)
        {
            return t->right;
        }
        else if (t->right == NULL)
        {
            return t->left;
        }
        else
        {
            treenode *y = largest(t->left);
            t->data = y->data;
            t->left = deletenode(t->left, y->data, success);
            success = true;

            return t;
        }
    }
    bool removenode(int data)
    {
        bool success;
        head->root = deletenode(head->root, data, success);
        if (success)
        {
            cout << "deleted";
            head->count--;
            return true;
        }
        else
        {
            cout << "not found";
        }
    }
    bool addnode(int datain)
    {
        bool success;
        head->root = bstinsert(head->root, datain, success);
        if (success)
        {
            head->count++;
        }
        return success;
    }
    bool search(treenode *t, int target)
    {
        bool success;
        if (t == NULL)
            success = false;
        else if (t->data > target)
            success = search(t->left, target);
        else if (t->data < target)
            success = search(t->right, target);
        else
            success = true;
        return success;
    }
    bool retrievenode(int data)
    {
        return search(head->root, data);
    }
    void inorder(treenode *t)
    {
        if (t != NULL)
        {
            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right);
        }
    }

    void postorder(treenode *t)
    {
        if (t != NULL)
        {
            postorder(t->left);
            postorder(t->right);
            cout << t->data << " ";
        }
    }

    treenode *smallest(treenode *root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        return smallest(root->left);
    }

    treenode *largest(treenode *root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        return largest(root->right);
    }

    void traversal(int order)
    {
        switch (order)
        {
        case 1:
            postorder(head->root);
            break;
        case 2:
            inorder(head->root);
            break;
        }
    }
};
int main()
{
    bst b;

    bool flag;
    flag = b.addnode(10);
    b.addnode(20);
    b.addnode(15);
    b.addnode(5);
    b.addnode(25);

    b.traversal(2);
    b.removenode(20);
    b.traversal(2);
    flag = b.retrievenode(15);
    if (flag)
    {
        cout << "found";
    }
    return 0;
}
