namespace fa4
{
    internal class Program
    {
        //Szimuláljunk n db pénzfeldobást, keressük meg a leghosszabb
        //azonos dobásból álló sorozatot
        static void Main(string[] args)
        {
            int n;
            do
            {
                Console.Write("Hány dobás legyen? ");
                n = int.Parse(Console.ReadLine());
            } while (n < 2);
            int[] dobasok = new int[n];
            Random rnd;
            rnd = new Random();
            for (int i = 0; i < dobasok.Length; i++)
            {
                dobasok[i] = rnd.Next(2);
            }
            //for (int i = 14; i < dobasok.Length; i++)
            //{
            //    dobasok[i] = 0;
            //}
            int max = 1;
            int maxhely = 0;
            int szamlalo = 1;
            for (int i = 1; i < dobasok.Length; i++)
            {
                //Ez jó megoldás
                //if (dobasok[i - 1] == dobasok[i])
                //{
                //    szamlalo++;
                //    if (i == dobasok.Length - 1 && max < szamlalo)
                //    {
                //        max = szamlalo;
                //        maxhely = i - max + 1;
                //    }
                //}
                //else
                //{
                //    if (max < szamlalo)
                //    {
                //        max = szamlalo;
                //        maxhely = i - max;
                //    }
                //    szamlalo = 1;
                //}
            }
            Console.WriteLine("dobasok:");
            for (int i = 0; i < dobasok.Length; i++)
            {
                Console.Write(dobasok[i]);
            }
            Console.WriteLine();
            Console.WriteLine($"max={max}  maxhely={maxhely}");
        }
    }
}
