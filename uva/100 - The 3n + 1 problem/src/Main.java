import java.util.Scanner;


public class Main
{
	public static class Problem
	{
		public static int cal_count (int value)
		{
			int count = 0;
			while (value != 1)
			{
				if (0 == value % 2)
				{
					value = value / 2;
				}
				else
				{
					value = value * 3 + 1;
				}
				count++;
			}
			return count;
		}
	}
	
	public static void main(String[] args)
	{
		//System.out.print("==\n");
		// TODO Auto-generated method stub
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		int a, b;
		while (scanner.hasNext())
		{
			a = scanner.nextInt();
			b = scanner.nextInt();
			
			boolean flag = false;
			
			if (a > b)
			{
				flag = true;
				int tmp_value;
				tmp_value = a;
				a = b;
				b = tmp_value;
			}
			
			int max;
			max = Main.Problem.cal_count(a);
			
			for (int i = a + 1; i <= b; i++)
			{
				int tmp = Main.Problem.cal_count(i);
				if (tmp > max)
				{
					max = tmp;
				}
			}
			max++;
			if (flag == true)
			{
				int tmp_value;
				tmp_value = a;
				a = b;
				b = tmp_value;
			}
			System.out.println( a + " " + b + " " + max);
			
		}
	}

}

