#include <bits/stdc++.h>
using namespace std;

class SeatManager
{
public:
    SeatManager(int n)
    {
        marker = 1;
    }

    int reserve()
    {
        if (!available.empty())
        {
            int seatNumber = available.top();
            available.pop();
            return seatNumber;
        }

        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber)
    {
        available.push(seatNumber);
    }

private:
    int marker;
    priority_queue<int, vector<int>, greater<int>> available;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */