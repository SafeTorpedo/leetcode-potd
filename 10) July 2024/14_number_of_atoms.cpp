#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int n = formula.size();

        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n)
        {
            if (formula[i] == '(')
            {
                st.push(unordered_map<string, int>());
                i++;
            }
            else if (formula[i] == ')')
            {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                string multiplier;
                while (i < n && isdigit(formula[i]))
                {
                    multiplier.push_back(formula[i]);
                    i++;
                }

                if (!multiplier.empty())
                {
                    int mult = stoi(multiplier);
                    for (auto &it : curr)
                    {
                        string element = it.first;
                        int count = it.second;

                        curr[element] = count * mult;
                    }
                }

                for (auto &it : curr)
                {
                    string element = it.first;
                    int count = it.second;

                    st.top()[element] += count;
                }
            }
            else
            {
                string currElement;
                currElement.push_back(formula[i]);
                i++;

                while (i < n && isalpha(formula[i]) && islower(formula[i]))
                {
                    currElement.push_back(formula[i]);
                    i++;
                }

                string count;
                while (i < n && isdigit(formula[i]))
                {
                    count.push_back(formula[i]);
                    i++;
                }

                int cnt = count.empty() ? 1 : stoi(count);
                st.top()[currElement] += cnt;
            }
        }

        string ans;
        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        for (auto &it : sortedMap)
        {
            string element = it.first;
            int count = it.second;

            ans += element;
            if (count > 1)
                ans += to_string(count);
        }

        return ans;
    }
};