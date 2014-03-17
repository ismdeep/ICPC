import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static final int MAXN = 10000;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//System.out.println("ismdeep");
		BigInteger a[] = new BigInteger[MAXN];
		for (int i = 0; i < MAXN; i++)
		{
			a[i] = new BigInteger("0");
		}
		a[4] = new BigInteger("1");
		a[1] = new BigInteger("1");
		a[2] = new BigInteger("1");
		a[3] = new BigInteger("1");
		for (int i = 5; i < MAXN; i++)
		{
			a[i] = new BigInteger("0");
			a[i] = a[i].add(a[i-1]);
			a[i] = a[i].add(a[i-2]);
			a[i] = a[i].add(a[i-3]);
			a[i] = a[i].add(a[i-4]);
		}
		int n;
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext())
		{
			n = scanner.nextInt();
			System.out.println(a[n].toString());
		}
	}

}


