import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Senior3 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());

        int n = Integer.parseInt(tokens.nextToken());
        int m = Integer.parseInt(tokens.nextToken());
        int q = Integer.parseInt(tokens.nextToken());

        List<Pen> rawPens = new ArrayList<>();
        TreeSet<Pen> bestPens = new TreeSet<>();
        TreeSet<Pen> otherPens = new TreeSet<>();
        List<TreeSet<Pen>> pensByColor = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            pensByColor.add(new TreeSet<>());
        }
        for (int i = 0; i < n; i++) {
            tokens = new StringTokenizer(reader.readLine());
            Pen pen = new Pen();
            pen.id = i;
            pen.color = Integer.parseInt(tokens.nextToken());
            pen.prettiness = Integer.parseInt(tokens.nextToken());
            rawPens.add(pen);
            pensByColor.get(pen.color - 1).add(pen);
            otherPens.add(pen);
        }
        long sumFirst = 0;
        for (int i = 0; i < m; i++) {
            Pen bestPen = pensByColor.get(i).last();
            bestPens.add(bestPen);
            sumFirst += bestPen.prettiness;
            otherPens.remove(bestPen);
        }

        Pen worstFirst = bestPens.first();
        Pen bestSecond = null;
        if (!otherPens.isEmpty()) {
            bestSecond = otherPens.last();
        }
        if (bestSecond != null && bestSecond.prettiness > worstFirst.prettiness) {
            System.out.println(sumFirst - worstFirst.prettiness + bestSecond.prettiness);
        } else {
            System.out.println(sumFirst);
        }

        for (int i = 0; i < q; i++) {
            tokens = new StringTokenizer(reader.readLine());
            String t = tokens.nextToken();
            int id = Integer.parseInt(tokens.nextToken());
            int v = Integer.parseInt(tokens.nextToken());

            Pen oldPen = rawPens.get(id - 1);
            Pen newPen = new Pen();
            newPen.id = oldPen.id;
            if ("1".equals(t)) {
                newPen.color = v;
                newPen.prettiness = oldPen.prettiness;
            }
            if ("2".equals(t)) {
                newPen.color = oldPen.color;
                newPen.prettiness = v;
            }

            if (oldPen.color == newPen.color) {
                rawPens.remove(id - 1);
                rawPens.add(id - 1, newPen);

                Pen currentBest = pensByColor.get(oldPen.color - 1).last();
                pensByColor.get(oldPen.color - 1).remove(oldPen);
                pensByColor.get(newPen.color - 1).add(newPen);
                Pen newBest = pensByColor.get(newPen.color - 1).last();

                bestPens.remove(currentBest);
                sumFirst -= currentBest.prettiness;
                otherPens.add(currentBest);
                otherPens.remove(oldPen);
                otherPens.add(newPen);
                otherPens.remove(newBest);
                bestPens.add(newBest);
                sumFirst += newBest.prettiness;
            } else {
                rawPens.remove(id - 1);
                rawPens.add(id - 1, newPen);

                boolean firstRemoved = bestPens.remove(oldPen);
                pensByColor.get(oldPen.color - 1).remove(oldPen);
                if (firstRemoved) {
                    sumFirst -= oldPen.prettiness;
                    Pen newBest = pensByColor.get(oldPen.color - 1).last();
                    bestPens.add(newBest);
                    sumFirst += newBest.prettiness;
                    otherPens.remove(newBest);
                } else {
                    otherPens.remove(oldPen);
                }

                Pen currentBest = pensByColor.get(newPen.color - 1).last();
                pensByColor.get(newPen.color - 1).add(newPen);
                Pen newBest = pensByColor.get(newPen.color - 1).last();
                if (newBest.id != currentBest.id) {
                    bestPens.remove(currentBest);
                    sumFirst -= currentBest.prettiness;
                    otherPens.add(currentBest);
                    bestPens.add(newBest);
                    sumFirst += newBest.prettiness;
                }
                if (newBest.id != newPen.id){
                    otherPens.add(newPen);
                }
            }

            worstFirst = bestPens.first();
            bestSecond = null;
            if (!otherPens.isEmpty()) {
                bestSecond = otherPens.last();
            }
            if (bestSecond != null && bestSecond.prettiness > worstFirst.prettiness) {
                System.out.println(sumFirst - worstFirst.prettiness + bestSecond.prettiness);
            } else {
                System.out.println(sumFirst);
            }
        }
    }

    public static class Pen implements Comparable<Pen> {
        int id;
        int color;
        int prettiness;

        @Override
        public boolean equals(Object o) {
            Pen pen = (Pen) o;
            return id == pen.id && prettiness == pen.prettiness;
        }

        @Override
        public int hashCode() {
            return Objects.hash(id, prettiness);
        }

        @Override
        public int compareTo(Pen o) {
            if (prettiness != o.prettiness) {
                return prettiness - o.prettiness;
            } else {
                return id - o.id;
            }
        }
    }
}
