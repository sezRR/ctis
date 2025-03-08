
public class Vitamins {
	private String name;
	private int numberOfCapsul;
	private String brand;
	private int codeNumber;
	
	public Vitamins() {
		this.name="No Name";
		this.numberOfCapsul = 0;
		this.brand = "No Brand";
		this.codeNumber = 0;
	}
	
	public Vitamins(String name, int numberOfCapsul, String brand, int codeNumber) {
		this.name = name;
		this.numberOfCapsul = numberOfCapsul;
		this.brand = brand;
		this.codeNumber = codeNumber;
	}
	
	
	
	public void setName(String name) {
		this.name = name;
	}

	public void setNumberOfCapsul(int numberOfCapsul) {
		this.numberOfCapsul = numberOfCapsul;
	}

	public void setBrand(String brand) {
		this.brand = brand;
	}

	public void setCodeNumber(int codeNumber) {
		this.codeNumber = codeNumber;
	}

	@Override
	public String toString() {
		String output = "";
		output += "Vitamin Info:\n\n";
		output += "Name="+this.name+"\n";
		output += "NumOfCapsul ="+this.numberOfCapsul+"\n";
		output += "CodeNumber="+this.codeNumber+"\n";
		return output;
	}
}
