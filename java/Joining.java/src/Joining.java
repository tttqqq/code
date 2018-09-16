class Sleeper extends Thread{
    private int duration;
    public Sleeper(String name, int sleeepTime){
        super(name);
        duration = sleeepTime;
        start();
    }
    public  void run(){
        try {
            sleep(duration);
        }catch (InterruptedException e){
            System.out.println(getName()+"was interrupted."+"isInterrrupted():" + isInterrupted());
            System.out.println("我直接退出啦");
            return;
        }
        System.out.println(getName()+"has awakened normally!");
    }
}

class Joiner extends Thread{
    private Sleeper sleeper;
    public Joiner(String name, Sleeper sleeper){
        super(name);
        this.sleeper = sleeper;
        start();
    }
    public void run(){
        try {
            sleeper.join();
        }catch (InterruptedException e){
            System.out.println(getName()+"Interrupted");
        }
        System.out.println(getName() + "join completed");
    }
}

public class Joining {
    public static void main(String[] args){
        Sleeper A1 = new Sleeper("A1",1500);
        Sleeper A2 = new Sleeper("A2",1500);
        Joiner J1 = new Joiner("J1",A1), J2 = new Joiner("J2",A2);

        A1.interrupt();
    }

}
