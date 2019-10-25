import java.util.StringTokenizer;
import java.util.HashMap;

class Parser{

private static class State{    

    public boolean eoi;
    public HashMap<String, State> nextWords;

    public State(){}

    public State(HashMap<String, State> next){
        if(next==null)
        eoi = true;
        this.nextWords = next;
    }
    
}

public static void main(String[] args){
    setupStates();
    String test1 = "the lazy smelly dog ran EOI";           //Multiple adjectives

    String test2 = "the lazy smelly dog ran slowly EOI";    //Multiple adjectives with adverb
    
    String test3 = "the cat ran EOI";                       //No adjectives 
    
    String test4 = "the cat ran slowly EOI";                //No adjectives with adverb

    System.out.println(validateSentence(test1));
    System.out.println(validateSentence(test2));
    System.out.println(validateSentence(test3));
    System.out.println(validateSentence(test4));

}

public static void setupStates(){
    State s4 = new State(null);
    State s3 = new State(new HashMap<>(){{
        put("slowly", s4);
        put("noisily", s4);
        put("EOI", s4);
    }});

    State s2 = new State(new HashMap<>(){{
        put("ate", s3);
        put("ran", s3);
    }}); 

    State s1 = new State(new HashMap<>());
    s1.nextWords = new HashMap<>(){{
        put("lazy", s1);
        put("smelly", s1);
        put("dog", s2);
        put("cat", s2);
    }};

    State s0 = new State(new HashMap<>(){{
        put("the", s1);
    }});
    startState = s0;
}

private static State startState;

public static boolean validateSentence(String text){
    StringTokenizer sT = new StringTokenizer(text);
    String token = null;
    State currentState = startState; 
    while(sT.hasMoreTokens()){
        token = sT.nextToken();
        if(!currentState.eoi && currentState.nextWords.containsKey(token)){
            currentState = currentState.nextWords.get(token);
        }
        else return false;
    }
    if(currentState.eoi)
        return true;
    return false;
}

}