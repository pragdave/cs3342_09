import java.util.*;
import javafx.util.*;

public class SentenceChecker {

    private static HashMap<Pair<String, String>, String> states;

    public static void main(String[] args) {
        buildStateMap();
        runTests();
    }
    
    public static void buildStateMap() {
        states = new HashMap<>();
        states.put(new Pair("S0", "the"),     "S1");
        states.put(new Pair("S1", "lazy"),    "S1");
        states.put(new Pair("S1", "smelly"),  "S1");
        states.put(new Pair("S1", "dog"),     "S2");
        states.put(new Pair("S1", "cat"),     "S2");
        states.put(new Pair("S2", "ate"),     "S3");
        states.put(new Pair("S2", "ran"),     "S3");
        states.put(new Pair("S3", "slowly"),  "S4");
        states.put(new Pair("S3", "noisily"), "S4");
        states.put(new Pair("S3", "EOI"),    "END");
        states.put(new Pair("S4", "EOI"),    "END");
    }

    public static void runTests() {
        String[] sent1 = { "the", "smelly", "dog", "ran", "EOI"};
        String[] sent2 = { "the", "smelly", "ran", "EOI"};
        assert isSentence(sent1);
        System.out.println(isSentence(sent1));
        assert isSentence(sent2);
        System.out.println(isSentence(sent2));
    }

    public static Boolean isSentence(String[] sent) {
        Pair<String, String> temp;
        String currState = "S0";
        for (int i = 0; i < sent.length; i++) {
            temp = new Pair<>(currState, sent[i]);

            if (states.containsKey(temp)) {
                currState = states.get(temp);
                if (currState.equals("END")) {
                    return true;
                }
            }
        }
        return false;
    }
}