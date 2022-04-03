#include <iostream>
#include <vector>
#include <string>

using namespace std;

using vs = vector<string>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto game = vs(n);
	for (int i = 0; i < n; ++i) {
		cin >> game[i];
	}

	auto ans = int{ 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			const auto& b = game[i][j];
			auto now = int{ 1 };
			auto k = int{ 1 };
			while (i + k < n && j + k < m) {
				if (b == game[i][j + k] &&
					b == game[i + k][j] &&
					b == game[i + k][j + k]) {
					now = (k + 1) * (k + 1);
				}

				++k;
			}

			if (ans < now) {
				ans = now;
			}
		}
	}

	cout << ans;

	return 0;
}