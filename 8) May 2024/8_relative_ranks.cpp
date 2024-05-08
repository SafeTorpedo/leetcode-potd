#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int N = score.size();

        int M = *max_element(score.begin(), score.end());
        vector<int> scoreToIndex(M + 1, 0);
        for (int i = 0; i < N; i++)
        {
            scoreToIndex[score[i]] = i + 1;
        }

        const vector<string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        vector<string> rank(N);
        int place = 1;
        for (int i = M; i >= 0; i--)
        {
            if (scoreToIndex[i] != 0)
            {
                int originalIndex = scoreToIndex[i] - 1;
                if (place < 4)
                {
                    rank[originalIndex] = MEDALS[place - 1];
                }
                else
                {
                    rank[originalIndex] = to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};