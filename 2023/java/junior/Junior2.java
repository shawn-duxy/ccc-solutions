import java.util.*;

public class Junior2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int spiciness = 0;
        for (int i = 0; i < n; i++) {
            String pepper = in.next();
            if ("Poblano".equals(pepper)) {
                spiciness += 1500;
            } else if ("Mirasol".equals(pepper)) {
                spiciness += 6000;
            } else if ("Serrano".equals(pepper)) {
                spiciness += 15500;
            } else if ("Cayenne".equals(pepper)) {
                spiciness += 40000;
            } else if ("Thai".equals(pepper)) {
                spiciness += 75000;
            } else if ("Habanero".equals(pepper)) {
                spiciness += 125000;
            }
        }

        System.out.println(spiciness);
    }
}