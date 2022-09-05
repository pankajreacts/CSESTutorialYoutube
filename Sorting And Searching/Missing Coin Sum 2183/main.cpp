#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    if (A[0] > 1)
    {
        cout << "1\n";
        return 0;
    }

    ll R = 0; // Maximum value upto which we can make sum without missing any value from 0 to R
    for (int i = 0; i < n; i++)
    {
        if (R + 1 < A[i])
        {
            cout << R + 1 << "\n";
            return 0;
        }
        R += A[i];
    }
    cout << R + 1 << "\n";
}