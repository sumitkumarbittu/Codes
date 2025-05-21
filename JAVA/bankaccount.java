import java.util.*;

public class bankaccount
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        double bal = 10000, x;
        while(true)
        {
            char c = s.next().charAt(0);
            switch(c)
            {
                case 'c':
                case 'C':
                    System.out.println(bal);
                    break;

                case 'd':
                case 'D': 
                    x = s.nextDouble();
                    if(x>0)
                    bal+=x;
                    else
                    System.out.println("Input positive deposit!");
                    System.out.println(bal);
                    break;

                case 'w':
                case 'W':
                    x = s.nextDouble();
                    if(bal >= x)
                    bal-=x;
                    else
                    System.out.println("Insufficient Balance");
                    System.out.println(bal);
                    break;

                case 'e':
                case 'E':
                    System.out.println(bal);
                    System.exit(0);

                default:
                    System.out.println("Invalid Selection");
            }
        }
    }
}