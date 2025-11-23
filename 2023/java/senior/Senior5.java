import java.util.*;

public class Senior5 {
    private static Set<Integer> numbers = new HashSet<>();
    private static int N = (int) Math.pow(3, 19);

    private static void fill(int a, int n, int k) {
        if (k >= N) {
            for (int i = (int) ((long) a * n / k); i <= (long) (a + 1) * n / k; i++) {
                numbers.add(i);
            }
        } else {
            fill(a * 3, n, k * 3);
            fill(a * 3 + 2, n, k * 3);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        fill(0, n, 1);

        List<Integer> answers = new ArrayList<>();
        for (int i : numbers) {
            Set<Integer> s = new HashSet<>();
            s.add(0);
            s.add(n);
            long a = i;
            boolean covered = false;
            while (true) {
                if (3 * a <= n) {
                    a *= 3;
                    if (s.contains((int) a)) {
                        covered = false;
                        break;
                    }
                    s.add((int) a);
                } else if (3 * a >= n * 2) {
                    a = a * 3 - n * 2;
                    if (s.contains((int) a)) {
                        covered = false;
                        break;
                    }
                    s.add((int) a);
                } else {
                    covered = true;
                    break;
                }
            }
            if (!covered) {
                answers.add(i);
            }
        }

        answers.sort(Comparator.naturalOrder());
        for (int i : answers) {
            System.out.println(i);
        }
    }
}
