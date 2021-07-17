#include<iostream>
#include<queue>
using namespace std;
int pre[1005];
int inor[1005];
int i=0;
class node
{
	public:
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data=d;
		left=NULL;
		right = NULL;
	}

};
node* buildbst(int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int t = pre[i++];
	node *root = new node(t);
	int k=-1;
	for(int j=s;j<=e;j++)
	{
		if(inor[j]==t)
		{
			k = j;
			break;
		}
	}
	root->left = buildbst(s,k-1);
	root->right = buildbst(k+1,e);
	return root;
}
void printlevelwise(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *x= q.front();
        q.pop();
        if(x==NULL)
           {
                cout<<endl;
                if(!q.empty())
                {
                    q.push(NULL);
                }
                else
                {
                    return;
                }


           }
           else
           {
               cout<<x->data<<" ";
               if(x->left)
               {
                   q.push(x->left);
               }
               if(x->right)
               {
                   q.push(x->right);
               }
           }
    }
}
int height(node *root)
{
    if(root ==NULL)
    {
        return 0;
    }
    int op1 = height(root->left) + 1;
    int op2 = height(root->right) +1;
    return max(op1,op2);
}
bool isbst(node *root,int mini,int maxi)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=mini &&root->data<=maxi&&isbst(root->left,mini,root->data)&&isbst(root->right,root->data,maxi))
    {
        return true;
    }
    return false;
}
int ans =0;
int largesttree(node *root)
{
    if(root==NULL)
    {
        return ans= 0;
    }
    if(isbst(root,INT_MIN,INT_MAX))
    {
        return ans=  height(root->left)+height(root->right)+1;
    }
    else if(isbst(root->left,INT_MIN,INT_MAX)&&(height(root->left)>=height(root->right)))
	{
		return ans = height(root->left);
	}
	else{
        return ans =  height(root->right);
	}
	return ans;

}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>inor[i];
	}
	node *root = buildbst(0,n-1);
//	printlevelwise(root);
    cout<<largesttree(root);

}
