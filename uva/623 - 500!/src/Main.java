import java.math.BigInteger;
import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext())
		{
			int n;
			n = scanner.nextInt();
			BigInteger sumBigInteger = new BigInteger("1");
			for (int i = 1; i <= n; i++)
			{
				sumBigInteger = sumBigInteger.multiply(new BigInteger(Integer.toString(i)));
			}
			System.out.println(n + "!");
			System.out.println(sumBigInteger.toString());
		}
	}

}
