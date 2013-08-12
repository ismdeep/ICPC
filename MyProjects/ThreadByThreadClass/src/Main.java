
public class Main {
    public static void main(String[] args) {
    	    	
		ShowNumber arrShowNumber[];
		
		arrShowNumber = new ShowNumber[4];
		
		for (int i = 0; i < 4; i++)
		{
			arrShowNumber[i] = new ShowNumber();
		}
		
		for (int i = 0; i < 4; i++)
		{
			arrShowNumber[i].start();
		}
		
	}
}

// end 
// ism 
