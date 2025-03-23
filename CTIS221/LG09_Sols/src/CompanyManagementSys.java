import java.util.Scanner;

public class CompanyManagementSys {
	private static final int MAX_CAPACITY = 5;
	private static Employee[] employee = new Employee[MAX_CAPACITY];
	private static int count = 0;

	public static void addEmployee() {
		Scanner scanner = new Scanner(System.in);
		while (count < MAX_CAPACITY) {
			Employee e = new Employee();
			System.out.print("Enter Employee Id: ");
			int id = scanner.nextInt();
			scanner.nextLine();
			if (searchEmployeeById(id)) {
				System.out.println("Employee ID already exists. Please enter a different ID.");
				continue;
			}
			e.setId(id);
			e.getInput();

			employee[count++] = e;
			System.out.println("Employee added successfully!");


			System.out.print("Do you want to add another employee? (Y/N): ");
			String response = scanner.nextLine();

			if (response.equalsIgnoreCase("N")) {
				break;
			}


			if (count == MAX_CAPACITY) {
				System.out.println("Maximum capacity of employees reached.");
				break;
			}
		}
	}


	public static boolean searchEmployeeById(int id) {
		for (int i = 0; i < count; i++) {
			if (employee[i].getId() == id) {
				return true;
			}
		}
		return false;
	}


	public static Employee searchEmployee(int id) {
		Employee foundEmployee = null;

		for (int i = 0; i < count; i++) {
			if (employee[i].getId() == (id)) {
				foundEmployee = employee[i];
				return foundEmployee;
			}
		}
		return null;
	}


	public static String display() {
		String output="";

		if (count == 0) {
			System.out.println("No employees to display.");
		} else {
			for (int i = 0; i < count; i++) {
				output +=  employee[i].toString()+ "\n";
			}
		}
		return output;
	}


	public static double calculateAverageSalary() {
		if (count == 0) {
			return 0;
		}

		double totalGpa = 0;
		for (int i = 0; i < count; i++) {
			totalGpa += employee[i].getSalary();
		}
		return totalGpa / count;
	}
}