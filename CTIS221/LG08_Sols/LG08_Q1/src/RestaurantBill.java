import java.util.Scanner;

public class RestaurantBill {
	private int tableNo;
	private String menuItem;
	private double size;
	private double price;
	private static int countOfBills = 0;
	private static final double CHICKEN = 200;
	private static final double BEEF = 310;
	
	public RestaurantBill() {
		countOfBills++;
		
	}

	public double getPrice() {
		return price;
	}

	public static int getCountOfBills() {
		return countOfBills;
	}
	
	public void getInput() {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter the table number: ");
		this.tableNo = scanner.nextInt();
		
		scanner.skip("\\R");
		
		System.out.println("Enter the menu item's name: ");
		this.menuItem = scanner.nextLine();
		
		System.out.println("Enter the size in grams: ");
		this.size = scanner.nextInt();
	}
	
	public void calculateBill() {
		switch (this.menuItem.toLowerCase()){
		case "chicken wrap": {
			this.price += CHICKEN;
			if (this.size >= 120 && this.size < 180) {
				this.price += this.price * 0.4;
			} else if (this.size >= 180) {
				this.price += this.price * 0.7;
			}
			break;
		}
		case "beef wrap": {
			this.price += BEEF;
			if (this.size >= 120 && this.size < 180) {
				this.price += this.price * 0.4;
			} else if (this.size >= 180) {
				this.price += this.price * 0.8;
			}
			break;
		}
	}
	}

	@Override
	public String toString() {
		return "RestaurantBill [tableNo=" + tableNo + ", menuItem=" + menuItem + ", size=" + size + ", price=" + price
				+ "]";
	}
	
}
