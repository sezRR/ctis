import java.util.Scanner;

public class Q2 {

	public static void main(String[] args) {
		String bookType = "";
		Scanner scanner = new Scanner(System.in);
		
		do {
			System.out.println("H. Hardcover");
			System.out.println("P. Paperback");
			System.out.println("E. EBook");
			System.out.print("Enter the type of book (H/h: Hardcover, P/p: Paperback, E/e: EBook): ");
			bookType = scanner.next();
		} while (!bookType.equalsIgnoreCase("h") && !bookType.equalsIgnoreCase("p") && !bookType.equalsIgnoreCase("e"));
		
		System.out.print("How many books do you want to enter: ");
		int booksCount = scanner.nextInt();
		
		double totalCost = 0;
		for (int i = 1; i <= booksCount; i++) {
			System.out.printf("Enter %d. item's cost in TL: ", i);
			totalCost += scanner.nextDouble();
		}
		
		double totalVAT = 0;
		if (bookType.equalsIgnoreCase("h")) {
			totalVAT = totalCost * 0.12;
		} else if (bookType.equalsIgnoreCase("p")) {
			totalVAT = totalCost * 0.08;
		} else {
			totalVAT = totalCost * 0.05;
		}
		
		System.out.printf("Total cost: %.2f TL\n", totalCost);
		System.out.printf("Total VAT: %.2f TL", totalVAT);
	}

}
