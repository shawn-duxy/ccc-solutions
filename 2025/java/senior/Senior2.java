import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior2 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = reader.readLine();

        long total = 0;
        long current = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isAlphabetic(c)) {
                total += current;
                current = 0;
            } else {
                current = current * 10 + c - '0';
            }
        }
        total += current;

        long r = Long.parseLong(reader.readLine()) % total;

        current = 0;
        char last = s.charAt(0);
        char letter = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isAlphabetic(c)) {
                letter = c;
                r -= current;
                current = 0;
                if (r < 0) {
                    System.out.println(last);
                    return;
                }
                last = letter;
            } else {
                current = current * 10 + c - '0';
            }
        }
        System.out.println(letter);
    }
}