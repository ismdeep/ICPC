
public class ThreadRunnable {
    public static void main(String[] args) {
		Thread t1 = new Thread(new Hello1());
		Thread t2 = new Thread(new Hello2());
		Thread t3 = new Thread(new Hello3());
		Thread t4 = new Thread(new Hello4());
		t1.start();
		t2.start();
		t3.start();
		t4.start();
	}
}


