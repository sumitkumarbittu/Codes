interface A {
    void def(String s);
}

interface B {
    void def(int n);
}

public class MultipleInheritance implements A,B{
    public void def(String s) {
        System.out.println("Hello!");
    }

    public void def(int n) {
        System.out.println(n+4);
    }

    public static void main(String[] args) {
        A x = new MultipleInheritance();
        B y = new MultipleInheritance();

        x.def("Class A");
        y.def(6);
    }
}
