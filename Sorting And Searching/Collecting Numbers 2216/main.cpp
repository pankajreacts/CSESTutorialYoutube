#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (A[i].second < A[i - 1].second)
            ans++;
    cout << ans << "\n";
}