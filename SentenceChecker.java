
/**
 * Author: Jennifer Carballo
 * Date: April 5, 2020
 * Description: Checks if a string array is a sentence based on sentence structure
 *              Uses HashMap to hold expected states
 * To Run: java -ea SentenceChecker
 */

import java.util.*;
import javafx.util.*;

public class SentenceChecker {

    private static HashMap<Pair<String, String>, String> states;

    public static void main(String[] args) {
        buildStateMap();
        runTests();
    }
    
    /**
     * Puts Pair<Current State, String> 
     * with Next State into HashMap
     * Based off table from previous questions
     */
    public static void buildStateMap() {
        states = new HashMap<>();
        states.put(new Pair("S0", "the"), "S1");
        states.put(new Pair("S1", "lazy"), "S1");
        states.put(new Pair("S1", "smelly"), "S1");
        states.put(new Pair("S1", "dog"), "S2");
        states.put(new Pair("S1", "cat"), "S2");
        states.put(new Pair("S2", "ate"), "S3");
        states.put(new Pair("S2", "ran"), "S3");
        states.put(new Pair("S3", "slowly"), "S4");
        states.put(new Pair("S3", "noisily"), "S4");
        states.put(new Pair("S3", "EOI"), "END");
        states.put(new Pair("S4", "EOI"), "END");
    }

    /**
     * Runs tests on different 
     * correct and incorrect sentences
     * Uses assert
     * Prints "All tests passed!" if tests have...passed obv
     */
    public static void runTests() {
        //True sentences
        String[] sent1 = { "the", "smelly", "dog", "ran", "EOI" };
        String[] sent2 = { "the", "cat", "ran", "EOI" };
        String[] sent3 = { "the", "dog", "ate", "slowly", "EOI" };
        String[] sent4 = { "the", "cat", "ate", "noisily", "EOI" };
        String[] sent5 = { "the", "lazy", "cat", "ate", "slowly", "EOI" };

        //False sentences
        String[] sent6 = { "the", "smelly", "ran", "EOI" };
        String[] sent7 = { "the", "bird", "ran" };
        String[] sent8 = { "dog", "ate", "slowly", "EOI" };
        String[] sent9 = { "the", "cat", "noisily", "EOI" };
        String[] sent10 = { "the", "EOI" };

        try {
            //Should be true
            assert isSentence(sent1);
            assert isSentence(sent2);
            assert isSentence(sent3);
            assert isSentence(sent4);
            assert isSentence(sent5);

            //Should be false
            assert !isSentence(sent6);
            assert !isSentence(sent7);
            assert !isSentence(sent8);
            assert !isSentence(sent9);
            assert !isSentence(sent10);
        } catch (Exception e) {
            System.out.println("Testing Failed. \nInfo:\n" + e.getMessage());
        }
        System.out.println("All tests passed!");
    }

    /**
     * Uses HashMap to compare expected state
     * If all states and string matched and reached "EOI" return true
     * If not, it's not a sentence, return false
     */
    public static Boolean isSentence(String[] sent) {
        Pair<String, String> temp; //Pair<Current State, Word>
        String currState = "S0"; //first state must be S0
        for (int i = 0; i < sent.length; i++) {
            temp = new Pair<>(currState, sent[i]);
            if (states.containsKey(temp)) { //checks if pair is valid
                currState = states.get(temp); //sets next state to current state
                if (currState.equals("END")) { //checks if reached end state
                    return true;
                }
            }
        }
        return false; //sent is not a sentence
    }
}