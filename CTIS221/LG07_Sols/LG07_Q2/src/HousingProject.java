import java.util.Scanner;

public class HousingProject {
	private String brand;
	private String city;
	private double price;
	private int numberOfPayment;
	private String housePlan;
	
	public HousingProject(String brand, String city, double price, int numberOfPayment, String housePlan) {
		super();
		this.brand = brand;
		this.city = city;
		this.price = price;
		this.numberOfPayment = numberOfPayment;
		this.housePlan = housePlan;
	}
	
	public HousingProject() {
		this.brand = "NO BRAND";
		this.city = "NO CITY";
		this.price = 0;
		this.numberOfPayment = 0;
		this.housePlan = "NO HOUSE PLAN";
	}
	
	public void getInput() {
		Scanner scanner =  new Scanner(System.in);

		System.out.print("Enter the brand: ");
		this.brand = scanner.nextLine();
		
		System.out.print("Enter the city: ");
		this.city = scanner.nextLine();
		
		System.out.print("Enter the price: ");
		this.price = scanner.nextDouble();
		
		System.out.print("Enter number of payments: ");
		this.numberOfPayment = scanner.nextInt();
		
		scanner.skip("\\R");
		
		System.out.print("Enter the house plan: ");
		this.housePlan = scanner.nextLine();
		
		System.out.print("Enter the discount percentage: ");
		
		discount(scanner.nextInt());
	}
	
	public void discount(int percentage) {
		this.price -= price * percentage/100.0;
	}
	
	@Override
	public String toString() {
		String output = "";
		output += "Housing Project\n";
		output += "Name: " + this.brand + "\n";
		output += "City: " + this.city + "\n";
		output += "Price: " + this.price + "\n";
		output += "Number of Payments: " + this.numberOfPayment + "\n";
		output += "House Plan: " + this.housePlan + "\n";
		
		return output;
	}
}
