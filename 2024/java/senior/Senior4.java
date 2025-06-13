import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior4 {
    static List<List<int[]>> roads = new ArrayList<>();
    static String[] colors;
    static Set<Integer> visited = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());

        int n, m;
        n = Integer.parseInt(tokens.nextToken());
        m = Integer.parseInt(tokens.nextToken());

        for (int i = 0; i <= n; i++) {
            roads.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            tokens = new StringTokenizer(reader.readLine());
            int a, b;
            a = Integer.parseInt(tokens.nextToken());
            b = Integer.parseInt(tokens.nextToken());
            roads.get(a).add(new int[]{b, i});
            roads.get(b).add(new int[]{a, i});
        }

        colors = new String[m];
        Arrays.fill(colors, "G");

        for (int i = 1; i <= n; i++) {
            dfs(i, true);
        }

        System.out.println(String.join("", colors));
    }

    private static void dfs(int vertex, boolean useRed) {
        visited.add(vertex);
        for (int[] road : roads.get(vertex)) {
            if (!visited.contains(road[0])) {
                if (useRed) {
                    colors[road[1]] = "R";
                } else {
                    colors[road[1]] = "B";
                }
                dfs(road[0], !useRed);
            }
        }
    }
}
