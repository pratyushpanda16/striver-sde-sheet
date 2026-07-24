class Solution:
    def JobScheduling(self, Jobs: List[List[int]]) -> List[int]:
        Jobs.sort(key=lambda x: x[2], reverse=True)

        max_deadline = max(job[1] for job in Jobs)
        slot = [-1] * (max_deadline + 1)

        count_jobs = 0
        total_profit = 0

        for i, job in enumerate(Jobs):
            deadline, profit = job[1], job[2]
            for j in range(deadline, 0, -1):
                if slot[j] == -1:
                    slot[j] = i
                    count_jobs += 1
                    total_profit += profit
                    break

        return [count_jobs, total_profit]
