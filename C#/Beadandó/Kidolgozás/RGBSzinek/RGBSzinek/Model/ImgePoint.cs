using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RGBSzinek.Model
{
    public class ImagePoint
    {
        public int sum => R + G + B;
        public int avg => sum / 3;
        public bool isLight => sum > 600;

        public byte R { get; set; }
        public byte G { get; set; }
        public byte B { get; set; }

        public int PointX { get; set; }
        public int PointY { get; set; }

    }
}
