import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner cin = new Scanner(System.in);

        while(cin.hasNext()){
            String a1,b1,c1;
            String x;
            a1 = cin.next();
            x = cin.next();
            b1 = cin.next();
            BigInteger n = new BigInteger("2147483647");
            BigInteger a = new BigInteger(a1);
            BigInteger b = new BigInteger(b1);
            BigInteger c;
            System.out.println(a1.toString() + ' ' + x + ' ' + b1.toString());
            if(x.equals("+")){
                c = a.add(b);
                if(a.compareTo(n)>0){
                    System.out.println("first number too big");
                }
                if(b.compareTo(n)>0){
                    System.out.println("second number too big");
                }
                if(c.compareTo(n)>0){
                    System.out.println("result too big");
                }
            }
            if(x.equals("*")){
                c = a.multiply(b);
                if(a.compareTo(n)>0){
                    System.out.println("first number too big");
                }
                if(b.compareTo(n)>0){
                    System.out.println("second number too big");
                }
                if(c.compareTo(n)>0){
                    System.out.println("result too big");
                }
            }
        }
    }

}

