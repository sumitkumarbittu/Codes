import java.util.Scanner;

interface RemoveSpaces {
    String removespaces(String str);
}

public class RepSpace implements RemoveSpaces {
    public String removespaces(String str) {
        String s = "";
        for(int i=0;i<str.length();i++) {
            char c = str.charAt(i);
            if(c != ' ')
            s+=c;
            else
            s+='_';
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        RemoveSpaces r = new RepSpace();
        String str = sc.nextLine();
        str = r.removespaces(str);
        System.out.println("Modified : " + str);
        sc.close();
    }
}