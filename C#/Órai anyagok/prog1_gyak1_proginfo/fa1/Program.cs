using System.Globalization;

namespace fa1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello, World!");
            Console.WriteLine(CultureInfo.CurrentCulture + "   " +CultureInfo.CurrentUICulture);
            
            Console.WriteLine("IntMax={0}",int.MaxValue);
            Console.WriteLine("DuobleMax={0}",double.MaxValue);
            
            Console.Write("Adja meg a nevét: ");
            string nev = Console.ReadLine();
            Console.WriteLine("Helló {0}!", nev);
            Console.Write("Adja meg a kedvenc egész számát: ");
            int szam = int.Parse(Console.ReadLine());
            Console.Write("Adja meg a kedvenc nem egész számát: ");
            double szam2 = double.Parse(Console.ReadLine());
            Console.WriteLine("{0} kedvenc számai: {1}; {2}", nev, szam, szam2);
            
            //Console.ReadLine();
        }
    }
}
