using RGBSzinek.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RGBSzinek.Classes
{
    public class ImageHandling
    {
        public ImageHandling()
        {

        }

        public int NumberOfLightPoint(List<Point> points)
        {
            int ret = 0;
            ret = points.Where(p => p.isLight == true).Count();
            return ret;
        }

        public (byte R, byte G, byte B) GetColor(List<Point> points, int x, int y)
        {
            (byte R, byte G, byte B) ret = (R:0, G:0, B:0);
            ret.R = points.Where(c => c.PointX == x && c.PointY == y).Select(p => p.R).FirstOrDefault();
            ret.G = points.Where(c => c.PointX == x && c.PointY == y).Select(p => p.G).FirstOrDefault();
            ret.B = points.Where(c => c.PointX == x && c.PointY == y).Select(p => p.B).FirstOrDefault();
            return ret;
        }
        public List<Point> OpenFile(string path)
        {
            List<Point> ret = new List<Point>();
            if (File.Exists(path))
            {
                int posY = 0;
                foreach (string line in File.ReadAllLines(path))
                {
                    string[] parts = line.Split(' ');
                    int posX = 0;
                    for (int i = 2; i < parts.Length; i = i + 3)
                    {
                        Point currentPoint = new Point();
                        currentPoint.R = byte.Parse(parts[i - 2]);
                        currentPoint.G = byte.Parse(parts[i - 1]);
                        currentPoint.B = byte.Parse(parts[i]);
                        currentPoint.PointX = posX;
                        currentPoint.PointY = posY;
                        ret.Add(currentPoint);
                        posX++;
                    }
                    posY++;
                }
            }
            return ret;
        }
    }
}
