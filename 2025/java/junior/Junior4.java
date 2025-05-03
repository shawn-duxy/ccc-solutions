import java.util.*;

public class Junior4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        List<String> weather = new ArrayList<>();
        List<Integer> days = new ArrayList<>();
        String current = in.next();
        int count = 1;
        for (int i = 1; i < n; i++) {
            String w = in.next();
            if (current.equals(w)) {
                count++;
            } else {
                weather.add(current);
                days.add(count);
                current = w;
                count = 1;
            }
        }
        weather.add(current);
        days.add(count);

        if (weather.size() == 1 && weather.get(0).equals("S")) {
            System.out.println(days.get(0) - 1);
            return;
        }

        int max = 1;
        for (int i = 0; i < weather.size(); i++) {
            if (weather.get(i).equals("S")) {
                max = Math.max(max, days.get(i));
            } else if (weather.get(i).equals("P") && days.get(i) == 1) {
                int total = 1;
                if (i > 0) {
                    total += days.get(i - 1);
                }
                if (i < weather.size() - 1) {
                    total += days.get(i + 1);
                }
                max = Math.max(max, total);
            } else {
                if (i > 0) {
                    max = Math.max(max, days.get(i - 1) + 1);
                }
                if (i < weather.size() - 1) {
                    max = Math.max(max, days.get(i + 1) + 1);
                }
            }
        }
        System.out.println(max);
    }
}
