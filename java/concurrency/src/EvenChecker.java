import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class EvenChecker implements Runnable{
    private IntGenerator generator;
    private final int id;
    public EvenChecker(IntGenerator g, int ident){
        generator = g;
        id = ident;
    }
    public void run(){
        while (!generator.isCanceled()){
            try {
                TimeUnit.SECONDS.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            int val = generator.next();
            System.out.println("id: "+ id +" val: " + val);
            if(val%2 !=0){
                System.out.println(val+" not even!");
                generator.cancel();
            }
        }
    }
    public static void  test(IntGenerator gp, int count){
        System.out.println("Press Control-c to exit");
        ExecutorService exec = Executors.newCachedThreadPool();
        for(int i = 0;i<count;i++){
            exec.execute(new EvenChecker(gp,i));
        }
        exec.shutdown();
    }
    public static void  test(IntGenerator gp){
        test(gp,10);
    }
}
