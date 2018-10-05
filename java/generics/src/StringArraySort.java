import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class StringArraySort {
    public static void main(String[] args)
    {
        String[] arrayString = {"hello","world","chentaoquan","wangtingting"};
        Arrays.sort(arrayString,String.CASE_INSENSITIVE_ORDER);

        //三种打印
        for(String s:arrayString){
            System.out.println(s);
        }
        System.out.println("******************************************");
        //迭代器需要转换为list

        List<String> list =  Arrays.asList(arrayString);
        Iterator<String> iterator = list.iterator();
        while (iterator.hasNext()){
            String str =  (String) iterator.next();
            System.out.println(str);
        }

        System.out.println("******************************************");
        //for打印
        for(int i = 0; i<arrayString.length; i++){
            System.out.println(arrayString[i]);
        }
    }
}
