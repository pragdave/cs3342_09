class fsm {
    static String[] adjective = {"lazy","smelly"};
    static String[] noun = {"dog", "cat"};
    static String[] verb = {"ate", "ran"};
    static String[] adverb= {"slowly", "noisily" };

    public static void main(String[] args) {
        // boolean t = contain(adjective,"laz");
        String[] test1 = {"the", "lazy", "dog"};
        String[] test2 = {"the", "laz", "dog"};
        String[] test3 = {"the", "lazy", "lazy", "lazy"};

        System.out.println(loadFSM(test1));
        System.out.println(loadFSM(test2));
        System.out.println(loadFSM(test3));
    }

    public static boolean loadFSM(String[] list) {
        int state = 0;
        int index = 1;

        // s0
        if (list[0].equals("the") && list.length >= 3) {
            state = 1;
        } else {
            return false;
        }

        //s1
        if (state == 1) {
            if (contain(adjective, list[1])) {
                state = 2;
                index++;
            }  else if (contain(noun, list[1])){
                state = 3;
                index++;
            } else {
                return false;
            }
        }

        //s2
        if (state == 2) {
            for (int i = index; i < list.length; i++) {
                index++;
                if (contain(noun, list[i])) {
                    state = 3;
                    break;
                }
            }
            return false;
        }

        //s3
        if (state == 3) {
            return true;
        }
        return false;
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