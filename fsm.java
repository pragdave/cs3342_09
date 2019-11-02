class fsm {
    static String[] adjective = {"lazy","smelly"};
    static String[] noun = {"dog", "cat"};
    static String[] verb = {"ate", "ran"};
    static String[] adverb= {"slowly", "noisily" };

    public static void main(String[] args) {
        String[] test1 = {"the", "lazy", "dog", "ate", "EOI"};
        String[] test2 = {"the", "smelly", "lazy","dog", "ran", "EOI"};
        String[] test3 = {"the", "lazy", "lazy", "lazy"};
        String[] test4 = {"the", "lazy", "dog", "ate", "slowly", "EOI"};

        System.out.println(loadFSM(test1));
        System.out.println(loadFSM(test2));
        System.out.println(loadFSM(test3));
        System.out.println(loadFSM(test4));
    }

    public static boolean loadFSM(String[] list) {
        int state = 0;

        for (int i = 0; i < list.length; i ++) {
            state = runFSM(list[i], state);
        }

        if (state == 6 ) {
            return true;
        }

        return false;
    }

    public static int runFSM(String word, int state) {
        switch (state) {
        case 0:
            if (word == "the") { return 1; }
            return -1; 
        

        case 1:
            if (contain(adjective,word)) { return 2; }
            else if (contain(noun, word)) { return 3; }
            return -1; 
        

        case 2:
            if (contain(adjective,word)) { return 2; }
            else if (contain(noun, word)) { return 3; }
            return -1;
        

        case 3:
            if (contain(verb, word)) { return 4; }
            return -1; 
        

        case 4:
            if (word.equals ("EOI")){ return 6; }
            else if (contain(adverb, word)) { return 5; }
            return -1; 
        

        case 5:
            if (word.equals ("EOI")){ return 6; }
            return -1;
            
        default:
            return -1;
        }
    }

    public static boolean contain(String[] terminal, String word) {
        for (int i = 0; i < terminal.length; i ++ ) {
            if (word.equals(terminal[i])) {
                return true;
            } 
        }
        return false;
    }

}