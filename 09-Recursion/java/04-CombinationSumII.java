class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Map<Integer, Integer> freqMap = new TreeMap<>();
        for (int c : candidates) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        List<int[]> pairs = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            pairs.add(new int[]{entry.getKey(), entry.getValue()});
        }

        List<List<Integer>> result = new ArrayList<>();
        backtrack(pairs, 0, target, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(List<int[]> pairs, int index, int remaining, List<Integer> current, List<List<Integer>> result) {
        if (remaining == 0) {
            result.add(new ArrayList<>(current));
            return;
        }
        if (index == pairs.size()) return;

        int value = pairs.get(index)[0];
        int count = pairs.get(index)[1];

        for (int copies = 0; copies <= count; copies++) {
            if (value * copies > remaining) break;

            for (int j = 0; j < copies; j++) {
                current.add(value);
            }
            backtrack(pairs, index + 1, remaining - value * copies, current, result);
            for (int j = 0; j < copies; j++) {
                current.remove(current.size() - 1);
            }
        }
    }
}
