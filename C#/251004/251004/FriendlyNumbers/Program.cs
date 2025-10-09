/*
A számelméletben azokat a számpárokat, amelyekre igaz, hogy az egyik szám önmagánál 
kisebb osztóinak összege a másik számmal egyenlő és fordítva, barátságos számoknak hívjuk.

Ilyen például a (220; 284) számpár.

220 önmagánál kisebb osztói: 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110.

1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284

284 önmagánál kisebb osztói: 1, 2, 4, 71, 142.

1 + 2 + 4 + 71 + 142 = 220.

 */

namespace FriendlyNumbers
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Friendly numbers");
            Console.WriteLine(IsFriendlyPair(1184, 1210));
        }

        public static bool IsFriendlyPair(int num1, int num2)
        {
            List<int> _number1Divisors = new List<int>();
            List<int> _number2Divisors = new List<int>();
            
            for (int i = 1; i < num1; i++)
            {
                if (num1 % i == 0) { _number1Divisors.Add(i); }
            }

            for (int i = 1; i < num2; i++)
            {
                if (num2 % i == 0) { _number2Divisors.Add(i); }
            }

            return _number1Divisors.Sum() == num2 && _number2Divisors.Sum() == num1;
        }
    }
}
