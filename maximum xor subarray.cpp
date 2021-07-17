#include<iostream>
#include<climits>
using namespace std;

int arr[1005];
int maximumxorsubarray(int n)
{
	int maxans = INT_MIN;
	int xorr =0;
	for(int i=0;i<n;i++)
	{
		int curr = i;
		for(int j=i;j<n;j++)
		{
		  xorr = arr[curr]^arr[j];
		  maxans = max(maxans,xorr);

		}
	}
	return maxans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<maximumxorsubarray(n);
}
