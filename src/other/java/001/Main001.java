import java.io.*;
import java.util.*;


public class Main001
{
    public static void main(String[] args)
    {
        int max, min;
        int tmp; // use it for input numbers
        Scanner reader = new Scanner(System.in);
        tmp = reader.nextInt();
        
        max = tmp;
        min = tmp;
        
        for (int i = 1; i < 10; i++)
        {
            tmp = reader.nextInt();
            if (tmp > max)
            {
                max = tmp;
            }
            
            if (tmp < min)
            {
                min = tmp;
            }
        }
        
        System.out.println("max = " + max + "  \nmin = " + min);
        
    }
}

// end 
// ism 

