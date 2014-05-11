import java.util.Scanner;

public class Main
{
	public static final int MAX_SIZE = 1000001;
	public static final int MOD = 1000000007;
	public static int shit[];
	public static double fuck[];

	public static void make_the_shit_and_fuck_map()
	{
		shit = new int[Main.MAX_SIZE];
		fuck = new double[Main.MAX_SIZE];
		shit[1] = 1;
		shit[2] = 3;
		int fact = 2;
		for (int i = 3; i < Main.MAX_SIZE; i++)
		{
			shit[i] = shit[i - 1] * i + fact;   shit[i] %= Main.MOD;
			fact *= i;                          fact    %= Main.MOD;
		}
		fuck[1] = (double)1;
		for (int i = 2; i < Main.MAX_SIZE; i++)
		{
			fuck[i] = fuck[i-1] + (double)1/(double)i;
		}
	}
	
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		make_the_shit_and_fuck_map();
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		int t;
		t = scanner.nextInt();
		for (int case_index = 1; case_index <= t; case_index++)
		{
			int n;
			n = scanner.nextInt();
			System.out.print("Case " + case_index + ": " + shit[n] + " ");
			System.out.printf("%.6f", fuck[n]);
			System.out.println();
		}
	}
}
