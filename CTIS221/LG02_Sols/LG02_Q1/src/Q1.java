import java.util.Scanner;

public class Q1 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter worked hour: ");
		int workedHours = scanner.nextInt();
		
		double paid = 0;
		if (workedHours <= 35) {
			paid = workedHours * 10;
		} else {
			paid += 220 + (workedHours - 35) * 16;
		}
		
		System.out.printf("Amount of the salary to be paid: %.2f$", paid);
	}

}
