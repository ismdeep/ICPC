import java.util.Scanner;


public class Main
{
	public static void main(String[] args)
	{
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		
		int t;
		
		t = scanner.nextInt();
		
		
		for (int case_index = 1; case_index <= t; case_index++)
		{
			System.out.print("Case " + case_index + ": ");
			
			int n;
			n = scanner.nextInt();
			
			int arr[] = new int[n];
			
			for (int i = 0; i < n; i++)
			{
				arr[i] = scanner.nextInt();
			}
			
			int jump_up = 0;
			int jump_down = 0;
			
			for (int i = 1; i < n; i++)
			{
				if (arr[i] > arr[i-1])
				{
					jump_up++;
				}
				if (arr[i] < arr[i-1])
				{
					jump_down++;
				}
			}
			
			System.out.println(jump_up + " " + jump_down);
			
		}
		
		
		
	}
}
