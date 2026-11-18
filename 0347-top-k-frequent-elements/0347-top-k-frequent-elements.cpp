class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        using Freq = int;
        using K = int;

        std::unordered_map<K, std::pair<Freq, std::list<K>::iterator>> cache;
        std::unordered_map<Freq, std::list<K>> freqs;

        int maxFreq = 0;

        for (const auto num : nums) {
            if (auto it = cache.find(num); it != cache.end()) {
                auto &[fr, it2] = it->second;

                freqs[fr + 1].splice(
                    freqs[fr + 1].end(),
                    freqs[fr],
                    it2
                );

                ++fr;
                maxFreq = std::max(maxFreq, fr);
            } else {
                auto it2 = freqs[1].insert(freqs[1].end(), num);
                cache[num] = {1, it2};
                maxFreq = std::max(maxFreq, 1);
            }
        }

        std::vector<int> res;
        res.reserve(k);

        for (int i = maxFreq; i >= 1; --i) {
            if (auto it = freqs.find(i); it != freqs.end()) {
                for (const auto num : it->second) {
                    res.push_back(num);

                    if (res.size() == k) {
                        return res;
                    }
                }
            }
        }

        return res;
    }
};