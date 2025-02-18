import java.util.Iterator;
import java.util.Scanner;

public class Q3 {
	static int menu() {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("	MENU		");
		System.out.println("1. Initialize array");
		System.out.println("2. Input array elements");
		System.out.println("3. Output array elements");
		System.out.println("4. Searcha value");
		System.out.println("5. Exit program");
		int choice;
		do {
			System.out.print("Enter your choice: ");
			choice = scanner.nextInt();
		} while (choice < 1 || choice >  5);
		
		return choice;
	}
	
	static void initialize(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			arr[i] = 0;
		}
		System.out.println("All elements are initialized by zero\n");
	}
	
	static int fillArray(int[] arr) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter the elements of the array:");
		
		int pos = 0;
		int lastEl = -1;
		while (pos < 10 && lastEl != 0) {
			lastEl = scanner.nextInt();
			arr[pos++] = lastEl;
		}
		pos -= 1;
		System.out.printf("The size of the array: %d\n\n", pos);
		return pos;
	}
	
	static void displayArray(int[] arr) {
		for (int numb : arr) {
			System.out.printf("%d ", numb);
		}
		System.out.println("\n");
	}
	
	static int findPos(int[] arr, int search) {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == search)
				return i;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		int[] arr = new int[10];
		
		while(true) {
			int choice = menu();
			switch (choice) {
			case 1: {
				initialize(arr);			
				break;
			}
			case 2: {
				fillArray(arr);
				break;
			}
			case 3: {
				displayArray(arr);
				break;
			}
			case 4: {
				Scanner sc = new Scanner(System.in);
				System.out.print("Enter the value that will be searched: ");
				int res = findPos(arr, sc.nextInt());
				if (res != -1) {
					System.out.printf("Position of the value is: %d\n\n", res);
				} else {
					System.out.println("The array does NOT contain the searched number!");
				}
				break;
			}
			case 5: {
				return;
			}
			}
		}
	}
}
