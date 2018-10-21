import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.EOFException;
import java.io.IOException;

public class FormattedMemoryInput {
    public static void main(String[] args) throws IOException{
        try {
            DataInputStream in = new DataInputStream(
                    new ByteArrayInputStream(
                            BufferedInputFile.read("D:\\Source\\java\\IO\\src\\FormattedMemoryInput.java").getBytes()
                    )
            );
            while (true){
                System.out.print((char)in.readByte());
            }
        }catch (EOFException e){
            e.printStackTrace();
            System.err.println("End of Stream");
        }
    }
}
