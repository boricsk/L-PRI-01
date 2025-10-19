namespace fa2_Vektor3D
{
    /// <summary>
    /// Vektor3D osztály,
    /// private tagok: név, x,y,z 
    /// public tagok:
    /// konstruktor(név, x, y, z)
    /// Hossz() metódus (Math.Sqrt(a))
    /// Kiír() metódus: formája: név(1; 2; 3) 
    /// tesztelés: példányosítás a Main-ben, metódusok meghívása
    /// </summary>
    internal class Program
    {        
        static void Main(string[] args)
        {
            ////vált...
            //int a;
            //a = 10;
            ////inicializálás
            //int b = 2;
            //Console.WriteLine(a+ " "+b);

            //Vektor3D v = new Vektor3D();
            //Console.WriteLine(v);
            Vektor3D vektor = new Vektor3D("AB", 2, 3, 4);            
            Console.WriteLine(vektor); //típust írja ki
            vektor.Kiir2();
            Console.WriteLine($"A {vektor.Kiir()} vektor hossza: {vektor.Hossz():N3}");
        }
    }
}
