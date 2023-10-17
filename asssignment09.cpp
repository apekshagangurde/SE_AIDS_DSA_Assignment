#include<iostream>
using namespace std;
class node{
Public:
    string key;
    string meaning;
    node*left;
    node*right;
};
class AVL{
node*root;
Public:
    AVl(){
    root=NULL;
    }
    void creat();
    node*Insert(node*cur,node*temp); //insert node
    node*balanced(node*temp);    //to balanced tree
    int diff(node*temp);       //to calculate difference
    int height(node*temp);    //to calculate height
    int maximum(int a,int b);   //to fine more node


    node* LL(node* par);
    node* RR(node* par);
    node* LR(node* par);       //rotation to balanced tree
    node* RL(node* par);


    void ascending(node* temp);
    node* delete_n(node *root, string key1);
    void deleten();

    node*extracting(node *t);
    void descending(node *temp);
    void display();
    bool search(node * cur, string key);
    void search_value();

};


int main(){

char c;
int ch;
AVL a;
do{
   cout<<"***************************************";
   cout<<


}


}
