import java.util.Scanner;

public class RestaurantBillMain {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
			System.out.print("Do you want to check the bill (Yes/No): ");
			
			String cont = scanner.next();
			if (cont.equalsIgnoreCase("no")) {
				break;
			}
			
			RestaurantBill restaurantBill = new RestaurantBill();
			restaurantBill.getInput();
			restaurantBill.calculateBill();
			System.out.printf("The bill is %.1f TL\n", restaurantBill.getPrice());
		}
		
		System.out.printf("There are %d bills.", RestaurantBill.getCountOfBills());
	}

}
