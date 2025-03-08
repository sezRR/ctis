
public class Q2 {

	public static void main(String[] args) {
		MovieTicket movieTicket1 = new MovieTicket();
		movieTicket1.calculateDiscountedPrice();
		movieTicket1.calculate3DPrice();
		
		MovieTicket movieTicket2 = new MovieTicket("Shrek 8", "Selim Deniz", 7, 26, "10.30", false, 180);
		movieTicket2.calculateDiscountedPrice();
		movieTicket2.calculate3DPrice();
		
		MovieTicket movieTicket3 = new MovieTicket("Subway Surfers The Movie", "Celal Şengör", 68, 10, "8.30", true, 200);
		movieTicket3.calculateDiscountedPrice();
		movieTicket3.calculate3DPrice();
		
		System.out.println(movieTicket1);
		System.out.println(movieTicket2);
		System.out.println(movieTicket3);
		
		System.out.println("Price of the movie tickets after updates - if any:");
		System.out.printf("%s should pay %.1f TL for %s\n", movieTicket2.getCustomerName(), movieTicket2.getPrice(), movieTicket2.getMovieName());
		System.out.printf("%s should pay %.1f TL for %s", movieTicket3.getCustomerName(), movieTicket3.getPrice(), movieTicket3.getMovieName());
	}

}
