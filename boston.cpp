#include<iostream>
#include<cmath>
using namespace std;
int sumofdigits(int n)
{
	int sum = 0,rem=0;
	while(n>0)
	{
		rem = n%10;
		sum+= rem;
		n/=10;
	}
	return sum;
}
int sumofprimefactors(int n)
{
	int sum =0;
    int summ=0;
	int x = n;
	while(n%2==0)
	{
		sum+=2;
		n/=2;
	}
	for(int i=3;i<=n;i=i+2)
	{
		while(n%i==0)
        {
            int x =i;
            if(i>=11)
            {
                while(i>0)
                {
                int rem = i%10;
                sum+=rem;
                i=i/10;
                }
            }
            else
            {
                sum +=x;

            }
            n/=i;

        }

	}
	return sum;
}
int main() {
	int n;
	cin>>n;
	cout<<sumofprimefactors(n);
	// if(sumofdigits(n)==sumofprimefactors(n))
	// {
	// 	cout<<1;
	// }
	// else
	// {
	// 	cout<<0;
	// }
	return 0;
}
