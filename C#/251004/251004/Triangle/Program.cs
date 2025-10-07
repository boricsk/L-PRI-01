namespace Triangle
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Triangle();
        }

        static void Triangle()
        { 
            int n = 0;
            do
            {
                Console.WriteLine("n= ");
                n = Convert.ToInt32 (Console.ReadLine());
            } while (n < 1);

            Console.WriteLine();

            //for (int i = 1; i < n + 1; i = i + 2)
            //{
            //    Console.Write($"{i} ");
            //}

            Console.WriteLine();

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = n - i; j >= 0; j--)
                {
                    Console.Write(" ");
                }

                for (int k = 0; k < i; k++)
                {
                    if (i <= 9) { Console.Write($"0{i}"); }
                    else
                    {
                        Console.Write($"{i}");
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
