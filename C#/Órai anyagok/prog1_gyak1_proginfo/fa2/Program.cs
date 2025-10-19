namespace fa2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("10/3={0} egész osztás",10/3);
            //Console.WriteLine("10.0/3={0:N2} hányados", 10.0 / 3);
            //int a = 10, b = 3;
            //Console.WriteLine($"{a} / {b} = {a/b}  egész osztás");
            //Console.WriteLine($"(double){a} / {b} = {(double)a / b:N2} hányados");
            //Console.WriteLine($"{a} % {b} = {a % b}   maradék");

            Console.WriteLine("a természetes számok n-ig");
            int n;
            do
            {
                Console.Write("n=");
                n = Convert.ToInt32(Console.ReadLine());
            } while (n < 2);
            for (int i = 1; i < n + 1; i++)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
            Console.WriteLine("\na természetes páros számok n-ig");
            for (int i = 1; i < n + 1; i++)
            {
                if (i % 2 == 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine();
            Console.WriteLine("\na természetes páratlan számok n-ig");
            for (int i = 1; i < n + 1; i = i + 2)
            {
                Console.Write(i + " ");
            }
            //Rajzoljunk egy n soros piramist
            //   1
            //  2 2
            // 3 3 3
            //stb.
            Console.WriteLine("piramis");
            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 0; j < n - i + 1; j++)
                {
                    Console.Write("   ");
                }
                for (int j = 0; j < i; j++)
                {
                    Console.Write("{0,3}   ", i);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
