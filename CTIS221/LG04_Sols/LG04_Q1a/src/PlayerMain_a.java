public class PlayerMain_a {
	public static void main(String[] args) {
		Player player = new Player();
		player.initialize();
		System.out.println("Name: " + player.name);
		System.out.println("Type: " + player.type);
		System.out.println("High Score: " + player.highscore);
	}
}
