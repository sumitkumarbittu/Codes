import java.util.*;

public class bigbaazar
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);

        double item, x=0;
        int age, i = 1;
        char c;

        while(true)
        {
            item = 0;
            System.out.print("Input Category : ");
            c = s.next().charAt(0);
            switch(c)
            {
                case 'f' :
                case 'F' : 
                    System.out.print("Enter Item Amount : ");
                    item = s.nextDouble();
                    if(item >= 5000)
                    item *= 0.5;
                    else if(item >= 2000)
                    item *= 0.8;
                    else if(item >= 500)
                    item *= 0.9;
                    break;

                case 'c' : 
                case 'C' :
                    System.out.print("Enter age : ");
                    age = s.nextInt();
                    System.out.print("Enter Item Amount : ");
                    item = s.nextDouble();
                    if(age >= 40)
                    {
                        if(item >= 5000)
                        item *= 0.5;
                        else if(item >= 2000)
                        item *= 0.8;
                        else if(item >= 500)
                        item *= 0.9;
                    }
                    else if(age >= 20)
                    {
                        if(item >= 5000)
                        item *= 0.4;
                        else if(item >= 2000)
                        item *= 0.7;
                        else if(item >= 500)
                        item *= 0.85;
                    }
                    else
                    {
                        if(item >= 2500)
                        item *= 0.5;
                    }
                    break;

                case 'e' :
                case 'E' :
                    System.out.println("Total : "+x);
                    System.exit(0);

            }
            System.out.println("Item "+(i++) + " = " +item);
            x+=item;
            System.out.println("Total : "+x);
        }
    }
}