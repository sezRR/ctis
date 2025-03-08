import java.util.Scanner;

public class FoodOrderMain {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.print("Do you want to place an order? (Yes/No): ");
			String toCont = scanner.next();
			
			if (toCont.equalsIgnoreCase("no"))
				break;
			
			FoodOrder foodOrder = new FoodOrder();
			foodOrder.getInput();
			
			boolean isCouponAvailable = FoodOrder.checkForCoupons();
			if (isCouponAvailable || FoodOrder.getCouponCount() > 0) {
				System.out.print("Do you want to use a coupon? (Yes/No): ");
				String useCoupon = scanner.next();
				if (useCoupon.equalsIgnoreCase("yes")) {
					foodOrder.applyCoupon();
					System.out.println(foodOrder);
				}
			}
		}
		System.out.printf("You have made %d orders.\n", FoodOrder.getOrderCount());
		System.out.printf("You have %d coupons left.\n", FoodOrder.getCouponCount());
	}

}
