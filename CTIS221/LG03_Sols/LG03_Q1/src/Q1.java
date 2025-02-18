import java.util.Scanner;

public class Q1 {

	static String menu() {
		Scanner scanner = new Scanner(System.in);
		
		String choice;
		do {
			System.out.println("	MENU		");
			System.out.println("********************");
			System.out.println("A. Add fractional parts of two numbers (maximum 4 decimal digits for each number)");
			System.out.println("B. Convert a double number to integer");
			System.out.println("C. QUIT");
			System.out.print("Enter your choice: ");
			choice = scanner.next();
		} while (!choice.equalsIgnoreCase("A") && !choice.equalsIgnoreCase("B") && !choice.equalsIgnoreCase("C"));
		
		return choice;
	}
	
	static double fracPart(double num1, double num2) {
		return (num1 - (int)num1) + (num2 - (int)num2);
	}
	
	static int roundNum(double num) {
		return (int)Math.round(num);
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
			String choice = menu();
			
			if (choice.equalsIgnoreCase("A")) {
				System.out.println("Enter two double numbers");
				double num1 = scanner.nextDouble();
				double num2 = scanner.nextDouble();
				System.out.printf("%.4f + %.4f = %.4f\n\n", num1, num2, fracPart(num1, num2));
			} else if (choice.equalsIgnoreCase("B")) {
				System.out.print("Enter a double number: ");
				double num = scanner.nextDouble();
				System.out.printf("The number %.4f converted to the integer number %d\n\n", num, roundNum(num));
			} else {
				return;
			}
		}

	}

}
