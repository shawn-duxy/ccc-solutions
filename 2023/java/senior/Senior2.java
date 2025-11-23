import java.util.*;

public class Senior2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        List<Integer> h = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            h.add(in.nextInt());
        }

        List<Integer> result = new ArrayList<>();
        result.add(0);
        for (int i = 1; i < n; i++) {
            result.add(Integer.MAX_VALUE);
        }

        for (int i = 1; i < n; i++) {
            int s = i - 1, e = i;
            int d = Math.abs(h.get(e) - h.get(s));
            if (result.get(e - s) > d) {
                result.set(e - s, d);
            }
            while (s > 0 && e < n - 1) {
                s--;
                e++;
                d += Math.abs(h.get(e) - h.get(s));
                if (result.get(e - s) > d) {
                    result.set(e - s, d);
                }
            }
            if (i < n - 1) {
                s = i - 1;
                e = i + 1;
                d = Math.abs(h.get(e) - h.get(s));
                if (result.get(e - s) > d) {
                    result.set(e - s, d);
                }
                while (s > 0 && e < n - 1) {
                    s--;
                    e++;
                    d += Math.abs(h.get(e) - h.get(s));
                    if (result.get(e - s) > d) {
                        result.set(e - s, d);
                    }
                }
            }
        }

        System.out.print(result.get(0));
        for (int i = 1; i < n; i++) {
            System.out.print(" " + result.get(i));
        }
    }
}
