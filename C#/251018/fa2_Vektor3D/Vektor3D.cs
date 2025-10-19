using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fa2_Vektor3D
{
    /// <summary>
    /// Vektor3D osztály,
    /// private tagok: név, x,y,z 
    /// public tagok:
    /// konstruktor(név, x, y, z)
    /// Hossz() metódus (Math.Sqrt(a))
    /// Kiír() metódus: formája: név(1; 2; 3) 
    /// </summary>
    internal class Vektor3D
    {
        /// private tagok: nev, x,y,z
        private string nev;
        private double x, y, z;

        //public Vektor3D()
        //{
        //}

        /// public tagok:
        /// konstruktor(név, x, y, z)
        public Vektor3D(string nev0, double x0, double y0, double z0)
        {
            nev = nev0;
            x = x0;
            y = y0;
            z = z0;
        }

        /// Hossz() metódus (Math.Sqrt(a))
        public double Hossz()
        {
            return Math.Sqrt(x * x + y * y + z * z);
        }         
        /// Kiír() metódus: formája: név(1; 2; 3)
        public string Kiir()
        {
             return string.Format($"{nev}({x}; {y}; {z})");
        }
        public void Kiir2()
        {
            Console.WriteLine($"a vektor: {nev}({x}; {y}; {z})");
        }
    }
}
