namespace Stringek
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Formázás
            short[] értékek = { Int16.MinValue, -27, 0, 1042, Int16.MaxValue };
            Console.WriteLine("{0,10} {1,10}", "Decimális", "Hexadecimális");
            foreach (short érték in értékek)
            {
                string formázott = string.Format("{0,10:G}: {0,10:X}", érték);
                Console.WriteLine(formázott);
            }

            //Összefűfés
            string név1 = "Szabó";
            string név2 = "Pál";
            string teljes_név = név1 + " " + név2;
            Console.WriteLine(teljes_név.ToUpper());
            Console.WriteLine(teljes_név.ToLower());
            Console.WriteLine(" teljes név hossza: {0}", teljes_név.Length);


        }
    }
}
