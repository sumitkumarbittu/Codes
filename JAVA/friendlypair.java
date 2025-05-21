import java.util.Scanner;

public class friendlypair
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int m = s.nextInt();
        int n = s.nextInt();

        int p = sumdivisor(m);
        int q = sumdivisor(n);

        if(p*n == q*m)
        System.out.println(m + " & " + n + " are Friendly Pair.");
        else
        System.out.println(m + " & " + n + " are not Friendly Pair.");

        s.close();

    }

    public static int sumdivisor(int n)
    {
        int s = 0;
        for(int i = 1; i<n; i++)
        {
            if(n%i == 0)
            s+=i;
        }
        return s;
    }
}