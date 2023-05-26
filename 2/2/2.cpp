#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> Read()
{
    int si, sj;
    cin >> si >> sj;
    vector<vector<char>> a(si, vector<char>(sj));

    for (int i = 0; i < si; i++)
        for (int j = 0; j < sj; j++)
            cin >> a[i][j];

    return a;
}

vector<vector<char>> dMirror(vector<vector<char>> a)
{
    int si = (int)a.size(), sj = (int)a[0].size();
    vector<vector<char>> r(si, vector<char>(sj));

    for (int i = 0; i < si; i++)
        for (int j = 0; j < sj; j++)
            r[j][i] = a[i][j];

    return r;
}

vector<vector<char>> hMirror(vector<vector<char>> a)
{
    int si = (int)a.size(), sj = (int)a[0].size();
    vector<vector<char>> r(si, vector<char>(sj));

    for (int i = 0; i < si; i++)
        for (int j = 0; j < sj; j++)
            r[si - 1 - i][j] = a[i][j];

    return r;
}

vector<vector<char>> Remove(vector<vector<char>> a)
{
    int si = (int)a.size(), sj = (int)a[0].size();
    int mini = si,maxi=-1, minj = sj, maxj = -1;


    for (int i = 0; i < si; i++)
        for (int j = 0; j < sj; j++)
            if (a[i][j] == '#')
            {
                mini = min(mini, i);
                minj = min(minj, j);
                maxi = max(maxi, i);
                maxj = max(maxj, j);
            }
    
    if (maxi == -1)
        return vector<vector<char>>();

    vector<vector<char>> r(maxi-mini+1, vector<char>(maxj-minj+1));

    for (int i = mini; i <= maxi; i++)
        for (int j = minj; j <= maxj; j++)
            r[i - mini][j - minj] = a[i][j];

    return r;
}

vector<vector<char>> Rotate(vector<vector<char>> a)
{
    return hMirror(dMirror(a));
}


int main()
{
    vector<vector<char>> a = Remove(Read());
    vector<vector<char>> b = Remove(Read());

    for (int i = 0; i < 2; i++)
    {
        a = hMirror(a);

        for (int j = 0; j < 4; j++)
        {
            a = Rotate(a);
            if (a == b)
            {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}