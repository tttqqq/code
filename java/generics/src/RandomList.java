import java.util.ArrayList;
import java.util.Random;

public class RandomList<T> {
    private ArrayList<T> arrayList = new ArrayList<T>();
    private Random rand = new Random(47);
    public void add(T aa){
        arrayList.add(aa);
    }
    public T select(){
        int index = rand.nextInt(arrayList.size());
        System.out.println("the random select: "+ index);
        return arrayList.get((int)Math.random()*arrayList.size());
    }
    public static void main(String[] args){
        RandomList<String> randomList = new RandomList<String>();
        for(String s : ("hello world my name is chentaoquan . what is your name , baby ？").split(" ")){
            randomList.add(s);
        }
        System.out.println("the random select String name: "+ randomList.select());
    }
}
