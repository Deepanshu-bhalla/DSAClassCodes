package Sorting;

import java.util.Scanner;

public class InsertionSort {
    void sort(){
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[5];

        //Step-1 Input

        System.out.println("Enter elements in Array");
        for (int i = 0; i < arr.length; i++) {
            arr[i]  = scanner.nextInt();
        }

        //Step-2 Process
        for(int r=1;r<arr.length;r++){ //pass
            for(int c=0;c<r;c++){//comp
                if(arr[r]<arr[c]){ //swapping
                    int temp = arr[c];
                    arr[c] = arr[r];
                    arr[r] = temp;
                }
            }
        }


        //Step-3 Output

        System.out.println("---InsertionSort---");
        for (int j : arr) {
            System.out.print(j + " ");
        }
    }
    public static void main(String[] args) {
        InsertionSort insertionSort = new InsertionSort();
        insertionSort.sort();

    }
}
