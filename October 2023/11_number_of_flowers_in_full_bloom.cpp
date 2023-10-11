#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end());

        sort(flowers.begin(), flowers.end());

        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> heap;

        vector<int> ans;

        int i = 0, n = flowers.size();
        for (int person : sortedPeople)
        {
            while (i < n && flowers[i][0] <= person)
            {
                heap.push(flowers[i][1]);
                i++;
            }

            while (!heap.empty() && heap.top() < person)
                heap.pop();

            m[person] = heap.size();
        }

        for (int person : people)
            ans.push_back(m[person]);

        return ans;
    }
};