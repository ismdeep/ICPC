import java.util.Scanner;



public class Main {

	public static int next_index (int index, int n)
	{
		int indexTmp;
		if (index > n)
		{
			indexTmp = (index * 2) - 2 * n - 1;
		}
		else
		{
			indexTmp = index * 2;
		}
		return indexTmp;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub\
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNext())
		{
			int n;
			n = scanner.nextInt();
			int count = 0;
			int nextIndex;
			nextIndex = Main.next_index(1, n);count++;
			while (1 != nextIndex)
			{
				nextIndex = Main.next_index(nextIndex, n);count++;
			}
			System.out.println(count);
		}
	}

}
