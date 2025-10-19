using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fa3_Kikotojatek
{
    /// Készítsen egy Kikötő osztályt a következő elemekkel:
    ///kikötő osztály { adattag: hajókszáma int[] (dokkokban) 
    ///                         N egész, a hajók száma a kikötőben}
    ///konstruktor() :  be param dokkok száma, lefoglalja a tömböt, 
    ///                 kiosztja a hajókat (beolvas meghívása)
    ///Beolvas():	 be void, bekéri a dokkokban álló hajók számát,
    ///beírja a tömbbe, N frissítése
    ///Mutat() :    be void, kiírja a kikötő állapotát az alábbi 
    ///formátumban:
    ///2: OOOO
    ///3: OO
    ///…
    ///ki: a kikötőben lévő hajók száma
    ///
    ///Sorsol(): be void, dob két dobókockával, az összeget kiírja, 
    ///és a sorsolt dokkból levesz egy hajót.
    internal class Kikoto
    {
        ///kikötő osztály { adattag: hajókszáma int[] (dokkokban) 
        ///                         N egész, a hajók száma a kikötőben}
        private int[] hajokSzama;
        private int N;
        ///konstruktor() :  be param dokkok száma, lefoglalja a tömböt, 
        ///                 kiosztja a hajókat (beolvas meghívása)
        public Kikoto(int dokkokSzama)
        {
            hajokSzama = new int[dokkokSzama];
            Beolvas();
        }
        ///Beolvas():	 be void, bekéri a dokkokban álló hajók számát,
        ///beírja a tömbbe, N frissítése
        private void Beolvas()
        {
            N = 0;
            for (int i = 0; i < hajokSzama.Length; i++)
            {
                Console.Write($"{i + 2}. dokk: ");
                hajokSzama[i] = int.Parse(Console.ReadLine());
                N += hajokSzama[i];
            }
        }
        ///Mutat() :    be void, kiírja a kikötő állapotát az alábbi 
        ///formátumban:
        ///2: OOOO
        ///3: OO
        ///…
        ///ki: a kikötőben lévő hajók száma
        public void Mutat()
        {
            for (int i = 0; i < hajokSzama.Length; i++)
            {
                Console.Write($"{i + 2,2} : ");
                for (int j = 0; j < hajokSzama[i]; j++)
                {
                    Console.Write("O");
                }
                Console.WriteLine();
            }
            Console.WriteLine("A kikötőben lévő hajók száma: " + N);
        }
    }
}
