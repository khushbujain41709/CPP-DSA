// It is done only in Bottom Up Approach - Tabulation
// For 1D DP Space Optimization, if dp[i] = f(dp[i-1] , dp[i-2]) so make dp[i] -> dp[2], dp[i-1] -> dp[1], dp[i-2] -> dp[0]
// Then shift operations, dp[0] = dp[1]; and dp[1] = dp[2];

// 2D DP Space Optimization cannot be applied if all elements of grid is given.
