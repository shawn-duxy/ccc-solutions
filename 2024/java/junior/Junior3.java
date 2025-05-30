import java.util.*;

public class Junior3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int[] scores = new int[76];
        for (int i = 0; i < n; i++) {
            int score = in.nextInt();
            scores[score]++;
        }

        int pos = 0;
        for (int i = 75; i >= 0; i--) {
            if (scores[i] > 0) {
                pos++;
            }
            if (pos == 3) {
                System.out.println(i + " " + scores[i]);
                break;
            }
        }
    }
}
