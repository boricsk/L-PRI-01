namespace DobasSwitch
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int dobás = 0;
            Random rnd = new Random(); //objektum létrehozása!
            dobás = rnd.Next(1, 7);
            switch (dobás)
            {
                case 2:
                case 4:
                case 6:
                    Console.WriteLine("A dobás eredménye: {0} – páros", dobás);
                    break;
                case 1:
                case 3:
                case 5:
                    Console.WriteLine("A dobás eredménye: {0} - páratlan", dobás);
                    break;
            }
        }
    }
}
