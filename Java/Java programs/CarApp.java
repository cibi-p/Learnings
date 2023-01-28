class Car
{
    String brand; //state or property
    String color; //state or property
    int price; //state or property
    void accelerate() //behavior or action performed or methods
    {
        System.out.println("A car accelerates");
    }
}
class CarApp
{
    public static void main(String args[])
    {
        Car c=new Car(); //c is the object of car class.
        c.brand="maruthi";
        c.color="red";
        c.price=1200000;
        System.out.println(c.brand);
        System.out.println(c.color);
        System.out.println(c.price);
        c.accelerate();
    }
}