
public class ShowNumber implements Runnable{
    public static int i = 0;
	public void run()
    {
		System.out.println(i++);
	}
}
