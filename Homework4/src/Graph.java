
/**
 * @program: Homework4
 * @description: Graph data structure
 * @author: Zekun Zhang
 * @create: 2019-04-26 22:31
 */

public class Graph {
    private int V;
    private int E;

    private Bag<Integer>[] adj;

    Graph(int V) {
        this.V = V;
        this.E = 0;
        adj = (Bag<Integer>[]) new Bag[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new Bag<>();
        }

    }

    void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v);
        E++;
    }

    Iterable<Integer> adj(int v) {
        return adj[v];
    }

    int V() {
        return V;
    }

    int E() {
        return E;
    }

//    String toString(){}
}
