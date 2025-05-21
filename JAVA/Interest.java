import java.util.Scanner;

public class Interest
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        int c = s.nextInt();

        switch(c)
        {
            case 1 : 
                double p = s.nextDouble();
                double r = s.nextDouble();
                int t = s.nextInt();
                System.out.println(p*Math.pow(1+r/100, t));
                break;

            case 2 : 
                double I = s.nextDouble();
                double R = s.nextDouble();
                int T = s.nextInt();
                T = T*12;
                System.out.println(I*T+(I*T*(T+1)/2*R/100/12));
                break;

            default : 
                System.out.println("End");

        }
        s.close();
    }
}