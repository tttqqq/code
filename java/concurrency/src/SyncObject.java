import java.util.concurrent.TimeUnit;

class DualSynch{
    private  Object syncObject = new Object();
    public synchronized void f(){
        try {
            TimeUnit.SECONDS.sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        for(int i = 0;i<5;i++){
            System.out.println("f()");
            Thread.yield();
        }
    }

    public void g() throws InterruptedException {
        synchronized(syncObject){
//            TimeUnit.SECONDS.sleep(1);
            for(int i = 0;i<5;i++){
                System.out.println("g()");
                Thread.yield();
            }
        }
    }
}

//同一个对象中的锁对不同线程没有影响，只有在同一个线程中使用同一个对象的锁，才会出现等待的情况。
public class SyncObject {
    public static void main(String[] args) throws InterruptedException {
        final DualSynch ds = new DualSynch();
        new Thread(){
            public void run(){
                ds.f();
            }
        }.start();
//        ds.f();
        ds.g();
    }
}
