import java.util.*;

public class replaceone
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int n =a, i=0;
        while(n>0)
        {i++; n/=10;}
        for(int j=i-1;j>=0;j--)
        {
            int x = a/(int)Math.pow(10,j);
            if(x == 0)
            System.out.print(1);
            else
            System.out.print(x);
            a=a%(int)Math.pow(10,j);
        }
    }
}