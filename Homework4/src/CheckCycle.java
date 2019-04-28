/**
 * @program: Homework4
 * @description: Check whether there is any cycle in the Graph
 * @author: Zekun Zhang
 * @create: 2019-04-28 00:10
 */

public class CheckCycle {
    private boolean[] marked;
    private boolean isAcyclic;

    CheckCycle(Graph graph) {
        marked = new boolean[graph.V()];
        isAcyclic = true;
        for (int i = 0; i < graph.V(); i++) {
            if (!marked[i]) {
                dfs(graph, i, i);
            }
        }
    }

    private void dfs(Graph graph, int v, int w) {
        marked[v] = true;
        for (int i : graph.adj(v)) {
            if (!marked[i]) {
                dfs(graph, i, v);
            } else if (i != w) {
                isAcyclic = false;
            }
        }
    }

    public boolean isAcyclic() {
        return isAcyclic;
    }

}
