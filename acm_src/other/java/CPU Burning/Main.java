

public class Main
{
    public static void main(String[] args)
    {
        BurnCpu[] burn;
        burn = new BurnCpu[4];
        for (int i = 0; i < 4; i++)
        {
            burn[i] = new BurnCpu();
        }
        
        for (int i = 0; i < 4; i++)
        {
            burn[i].start();
        }
        
    }
}
