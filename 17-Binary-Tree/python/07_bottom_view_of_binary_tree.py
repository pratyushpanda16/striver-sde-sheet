from collections import deque

class Solution:
    def bottomView(self, root):
        if not root:
            return []

        hd_map = {}
        q = deque([(root, 0)])

        while q:
            node, hd = q.popleft()
            hd_map[hd] = node.data

            if node.left:
                q.append((node.left, hd - 1))
            if node.right:
                q.append((node.right, hd + 1))

        return [hd_map[hd] for hd in sorted(hd_map.keys())]
