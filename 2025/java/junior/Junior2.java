import java.util.*;

public class Junior2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int d = in.nextInt();
        int e = in.nextInt();

        for (int i = 0; i < e; i++) {
            String s = in.next();
            int q = in.nextInt();
            if ("+".equals(s)) {
                d += q;
            } else {
                d -= q;
            }
        }
        System.out.println(d);
    }
}
