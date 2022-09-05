#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pii> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    int count = 0;
    set<pii> S;

    for (int i = 0; i < n; i++)
    {
        set<pii>::iterator itr = S.upper_bound(A[i]);
        if (itr != S.end())
        {
            S.erase(itr);
        }
        else
            count++;
        S.insert(A[i]);
    }

    cout << count << "\n";
}