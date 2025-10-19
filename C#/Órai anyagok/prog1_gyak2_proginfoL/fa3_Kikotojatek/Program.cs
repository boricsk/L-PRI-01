namespace fa3_Kikotojatek
{
    /// <summary>
    /// 2. feladat
    /// Kikötő játék: Egy kikötőben van 11 db dokk, 
    /// sorszámuk: 2, 3, 4, … 12. A játékos eloszt N db hajót 
    /// a 11 dokkba, majd két dobókockával dob egymás után. 
    /// Amikor egy dokk sorszámát dobja, onnan elmegy egy hajó. 
    /// Ha minden dokk kiürül, vége a játéknak. 
    /// Szimulálja ezt a játékot egy programmal. 
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
    ///és a sorsolt dokkból levesz egy hajót. Adja vissza az N aktuális értékét.
    ///Program.Main()-ben:
    ///Példányosítsa a Kikötőt és tesztelje: ciklus amíg van hajó, 
    ///gombnyomásra lépkedjen, lépésenként Mutat().
    /// </summary>
    internal class Program
    {
        static void Main(string[] args)
        {
            Kikoto kikoto=new Kikoto(11);
            Console.Clear();
            kikoto.Mutat();
        }
    }
}
