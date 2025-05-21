interface abc {    
    void def(String a);

    void ghi(int x);
}

public class Interface implements abc {
    public void def(String a) {
        System.out.println(a);
    }

    public void ghi(int x) {
        System.out.println(x+3);
    }

    public static void main(String[] args) {
        abc x = new Interface();

        x.def("Hello!");
        x.ghi(4);
    }
}
