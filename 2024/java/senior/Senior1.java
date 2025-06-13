import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Senior1 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = Integer.parseInt(reader.readLine());
        }

        int total = 0;
        for (int i = 0; i < n / 2; i++) {
            if (h[i] == h[i + n / 2]) {
                total += 2;
            }
        }

        System.out.println(total);
    }
}
