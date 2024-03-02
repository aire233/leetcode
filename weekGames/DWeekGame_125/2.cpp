#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for (int num : nums) {
            minHeap.push(static_cast<long long>(num));
        }

        int operations = 0;
        while (!minHeap.empty() && minHeap.top() < k) {
            if (minHeap.size() == 1) {
                return -1;
            }

            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            long long merged = x * 2 + y;
            minHeap.push(merged);

            operations++;
        }

        return minHeap.empty() || minHeap.top() >= k ? operations : -1;
    }
};