package algorithms.graph.search;

import datastructures.graph.Graph;

/**
 *  The {@code DepthFirstSearch} class represents a data type for 
 *  determining the vertices connected to a given source vertex <em>s</em>
 *  in an undirected graph. For versions that find the paths, see
 *  {@link DepthFirstPaths} and {@link BreadthFirstPaths}.
 *  <p>
 *  This implementation uses depth-first search.
 *  The constructor takes time proportional to <em>V</em> + <em>E</em>
 *  (in the worst case),
 *  where <em>V</em> is the number of vertices and <em>E</em> is the number of edges.
 *  It uses extra space (not including the graph) proportional to <em>V</em>.
 *  <p>
 *  For additional documentation, see <a href="http://algs4.cs.princeton.edu/41graph">Section 4.1</a>   
 *  of <i>Algorithms, 4th Edition</i> by Robert Sedgewick and Kevin Wayne.
 *
 *  @author Robert Sedgewick
 *  @author Kevin Wayne
 */
public class DepthFirstSearch {
    private boolean[] marked;    // marked[v] = is there an s-v path?
    private int[] depth;      // depth[v] = depth of vertex v
    private int count;           // number of vertices connected to s

    /**
     * Computes the vertices in graph {@code G} that are
     * connected to the source vertex {@code s}.
     * @param G the graph
     * @param s the source vertex
     * @throws IllegalArgumentException unless {@code 0 <= s < V}
     */
    public DepthFirstSearch(Graph G, int s) {
        marked = new boolean[G.V()];
        depth = new int[G.V()];
        for (int v = 0; v < G.V(); v++)
            depth[v] = -1;
        validateVertex(s);
        dfs(G, s, 0);
    }

    // depth first search from v
    private void dfs(Graph G, int v, int i) {
        count++;
        marked[v] = true;
        depth[v] = i;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w, i+1);
            }
        }
    }
    
    /**
     * Returns the depth of vertex {@code v} from the source vertex {@code s}
     * @param v the vertex
     * @return the depth of a vertex
     * @throws IllegalArgumentException unless {@code 0 <= v < V}
     */
    public int depthOf(int v) {
        validateVertex(v);
        return depth[v];
    }

    /**
     * Is there a path between the source vertex {@code s} and vertex {@code v}?
     * @param v the vertex
     * @return {@code true} if there is a path, {@code false} otherwise
     * @throws IllegalArgumentException unless {@code 0 <= v < V}
     */
    public boolean marked(int v) {
        validateVertex(v);
        return marked[v];
    }

    /**
     * Returns the number of vertices connected to the source vertex {@code s}.
     * @return the number of vertices connected to the source vertex {@code s}
     */
    public int count() {
        return count;
    }

    // throw an IllegalArgumentException unless {@code 0 <= v < V}
    private void validateVertex(int v) {
        int V = marked.length;
        if (v < 0 || v >= V)
            throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
    }
}
