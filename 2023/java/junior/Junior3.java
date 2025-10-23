import java.util.*;
import java.util.stream.Collectors;

public class Junior3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        List<String> schedule = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            schedule.add(in.next());
        }

        List<Integer> best = new ArrayList<>();
        int max = 0;
        for (int i = 0; i < 5; i++) {
            int d = 0;
            for (int j = 0; j < n; j++) {
                if (schedule.get(j).charAt(i) == 'Y') {
                    d++;
                }
            }
            if (d > max) {
                max = d;
                best.clear();
                best.add(i + 1);
            } else if (d == max) {
                best.add(i + 1);
            }
        }

        System.out.println(best.stream().map(String::valueOf).collect(Collectors.joining(",")));
    }
}