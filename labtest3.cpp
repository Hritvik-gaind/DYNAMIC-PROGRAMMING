#include <iostream>
#include<climits>
#include<cmath>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node*right;
    node(int d)
    {
        data =d;
        left=NULL;
        right=NULL;
    }
};
void preorder(node *root)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    //recursive case
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    //recursive case
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    //recursive case
    postorder(root->left);
    cout<<root->data<<" ";
    postorder(root->right);
}
node *insertinbst(node *root,int data)
{
    //base case
    if(root==NULL)
    {
        root = new node(data);
        return root;
    }
    //recursive case
    if(data<=root->data)
    {
        root->left = insertinbst(root->left,data);
    }
    else
    {
        root->right = insertinbst(root->right,data);
    }
    return root;
}
node *buildbst(){
    node *root=NULL;
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insertinbst(root,data);
        cin>>data;
    }
    return root;
}
int main() {
    node *root = buildbst();
    cout<<" preorder output is ";
    preorder(root);
    cout<<endl;
    cout<<"inorder output is ";
    inorder(root);
    cout<<endl;
    cout<<"post order output is ";
    postorder(root);
    }
