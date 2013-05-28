public class Main
{
    public static void main(String[] args)
    {
        Number num = new Number();
        
        for (int i = 100; i <= 200; i++)
        {
            num.setValue(i);
            if (num.isPrime())
            {
                System.out.println(num.getValue());
            }
        }
        
    }
}
