class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<int> nums;
        vector<int> fact(n + 1, 1);

        for (int i = 1; i <= n; ++i)
            nums.push_back(i);

        for (int i = 2; i <= n; ++i)
            fact[i] = fact[i - 1] * i;

        --k;

        for (int i = n - 1; i >= 0; --i) {
            int j = k / fact[i];
            k %= fact[i];
            res += to_string(nums[j]);
            nums.erase(nums.begin() + j);
        }

        return res;
    }
};
