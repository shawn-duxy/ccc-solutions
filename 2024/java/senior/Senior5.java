import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Senior5 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());
        long[][] chocolate = new long[2][n];

        BigInteger total = BigInteger.ZERO;
        for (int i = 0; i < 2; i++) {
            StringTokenizer tokens = new StringTokenizer(reader.readLine());
            for (int j = 0; j < n; j++) {
                long v = Long.parseLong(tokens.nextToken()) * 2 * n;
                chocolate[i][j] = v;
                total = total.add(BigInteger.valueOf(v));
            }
        }
        long avg = total.divide(BigInteger.valueOf(2 * n)).longValue();

        long[][] prefix = new long[2][n + 1];
        prefix[0][0] = 0;
        prefix[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[0][i] = chocolate[0][i - 1] - avg + prefix[0][i - 1];
            prefix[1][i] = chocolate[1][i - 1] - avg + prefix[1][i - 1];
        }

        Map<Long, Long>[] best = new HashMap[4];
        for (int i = 0; i < 4; i++) {
            best[i] = new HashMap<>(2 * (n + 1));
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k < 2; k++) {
                    best[i].put(prefix[k][j], Long.MIN_VALUE);
                }
            }
        }
        long[][] result = new long[2][n + 1];
        result[0][0] = 0;
        result[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < 2; k++) {
                best[k].put(prefix[k][i - 1], Math.max((Long) best[k].get(prefix[k][i - 1]), result[1 - k][i - 1]));
                best[k + 2].put(prefix[1 - k][i - 1], Math.max((Long) best[k + 2].get(prefix[1 - k][i - 1]), result[k][i - 1]));
            }
            for (int k = 0; k < 2; k++) {
                long parts = Math.max(result[k][i - 1], result[1 - k][i - 1]);
                if (best[1 - k].containsKey(prefix[1 - k][i])) {
                    parts = Math.max(parts, (Long) best[1 - k].get(prefix[1 - k][i]) + 1);
                }
                if (best[3 - k].containsKey(-1 * prefix[1 - k][i])) {
                    parts = Math.max(parts, (Long) best[3 - k].get(-1 * prefix[1 - k][i]) + 1);
                }
                result[k][i] = parts;
            }
            if (prefix[0][i] + prefix[1][i] == 0) {
                long max = Math.max(result[0][i], result[1][i]);
                result[0][i] = max + 1;
                result[1][i] = max + 1;
            }
        }

        System.out.println(result[1][n]);
    }
}
