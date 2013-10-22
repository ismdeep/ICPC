import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger fabonacci[] = new BigInteger[44];
		for (int i = 0; i < 44; i++)
		{
			fabonacci[i] = new BigInteger("0");
		}
		fabonacci[1] = new BigInteger("1");
		fabonacci[2] = new BigInteger("1");
		for (int i = 3; i < 44; i++)
		{
			fabonacci[i] = fabonacci[i-1].add(fabonacci[i-2]);
		}
		int n;
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext())
		{
			n = scanner.nextInt();
			for (int i = 1; i <= n; i++)
			{
				System.out.print(fabonacci[i].toString() + " ");
			}
			System.out.println();
		}
	}

}
