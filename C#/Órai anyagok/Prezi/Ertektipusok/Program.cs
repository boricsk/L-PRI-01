namespace Ertektipusok
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int x = 10;
            int y = x;
            Console.WriteLine(x.ToString());
            Console.WriteLine(x.GetType());
            Console.WriteLine(x.Equals(y));
            Console.WriteLine($"x={x} y={y}");
            if (x == y)
                Console.WriteLine("Egyenlők ");
            x = 5;
            Console.WriteLine(x.Equals(y));
            Console.WriteLine(x.GetHashCode());
            Console.WriteLine($"x={x} y={y}");
            if (x == y)
                Console.WriteLine("Egyenlők");

        }
    }
}
