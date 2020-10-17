public class linear_search{

    // Function for Linear Search
    public static int linearSearch(int[] arr, int key){
        for(int i=0;i<arr.length;i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1; 
    }
    public static void main(String a[]){
        // Sample Array
        int[] a1= {10,20,30,40,50,60};
        int key = 30;
        System.out.println(key+" is found at index: " + linearSearch(a1, key)); 
    }
}