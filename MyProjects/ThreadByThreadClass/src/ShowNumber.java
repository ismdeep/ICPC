
public class ShowNumber extends Thread{
    public static int i = 0;
	public void run()
    {
    	System.out.println(i++);
    }
}
