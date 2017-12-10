#include<iostream>
#include<stack>
using namespace std;
template<typename T>
class Queue
{
    public:
        stack<T> inbox;
        stack<T> outbox;
        void queue(T x)
        {
            inbox.push(x);
        }
        T dequeue()
        {
            if(outbox.empty())
            {
                while(!inbox.empty())
                {
                    T temp;
                    temp = inbox.top();
                    outbox.push(temp);
                    inbox.pop();
                }
            }
            T temp1;
            temp1=outbox.top();
            outbox.pop();
            return temp1;
        }
};
int main()
{
    Queue<int> q;
    q.queue(10);
    q.queue(20);
    q.queue(30);
    q.queue(40);
    q.queue(50);
    q.queue(60);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}
