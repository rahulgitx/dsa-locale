import java.util.*;



// abstraction, polymorphism, encapsulation, inheritance 
public class temp2{

    public static void barkAnimal(String sound){
        System.out.println("Sound made by animal " + " " + sound);
    }

    public static void barkAnimal(int count){
        for(int i=0; i<count; i++){
            System.out.println("Sound made animal");
        }
    }

    public static void main(String...args){
        List<Integer> list = new ArrayList<>();
        list.add(1);
        // list.remove(1);

        // barkAnimal(2);
        Car car = new Car();
        car.drive();
        car.driveFast();

        Bus bus = new Bus();
        bus.pickupPassenger();
        bus.driveSlow();

    }
}

class Vehicle{
    private String engine;
    public Vehicle(){
        System.out.println("Vehicle class created");
    }
    public void drive(){
        System.out.println("Driving vehicle");
    }
    public void pickupPassenger(){
        System.out.println("Picking up passenger...");
    }
}

class Car extends Vehicle{
    public Car(){
        System.out.println("Car class created");

    }
    public void driveFast(){
        System.out.println("Driving at 100km/hr");
    }
}

class Bus extends Vehicle{
    public Bus(){
        System.out.println("Bus class created");

    }
    public void driveSlow(){
        System.out.println("Driving at 40km/hr");
    }
}