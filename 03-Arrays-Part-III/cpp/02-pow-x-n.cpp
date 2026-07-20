class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;
        double currentProduct = x;

        while (power > 0) {
            if (power & 1) {
                result *= currentProduct;
            }
            currentProduct *= currentProduct;
            power >>= 1;
        }

        return result;
    }
};
