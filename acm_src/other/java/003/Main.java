import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		
		int a, b, c;
		a = read.nextInt();
		b = read.nextInt();
		c = read.nextInt();
		
		if (b > a)
		{
			int tmp;
			tmp = a;
			a   = b;
			b   = tmp;
		}
		
		if (c > a)
		{
			int tmp;
			tmp = a;
			a   = c;
			c   = tmp;
		}
		
		if(c > b)
		{
			int tmp;
			tmp = b;
			b   = c;
			c   = tmp;
		}
		
		System.out.println(a + " " + b + " " + c);
	}
}

