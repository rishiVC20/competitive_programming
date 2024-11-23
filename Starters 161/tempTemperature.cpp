#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to check if a given unsavoriness U is feasible
bool isFeasible(const vector<int>& A, int N, int K, int U) {
    vector<vector<bool>> dp(N, vector<bool>(K + 1, false));
    
    // Initialize for step 1
    for (int j = 0; j <= K; ++j) {
        dp[0][j] = true;
    }

    // Fill DP table
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= j; ++k) { // Check with `k` changes
                if (dp[i - 1][k]) { // If previous step was valid
                    if (abs(A[i] - A[i - 1]) <= U) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    // Check if feasible with ≤ K changes
    for (int j = 0; j <= K; ++j) {
        if (dp[N - 1][j]) return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Binary search for the minimum unsavoriness
        int left = 0, right = *max_element(A.begin(), A.end());
        int result = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isFeasible(A, N, K, mid)) {
                result = mid; // Update result
                right = mid - 1; // Try for smaller unsavoriness
            } else {
                left = mid + 1; // Increase unsavoriness
            }
        }

        cout << result << endl; // Minimum possible unsavoriness
    }
    return 0;
}
