class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0

        sign = 1
        i = 0
        if s[0] == '-':
            sign = -1
            i = 1
        elif s[0] == '+':
            i = 1

        res = 0
        INT_MAX, INT_MIN = 2**31 - 1, -2**31
        while i < len(s) and s[i].isdigit():
            res = res * 10 + int(s[i])
            if sign == 1 and res > INT_MAX:
                return INT_MAX
            if sign == -1 and -res < INT_MIN:
                return INT_MIN
            i += 1

        return sign * res
