#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

class AVLnode
{
public:
    char keyword[20], meaning[20];
    AVLnode *left, *right;
    int ht;
};

class AVLtree
{
public:
    AVLnode *root;
    AVLtree() { root = NULL; }
    AVLnode *rotate_right(AVLnode *x);
    AVLnode *rotate_left(AVLnode *x);
    AVLnode *LL(AVLnode *x);
    AVLnode *LR(AVLnode *x);
    AVLnode *RR(AVLnode *x);
    AVLnode *RL(AVLnode *x);
    int height(AVLnode *T);
    int BF(AVLnode *T);
    AVLnode *insert(AVLnode *root, char newkey[20], char mean[20]);
    void inorder(AVLnode *root);
    AVLnode *search(AVLnode *root, char key[20]);
};

AVLnode *AVLtree::rotate_right(AVLnode *x)
{
    AVLnode *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

AVLnode *AVLtree::rotate_left(AVLnode *x)
{
    AVLnode *y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

AVLnode *AVLtree::LL(AVLnode *T)
{
    cout << "\n in LL rotation \n";
    T = rotate_right(T);
    return T;
}

AVLnode *AVLtree::RR(AVLnode *T)
{
    cout << "\n in RR rotation \n";
    T = rotate_left(T);
    return T;
}

AVLnode *AVLtree::RL(AVLnode *T)
{
    cout << "\n in RL rotation \n";
    T->right = rotate_right(T->right);
    T = rotate_left(T);
    return T;
}

AVLnode *AVLtree::LR(AVLnode *T)
{
    cout << "\n in LR rotation \n";
    T->left = rotate_left(T->left);
    T = rotate_right(T);
    return T;
}

int AVLtree::height(AVLnode *T)
{
    int hl, hr;
    if (T == NULL)
        return 0;
    if (T->left == NULL && T->right == NULL)
        return 0;
    hl = height(T->left);
    hr = height(T->right);
    if (hl < hr)
        return hr + 1;
    else
        return hl + 1;
}

int AVLtree::BF(AVLnode *T)
{
    int lh, rh;
    if (T == NULL)
        return 0;
    else
    {
        if (T->left == NULL)
            lh = 0;
        else
            lh = 1 + T->left->ht;
        if (T->right == NULL)
            rh = 0;
        else
            rh = 1 + T->right->ht;
    }
    return (lh - rh);
}

AVLnode *AVLtree::insert(AVLnode *root, char newkey[20], char mean[20])
{
    AVLnode *curr;
    int lh, rh;
    if (root == NULL)
    {
        curr = new AVLnode;
        strcpy(curr->keyword, newkey);
        strcpy(curr->meaning, mean);
        curr->ht = 0;
        curr->left = NULL;
        curr->right = NULL;
        root = curr;
        cout << root->keyword;
    }
    else
    {
        if (strcmp(newkey, root->keyword) < 0)
        {
            root->left = insert(root->left, newkey, mean);
            if (BF(root) == 2)
            {
                if (strcmp(newkey, root->left->keyword) < 0)
                {
                    root = LL(root);
                }
                else
                {
                    root = LR(root);
                }
            }
        }
        else
        {
            if (strcmp(newkey, root->keyword) > 0)
            {
                root->right = insert(root->right, newkey, mean);
                if (BF(root) == -2)
                {
                    if (strcmp(newkey, root->right->keyword) > 0)
                    {
                        root = RR(root);
                    }
                    else
                    {
                        root = RL(root);
                    }
                }
            }
            else
                cout << "Duplicate";
        }
    }
    root->ht = height(root);
    return root;
}

void AVLtree::inorder(AVLnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << "\n"
             << root->keyword << "->" << root->meaning << "-BF:" << BF(root);
        inorder(root->right);
    }
}

AVLnode *AVLtree::search(AVLnode *root, char key[20])
{
    if (root == NULL || strcmp(root->keyword, key) == 0)
        return root;
    if (strcmp(root->keyword, key) < 0)
        return search(root->right, key);
    return search(root->left, key);
}

int main()
{
    AVLtree A;
    int choice;
    char w[20], mean[20];


    do
    {
        cout << "\n 1. Insert ";
        cout << "\n 2. Search ";
        cout << "\n 3. Inorder ";
        cout << "\n Enter choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n Enter word and meaning: ";
            cin >> w >> mean;
            A.root = A.insert(A.root, w, mean);
            break;
        case 2:
            cout << "\n Enter word to be searched: ";
            cin >> w;
            AVLnode *x = A.search(A.root, w);
            if (x != NULL)
                cout << x->keyword << " " << x->meaning;
            else
                cout << "Word not found.";
            break;
        //case 3:
            //A.inorder(A.root);
            break;
        }
    } while (choice < 4);

    getch();
    return 0;
}
