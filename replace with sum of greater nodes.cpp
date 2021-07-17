#include<iostream>
#include<unordered_map>

using namespace std;
class node{
public:
    int data;
    node*left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
int sum[1000000]={0};
node *buildtree(int *arr,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    node *root = new node(arr[mid]);
    root->left = buildtree(arr,s,mid-1);
    root->right = buildtree(arr,mid+1,e);
    return root;
}
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
void replacewithgreater(node * root,unordered_map<int,int> h)
{
    if (root==NULL)
    {
        return;
    }
    swap(root->data,h[root->data]);
    // for(auto x:h[root->data])
    // {
    //     swap(root->data,);
    // }
    replacewithgreater(root->left,h);
    replacewithgreater(root->right,h);
}

int main()
{
    unordered_map<int,int> h;
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        sum[i] = arr[i];
        for(int j=i+1;j<n;j++)
        {
            sum[i] +=arr[j];
        }

    }
    sum[n-1] = arr[n-1];
    node *root = buildtree(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        h.insert({arr[i],sum[i]});
    }
    // cout<<h[root->data];
    // for(auto x:h)
    // {
    //     cout<<x.first<<"--> "<<x.second<<endl;
    // }

    replacewithgreater(root,h);
    inorder(root);

//    for(int i=0;i<n;i++)
//    {
//        cout<<sum[i]<<" ";
//    }





}
