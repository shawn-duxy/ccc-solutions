import java.util.*;

public class Senior3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m, r, c;
        n = in.nextInt();
        m = in.nextInt();
        r = in.nextInt();
        c = in.nextInt();

        if (r > 0 && r < n && c > 0 && c < m) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print('a');
                }
                System.out.println();
            }
            for (int i = r; i < n; i++) {
                for (int j = 0; j < c; j++) {
                    System.out.print('a');
                }
                for (int j = c; j < m; j++) {
                    System.out.print('b');
                }
                System.out.println();
            }
            return;
        }

        List<List<Character>> result = new ArrayList<>();
        boolean flip = false;
        if (r != 0 && r != n && (c == 0 || c == m)) {
            flip = true;
            int t = r;
            r = c;
            c = t;
            t = n;
            n = m;
            m = t;
        }

        if (r == 0) {
            for (int i = 0; i < n - 1; i++) {
                List<Character> row = new ArrayList<>();
                for (int j = 0; j < m - 1; j++) {
                    row.add('a');
                }
                row.add('b');
                result.add(row);
            }
            List<Character> row = new ArrayList<>();
            for (int i = 0; i < c; i++) {
                row.add('a');
            }
            for (int i = c; i < m - 1; i++) {
                row.add('b');
            }
            if (c == m) {
                row.set(m - 1, 'b');
            }
            if (c < m) {
                row.add('c');
            }
            result.add(row);
        } else if (r == n) {
            if (c % 2 != 0 && m % 2 == 0) {
                System.out.println("IMPOSSIBLE");
                return;
            }
            for (int i = 0; i < n; i++) {
                List<Character> row = new ArrayList<>();
                for (int j = 0; j < m; j++) {
                    row.add('a');
                }
                result.add(row);
            }
            if ((m - c) % 2 == 1) {
                result.getFirst().set(m / 2, 'b');
            }
            for (int i = 0; i < (m - c) / 2; i++) {
                result.getFirst().set(m / 2 - i - 1, 'b');
                result.getFirst().set((m + 1) / 2 + i, 'b');
            }
        }

        if (flip) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(result.get(j).get(i));
                }
                System.out.println();
            }
        } else {
            for (List<Character> row : result) {
                for (char ch : row) {
                    System.out.print(ch);
                }
                System.out.println();
            }
        }
    }
}
