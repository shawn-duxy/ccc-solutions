import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior3 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());
        int[] a = new int[n];
        int[] b = new int[n];
        String[] lineA = reader.readLine().split(" ");
        String[] lineB = reader.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(lineA[i]);
            b[i] = Integer.parseInt(lineB[i]);
        }

        List<int[]> left = new ArrayList<>();
        List<int[]> right = new ArrayList<>();
        int j = 0;
        for (int i = 0; i < n; i++) {
            int start = j;
            boolean swipe = false;
            while (j < i && b[j] == a[i]) {
                j++;
                swipe = true;
            }
            if (swipe) {
                left.add(new int[]{start, i});
            }
            swipe = false;
            while (j < n && b[j] == a[i]) {
                j++;
                swipe = true;
            }
            if (swipe && i != j - 1) {
                right.add(new int[]{i, j - 1});
            }
        }

        if (j == n) {
            System.out.println("YES");
            System.out.println(left.size() + right.size());
            for (int i = right.size() - 1; i >= 0; i--) {
                System.out.println("R " + right.get(i)[0] + " " + right.get(i)[1]);
            }
            for (int i = 0; i < left.size(); i++) {
                System.out.println("L " + left.get(i)[0] + " " + left.get(i)[1]);
            }
        } else {
            System.out.println("NO");
        }
    }
}
