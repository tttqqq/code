public class GuessName{
	Player p1;
	Player p2;
	Player p3;
	
	public void startGame() {
		p1 = new Player();
		p2 = new Player("p2");
		p3 = new Player("P3");
		
		int guessp1 = 0;
//		int guessp2 = 0;
//		int guessp3 = 0;
		
//		boolean p1IsRight = false;
//		boolean p2IsRight = false;
//		boolean p3IsRight = false;
		
		int targetNumber = (int)(Math.random()*10);
		System.out.println("I'm thinking the number from 0 to 9 .....");
		
		while(true) {
			System.out.println("Number to guess is: "+ targetNumber);
			
			p1.guess();
			p2.guess();
			p3.guess();
			
			guessp1 = p1.number;
			System.out.println("p1 guess number: " + guessp1);
//			guessp2 = p2.number;
//			System.out.println("p1 guess number: " + guessp2);
//			guessp3 = p3.number;
//			System.out.println("p1 guess number: " + guessp3);
			
//			if(guessp1 == targetNumber || guessp2 == targetNumber || guessp3 == targetNumber) {
//				System.out.println("so easy!!");
//			}
			System.out.println("");
			if(guessp1 == targetNumber) {
//				p1IsRight = true;
				System.out.println("p1 guess!!");
				break;
			}
			
			if(p2.number == targetNumber) {
//				p2IsRight = true;
				System.out.println("p2 guess!!");
				break;
			}
			if(p3.number == targetNumber) {
//				p3IsRight = true;
				System.out.println("p3 guess!!");
				break;
			}			
			
			System.out.println("********************Round over,no body guess,Next!!***********************");			
		}
	}
}