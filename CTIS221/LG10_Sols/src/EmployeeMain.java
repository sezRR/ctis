import java.util.Scanner;

public class EmployeeMain {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			CompanyManagementSys.addEmployee();
			System.out.print("Do you want to add another employee? (Y/N): ");
			String continueAdd = sc.next();
			if (continueAdd.equalsIgnoreCase("N"))
				break;
		}

		System.out.println(CompanyManagementSys.display());
		System.out.println("--------------------");
		System.out.println("Avg of all Employee Salaries: " + CompanyManagementSys.calculateAverageSalary());
		System.out.println("--------------------");
		
		System.out.println("Which employee would you like to search? Enter their id: ");
		int searchId = sc.nextInt();
		Employee employee = CompanyManagementSys.searchEmployee(searchId);
		if (employee != null) {
			System.out.println(employee);
		}
		
	
	}

}
