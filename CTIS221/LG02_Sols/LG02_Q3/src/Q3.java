import java.util.Random;
import java.util.Scanner;

public class Q3 {

	public static void main(String[] args) {
		System.out.println("P. Play the number guessing game");
		System.out.println("E. Exit game");
		Scanner scanner = new Scanner(System.in);
		String choice = scanner.next();
		
		if (!choice.equalsIgnoreCase("p") && !choice.equalsIgnoreCase("e")) {
			System.out.println("\nInvalid input!");
			return;
		} else if (choice.equalsIgnoreCase("e")) {
			return;
		}
		
		Random random = new Random();
		int generatedNumber = random.nextInt(10) + 1;
		
		System.out.print("Please guess a number between 1 and 10: ");
		int guess = scanner.nextInt();
		
		if (guess == generatedNumber) {
			System.out.printf("Congratulations, you have guessed number %d correctly.", generatedNumber);
		} else {
			System.out.printf("You couldn't guess correctly, the number is %d.\nSee you again next time.", generatedNumber);
		}
	}

}
