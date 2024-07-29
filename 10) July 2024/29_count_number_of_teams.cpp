#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int teams = 0;
        vector<vector<int>> increasingCache(n, vector<int>(4, -1));
        vector<vector<int>> decreasingCache(n, vector<int>(4, -1));

        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            teams += countIncreasingTeams(rating, startIndex, 1, increasingCache) + countDecreasingTeams(rating, startIndex, 1, decreasingCache);
        }

        return teams;
    }

private:
    int countIncreasingTeams(const vector<int> &rating, int currentIndex, int teamSize, vector<vector<int>> &increasingCache)
    {
        int n = rating.size();

        if (currentIndex == n)
            return 0;

        if (teamSize == 3)
            return 1;

        if (increasingCache[currentIndex][teamSize] != -1)
        {
            return increasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++)
        {
            if (rating[nextIndex] > rating[currentIndex])
            {
                validTeams += countIncreasingTeams(rating, nextIndex, teamSize + 1, increasingCache);
            }
        }

        return increasingCache[currentIndex][teamSize] = validTeams;
    }

    int countDecreasingTeams(const vector<int> &rating, int currentIndex, int teamSize, vector<vector<int>> &decreasingCache)
    {
        int n = rating.size();

        if (currentIndex == n)
            return 0;

        if (teamSize == 3)
            return 1;

        if (decreasingCache[currentIndex][teamSize] != -1)
        {
            return decreasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++)
        {
            if (rating[nextIndex] < rating[currentIndex])
            {
                validTeams += countDecreasingTeams(
                    rating, nextIndex, teamSize + 1, decreasingCache);
            }
        }

        return decreasingCache[currentIndex][teamSize] = validTeams;
    }
};