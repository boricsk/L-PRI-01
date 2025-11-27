namespace BoxingAndUnboxing
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Boxing
            double x = 5.2;
            object boxing = x;

            //Unboxing
            double unboxing = (double)boxing;
        }
    }
}
