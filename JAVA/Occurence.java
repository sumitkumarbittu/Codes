import java.util.Scanner;

public class Occurence {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int v=0,c=0,s=0;
        StringBuilder res = new StringBuilder();

        String in = sc.nextLine();

        for(int i=0;i<in.length();i++) {
            char ch = in.charAt(i);
            if(Character.isLetter(ch))
            {
                ch = Character.toLowerCase(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
                else {
                    c++;
                    res.append(ch);
                }
            }
            else {
                s++;   
                res.append(ch);
            }
        }

        System.out.println(v);
        System.out.println(c);
        System.out.println(s);
        System.out.println(res.toString());

        sc.close();
    }
    
}
