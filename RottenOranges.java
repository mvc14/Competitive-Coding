class Solution {
    int[][] grid;
    public int orangesRotting(int[][] grid) {
        this.grid = grid;

        int fresh = 0;
        if (grid.length == 0) return 0;
        int count = 0;

        Queue<int[]> q = new LinkedList<>(); 

        // count indexes of rotten
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    q.add(new int[]{i, j});
                } else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;
        int[][] directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

        while (!q.isEmpty()) {
            int n = q.size();
            boolean rottenAny = false;
            for (int i = 0; i < n; i++) {
                int[] arr = q.poll();
                int row = arr[0], col = arr[1];
                for (int[] d : directions) {
                    int newRow = row + d[0]; int newCol = col + d[1];
                    if (checkBounds(newRow, newCol) && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.add(new int[] {newRow, newCol}); fresh--;
                        rottenAny = true;
                    }
                }
            }

            if (rottenAny) {
                count++;
            }
        }
        return fresh == 0 ? count : -1;
    }

    public boolean checkBounds(int row, int col) {
        return (row >= 0 && row < grid.length && col >= 0 && col < grid[0].length);
    }
}
