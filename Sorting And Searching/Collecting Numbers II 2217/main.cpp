#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int ans = 1;

void update(int u, int v, int val, vector<pii> &A, vector<int> &pos)
{
    int n = A.size();
    if (pos[u] > pos[v])
        swap(u, v);
    int i = pos[u], j = pos[v];

    // Adjusting for i's left
    if (i > 0 && A[i - 1].second > A[i].second)
        ans += val;
    // Adjusting for j's right
    if (j < n - 1 && A[j].second > A[j + 1].second)
        ans += val;

    if (i + 1 == j)
    {
        // If adjacent
        if (A[i].second > A[j].second)
            ans += val;
    }
    else
    {
        if (A[i].second > A[i + 1].second)
            ans += val;
        if (A[j - 1].second > A[j].second)
            ans += val;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pii> A(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    for (int i = 1; i < n; i++)
        if (A[i - 1].second > A[i].second)
            ans++;
    for (int i = 0; i < n; i++)
        pos[A[i].second] = i; // Old to new index

    while (k--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        update(u, v, -1, A, pos);

        // Now swap and update correspondingly
        int i = pos[u], j = pos[v];
        swap(A[i].second, A[j].second);
        swap(pos[u], pos[v]);

        update(u, v, 1, A, pos);

        cout << ans << "\n";
    }
}