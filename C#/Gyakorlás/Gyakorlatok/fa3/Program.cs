namespace fa3
{
    //n-ig írjuk ki az ikerprím párokat
    //ikerprím két prímszám, ha különbségük 2
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = 0;
            do
            {
                Console.Write("n = ");
                int.TryParse(Console.ReadLine(), out n);
            } while (n < 2);

            for (int i = 3; i < n; i++)
            {
                if (IsTwinPrime(i, i + 2)) { Console.WriteLine($"{i} {i + 2}"); }
            }
        }

        public static bool IsTwinPrime(int n1, int n2)
        {
            if (Math.Abs(n1 - n2) != 2) { return false; }
            return IsPrime(n1) && IsPrime(n2);
        }

        public static bool IsPrime(int n)
        {
            if (n == 1) { return false; }
            int sqrt = (int)Math.Sqrt(n);
            for (int i = 2; i <= sqrt; i++)
            {
                if (n % i == 0) { return false; }
            }

            return true;
        }
    }
}
