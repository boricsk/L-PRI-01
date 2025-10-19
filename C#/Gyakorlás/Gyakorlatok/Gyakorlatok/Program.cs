using System.Globalization;

namespace Gyakorlatok
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"Culture info : {CultureInfo.CurrentCulture} {CultureInfo.CurrentUICulture}");
            Console.WriteLine($"Int maximum : {int.MaxValue}");
            Console.WriteLine($"Double maximum : {double.MaxValue}");
            Console.WriteLine("Kérem a neved :");
            string nev = Console.ReadLine();
            Console.WriteLine("Kedvenc egész szám? ");
            int favInt = int.Parse( Console.ReadLine() );
            Console.WriteLine("Kedvenc nem egész szám? ");
            double favdouble = double.Parse( Console.ReadLine() );
            Console.WriteLine($"A kedvenc számaid : {favInt} , {favdouble}");
        }
    }
}
