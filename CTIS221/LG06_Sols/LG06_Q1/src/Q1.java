public class Q1 {

	public static void main(String[] args) {
		MealPlan mealPlan1 = new MealPlan();
		mealPlan1.calculateExtraPrice();
		
		MealPlan mealPlan2 = new MealPlan("Monthly Plan", "A", 2500);
		mealPlan2.calculateExtraPrice();
		
		MealPlan mealPlan3 = new MealPlan("Semester Plan", "F", 10000);
		mealPlan3.calculateExtraPrice();
		
		mealPlan1.display();
		mealPlan2.display();
		mealPlan3.display();
		
		MealPlan[] mealPlans = new MealPlan[] {mealPlan1, mealPlan2, mealPlan3};
		System.out.println("Price of meal plans after adding extra prices - if any:");
		
		double monthlyCost = 0, semesterCost = 0;
		for (MealPlan mealPlan : mealPlans) {
			switch (mealPlan.getMealPlan()) {
			case "Monthly Plan": {
				monthlyCost += mealPlan.getPrice();
				break;
			}
			case "Semester Plan": {
				semesterCost += mealPlan.getPrice();
			}
		}
		}
		System.out.printf("Monthly Plan costs %.2f TL\n", monthlyCost);
		System.out.printf("Semester Plan costs %.2f TL", semesterCost);
	}
}
