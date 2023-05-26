#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() 
{
    const int inf = INT_MAX;
    vector<int> a, b, c, d;
    int n, s, f, m;
    cin >> n >> s >> f >> m;

    a.resize(m);
    b.resize(m);
    c.resize(m);
    d.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> distination(n, inf);
    distination[s - 1] = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (distination[c[j] - 1] > d[j] && distination[a[j] - 1] != inf && b[j] >= distination[a[j] - 1])
            {
                distination[c[j] - 1] = d[j];
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (distination[i] == inf) 
        {
            distination[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (distination[i] == 0)
        {
            distination[i] = -1;
            distination[s - 1] = 0;
        }
    }

    int ans = distination[f - 1];
    cout << ans << endl;
}