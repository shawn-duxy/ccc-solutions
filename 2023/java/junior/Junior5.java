import java.util.*;

public class Junior5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String w = in.next();

        int r = in.nextInt();
        int c = in.nextInt();

        char[][] grid = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = in.next().charAt(0);
            }
        }

        int count = 0;
        int[][] offset = {
                {0, 1},
                {1, 1},
                {1, 0},
                {1, -1},
                {0, -1},
                {-1, -1},
                {-1, 0},
                {-1, 1}
        };

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == w.charAt(0)) {
                    for (int k = 0; k < offset.length; k++) {
                        StringBuilder t = new StringBuilder("" + grid[i][j]);
                        for (int a = 1; a < w.length(); a++) {
                            int x = i + offset[k][0] * a;
                            int y = j + offset[k][1] * a;
                            if (x >= 0 && x < r && y >= 0 && y < c) {
                                t.append(grid[x][y]);
                            }
                        }
                        if (w.contentEquals(t)) {
                            count++;
                        }
                        for (int a = 2; a < w.length(); a++) {
                            t = new StringBuilder("" + grid[i][j]);
                            for (int b = 1; b < a; b++) {
                                int x = i + offset[k][0] * b;
                                int y = j + offset[k][1] * b;
                                if (x >= 0 && x < r && y >= 0 && y < c) {
                                    t.append(grid[x][y]);
                                }
                            }
                            String part = t.toString();
                            for (int d = 1; d <= w.length() - a; d++) {
                                int x = i + offset[k][0] * (a - 1) + offset[(k + 2) % 8][0] * d;
                                int y = j + offset[k][1] * (a - 1) + offset[(k + 2) % 8][1] * d;
                                if (x >= 0 && x < r && y >= 0 && y < c) {
                                    t.append(grid[x][y]);
                                }
                            }
                            if (w.contentEquals(t)) {
                                count++;
                            }
                            t = new StringBuilder(part);
                            for (int d = 1; d <= w.length() - a; d++) {
                                int x = i + offset[k][0] * (a - 1) + offset[(k + 6) % 8][0] * d;
                                int y = j + offset[k][1] * (a - 1) + offset[(k + 6) % 8][1] * d;
                                if (x >= 0 && x < r && y >= 0 && y < c) {
                                    t.append(grid[x][y]);
                                }
                            }
                            if (w.contentEquals(t)) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        System.out.println(count);
    }
}
