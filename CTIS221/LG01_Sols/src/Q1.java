
public class Q1 {

	public static void main(String[] args) {
		// declaration of variables
		String university, department;

		// initialization of variables
		int x = 17, y = 5, z = 23;
		double var1 = 12.34, var2 = 98.7;
		boolean flag = true;
		String course = "Java Course";
		char letterGrade = 'C';
		university = "Bilkent University";
		department = "CTIS";
		
		// print these variables with different ways
		System.out.println("Welcome to " + university + " " + "department");
		
		System.out.println("Course name: " + course);
		System.out.println("Course name\n-----------\n" + course);
		System.out.println("Course\tname\tis\t\"" + course + "\"");
		
		System.out.printf("Letter Grade = %c", letterGrade);
		System.out.print(" - ");
		System.out.println("Letter Grade = " + letterGrade);
		
		System.out.printf("The first number is %d integer\n", x);
		System.out.println("Sum of the integers: " + x + y + z);
		System.out.println("Sum of the integers: " + (x + y + z));
		
		System.out.println("Average of doubles is " + (var1 + var2) / 2);
		System.out.printf("Average of doubles is %.3f", (var1 + var2) / 2);
		System.out.println();
		System.out.println("Flag: " + flag);
	}
}
