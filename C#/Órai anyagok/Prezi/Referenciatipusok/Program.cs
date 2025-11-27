namespace Referenciatipusok
{
    internal class uj
    {
        public int u;
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            uj x;
            x = new uj();
            x.u = 10;
            uj y = x;
            Console.WriteLine(x.ToString());
            Console.WriteLine(x.GetType());
            Console.WriteLine(x.Equals(y));
            Console.WriteLine($"x={x} y={y}");
            Console.WriteLine($"x.u={x.u} y.u={y.u}");
            if (x == y) Console.WriteLine("Egyenlők");
            if (x.u == y.u) Console.WriteLine("Egyenlők");
            x.u = 5;
            Console.WriteLine(x.Equals(y));
            Console.WriteLine(x.GetHashCode());
            Console.WriteLine($"x={x} y={y}");
            Console.WriteLine($"x.u={x.u} y.u={y.u}");
            if (x == y) Console.WriteLine("Egyenlők"); //a referenciát hasonlítja össze
            if (x.u == y.u) Console.WriteLine("Egyenlők"); //az értéket
            Tombok();
        }

        static void Tombok()
        {
            long[] tömb = new long[20];                         //20 elemű tömb létrehozása
            tömb[0] = 526;
            tömb[19] = 7000;
            //tömb[20] = 10;                                    //IndexOutOfRangeException van futás időben (lefordul)

            int[] tmb = new int[] { 1, 2 };                     //Kezdő init
            bool[] LogikaiTömb = { true, true, false };         //New nélkül is használható a kezdőinit

            //Object tömbök
            object[] Objektumok = new object[3];
            Objektumok[0] = 48;
            Objektumok[1] = "Szöveg";
            Objektumok[2] = false;

            foreach (var obj in Objektumok)
            {
                Console.WriteLine(obj);
            }
            /*
             System.Array osztály
                 Minden tömb örököl ebből az osztályból metódusokat. 
                 Statikus metódusok, vagyis az Array osztályra kell őket meghívni és paraméterként kapják az aktuális tömböt, amin dolgoznak.
                 Sort(): egydimenziós tömböket tud rendezni
                 Reverse(): megfordítja a tömb elemeinek sorrendjét
                 Clear(): kinullázza a tömbben lévő elemek értékét

                 Tulajdonságok
                 Length: tömb elemeinek száma
                 Rank: a tömb dimenzióinak a számát adja meg.
             */

            int[] tmb1 = new int[] { 1, 2, 3, 4, 5 };
            foreach (int x in tmb1)
            {
                Console.Write("{0} ", x);
            }
            Console.WriteLine("Fordított sorrendben: ");
            Array.Reverse(tmb1);
            foreach (int x in tmb1)
            {
                Console.Write("{0} ", x); //5,4,3,2,1
            }
            Console.WriteLine("NUllázzuk az első 3 elemet: ");
            Array.Clear(tmb1, 0, 3);
            foreach (int x in tmb1)
            {
                Console.Write("{0} ", x); //0,0,0,2,1
            }
        }

        public static void TobbDimTombok()
        {
            //Két sot és 3 oszlopot tartalmazó rectangular array
            byte[,] tomb = new byte[2, 3];
            byte i = 1;
            for (int sor = 0; sor < tomb.GetLength(0); sor++)
            {
                for (int oszlop = 0; oszlop < tomb.GetLength(1); oszlop++)
                    tomb[sor, oszlop] = i++;
            }
            for (int sor = 0; sor < tomb.GetLength(0); sor++)
            {
                for (int oszlop = 0; oszlop < tomb.GetLength(1); oszlop++)
                    Console.Write(tomb[sor, oszlop] + "\t");
                Console.WriteLine();
            }
            Console.WriteLine("A tömb elemszáma: {0}, a tömb dimenziója: {1}", tomb.Length, tomb.Rank);

            //Jagged array
            int[][] jtomb = new int[4][];
            for (var ji = 0; ji < tomb.Length; i++)
            {
                jtomb[ji] = new int[ji + 2]; //Minden sor egy nem egyforma vektort tartalmaz
            }
            for (int s = 0; s < tomb.GetLength(0); s++)
            {
                for (int oszl = 0; oszl < jtomb[s].Length; oszl++)
                {
                    Console.Write(jtomb[s][oszl] + "\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine("A tömb elemszáma: {0}, a tömb dimenziója:{1}", tomb.Length, tomb.Rank);

        }
    }
}
