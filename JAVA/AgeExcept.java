import java.util.Scanner;

class InvalidAgeExcept extends Exception {
    public InvalidAgeExcept(String s) {
        super(s);
    }
}

public class AgeExcept {
    public static void main(String []args) {
        Scanner s = new Scanner(System.in);

        try {
            int age = s.nextInt();
            if(age < 0)
                throw new InvalidAgeExcept("Age cannot be zero!");
            else if(age > 100)
                throw new InvalidAgeExcept("Age cannot be greater than 100!");

            System.out.println("Valid Age : " + age);
            
        } catch(InvalidAgeExcept e) {
            System.out.println("Error : " + e.getMessage() );
        } catch(Exception e) {
            System.out.println("Error : Please enter a valid Integer!");
        }
    }
}
