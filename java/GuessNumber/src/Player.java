public class Player{
	public Player() {
		System.out.println("无入参的构造函数");
	}
	public Player(String p) {
		System.out.println("有入参的构造函数" + p);
		pName = p;
	}	
	int number = 0;
	String pName = "NULL";
	public void guess() {		
		number = (int)(Math.random()*10);
		System.out.println(pName + " guess the number is :" + number);
	}
}