import java.util.Scanner;


public class Main
{
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		int n;
		n = scanner.nextInt();
		while (n != 0)
		{
			int tmp = n % 9;
			if (tmp == 0)
			{
				tmp = 9;
			}
			System.out.println(tmp);
			
			n = scanner.nextInt();
		}
	}

}