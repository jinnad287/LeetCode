class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n <= 1) return s;
        long long ans = s;

        // 1. Sequence 1 always reaches its highest point at the LAST EVEN index
        // If n - 1 is even, that is our target; otherwise it's n - 2
        long long last_even = (n - 1) % 2 == 0 ? (n - 1) : (n - 2);
        long long evens_count = last_even / 2;
        long long max_seq1 = s + evens_count * ((long long)m - 1);

        // 2. Sequence 2 always reaches its highest point at the LAST ODD index
        // If n - 1 is odd, that is our target; otherwise it's n - 2
        long long last_odd = (n - 1) % 2 == 1 ? (n - 1) : (n - 2);
        long long odds_count = (last_odd + 1) / 2;
        long long max_seq2 = s + (odds_count * (long long)m) - (odds_count - 1);

        // Return the highest value seen: starting point, seq1 peak, or seq2 peak
        return max({ans, max_seq1, max_seq2});
    }
};