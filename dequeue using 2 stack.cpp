#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack <int> input;
    stack <int> output;
public:
    void enqueue(int data)
    {
        input.push(data);
    }

    void dequeue()
    {
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        cout<<output.top();
        output.pop();
    }

};

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      enqueue(i);
  }
}
