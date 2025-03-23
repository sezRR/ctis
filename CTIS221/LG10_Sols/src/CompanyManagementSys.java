public class CompanyManagementSys {
	private static final int MAX_CAPACITY = 5;
	private static Employee[] employees = new Employee[MAX_CAPACITY];
	private static int count = 0;
	
	public static void addEmployee() {
		if (count == MAX_CAPACITY) {
			System.out.println("Maximum capacity of employees reached");
			return;
		}
		
		Employee newEmp = new Employee();
		newEmp.getInput();
		
		boolean isExists = searchEmployeeById(newEmp.getId());
		if (isExists) {
			System.out.println("Employee ID already exists. Please enter a different ID.");
			return;
		}
		
		employees[count++] = newEmp;
		System.out.println("Employee added successfully!");
	}
	
	public static boolean searchEmployeeById(int id) {
		for (int i = 0; i < count; i++)
			if (employees[i].getId() == id)
				return true;
		return false;
	}
	
	public static Employee searchEmployee(int id) {
		for (int i = 0; i < count; i++)
			if (employees[i].getId() == id)
				return employees[i];
		return null;
	}
	
	public static double calculateAverageSalary() {
		if (count == 0)
			return 0;
		
		double sum = 0;
		for (int i = 0; i < count; i++) {
			sum += employees[i].getSalary();
		}
		return sum / count;
	}
	
	public static String display() {
		StringBuffer strBuffer = new StringBuffer("Here is a list of the Employees:\n");
		for (int i = 0; i < count; i++) {
			strBuffer.append(employees[i]);
		}
		return strBuffer.toString();
	}
}
