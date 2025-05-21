import java.util.*;

public class special2digit
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        if(sum(n) + mul(n) == n)
        System.out.println("Special 2 digit number");
        else
        System.out.println("Not a Special 2 digit number");
    }

    public static int sum(int n)
    {
        int a=0;
        while(n>0)
        {a+=(n%10); n/=10;}
        return a;
    }

    public static int mul(int n)
    {
        int m=1;
        while(n>0)
        {m*=(n%10); n/=10;}
        return m;
    }
}