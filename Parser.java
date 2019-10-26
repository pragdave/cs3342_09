import java.util.StringTokenizer;
import java.util.HashMap;

class Parser {

    public static void main(String[] args) {
        setupStates();
        runTests();
    }

    public static void runTests() {

        String test1 = "the lazy smelly dog ran EOI"; // Multiple adjectives
        String test2 = "the lazy smelly dog ran slowly EOI"; // Multiple adjectives with adverb
        String test3 = "the lazy dog ate slowly EOI"; // One adjective
        String test4 = "the cat ate EOI"; // No adjectives
        String test5 = "the cat ran slowly EOI"; // No adjectives with adverb

        assert validateSentence(test1);
        assert validateSentence(test2);
        assert validateSentence(test3);
        assert validateSentence(test4);
        assert validateSentence(test5);

        String test6 = "smelly cat ran EOI";
        String test7 = "the cat ate";
        String test8 = "the cat slowly EOI";
        String test9 = "the lazy ate EOI";
        String test10 = "the dog EOI";

        assert !validateSentence(test6);
        assert !validateSentence(test7);
        assert !validateSentence(test8);
        assert !validateSentence(test9);
        assert !validateSentence(test10);

    }

    public static void setupStates() {
        State s4 = new State(null);
        State s3 = new State(new HashMap<>() {
            {
                put("slowly", s4);
                put("noisily", s4);
                put("EOI", s4);
            }
        });

        State s2 = new State(new HashMap<>() {
            {
                put("ate", s3);
                put("ran", s3);
            }
        });

        State s1 = new State(new HashMap<>());
        s1.transitions = new HashMap<>() {
            {
                put("lazy", s1);
                put("smelly", s1);
                put("dog", s2);
                put("cat", s2);
            }
        };

        State s0 = new State(new HashMap<>() {
            {
                put("the", s1);
            }
        });
        startState = s0;
    }

    private static State startState;

    public static boolean validateSentence(String text) {
        StringTokenizer sT = new StringTokenizer(text);
        String token = null;
        State currentState = startState;
        while (sT.hasMoreTokens() && !currentState.eoi) {
            token = sT.nextToken();
            if (currentState.transitions.containsKey(token)) {
                currentState = currentState.transitions.get(token);
            } else
                return false;
        }
        return currentState.eoi;
    }

    private static class State {

        public boolean eoi;
        public HashMap<String, State> transitions;

        public State(HashMap<String, State> transitions) {
            if (transitions == null)
                eoi = true;
            this.transitions = transitions;
        }
    }
}