#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int start = 0; // starting index of the window
    set<int> S;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (S.count(A[i]))
        {
            S.erase(A[start]);
            start++;
        }
        S.insert(A[i]);
        ans = max(ans, (int)S.size());
    }
    cout << ans << "\n";
}