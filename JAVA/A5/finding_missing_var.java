class Finding_Missing_Var {
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10, 11, 12, 12, 14, 15, 16, 17, 18, 19, 20};
       
        System.out.println("The array is: ");
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        
        System.out.println();
        for(int i = 1; i <= arr.length; i++) {

            if(arr[i-1] != i) {
                arr[i-1] = i;
            }
        }
        
        System.out.println("The array is: ");
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}