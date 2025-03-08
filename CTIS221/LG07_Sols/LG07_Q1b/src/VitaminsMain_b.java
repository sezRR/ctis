import java.util.Scanner;

public class VitaminsMain_b {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter name: ");
		String name = scanner.nextLine();
		
		scanner.skip("\\R");
		
		System.out.print("Enter brand name: ");
		String brand = scanner.nextLine();
		
		System.out.print("Enter the Number of Capsule: ");
		int numberOfCapsul = scanner.nextInt();
		
		System.out.print("Enter the Code number: ");
		int codeNumber = scanner.nextInt();
		
		 Vitamins vitamins1 = new Vitamins();
		 vitamins1.setName(name);
		 vitamins1.setBrand(brand);
		 vitamins1.setNumberOfCapsul(numberOfCapsul);
		 vitamins1.setCodeNumber(codeNumber);
		 
		 System.out.println(vitamins1.toString());
	}

}
