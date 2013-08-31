import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class Main
{
	
	public static long _2_pow_[] = new long[50];
	
	
	
	public static void main(String[] args)
	{
		// TODO Init _2_pow_ value
		_2_pow_[0] = 2;
		_2_pow_[1] = 4;
		for (int i = 2; i < 50; i++)
		{
			_2_pow_[i] = _2_pow_[i-1] * 2;
		}
		
		// TODO Auto-generated method stub
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		int t;
		t = scanner.nextInt();
		for (int case_index = 0; case_index < t; case_index++)
		{
			int n, k;
			n = scanner.nextInt();
			k = scanner.nextInt();
			
			long ans = 0;
			
			for (int digital = n; digital >= 1; digital--)
			{
				long mod_value = k % _2_pow_[digital];
				if ((mod_value - (_2_pow_[digital]/4) >= 0) && (mod_value + (_2_pow_[digital]/4) < _2_pow_[digital]))
				{
					ans *= 2;
					ans += 1;
				}
				else
				{
					ans *= 2;
				}
			}
			
			System.out.println(ans);
			
		}
	}

}
