namespace Szamla
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Szamla sz = new Szamla(1000000);

            Console.WriteLine($"Az egyenlae : {sz.Lekerdezes()}");
            sz.Betet(20000);
            Console.WriteLine($"Az egyenleg : {sz.Lekerdezes()}");
        }
    }
}
