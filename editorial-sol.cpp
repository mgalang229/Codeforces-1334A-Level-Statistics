#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		bool checker = true;
		vector<int> p(n);
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i] >> c[i];
		}
		for (int i = 0; i < n; i++) {
			checker &= (p[i] >= c[i]);
			if (i < n - 1) {
				checker &= (p[i] <= p[i + 1]);
				checker &= (c[i] <= c[i + 1]);
			}
		}
		if (!checker) {
			cout << "NO" << '\n';
			continue;
		}
		int prev_failed = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] - c[i] < prev_failed) {
				checker = false;
				break;
			}
			prev_failed = p[i] - c[i];
		}
		cout << (checker ? "YES" : "NO") << '\n';
	}
	return 0;
}
