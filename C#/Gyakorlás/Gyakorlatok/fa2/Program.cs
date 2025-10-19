namespace fa2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //természetes számok n-ig
            int n = 0;
            do
            {
                Console.Write("n = ");
                int.TryParse(Console.ReadLine(), out n );
            } while (n < 2);

            Console.WriteLine($"A természetes számok {n} -ig");

            for (int i = 1; i <= n; i++)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            Console.WriteLine($"A páros természetes számok {n} -ig");
            for (int i = 2; i <= n; i = i + 2)
            {
                Console.Write($"{i} ");
            }            
            Console.WriteLine();
            
            Console.WriteLine($"A páratlan természetes számok {n} -ig");
            for (int i = 1; i <= n; i = i + 2)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            Console.WriteLine("Háromszög");
            for (int i = 1; i <= n ; i++)
            {
                for (int j = 0; j < n - i + 1; j++)
                {
                    Console.Write("   ");
                }

                for (int j = 0; j < i; j++)
                {
                    Console.Write("{0,3}   ",i);
                }
                Console.WriteLine();
            }

            Console.WriteLine();
        }
    }
}
