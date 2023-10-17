#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
class node {
    char data;
    node* left;
    node* right;
public:
    node() {
        left = NULL;
        right = NULL;
    }

    friend class exptree;
};

class exptree {
    node* root;

public:
    node* getroot() {
        return root;
    }

    void create() {
        stack<node*> s;

        char prefix[100], ch;
        node* curr, * leftside, * rightside;

        cout << "Enter the prefix expression: ";
        cin >> prefix;

        int i = strlen(prefix);
        i = i - 1;

        for (int j = i; j >= 0; j--) {
            ch = prefix[j];
            node* temp = new node;
            temp->data = ch;

            if (ch >= 'a' && ch <= 'z') {
                s.push(temp);
            }
            else {
                leftside = s.top();//operand 1
                s.pop();
                rightside = s.top();//p
                s.pop();

                temp->left = leftside;
                temp->right = rightside;

                s.push(temp);
            }
        }

        root = s.top();
        s.pop();
    }

    void nonpostorder(node* root) {
        stack<node*> s1;
        stack<node*> s2;
        node* t = root;

        s1.push(t);

        while (!s1.empty()) {
            t = s1.top();
            s1.pop();
            s2.push(t);

            if (t->left != NULL)
                s1.push(t->left);

            if (t->right != NULL)
                s1.push(t->right);
        }

        while (!s2.empty()) {
            root = s2.top();
            s2.pop();
            cout << root->data << " ";
        }
    }

    void postorder(node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data;
        }
    }
};

int main() {
    int ch;
    exptree e1;

    while (1) {
        cout << "\n\n1. Create an expression tree";
        cout << "\n2. Postorder traversal";
        cout << "\n3. Delete the tree";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            e1.create();
            break;

        case 2:
            cout << "\nPostorder traversal: ";
            e1.postorder(e1.getroot());
            cout << endl;
            break;

        case 3:
            cout << "\nNon-recursive postorder traversal: ";
            e1.nonpostorder(e1.getroot());
            cout << endl;
            break;

        case 4:
            exit(0);

        default:
            cout << "\nInvalid choice! Try again.";
            break;
        }
    }
return 0;
}
