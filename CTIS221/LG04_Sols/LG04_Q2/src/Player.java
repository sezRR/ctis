public class Player {
	String name;
	String type;
	double highscore;
	
	public Player() {
		this.name = "MrDOOM93";
		this.type = "Premium";
		this.highscore = 788.49;
	}

	public Player(String name) {
		this.name = name;
	}
	
	public Player(String name, double highscore) {
		this.name = name;
		this.highscore = highscore;
	}
	
	public Player(String name, String type, double highscore) {
		this.name = name;
		this.type = type;
		this.highscore = highscore;
	}
	
	public void display() {
		System.out.println("Name: " + this.name);
		System.out.println("Type: " + this.type);
		System.out.println("High Score: " + this.highscore);
	}
	
	public double getHighScore() {
		return this.highscore;
	}
	
	public void setHighScore(double highscore) {
		this.highscore = highscore;
	}
}
