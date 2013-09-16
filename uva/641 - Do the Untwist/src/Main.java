import java.util.Scanner;


public class Main
{
	public static int Char2Int (char ch)
	{
		int intTmp = -1;
		if ('_' == ch)
		{
			intTmp = 0;
		}
		if (ch >= 'a' && ch <= 'z')
		{
			intTmp = (int)(ch - 'a' + 1);
		}
		if ('.' == ch)
		{
			intTmp = 27;
		}
		return intTmp;
	}
	public static char Int2Char(int value)
	{
		char charTmp = '\0';
		if (0 == value)
		{
			charTmp = '_';
		}
		if (value >= 1 && value <= 26)
		{
			charTmp = (char)(value - 1 + 'a');
		}
		if (27 == value)
		{
			charTmp = '.';
		}
		return charTmp;
	}
	
	public static void main (String[] args)
	{
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		
		int k;
		k = scanner.nextInt();
		while (0 != k)
		{
			String ciphertext;
			ciphertext = scanner.next();
			
			int cipher_code[] = new int[ciphertext.length()];
			int plain_code[]  = new int[ciphertext.length()];
			
			for (int i = 0; i < ciphertext.length(); i++)
			{
				cipher_code[i] = Main.Char2Int(ciphertext.charAt(i));
			}
			
			for (int i = 0; i < ciphertext.length(); i++)
			{
				plain_code[(k*i) % ciphertext.length()] = (cipher_code[i]+i) % 28;
			}
			
			for (int i = 0; i < ciphertext.length(); i++)
			{
				System.out.print(Main.Int2Char(plain_code[i]));
			}
			
			System.out.println();
			
			k = scanner.nextInt();
		}
		
	}
}