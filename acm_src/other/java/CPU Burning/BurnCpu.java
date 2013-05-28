public class BurnCpu extends Thread
{
    int sum;
    int MAXN = 999999;
    public void run()
    {
        for (int i = 0; i < MAXN; i++)
        {
            for (int j = 0; j < MAXN; j++)
            {
                sum = i * j;
            }
        }
    }
}
