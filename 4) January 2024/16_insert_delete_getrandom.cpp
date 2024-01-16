#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;
        else
        {
            arr.push_back(val);
            m[val] = arr.size() - 1;

            return true;
        }
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;
        else
        {
            int last = arr.back();
            arr[m[val]] = arr.back();

            arr.pop_back();
            m[last] = m[val];
            m.erase(val);
            return true;
        }
    }

    int getRandom()
    {
        return arr[rand() % arr.size()];
    }

private:
    vector<int> arr;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */