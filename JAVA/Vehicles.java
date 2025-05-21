import java.util.*;

class Vehicle {
    private String brand;
    private int year;

    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }

    public String getbrand() {
        return brand;
    }

    public int getyear() {
        return year;
    }

    public void display() {
        System.out.println("Brand : " + brand);
        System.out.println("Year : " + year);
    }
}

class Car extends Vehicle {
    private int numdoors;

    public Car(String brand, int year, int numdoors) {
        super(brand, year);
        this.numdoors = numdoors;
    }
    public void display() {
        super.display();
        System.out.println("No of Doors : " + numdoors);
    }
}

class ElectricCars extends Car {
    private double batterycap;

    public ElectricCars(String brand, int year, int numdoors, double batterycap) {
        super(brand, year, numdoors);
        this.batterycap = batterycap;
    }

    public void display() {
        super.display();
        System.out.println("Battery Capacity : " + batterycap);
    }
}

public class Vehicles {
    public static void main(String[] args) {
        ElectricCars a = new ElectricCars("TATA", 2024, 4, 4.4);
        a.display();
        System.out.println(a.getbrand());
        System.out.println(a.getyear());
    }
}