
public class PlayerMain_c {

	public static void main(String[] args) {
		Player player = new Player();
		player.display();
		player.setHighScore(673.00);
		System.out.println("\nHigh Score of the object is " + player.getHighScore());
	}

}
