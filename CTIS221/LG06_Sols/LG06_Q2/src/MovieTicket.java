
public class MovieTicket {
	public static final double DISCOUNT_OLDER_60 = 3/10.0;
	public static final double DISCOUNT_YOUNGER_8 = 75/100.0;
	public static final double COST_3D = 80;
	
	private String movieName;
	private String customerName;
	private int customerAge;
	private int seatNb;
	private String showTime;
	private boolean is3D;
	private double price;
	
	public MovieTicket() {
		this.movieName = "No Movie Name";
		this.customerName = "No Customer Name";
		this.customerAge = 0;
		this.seatNb = 0;
		this.showTime = "No Show Time";
		this.price = 0;
	}

	public MovieTicket(String movieName, String customerName, int customerAge, int seatNb, String showTime,
			boolean is3d, double price) {
		this.movieName = movieName;
		this.customerName = customerName;
		this.customerAge = customerAge;
		this.seatNb = seatNb;
		this.showTime = showTime;
		is3D = is3d;
		this.price = price;
	}
	
	public void calculateDiscountedPrice() {
		if (this.customerAge > 60)
			this.price -= this.price * MovieTicket.DISCOUNT_OLDER_60;
		else if (this.customerAge < 8)
			this.price -= this.price * MovieTicket.DISCOUNT_YOUNGER_8;
	}
	
	public void calculate3DPrice() {
		if (this.is3D)
			this.price += COST_3D; 
	}
	

	@Override
	public String toString() {
		String output = "";
		output += "Movie Ticket\n";
		output += "Movie Name="+this.movieName+"\n";
		output += "Custome Name="+this.customerName+"\n";
		output += "Customer Age="+this.customerAge+"\n";
		output += "Seat Number="+this.seatNb+"\n";
		output += "Show Time="+this.showTime+"\n";
		output += "3D="+this.is3D+"\n";
		output += "Price="+this.price+"TL"+"\n";
		return output;
	}

	public String getMovieName() {
		return movieName;
	}

	public String getCustomerName() {
		return customerName;
	}

	public int getSeatNb() {
		return seatNb;
	}

	public double getPrice() {
		return price;
	}
	
	
}
