import java.util.Scanner;

public class Q4 {

	public static void main(String[] args) {
		final int VIOLATION_SPEED_LIMIT = 2167;
		final int VIOLATION_RED_LIGHT = 1506;
		final int VIOLATION_PARKING = 993;
		
		double payment = 0;
		int paidBefore = 0;
		while(true) {
			System.out.println("TRAFFIC PENALTY PAYMENTS");
			System.out.println("------------------------");
			System.out.println("1. Speed Limit Violation");
			System.out.println("2. Red Light Violation");
			System.out.println("3. Parking Violation");
			System.out.println("4. EXIT");
			System.out.print("Enter the penalty article no: ");
			
			Scanner scanner = new Scanner(System.in);
			int articleNo = scanner.nextInt();

			
			double tempPayment = 0;
			
			switch (articleNo) {
			case 1: {
				tempPayment += VIOLATION_SPEED_LIMIT;
				break;
			}
			case 2: {
				tempPayment += VIOLATION_RED_LIGHT;
				break;
			}
			case 3: {
				tempPayment += VIOLATION_PARKING;
				break;
			}
			case 4: {
				System.out.printf("Penalty totals: %.2f TL\n", payment);
				System.out.printf("%d people paid the penalty before the deadline", paidBefore);
				return;
			}
			}
						
			System.out.print("Payment before deadline (y/n)? ");
			String isBefore = scanner.next();
			
			if (isBefore.equalsIgnoreCase("y")) {
				System.out.println("25% discount applied for the early payment!!");
				tempPayment -= tempPayment * 0.25;
				paidBefore++;
			}
			
			System.out.printf("Payment Amount: %.2f TL\n\n", tempPayment);
			payment += tempPayment;
		}
	}
}
