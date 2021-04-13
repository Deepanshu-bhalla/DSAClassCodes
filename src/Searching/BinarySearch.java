package Searching;

import java.util.Scanner;

public class BinarySearch {
    void func(){
        System.out.println("Enter elements in array");
        Scanner s = new Scanner(System.in);
        int [] arr = new int[10];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = s.nextInt();
        }


        //process

        int lb=0,ub=arr.length-1,mid = 0,count=0;
        System.out.println("Enter Searching element");
        int searchingElement = s.nextInt();

        while (lb<=ub){
            mid = (lb+ub)/2;
            if(arr[mid]==searchingElement || arr[mid]==ub || arr[mid]==lb){
                count++;
                break;
            }
            else if(searchingElement<arr[mid]){
                ub=mid-1;
            }
            else if(searchingElement>arr[mid]){
                lb = mid +1;
            }
        }

        if(count>0){
            System.out.println("Element Found");
        }
        else
            System.out.println("Element Not Found");

    }

    public static void main(String[] args) {
        BinarySearch obj = new BinarySearch();
        obj.func();
    }
}
