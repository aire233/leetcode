static auto _ = []() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int mn = ranges::min(enemyEnergies);
        if (currentEnergy < mn) {
            return 0;
        }
        long long s = reduce(enemyEnergies.begin(), enemyEnergies.end(), 0LL);
        return (currentEnergy + s - mn) / mn;
    }
};