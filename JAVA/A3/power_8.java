package assiment_3;

public class power_8 {
   public static void main(String[] args){ 
    boolean power;
    int temp;
    power = true;
    temp = 100;
    if(power == true ){
        if (temp < 80 ) {
            System.out.println("Machine overheating");
        }else{
            System.out.println("Machine running normally");
        }
        
    }
    else{
        System.out.println("Machine is OFF due to no power");
    }
    System.out.println("Machine status check completed");
}
}
