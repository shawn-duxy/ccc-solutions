import java.util.*;

public class Senior4 {
    private static List<Integer> parent = new ArrayList<>();
    private static List<Map<Integer, Integer>> matrix = new ArrayList<>();

    private static int find(int u) {
        if (u != parent.get(u)) {
            parent.set(u, find(parent.get(u)));
        }
        return parent.get(u);
    }

    private static long dijkstra(int n, int s, int e) {
        long[] dist = new long[n + 1];
        Arrays.fill(dist, -1L);
        Set<Integer> visited = new HashSet<>();
        List<Integer> paths = new ArrayList<>();

        dist[s] = 0;
        paths.add(s);

        while (!paths.isEmpty()) {
            long min = Long.MAX_VALUE;
            int minPath = -1;
            for (int path : paths) {
                if (min > dist[path]) {
                    min = dist[path];
                    minPath = path;
                }
            }
            paths.remove((Integer) minPath);

            if (visited.contains(minPath)) {
                continue;
            }
            visited.add(minPath);

            for (Map.Entry<Integer, Integer> i : matrix.get(minPath).entrySet()) {
                if (!visited.contains(i.getKey()) && (dist[i.getKey()] == -1 || dist[minPath] + i.getValue() < dist[i.getKey()])) {
                    dist[i.getKey()] = dist[minPath] + i.getValue();
                    paths.add(i.getKey());
                }
            }
        }

        return dist[e];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        List<Node> roads = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            Node road = new Node();
            road.u = in.nextInt();
            road.v = in.nextInt();
            road.d = in.nextInt();
            road.c = in.nextInt();
            roads.add(road);
        }

        roads.sort((Node a, Node b) -> {
            if (a.d != b.d) {
                return a.d - b.d;
            }
            return a.c - b.c;
        });

        long total = 0;
        for (int i = 0; i <= n; i++) {
            parent.add(i);
            matrix.add(new HashMap<>());
        }

        for (Node r : roads) {
            int u = r.u;
            int v = r.v;

            int set_u = find(u);
            int set_v = find(v);

            if (set_u != set_v) {
                parent.set(set_u, set_v);
                total += r.c;
                matrix.get(u).put(v, r.d);
                matrix.get(v).put(u, r.d);
            } else if (r.d < dijkstra(n, u, v)) {
                total += r.c;
                matrix.get(u).put(v, r.d);
                matrix.get(v).put(u, r.d);
            }
        }

        System.out.println(total);
    }

    private static class Node {
        int u, v, d, c;
    }
}
