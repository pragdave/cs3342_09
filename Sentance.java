import java.util.regex.Matcher;
public class Sentance{

    static String adjective[]={"lazy","smelly"};
    static String noun[]={"dog","cat"};
    static String verb[]={"ate","ran"};
    static String adverb[]={"slowly","noisly"};

    public static void main(String[] args){

        String right1[]={"the","lazy","dog","ate","noisly","EOI"};
        String right2[]={"the","dog","ate","noisly","EOI"};
        String right3[]={"the","lazy","smelly","cat","ran","slowly","EOI"};

        if(s0(right1))
            System.out.println("Correct! This is a proper sentance!");
        if(s0(right2))
            System.out.println("Correct! This is a proper sentance!");
        if(s0(right3))
            System.out.println("Correct! This is a proper sentance!");

        String wrong1[]={"the","noisly","dog","ate","noisly","EOI"};
        String wrong2[]={"the","frog","ate","noisly","EOI"};
        String wrong3[]={"the","lazy","dog","ate","smelly","EOI"};

        if(!s0(wrong1));
            System.out.println("Correct! This is NOT a proper sentance!");
        if(!s0(wrong2));
            System.out.println("Correct! This is NOT a proper sentance!");
        if(!s0(wrong3));
            System.out.println("Correct! This is NOT a proper sentance!");
    }


    public static boolean s0(String[] sentance){

        int i=0;
        if(!sentance[i].equals("the"))
            return false;
        else{
            return s1(sentance,++i);
        }
    }


    //checks while in state 1
    //if the next word equals an adjective, go into recursive loop to repeat as long as it finds an adjective
    //if it DOES NOT equal an adjective it goes to state 2 to see if thats valid
    public static boolean s1(String[] sentance, int i){

        for(int z=0;z<2;z++){
            if(sentance[i]==adjective[z]){
                return s1(sentance,++i);
            }
            else if(z==1){
                return s2(sentance,i);
            }
        }
        return false;
    }

    //if it finds a noun, it goes to state 3
    //if it does NOT find a noun, return false
    public static boolean s2(String[] sentance, int i){

        for(int z=0;z<2;z++){
            if(sentance[i]==noun[z]){
                return s3(sentance,++i);
            }
            else if(z==1){
                return false;
            }
        }
        return false;
    }

    //checks for a verb
    //if it finds a verb, goes to state 4
    //if not, return false
    public static boolean s3(String[] sentance, int i){

        for(int z=0;z<2;z++){
            if(sentance[i]==verb[z]){
                return s4(sentance,++i);
            }
            else if(z==1){
                return false;
            }
        }
        return false;
    }

    //checks for either EOI or an adverb
    public static boolean s4(String[] sentance, int i){

        if(sentance[i].equals("EOI"))
            return true;
        for(int z=0;z<2;z++){
            if(sentance[i]==adverb[z]){
                return s5(sentance,++i);
            }
            else if(z==1){
                return false;
            }
        }
        return false;
    }

    //if we are here only thing it can be is EOI
    public static boolean s5(String[] sentance, int i){ 
        
        if(sentance[i].equals("EOI"))
            return true;
        else
            return false;
    }
}