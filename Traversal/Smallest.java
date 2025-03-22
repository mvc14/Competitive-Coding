class Smallest {

    int val;
    // approach it by dfs
    public int kthSmallest(TreeNode root, int k) {
        int check = -10000; // compares the smallest
        val = check; // holds our current smallest
        dfs(root, k, 0, check);
        return val;
    }


    // currInd -> keeps track of the curr smallest
    // val -> keeps track of the root val

    public int dfs(TreeNode root, int k, int currInd, int check) {
        if (val != check) {
            return currInd;
        }

        if (root == null) {
            return currInd;
        }

        currInd = dfs(root.left, k, currInd, check) + 1;

        if (currInd == k) {
            val = root.val;
            return currInd;
        }

        return dfs(root.right, k, currInd, check);
    }
}
