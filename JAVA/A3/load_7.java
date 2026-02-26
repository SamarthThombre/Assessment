package assiment_3;

public class load_7 {
   public static void main(String[] args){ 
    int load;
    load=80;
    if(load < 40){
        System.out.println("Low server load");
    }else if(load < 75){
        System.out.println("Moderate server load");
    }
    else{
        System.out.println("High server load");
    }
}
}
