package Sorting;

import java.util.Scanner;

public class BubbleSort {
    void sort(int[] arr){

        for (int i = 0; i < arr.length - 1; i++) {
            for (int i1 = 0; i1 < arr.length - 1 - i; i1++) {
                if(arr[i1]>arr[i1+1]){
                    int temp = arr[i1];
                    arr[i1] = arr[i1+1];
                    arr[i1+1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BubbleSort bubbleSort = new BubbleSort();
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scanner.nextInt();
        }
        bubbleSort.sort(arr);
        System.out.println("Sorted Elements: ");
        for (int i = 0;i<arr.length;i++){
            System.out.print(arr[i] + " ");
        }
    }
}
