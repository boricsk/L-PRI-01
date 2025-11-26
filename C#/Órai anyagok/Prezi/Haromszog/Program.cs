namespace Haromszog
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double a = 0.0, b = 0.0, c = 0.0;
            string str = "";
            Console.Write("Adja meg az első oldalt! a: ");
            str = Console.ReadLine();
            a = Convert.ToDouble(str); //vagy double.Parse(str);
            Console.Write("Adja meg a második oldalt! b: ");
            str = Console.ReadLine();
            b = double.Parse(str);
            Console.Write("Adja meg a harmadik oldalt! c: ");
            c = Convert.ToDouble(Console.ReadLine());
            if (a + b > c && a + c > b && b + c > a)
                Console.WriteLine(" A háromszög megszerkeszthető.");
            else
                Console.WriteLine(" A háromszög nem szerkeszthető meg.");
        }
    }
}
