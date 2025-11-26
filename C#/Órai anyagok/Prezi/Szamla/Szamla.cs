using System;
using System.Collections.Generic;
using System.Text;

namespace Szamla
{
    internal class Szamla
    {
        private double _egyenleg;
        public Szamla(double kezdoEgyenleg)
        {
            _egyenleg = kezdoEgyenleg;
        }

        public void Betet(double osszeg)
        {
            _egyenleg += osszeg;
        }

        public void Kivet(double osszeg)
        {
            _egyenleg -= osszeg;
        }
        public double Lekerdezes()
        { return _egyenleg; }
    }
}
