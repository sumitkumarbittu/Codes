import java.util.*;

public class AlphaNumericOps {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        System.out.print("Input a String : ");
        String input = s.nextLine();

        countvowel(input);

        input = nonumeric(input);

        
    }

    public static void countvowel(String input) {
        int ev = 0, ov = 0;

        for(int i=0;i<input.length();i++) {
            char c = input.charAt(i);
            String vowel = "aeiouAEIOU";
            if(vowel.indexOf(c) != -1) {
                if(i%2 == 0)
                ov++;
                else
                ev++;
            }
        }
        System.out.println("No of Vowels at Odd Postion : " + ov);
        System.out.println("No of Vowels at Even Position : " + ev);
    }

    public static String nonumeric(String input) {
        for(int i=0;i<input.length();i++) {
            char c = input.charAt(i);
            if(!(c >= '0' && c <= '9'))
            inp += c;
        }
        System.out.println("String without Numbers : " + inp);
    }

    public static String sortedstring(String input) {
        for(int i=0;i<input.length();i++) {
            for(int j=i+1;j<input.length();i++) {
                if(input[i]==input[j])
                
            }
        }
    }
}
