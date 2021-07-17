#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data= d;
        left=NULL;
        right =NULL;
    }
};
node *buildtree(string s)
{
    if(s=="true")
    {
        int data;
        cin>>data;
        node * root = new node(data);
        string l;
        cin>>l;
        if(l=="true")
        {
            root->left = buildtree(l);
        }
        string r;
        cin>>r;
        if(r=="true")
        {
            root->right = buildtree(r);
        }
        return root;
    }
    return NULL;
}
void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
vector<int> printzigzag(node *root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    int level =1;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> temp;
        int sz = q.size();
        while(sz--)
        {
            node * t  = q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left)
            {
                q.push(t->left);
            }
            if(t->right)
            {
                q.push(t->right);
            }
        }
        if(level%2==0)
        {
            reverse(temp.begin(),temp.end());
        }
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
        level+=1;
    }
    return ans;


}
int main()
{
    node *root = buildtree("true");
//    preorder(root);
    vector <int> x = printzigzag(root);
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" ";
    }



}
