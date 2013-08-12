
public class Main {
    public static void main(String[] args) {
		Thread[] arrShowNumber;
		arrShowNumber = new Thread[100];
		
		for (int i = 0; i < 100; i++)
		{
			arrShowNumber[i] = new Thread(new ShowNumber());
		}
		
		for (int i = 0; i < 100; i++)
		{
			arrShowNumber[i].start();
		}
		
	}
}
