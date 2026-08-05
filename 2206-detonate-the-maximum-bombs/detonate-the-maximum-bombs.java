class Solution {
    public int maximumDetonation(int[][] bombs) {

int n = bombs.length;
List<List<Integer>> adj = new ArrayList<>();
for (int i =0;i<n;i++){
    adj.add(new ArrayList<>());
}
for(int i=0;i<n;i++){
    long x = bombs[i][0];
    long y = bombs[i][1];
    long z = bombs[i][2];
    for (int j=0;j<n;j++){
        if(i==j){
            continue;
        }
        long x1 = bombs[j][0];
        long y1 = bombs[j][1];
        long dx = x-x1;
        long dy = y-y1;
        if(dx*dx + dy*dy <= z*z){
            adj.get(i).add(j);
        }
    }
}
    int ans = 0;
    for(int i=0;i<n;i++){
        boolean[] visited = new boolean[n];
        ans = Math.max(ans,solve(i,adj,visited));

    }
    return ans;

    };
    private int solve(int node, List<List<Integer>> adj, boolean[] visited){
        int count=1;
        visited[node]=true;
        for(int i: adj.get(node)){
            if(!visited[i]){
                count += solve(i,adj,visited);
            }
        }
        return count;
    }
    
}