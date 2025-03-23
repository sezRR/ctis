import java.util.Scanner;

public class EmployeeMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scanner = new Scanner(System.in);
		CompanyManagementSys.addEmployee();

		System.out.println("-----------------");
		System.out.println("Here is a list of the Employees: ");
		System.out.println(CompanyManagementSys.display());
		

		System.out.println("\n------------------");
		System.out.printf("Avg of all Employee Salaries's: %.2f",CompanyManagementSys.calculateAverageSalary());

		System.out.println("\n------------------");
		System.out.print("Which employee would you like to search? Enter his/her id: ");
		Employee s = CompanyManagementSys.searchEmployee(scanner.nextInt());


		while (s == null) { 

			System.out.println("There is no such employee in the array");
			System.out.print("Which employee would you like to search? Enter his/her id: ");
			s = CompanyManagementSys.searchEmployee(scanner.nextInt());
		} 
		if(s!=null) {
			System.out.println("\nHere is the employee you were looking for...\n" + s.toString());
		}

	}


}


