package assiment_3;

public class network_10 {
   public static void main(String[] args){ 
    int speed;
    int strength;
    speed = 20;
    strength = 50;
    if(speed > 10 || strength > 70){
        System.out.println("Good network connection");
    }
    else{
        System.out.println("Poor network connection");
    }
    System.out.println("Network test completed");
}
}
