import java.util.*;

public class diagonalsq
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);

        int r = s.nextInt();
        int c = s.nextInt();
        if(r != c)
        System.out.println("Not a square!");
        else
        {
            int[][] a = new int[r][c];
            int u=c-1, d1=0, d2=0;
            for(int i = 0;i<r ;i++)
            {
                for(int j=0;j<c;j++)
                a[i][j] = s.nextInt();
            }
            for(int i = 0;i<r ;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(i == j)
                    d1 += a[i][j];
                }
                d2+=a[i][u--];
            }
            System.out.println(d1);
            System.out.println(d2);
        }
    }
}