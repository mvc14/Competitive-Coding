class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int n = intervals.length;
        if (n <= 1) {
            return intervals;
        }

        ArrayList<int[]> res = new ArrayList<>();
        int[] tmp = intervals[0];

        for (int i = 1; i < n; i++) {
            int[] cmp = intervals[i];
            if (cmp[0] <= tmp[1]) {
                tmp[1] = Math.max(tmp[1], cmp[1]);
                // tmp[0] = Math.min(tmp[0], cmp[0]);
            } else {
                res.add(tmp);
                tmp = cmp;
            }
        }

        res.add(tmp);

        return res.toArray(new int[res.size()][]);
    }
}
