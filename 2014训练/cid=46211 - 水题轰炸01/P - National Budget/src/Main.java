import java.math.BigInteger;
import java.util.Scanner;



public class Main
{
	public static void main(String[] args)
	{
		int t;
		Scanner scanner = new Scanner(System.in);
		t = scanner.nextInt();
		for (int run_id = 0; run_id < t; run_id++)
		{
			String a, b;
			a = scanner.next();
			b = scanner.next();
			BigInteger biga,bigb;
			biga = new BigInteger(a);
			bigb = new BigInteger(b);
			BigInteger sum = biga.add(bigb);
			System.out.println(sum.toString());
		}
	}
}
