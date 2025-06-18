import java.util.Scanner;

public class ConsoVowel {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String t = s.nextLine().toLowerCase();
        int conso = 0, vowel = 0;

        for(char c : t) {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            vowel++;
            else if(c >= 'a' && c<='z')
            conso++;
        }

        System.out.println("Conso : " + conso);
        System.out.println("Vowel : " + vowel);

        s.close();
    }
}