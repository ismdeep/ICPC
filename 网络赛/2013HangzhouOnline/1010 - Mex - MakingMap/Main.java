import java.io.*;
import java.util.*;

public class Main
{
	public static void main (String[] args) throws FileNotFoundException
	{
		FileReader fileReader = new FileReader ("in.dat");
		Scanner scanner = new Scanner(fileReader);
		while (scanner.hasNext())
		{
			int a;
			a = scanner.nextInt();
			System.out.println (a);
		}
	}
}

