#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> scores(N);
        int currentTotal = 0;

        for (int i = 0; i < N; ++i) {
            cin >> scores[i];
            currentTotal += scores[i];
        }

        int maxPossibleScore = (N + 1) * 100;
        int requiredTotal = maxPossibleScore / 2;

        int minScoreNeeded = requiredTotal - currentTotal;

        if (minScoreNeeded > 100) {
            cout << -1 << endl;
        } else if (minScoreNeeded <= 0) {
            cout << 0 << endl;
        } else {
            cout << minScoreNeeded << endl;
        }
    }

    return 0;
}