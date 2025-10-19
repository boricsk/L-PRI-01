namespace fa1_buggy
{
    internal class Program
    {
        //Házi feladat
        //Buggy 7 jobbra megy játék:
        //Szimulálja a „Buggy egy, jobbra megy” játékot.
        //A körben ülő játékosok sorban mondanak egymást követő egész számokat.
        //Amikor 7re végződő, vagy 7-tel osztható szám jönne,
        //helyette azt mondja a játékos: „Buggy (hibás)”
        //és ekkor a körbejárás megfordul.
        //Jobbra kezdünk. A szimulátor eredménye és kimenete:
        // 1 j 2 j 3 j 4 j 5 j 6 j Buggy 8 b 9 b 10 b 11 b 12 b 13 b Buggy 15 j 16 j Buggy 18 b 19 b …
        //gombnyomásra lépjen tovább.
        static void Main(string[] args)
        {
            //jobb -> true
            //bool irany = true;

            //for (int i = 1; i < 30; i++)
            //{
            //    if (i % 7 == 0 || i % 10 == 7)
            //    {
            //        irany = !irany;
            //        Console.WriteLine(" Buggy");
            //    }
            //    else
            //    {
            //        Console.Write(" " + i);
            //        if (irany) Console.WriteLine(" j");
            //        else Console.WriteLine(" b");
            //    }
            //    Console.ReadLine();
            //}

            //Fizz-Buzz 3-mal és 5-tel oszthatók
            //1-től n-ig a szám helyett Fizz, ha 3-mal, Buzz, ha 5-tel osztható,
            //Fizz Buzz, ha mindkettővel
            int n;
            do
            {
                Console.Write("n=");
                int.TryParse(Console.ReadLine(),out n);
            } while (n < 0);
            string a = "Fizz", b = "Buzz";
            for (int i = 1; i < n; i++)
            {
                Console.Write(" ");
                if (i%3==0&&i%5==0)
                {
                    Console.Write(a+b);
                    //Console.Write(" FizzBuzz");
                }
                else if (i%3==0)
                {
                    Console.Write(a);
                    //Console.Write(" Fizz");
                }
                else if (i % 5 == 0)
                {
                    Console.Write(b);
                    //Console.Write(" Buzz");
                }
                else
                {
                    Console.Write(i);
                }
            }
        }
    }
    //if(irany) Console.WriteLine(" j"); 
    //else Console.WriteLine(" b");

    ////?: operátor vagy háromoperandusú operátor
    ////felt ? kif1 : kif2
    //Console.WriteLine();
}
