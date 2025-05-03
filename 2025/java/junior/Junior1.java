import java.util.*;

public class Junior1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int c = in.nextInt();
        int p = in.nextInt();

        if (n <= c * p) {
            System.out.print("yes");
        } else {
            System.out.print("no");
        }
    }
}
