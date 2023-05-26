#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

int main()
{
    int si, sj;
    cin >> si >> sj;
    vector<vector<int>> a(si, vector<int>(sj));

    for (int i = 0; i < si; i++)
        for (int j = 0; j < sj; j++)
            cin >> a[i][j];

    vector<string> ans;
    int maxi = -1;

    for (int i = 0; i < si; i++)
        for (int j = 0; j < sj; j++)
        {
            if (a[i][j] == 1)
                maxi = i;
        }

    assert(maxi >= 0);

    for (int dj = 0; dj < sj; dj++)
    {
        int minj = dj;
        for (int j = dj; j < sj; j++)
        {
            if (a[maxi][j] < a[maxi][minj])
                minj = j;
        }

        if (minj != dj)
        {
            for (int i = 0; i < si ; i++)
            {
                swap(a[i][minj], a[i][dj]);
            }

            ans.push_back("C " + to_string(dj + 1) + " " + to_string(minj + 1));
        }
    }

    for (int di = 0; di < si; di++)
    {
        int mini = di;
        for (int i = di; i < si; i++)
        {
            if (a[i][0] < a[mini][0])
                mini = i;
        }

        if (mini != di)
        {
            for (int j = 0; j < sj; j++)
            {
                swap(a[mini][j], a[di][j]);
            }

            ans.push_back("R " + to_string(di + 1) + " " + to_string(mini + 1));
        }
    }
    
    cout << ans.size() << endl;

    for (string s : ans)
    {
        cout << s << endl;
    }

}
