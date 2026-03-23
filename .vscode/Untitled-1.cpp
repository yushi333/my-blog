#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> pre_max_pos(n + 1);
        pre_max_pos[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i] >= a[pre_max_pos[i - 1]])
                pre_max_pos[i] = i;
            else
                pre_max_pos[i] = pre_max_pos[i - 1];
        }

        int cnt = 0;
        int cur = n;
        while (cur >= 1) {
            ++cnt;
            cur = pre_max_pos[cur] - 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}