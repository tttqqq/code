import java.util.*;

public class MapIncludeList {
    public static <K,V> Map<K,V> map(){
        return new HashMap<K,V>();
    }
    public static void main(String[] args){
        Map<String,List<String>> newMap = MapIncludeList.map();
        List<String> strList = new ArrayList<>();
        strList.add("world");
        strList.add("china");
        newMap.put("hello",strList);

        List<String> strList1 = new ArrayList<>();
        strList1.add("tao");
        strList1.add("quan");
        newMap.put("chen",strList1);
//        for(Map<String,List<String>> map: newMap){
//
//        }
        Iterator it = newMap.keySet().iterator();
        while (it.hasNext()){
            String key = (String)it.next();
            System.out.println("foreach: key "+key+ "value: " + newMap.get(key));
        }

        System.out.println("*****************************************");
        Map<Integer,List<String>> newMap1 = new HashMap<Integer,List<String>>();
        newMap1.put(1,strList);
        newMap1.put(2,strList1);

        it = newMap1.keySet().iterator();
        while (it.hasNext()){
            int key = (int)it.next();
            System.out.println("foreach: key "+key+ "value: " + newMap1.get(key));
        }


    }
}
