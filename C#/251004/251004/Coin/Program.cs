namespace Coin
{
    internal class Program
    {
        //Szimuláljunk pénzfeldobást és keressük meg a leghosszabb sorozatot.
        /*
         01000111111001111000110010101 -> leghosszabb sorozat 6 pozíció 5

         */
        static void Main(string[] args)
        {
            int numberOfThrows = 0;
            do
            {
                Console.WriteLine("How many throws do you want? ");
                numberOfThrows = int.Parse(Console.ReadLine());
            } while (numberOfThrows < 2);

            var randomArray = GenerateRnadomSeries(numberOfThrows);

            int count = 1, tmpCount = 1;
            int pos = 0;
                        
            Console.WriteLine("The generated array");
            for (int i = 0; i < randomArray.Length; i++)
            {
                Console.Write($"{randomArray[i]} ");
            }
            Console.WriteLine("");
            for (int i = 1; i < randomArray.Length; i++)
            {
                if (randomArray[i - 1] == randomArray[i])
                {
                    count++;
                }
                else
                {
                    if (count >= tmpCount) {tmpCount = count;  pos = i- tmpCount; }
                    count = 1;
                }
            }
            Console.WriteLine($"Number of highest series : {tmpCount}");
            Console.WriteLine($"{pos}");

        }

        public static int[] GenerateRnadomSeries(int n)
        {
            int[] ret = new int[n];
            Random rnd = new Random();
            for (int i = 0; i < ret.Length; i++)
            {
                ret[i] = rnd.Next(2);
            }
            return ret;
        }
    }
}
