import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

//public final class Directiory {
//    public static File[] local(File dir, final String regex){
//        return dir.listFiles(new FilenameFilter(){
//            private Pattern pattern = Pattern.compile(regex);
//            public boolean accept(File dir,String name){
//                return pattern.matcher(new File(name).getName()).matches();
//            }
//        });
//    }
//    public static File[] local(String path,final String regex){
//        return local(new File(path), regex);
//    }
//
//    public static class TreeInfo implements Iterable<File>{
//        public  List<File> files = new ArrayList<>();
//        public List<File> dirs = new ArrayList<>();
//
//        public Iterator<File> iterator(){
//            return files.iterator();
//        }
//        void addAll(TreeInfo other){
//            files.addAll(other.files);
//            dirs.addAll(other.dirs);
//        }
//        public String toString(){
//            return "dirs:" + System.out.printf("%s",dirs)+"\n\nfiles:"+System.out.printf("%s",files);
//        }
//    }
//    public static TreeInfo walk(String start,String regex){
//        return recurseDirs(new File(start),regex);
//    }
//}
