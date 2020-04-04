To Professor Thomas:

This is the first time I've ever attempted writing a script, but hopefully it makes it easier on you. You must have swi-prolog for this to work, as I decided to experiment with prolog...

you should do the following:

1) execute the following command:

   $ bash script.sh

   - this will create an executable (a.out)


2) run the executable:

   $ ./a.out


3) Executing should put you in the environment where you will run the tests or where you will test some senteces you have come up with that you would like to test. You don't have to use square brackets to import the .pl files that contain all of the source code. The script did that already!
   

You really need to know two "functions" listed below

functions to know:
   - is_valid_sentence(string).
              or
     is_valid_sentence(List).

   - run_tests().


Example of executing these functions:

1) is_valid_sentence(string):

   is_valid_sentence("the dog ran eoi"). -- will return true
   is_valid_sentence("the dog eoi").     -- will return false
NOTE: eoi MUST be included at the end of the sentence

2) is_valid_sentence(List):
   
   is_valid_sentence(["the","dog","ran","eoi"]). -- will return true
   is_valid_sentence(["the","dog","eoi"]).       -- will return false

3) run_tests().  -- just like this: executes tests in tests.pl     



















