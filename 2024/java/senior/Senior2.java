import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior2 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());

        int t = Integer.parseInt(tokens.nextToken());
        tokens.nextToken();

        for (int i = 0; i < t; i++) {
            String s = reader.readLine();
            Set<Character> heavy = new HashSet<>();
            Set<Character> light = new HashSet<>();

            for (char c : s.toCharArray()) {
                if (light.contains(c)) {
                    heavy.add(c);
                    light.remove(c);
                } else if (!heavy.contains(c)) {
                    light.add(c);
                }
            }

            boolean isLight = light.contains(s.charAt(0));
            boolean fail = false;
            for (int j = 1; j < s.length(); j++) {
                if (isLight && !heavy.contains(s.charAt(j))) {
                    System.out.println("F");
                    fail = true;
                    break;
                }
                if (!isLight && !light.contains(s.charAt(j))) {
                    System.out.println("F");
                    fail = true;
                    break;
                }
                isLight = !isLight;
            }
            if (!fail) {
                System.out.println("T");
            }
        }
    }
}
