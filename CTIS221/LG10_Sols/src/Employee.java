import java.util.Scanner;

public class Employee {
	private String name;
	private int id;
	private double salary;
	private boolean isManager;
	
	public Employee() {
		
	}
	
	public void getInput() {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter Employee Id: ");
		this.id = scanner.nextInt();
		
		scanner.skip("\\R");
		
		System.out.print("Enter Employee Name: ");
		this.name = scanner.nextLine();
		
		System.out.print("Enter Employee Salary: ");
		this.salary = scanner.nextDouble();
		
		System.out.print("Is the employee a manager (Y/N): ");
		String isManager = scanner.next();
		if (isManager.equalsIgnoreCase("Y")) {
			this.isManager = true;
		}
	}

	public String getName() {
		return name;
	}

	public int getId() {
		return id;
	}

	public double getSalary() {
		return salary;
	}

	public boolean getManagerStatus() {
		return isManager;
	}

	public void setId(int id) {
		this.id = id;
	}

	@Override
	public String toString() {
		StringBuffer strBuffer = new StringBuffer("");
		strBuffer.append("Employee Name=" + this.getName() + ",\n  Id=" + this.getId() + ",\n Salary=" + this.getSalary() + ",\n Manager Status = ");
		if (this.getManagerStatus()) {
			strBuffer.append("Employee is a manager");
		} else {
			strBuffer.append("Employee is not a manager");
		}
		strBuffer.append("\n");
		return strBuffer.toString();
	}

	
	
}
