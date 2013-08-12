import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
    	Scanner scanner = new Scanner(System.in);
    	
    	int tmp;
    	int max, min;
    	
    	tmp = scanner.nextInt();
    	max = tmp;
    	min = tmp;
    	
    	for (int i = 1; i < 10; i++)
    	{
    		tmp = scanner.nextInt();
    		if (min > tmp)
    		{
    			min = tmp;
    		}
    		
    		if (max < tmp)
    		{
    			max = tmp;
    		}
    	}
    	
    	System.out.println("max = " + max + "  min = " + min);
    	
	}
}
