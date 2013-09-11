
public class Main {
    public boolean isPrime(int num)
    {
    	int stop = (int)Math.sqrt(num);
    	boolean yes = true;
    	
    	for (int i = 2; yes && i <= stop; i++)
    	{
    		if (num % i == 0)
    		{
    			yes = false;
    		}
    	}
    	
    	return yes;
    }
    
    public static void main(String[] args) {
		Main nMain = new Main();
    	
    	for (int number = 100; number <= 200; number++)
		{
			if (nMain.isPrime(number))
			{
				System.out.print(number);
				System.out.println();
			}
		}
	}
    
}
