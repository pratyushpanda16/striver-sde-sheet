class Solution:
    def merge(self, arr, low, mid, high):
        temp = []
        left, right = low, mid + 1
        cnt = 0

        while left <= mid and right <= high:
            if arr[left] <= arr[right]:
                temp.append(arr[left])
                left += 1
            else:
                temp.append(arr[right])
                right += 1
                cnt += (mid - left + 1)

        while left <= mid:
            temp.append(arr[left])
            left += 1

        while right <= high:
            temp.append(arr[right])
            right += 1

        for i in range(low, high + 1):
            arr[i] = temp[i - low]

        return cnt

    def mergeSort(self, arr, low, high):
        if low >= high:
            return 0

        mid = low + (high - low) // 2

        cnt = 0
        cnt += self.mergeSort(arr, low, mid)
        cnt += self.mergeSort(arr, mid + 1, high)
        cnt += self.merge(arr, low, mid, high)

        return cnt

    def numberOfInversions(self, arr):
        return self.mergeSort(arr, 0, len(arr) - 1)
