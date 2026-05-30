#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_optimal_path(int N, const int A[], int dp[][2]) {
    cout << "Optimal Path Station Sequence (0-indexed): ";

    int i = 0, skipped = 0, skipped_station = -1;
    while (i < N) {
        int move_1 = (i + 1 < N) ? dp[i + 1][skipped] : 0;
        int move_2 = (i + 2 < N) ? dp[i + 2][skipped] : 0;
        int take_val = A[i] + max(move_1, move_2);

        if (skipped == 1 || dp[i][0] == take_val) {
            cout << " -> " << i;

            i += (dp[i][skipped] == A[i] + move_1) ? 1 : 2;
        } else {
            skipped_station = i;
            skipped = 1;

            int skip_move_1 = (i + 1 < N) ? dp[i + 1][1] : 0;
            i += (dp[i][0] == skip_move_1) ? 1 : 2;
        }
    }
    cout << "\n";
    if (skipped_station != -1) {
        cout << "Special Power Used to ignore energy at Station: " << skipped_station << "\n";
    } else {
        cout << "Special Power was not needed.\n";
    }
} // Properly closed print_optimal_path here

int DP(int N, const int A[]) {
    if (N == 0) return 0;

    int dp[N+2][2];      // I'm seted it N+2 when robert in station 5 will search about 6 and 7 additional NUll charatecre

    dp[N][0] = dp[N][1] = 0;
    dp[N + 1][0] = dp[N + 1][1] = 0;    //N+1 for NUll Character in the end of array


    for (int i = N - 1; i >= 0; --i) {
        dp[i][1] = A[i] + max(dp[i + 1][1], dp[i + 2][1]);

        int take = A[i] + max(dp[i + 1][0], dp[i + 2][0]);
        int skip = 0 + max(dp[i + 1][1], dp[i + 2][1]);

        dp[i][0] = max(take, skip);
    }
    int result = dp[0][0];

     print_optimal_path(N, A, dp);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        int A[N];

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int result = DP(N, A);
        cout << result << "\n";
    }

    return 0;
}