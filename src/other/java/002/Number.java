public class Number
{
    private int value;
    
    public void setValue(int value)
    {
        this.value = value;
    }
    
    public int getValue()
    {
        return this.value;
    }
    
    public boolean isPrime()
    {
        int stop = (int)Math.sqrt(value);
        
        boolean yes = true;
        for (int i = 2; yes && i <= stop; i++)
        {
            if (value % i == 0)
            {
                yes = false;
            }
        }
        
        return yes;
    }
    
}