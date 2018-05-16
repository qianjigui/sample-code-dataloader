import  java.nio.ByteBuffer;
import  java.nio.ByteOrder;

public class Main {
    public static void main(String[] args) throws Exception{
        System.out.println("Hello World");
        java.io.InputStream in = new java.io.FileInputStream(new java.io.File("../C/data.txt"));
        byte[] data = new byte[8];
        in.read(data);
        ByteBuffer bb = ByteBuffer.wrap(data);
        bb.order(ByteOrder.LITTLE_ENDIAN);
        System.out.print("Header=");
        for(int i=0;i<4;i++){
            System.out.print((char)bb.get());
        }
        System.out.println();
        System.out.println("length="+bb.getInt());
    }
}

