import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior4 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());

        int n = Integer.parseInt(tokens.nextToken());
        int m = Integer.parseInt(tokens.nextToken());

        int[][] nodes = new int[m + 1][3];
        List<List<int[]>> graph = new ArrayList<>();
        List<PriorityQueue<int[]>> edges = new ArrayList<>();

        nodes[0] = new int[]{1, 1, 0};
        for (int i = 0; i <= m; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            edges.add(new PriorityQueue<>(Comparator.comparingInt(a -> a[1])));
        }
        edges.getFirst().add(new int[]{0, 0});
        for (int i = 1; i <= m; i++) {
            tokens = new StringTokenizer(reader.readLine());
            int s = Integer.parseInt(tokens.nextToken());
            int e = Integer.parseInt(tokens.nextToken());
            int c = Integer.parseInt(tokens.nextToken());

            nodes[i] = new int[]{s, e, c};

            edges.get(s - 1).add(new int[]{i, c});
            edges.get(e - 1).add(new int[]{i, c});
        }

        for (PriorityQueue<int[]> edge : edges) {
            int[] start = edge.poll();
            while (!edge.isEmpty()) {
                int[] end = edge.poll();
                graph.get(start[0]).add(new int[]{end[0], Math.abs(start[1] - end[1])});
                graph.get(end[0]).add(new int[]{start[0], Math.abs(start[1] - end[1])});
                start = end;
            }
        }

        long[] dist = new long[m + 1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<long[]> notVisited = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        notVisited.add(new long[]{0, 0});

        while (!notVisited.isEmpty()) {
            long[] next = notVisited.poll();
            for (int[] j : graph.get((int) next[1])) {
                long p = dist[(int) next[1]] + j[1];
                if (p < dist[j[0]]) {
                    dist[j[0]] = p;
                    notVisited.add(new long[]{p, j[0]});
                }
            }
        }

        long min = Long.MAX_VALUE;
        for (int i = 0; i <= m; i++) {
            if (nodes[i][0] == n || nodes[i][1] == n) {
                min = Math.min(min, dist[i]);
            }
        }
        System.out.println(min);
    }
}
