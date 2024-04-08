#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        vector<int> choice(2);
        choice[0] = count(students.begin(), students.end(), 0);
        choice[1] = count(students.begin(), students.end(), 1);

        int i = 0, n = sandwiches.size();
        while (i < n)
        {
            if (choice[sandwiches[i]] > 0)
                choice[sandwiches[i]]--;
            else
                break;

            i++;
        }

        return choice[0] + choice[1];
    }
};