// #include <iostream>
// #include <algorithm>
// #include <vector>
//
// using namespace std;
//
// int N;
// vector<int> A;
//
// int f(int i, int skipped) {
//     if (i > N) {
//         return 0;
//     }
//
//     if (skipped == 1) {
//         int move_1 = f(i + 1, 1);
//         int move_2 = f(i + 2, 1);
//         return A[i - 1] + max(move_1, move_2);
//     }
//     else {
//         int take = A[i - 1] + max(f(i + 1, 0), f(i + 2, 0));
//
//         int skip = 0 + max(f(i + 1, 1), f(i + 2, 1));
//
//         return max(take, skip);
//     }
// }
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//
//     // Read input directly into the global variables
//     if (cin >> N) {
//
//         A.resize(N);
//
//         // Populate the vector
//         for (int i = 0; i < N; ++i) {
//             cin >> A[i];
//         }
//
//         int result = f(1, 0);
//
//         cout << result << "\n";
//     }
//
//     return 0;
// }
