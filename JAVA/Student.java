public class Student
{
    public static void main(String[] args)
    {
        if(args.length != 4)
        return;
        String name = args[0];
        String roll = args[1];
        String course = args[2];
        String sem = args[3];

        System.out.println(" name : " +name);
        System.out.println(roll);
        System.out.println(course);
        System.out.println(sem);
    }
}