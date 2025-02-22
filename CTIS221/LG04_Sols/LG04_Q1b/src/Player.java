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
}
