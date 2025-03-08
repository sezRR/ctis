
public class MealPlan {
	public static final int PLAN_MONTHLY_MEAL_COUNT = 30;
	public static final int PLAN_SEMESTER_MEAL_COUNT = 150;
	
	public static final int MENU_PRICE_ALTERNATIVE = 50;
	
	private String mealPlanName;
	private String type;
	private double price;
	
	public MealPlan() {
		this.mealPlanName = "No Meal Plan Name";
		this.type = "No type";
		this.price = 0;
	}
	
	public MealPlan(String mealPlanName, String type, double price) {
		this.mealPlanName = mealPlanName;
		this.type = type;
		this.price = price;
	}
	
	public void display() {
		System.out.println("Meal Plan");
		System.out.println("Meal Plan Name=" + this.mealPlanName);
		System.out.println("Type="+this.type);
		System.out.println("Price="+this.price+"TL\n");
	}
	
	public void calculateExtraPrice() {
		if (this.type.equalsIgnoreCase("A")) {
			switch (this.mealPlanName) {
			case "Monthly Plan": {
				this.price += MENU_PRICE_ALTERNATIVE * PLAN_MONTHLY_MEAL_COUNT;
				break;
			}
			case "Semester Plan": {
				this.price += MENU_PRICE_ALTERNATIVE * PLAN_SEMESTER_MEAL_COUNT;
				break;
			}
			}
		}
	}
	
	public String getMealPlan() {
		return this.mealPlanName;
	}
	
	public double getPrice() {
		return this.price;
	}
}
