class Solution:
    def maxOfMin(self, arr: List[int]) -> List[int]:
        n = len(arr)
        result = [0] * n
        left = [0] * n
        right = [0] * n
        stack = []

        for i in range(n):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            left[i] = -1 if not stack else stack[-1]
            stack.append(i)

        stack.clear()

        for i in range(n - 1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            right[i] = n if not stack else stack[-1]
            stack.append(i)

        for i in range(n):
            window_size = right[i] - left[i] - 1
            idx = window_size - 1
            result[idx] = max(result[idx], arr[i])

        for i in range(n - 2, -1, -1):
            result[i] = max(result[i], result[i + 1])

        return result
