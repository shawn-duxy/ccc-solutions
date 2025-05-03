import java.util.*;

public class Junior5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        int c = in.nextInt();
        int m = in.nextInt();

        List<Integer> row = new ArrayList<>();
        int tile = (r - 1) * c % m + 1;
        for (int i = 0; i < c; i++) {
            row.add(tile);
            tile = tile % m + 1;
        }

        for (int i = r - 2; i >= 0; i--) {
            List<Integer> next = new ArrayList<>();
            for (int j = 0; j < c; j++) {
                int smallest = row.get(j);
                if (j > 0) {
                    smallest = Math.min(smallest, row.get(j - 1));
                }
                if (j < c - 1) {
                    smallest = Math.min(smallest, row.get(j + 1));
                }
                next.add(smallest + (i * c + j) % m + 1);
            }
            row = next;
        }

        System.out.println(row.stream().min(Integer::compareTo).get());
    }
}