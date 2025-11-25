namespace Kor
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int r;
            string sr;
            const double PI = 3.14;
            double kerület, terület;
            Console.WriteLine("Adja meg a kör sugarát!");
            sr = Console.ReadLine();
            //r = Convert.ToInt32(sr);
            if (int.TryParse(sr, out r))
            {
                Console.WriteLine("A kör sugara: {0}", r);
                kerület = 2 * r * PI;
                terület = r * r * PI;
                //vagy terület = Math.Pow(r, 2) * PI;
                Console.WriteLine("A kör kerülete: {0}, a területe: {1}.", kerület, terület);
            }
        }
    }
}
