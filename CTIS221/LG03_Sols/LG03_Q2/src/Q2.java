import java.util.Iterator;
import java.util.Scanner;

public class Q2 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter 10 integer numbers:");
		
		int[] arr = new int[10];
		for (int i = 0; i < 10; i++) {
			arr[i] = scanner.nextInt();
		}
		
		System.out.print("The array content:");
		
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int numb : arr) {
			System.out.printf("%d ", numb);
			if (numb > max)
				max = numb;
			else if (numb < min)
				min = numb;
		}
		
		System.out.printf("\n\nMin number: %d Max number: %d\n\n", min, max);
		
		System.out.printf("index \t number diff. to min \t diff. to max \n");
		System.out.printf("----- \t -----\t------------ \t -------------- \n");
		for (int i = 0; i < arr.length; i++) {
			System.out.printf("%d \t %d \t %d \t\t %d\n", i, arr[i], arr[i] - min, arr[i] - max);
		}
	}

}
