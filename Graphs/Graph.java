// Thought process: Trying to find if a cycle exists or not
// problem: https://leetcode.com/problems/course-schedule/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
// using Kahn's Algorithm

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indegrees = new int[numCourses];
        List<List<Integer>> adj = new ArrayList<>(numCourses);
        
        // setup 
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] prerequisite : prerequisites) {
            adj.get(prerequisite[1]).add(prerequisite[0]);
            indegrees[prerequisite[0]]++;
        }

        // if no indegrees, add it to da queue
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.add(i);
            }
        }

        int visited = 0;
        while (!q.isEmpty()) { // start with zero indegree node 
            int node = q.poll();
            visited++;

            for (int neighbor : adj.get(node)) { 
                // check the immediate neighbors and decrement the indegrees as we go 
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) { // if no indegrees, add it to da queue
                    q.offer(neighbor);
                }
            }
        }

        return visited == numCourses; // if equal, no cycles found
    }
}
