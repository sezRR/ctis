import java.util.Scanner;

public class FoodOrder {
	private String resturant;
	private String item;
	private double price;
	private static int orderCount = 0;
	private static int couponCount = 0;
	private static final double COUPON = 30;
	
	public FoodOrder() {
		orderCount++;
	}

	public static int getOrderCount() {
		return orderCount;
	}

	public static int getCouponCount() {
		return couponCount;
	}
	
	public static boolean checkForCoupons() {
		if (orderCount % 2 == 0 ) {
			couponCount++;
			System.out.println("Congratulations! You won a coupon!");
			return true;
		}
		return false;
	}
	
	public void applyCoupon() {
		if (couponCount > 0) {
			couponCount--;
			this.price -= 30;
		}
	}
	
	public void getInput() {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter restaurant: ");
		this.resturant = scanner.nextLine();
		
		System.out.print("Enter the ordered item: ");
		this.item = scanner.nextLine();
		
		System.out.print("Enter the price of the item: ");
		this.price = scanner.nextDouble();
	}

	@Override
	public String toString() {
		return "New price after applying coupon is " + this.price + "TL";
	}
	
	
}
