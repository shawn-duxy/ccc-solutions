import java.util.*;

public class Junior1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int p = in.nextInt();
        int c = in.nextInt();

        int points = p * 50 - c * 10;
        if (p > c) {
            points += 500;
        }

        System.out.println(points);
    }
}
