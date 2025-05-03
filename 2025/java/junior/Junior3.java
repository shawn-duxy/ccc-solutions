import java.util.*;

public class Junior3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        for (int i = 0; i < n; i++) {
            String s = in.next();
            int total = 0;
            int current = 0;
            boolean negative = false;
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if (Character.isAlphabetic(c)) {
                    if (negative) {
                        total -= current;
                    } else {
                        total += current;
                    }
                    current = 0;
                    negative = false;
                    if (Character.isUpperCase(c)) {
                        sb.append(c);
                    }
                } else if ('-' == c) {
                    if (negative) {
                        total -= current;
                    } else {
                        total += current;
                    }
                    current = 0;
                    negative = true;
                } else if (Character.isDigit(c)) {
                    current = current * 10 + c - '0';
                }
            }
            if (negative) {
                total -= current;
            } else {
                total += current;
            }
            System.out.println(sb.toString() + total);
        }
    }
}
