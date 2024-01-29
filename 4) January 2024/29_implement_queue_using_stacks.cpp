#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        int ans = peek();
        output.pop();
        return ans;
    }

    int peek()
    {
        if (output.empty())
        {
            while (input.size())
                output.push(input.top()), input.pop();
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }

private:
    stack<int> input, output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */