namespace fa3
{
    internal class Program
    {
        //n-ig írjuk ki az ikerprím párokat
        //ikerprím két prímszám, ha különbségük 2
        static bool PrimE(int szam)
        {
            if (szam <= 1) return false;
            int gyok = (int)Math.Sqrt(szam);
            for (int i = 2; i <= gyok; i++)
            {
                if (szam % i == 0) return false;
            }
            return true;
        }
        static bool IkerPrimE(int szam1, int szam2)
        {
            if (Math.Abs(szam1 - szam2) != 2) return false;
            return PrimE(szam1) && PrimE(szam2);
        }
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("n=");
                n = int.Parse(Console.ReadLine());
            } while (n < 2);
            for (int i = 3; i <= n; i = i + 2)
            {
                if (IkerPrimE(i, i + 2)) Console.Write($"({i}, {i+2}) ");
            }
        }
    }
}
