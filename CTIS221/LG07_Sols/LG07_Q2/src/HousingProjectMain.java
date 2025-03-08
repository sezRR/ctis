import java.util.Scanner;

public class HousingProjectMain {

	public static void main(String[] args) {
		while (true) {
			System.out.println("Do you want to add Housing Project (Yes/No): ");
			Scanner scanner = new Scanner(System.in);
			String answer = scanner.nextLine();
			
			if (answer.equalsIgnoreCase("no")) {
				System.out.println("Program terminated");
				break;
			}
			
			HousingProject h = new HousingProject();
			h.getInput();
			
			System.out.println("Price after discount:\n");
			System.out.println(h);
		}

	}

}
