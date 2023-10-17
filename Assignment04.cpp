#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};


class BST {
public:
    TreeNode* root;

    BST() {
        root = NULL;
    }

    bool isTreeEmpty() {
        return (root == NULL);
    }

    void insertNode(TreeNode* new_node) {
        if (root == NULL) {
            root = new_node;
            cout << "***Value Inserted as root node!***" << endl;
        } else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (new_node->value == temp->value) {
                    cout << "***Value Already exists. Insert another value!***" << endl;
                    return;
                } else if (new_node->value < temp->value) {
                    if (temp->left == NULL) {
                        temp->left = new_node;
                        cout << "***Value Inserted to the left!***" << endl;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = new_node;
                        cout << "***Value Inserted to the right!***" << endl;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    void printPreorder(TreeNode* r) {
        if (r == NULL)
            return;

        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }

    void printInorder(TreeNode* r) {
        if (r == NULL)
            return;

        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }

    void printPostorder(TreeNode* r) {
        if (r == NULL)
            return;

        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->value << " ";
    }

    TreeNode* iterativeSearch(int v) {
        if (root == NULL)
            return NULL;

        TreeNode* temp = root;
        while (temp != NULL) {
            if (v == temp->value) {
                return temp;
            } else if (v < temp->value) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        return NULL;
    }

    int height(TreeNode* r) {
        if (r == NULL)
            return -1;

        int lheight = height(r->left);
        int rheight = height(r->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }

    int minimum(TreeNode* root) {
        TreeNode* temp = root;
        int minVal = INT_MAX;

        while (temp != NULL) {
            if (temp->value < minVal) {
                minVal = temp->value;
            }
            temp = temp->left;
        }

        return minVal;
    }

    int maximum(TreeNode* root) {
        TreeNode* temp = root;
        int maxVal = INT_MIN;

        while (temp != NULL) {
            if (temp->value > maxVal) {
                maxVal = temp->value;
            }
            temp = temp->right;
        }

        return maxVal;
    }
};

int main() {
    BST obj;
    int option, val;

    do {
        cout << "\nWhat operation do you want to perform? Select an option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Height of Tree" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Swap Left & Right Pointers" << endl;
        cout << "6. Minimum Value in the Tree" << endl;
        cout << "7. Maximum Value in the Tree" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        TreeNode* new_node = new TreeNode();

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "INSERT" << endl;
                cout << "Enter the value of the tree node to insert in BST: ";
                cin >> val;
                new_node->value = val;
                obj.insertNode(new_node);
                break;
            case 2:
                cout << "SEARCH" << endl;
                cout << "Enter the value of the tree node to search in BST: ";
                cin >> val;
                new_node = obj.iterativeSearch(val);
                if (new_node != NULL) {
                    cout << "**Value found**" << endl;
                } else {
                    cout << "**Value not found**" << endl;
                }
                break;
            case 3:
                cout << "TREE HEIGHT" << endl;
                cout << "**Height**: " << obj.height(obj.root) << endl;
                break;
            case 4:
                cout << "Print/Traversal BST values" << endl;
                cout << "PRE-ORDER: ";
                obj.printPreorder(obj.root);
                cout << endl;
                cout << "IN-ORDER: ";
                obj.printInorder(obj.root);
                cout << endl;
                cout << "POST-ORDER: ";
                obj.printPostorder(obj.root);
                cout << endl;
                break;
            case 5:
                cout << "**Swap Left & Right Pointers**" << endl;
                // Implement the swap function here
                break;
            case 6:
                cout << "**Minimum Value in the Tree:** " << obj.minimum(obj.root) << endl;
                break;
            case 7:
                cout << "**Maximum Value in the Tree:** " << obj.maximum(obj.root) << endl;
                break;
            default:
                cout << "Enter a proper option number" << endl;
        }
    } while (option != 0);

return 0;
}
