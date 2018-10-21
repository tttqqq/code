import java.io.*;

public class BasicFileOutput {
    static String file = "chentaoquan.java";
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new StringReader(BufferedInputFile.read("D:\\Source\\java\\IO\\src\\BasicFileOutput.java")));
//        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file)));
        //对上面注释一句的优化
        PrintWriter out = new PrintWriter(file);
        int lineCount = 1;
        String s;
        while ((s = in.readLine())!= null){
            out.println(lineCount++ + ": "+ s);
        }
        out.close();
        System.out.println(BufferedInputFile.read(file));
    }
}
