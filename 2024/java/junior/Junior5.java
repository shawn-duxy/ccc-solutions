import java.util.*;

public class Junior5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        int c = in.nextInt();

        String[] patch = new String[r];
        for (int i = 0; i < r; i++) {
            patch[i] = in.next();
        }

        int a = in.nextInt();
        int b = in.nextInt();

        boolean[][] visited = new boolean[r][c];
        List<int[]> queue = new ArrayList<>();
        queue.add(new int[]{a, b});
        int total = 0;
        while (!queue.isEmpty()) {
            int[] place = queue.get(0);
            queue.remove(0);
            if (visited[place[0]][place[1]]) {
                continue;
            }
            visited[place[0]][place[1]] = true;
            char ch = patch[place[0]].charAt(place[1]);
            switch (ch) {
                case 'S':
                    total += 1;
                    break;
                case 'M':
                    total += 5;
                    break;
                case 'L':
                    total += 10;
                    break;
            }
            if (place[0] > 0 && !visited[place[0] - 1][place[1]] && patch[place[0] - 1].charAt(place[1]) != '*') {
                queue.add(new int[]{place[0] - 1, place[1]});
            }
            if (place[0] < r - 1 && !visited[place[0] + 1][place[1]] && patch[place[0] + 1].charAt(place[1]) != '*') {
                queue.add(new int[]{place[0] + 1, place[1]});
            }
            if (place[1] > 0 && !visited[place[0]][place[1] - 1] && patch[place[0]].charAt(place[1] - 1) != '*') {
                queue.add(new int[]{place[0], place[1] - 1});
            }
            if (place[1] < c - 1 && !visited[place[0]][place[1] + 1] && patch[place[0]].charAt(place[1] + 1) != '*') {
                queue.add(new int[]{place[0], place[1] + 1});
            }
        }

        System.out.println(total);
    }
}