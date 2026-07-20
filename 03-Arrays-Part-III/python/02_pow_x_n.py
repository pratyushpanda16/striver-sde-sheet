class Solution:
    def myPow(self, x: float, n: int) -> float:
        power = n
        if power < 0:
            x = 1 / x
            power = -power

        result = 1.0
        current_product = x

        while power > 0:
            if power & 1:
                result *= current_product
            current_product *= current_product
            power >>= 1

        return result
