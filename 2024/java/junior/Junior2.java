import java.util.*;

public class Junior2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int dusa = in.nextInt();

        while (true) {
            int yobis = in.nextInt();
            if (dusa > yobis) {
                dusa += yobis;
            } else {
                break;
            }
        }

        System.out.println(dusa);
    }
}
