import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior5 {
    private final static int MOD = 1000000 + 3;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());

        int n = Integer.parseInt(tokens.nextToken());

        List<int[]> tasks = new ArrayList<>();
        long[][] tree = new long[1 << 21][2];
        for (int i = 0; i < n; i++) {
            long ans = tree[0][0];
            tokens = new StringTokenizer(reader.readLine());
            String op = tokens.nextToken();

            int pos = 0;
            if ("A".equals(op)) {
                int start = (int) ((Integer.parseInt(tokens.nextToken()) + ans - 1) % MOD);
                int duration = (int) ((Integer.parseInt(tokens.nextToken()) + ans) % MOD);
                pos = (1 << 20) + start;
                tasks.add(new int[]{start, duration});
                long[] treeNode = tree[pos];
                treeNode[1] += duration;
                treeNode[0] = start + treeNode[1];
            } else {
                int index = (int) ((Integer.parseInt(tokens.nextToken()) + ans) % MOD);
                int[] task = tasks.get(index - 1);
                pos = (1 << 20) + task[0];
                long[] treeNode = tree[pos];
                treeNode[1] -= task[1];
                if (treeNode[1] == 0) {
                    treeNode[0] = 0;
                } else {
                    treeNode[0] -= task[1];
                }
            }

            pos = (pos + 1) / 2 - 1;
            while (true) {
                long[] left = tree[pos * 2 + 1];
                long[] right = tree[pos * 2 + 2];
                tree[pos][0] = Math.max(left[0] + right[1], right[0]);
                tree[pos][1] = left[1] + right[1];

                if (pos == 0) {
                    break;
                }
                pos = (pos + 1) / 2 - 1;
            }

            System.out.println(tree[0][0]);
        }
    }
}
