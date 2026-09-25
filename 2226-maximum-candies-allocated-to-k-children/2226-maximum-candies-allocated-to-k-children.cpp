class Solution {
public:
    using VI = vector<int>;
    using LL = long long;
    int maximumCandies(VI& A, LL T) {
        LL i = 0,
           j = *max_element(A.begin(), A.end());
        while (i < j) {
            auto k = (i + j + 1LL) / 2;
            auto take = accumulate(A.begin(), A.end(), 0LL, [=](auto t, auto x) { return t + x / k; });
            if (T <= take)
                i = k;
            else
                j = k - 1;
        }
        return i;
    }
};