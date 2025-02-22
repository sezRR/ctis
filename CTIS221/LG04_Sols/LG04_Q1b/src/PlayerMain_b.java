
public class PlayerMain_b {

	public static void main(String[] args) {
		Player p1 = new Player ();
		Player p2 = new Player ("KittenLove", "Regular", 994.81);
		Player p3 = new Player ("TNTisMyBro", "Premium", 834.00);
		Player p4 = new Player ("IamNotAGamer", "Regular", 755.26);

		System.out.println("Name: " + p1.name);
		System.out.println("High Score: " + p1.highscore);
		System.out.println("Type: " + p1.type);
		
		System.out.println("Name: " + p2.name);
		System.out.println("High Score: " + p2.highscore);
		System.out.println("Type: " + p2.type);
		
		System.out.println("Name: " + p3.name);
		System.out.println("High Score: " + p3.highscore);
		System.out.println("Type: " + p3.type);
		
		System.out.println("Name: " + p4.name);
		System.out.println("High Score: " + p4.highscore);
		System.out.println("Type: " + p4.type);
	}

}
