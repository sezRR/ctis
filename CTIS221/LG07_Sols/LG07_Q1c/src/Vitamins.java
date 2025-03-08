import java.util.Scanner;

public class Vitamins {
	private String name;
	private int numberOfCapsul;
	private String brand;
	private int codeNumber;
	
	public Vitamins() {
		this.name="No Name";
		this.numberOfCapsul = 0;
		this.brand = "No Brand";
		this.codeNumber = 0;
	}
	
	public Vitamins(String name, int numberOfCapsul, String brand, int codeNumber) {
		this.name = name;
		this.numberOfCapsul = numberOfCapsul;
		this.brand = brand;
		this.codeNumber = codeNumber;
	}
	
	public void getInput() {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter name: ");
		this.name = scanner.nextLine();
		
		
		System.out.print("Enter brand name: ");
		this.brand = scanner.nextLine();
		
		System.out.print("Enter the Number of Capsule: ");
		this.numberOfCapsul = scanner.nextInt();
		
		System.out.print("Enter the Code number: ");
		this.codeNumber = scanner.nextInt();
	}

	@Override
	public String toString() {
		String output = "";
		output += "Vitamin Info:\n\n";
		output += "Name="+this.name+"\n";
		output += "NumOfCapsul ="+this.numberOfCapsul+"\n";
		output += "Brand="+this.brand+"\n";
		output += "CodeNumber="+this.codeNumber+"\n";
		return output;
	}
}
