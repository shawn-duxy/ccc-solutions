import java.util.*;

public class Senior1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int c = in.nextInt();

        List<int[]> grid = new ArrayList<>();
        for (int i = 0; i < c; i++) {
            grid.add(new int[2]);
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < c; j++) {
                grid.get(j)[i] = in.nextInt();
            }
        }

        int length = 0;
        for (int i = 0; i < c; i++) {
            if (grid.get(i)[0] == 1) {
                length += 3;
            }
            if (grid.get(i)[1] == 1) {
                length += 3;
            }
            if (i % 2 == 0 && grid.get(i)[0] == 1 && grid.get(i)[1] == 1) {
                length -= 2;
            }
            if (i < c - 1 && grid.get(i)[0] == 1 && grid.get(i + 1)[0] == 1) {
                length -= 2;
            }
            if (i < c - 1 && grid.get(i)[1] == 1 && grid.get(i + 1)[1] == 1) {
                length -= 2;
            }
        }

        System.out.println(length);
    }
}
