class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int n=graph.length;
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[n];

        for (int i = 0; i < graph.length; i++) {
            for (int nbr : graph[i]) {
                adj.get(nbr).add(i);
                indegree[i] += 1;
            }
        }

        // step 2
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.add(i);
        }
        // step 3
        ArrayList<Integer> linearorder = new ArrayList<>();

        while (!q.isEmpty()) {
            int curr = q.poll();
            linearorder.add(curr);

            for (int nbr : adj.get(curr)) {
                indegree[nbr] -= 1;
                if (indegree[nbr] == 0)
                    q.add(nbr);
            }
        }

        Collections.sort(linearorder);

        return linearorder;
    }
}