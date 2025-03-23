import java.util.Scanner;

public class Employee {

	private String name;
	private int id;
	private double salary;
	private boolean isManager;
	public Employee() {
	}

	// getters and setters
	


	public void getInput() {

		// for getting user input
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Employee Name: ");
		name = scanner.nextLine();
		System.out.print("Enter Employee Salary: ");
		salary = scanner.nextDouble();
		scanner.nextLine();

		System.out.print("Does employee manager? (Y/N): ");
		String scholar = scanner.nextLine();
		if(scholar.equalsIgnoreCase("Y"))
			this.isManager = true;
		else if(scholar.equalsIgnoreCase("N"))
			this.isManager = false;

	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public double getSalary() {
		return salary;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public String getName() {
		return name;
	}

	@Override
	public String toString() {
		String a ="";
		if(isManager == true) {
			a += "Employee is a manager.";
		}else {
			a+= "Employee is not a manager.";
		}
		return "Employee Name=" + name 
				+ ",\n Id=" + id 
				+ ",\n Salary=" + salary 
				+ ",\n Manager Status=" + a + "\n";
	}

}
