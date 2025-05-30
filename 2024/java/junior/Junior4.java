import java.util.*;

public class Junior4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String text = in.nextLine();
        String output = in.nextLine();

        boolean hasSilent = text.length() > output.length();
        List<Character> mismatch = new ArrayList<>();
        char replace = ' ';

        int[] wordCount = new int[26];
        int[] outputCount = new int[26];
        for (int i = 0; i < text.length(); i++) {
            wordCount[text.charAt(i) - 'a']++;
        }
        for (int i = 0; i < output.length(); i++) {
            outputCount[output.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (wordCount[i] > outputCount[i]) {
                mismatch.add((char) ('a' + i));
            }
            if (wordCount[i] < outputCount[i]) {
                replace = (char) ('a' + i);
            }
        }
        String newText = text.replace(mismatch.get(0), replace);
        if (hasSilent) {
            newText = newText.replaceAll("" + mismatch.get(1), "");
        }
        if (newText.equals(output)) {
            System.out.println(mismatch.get(0) + " " + replace);
            if (hasSilent) {
                System.out.println(mismatch.get(1));
            } else {
                System.out.println("-");
            }
        } else {
            System.out.println(mismatch.get(1) + " " + replace);
            System.out.println(mismatch.get(0));
        }
    }
}
