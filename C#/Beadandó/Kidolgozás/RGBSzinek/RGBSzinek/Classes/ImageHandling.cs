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
        private List<ImagePoint> _points = new List<ImagePoint>();
        public ImageHandling(List<ImagePoint> points)
        {
            _points = points;
        }

        public int NumberOfLightPoint()
        {
            int ret = 0;
            ret = _points.Where(p => p.isLight == true).Count();
            return ret;
        }

        public int NumberOfLightPointNoLinq()
        {
            int ret = 0;            
            foreach (var point in _points)
            {
                if (point.isLight == true) { ret++; }                
            }
            return ret;
        }

        public (byte R, byte G, byte B) GetColor(int x, int y)
        {
            (byte R, byte G, byte B) ret = (R:0, G:0, B:0);
            ret.R = _points.Where(c => c.PointX == x && c.PointY == y).Select(p => p.R).FirstOrDefault();
            ret.G = _points.Where(c => c.PointX == x && c.PointY == y).Select(p => p.G).FirstOrDefault();
            ret.B = _points.Where(c => c.PointX == x && c.PointY == y).Select(p => p.B).FirstOrDefault();
            return ret;
        }

        public int GetSumOfDarkestPoint()
        {
            int ret = 0;
            ret = _points.Min(p => p.sum);
            return ret;
        }
        public int GetSumOfDarkestPointNoLinq()
        {            
            int minValue = 255 * 3;

            foreach (ImagePoint point in _points)
            {
                if (point.sum < minValue) {minValue = point.sum;}
            }
            return minValue;
        }
        public int GetSumOfDarkestPoint2()
        {          
            return _points.Select(p => p.sum).Distinct().OrderBy(p => p).FirstOrDefault();           
        }

        public List<ImagePoint> GetDarkestPointRGBCode()
        {
            List<ImagePoint> ret = new List<ImagePoint>();
            int darkestSumValue = _points.Min(p => p.sum);
            ret = _points.Where(s => s.sum == darkestSumValue).ToList();
            return ret;
        }
        public static List<ImagePoint> OpenFile(string path)
        {
            List<ImagePoint> ret = new List<ImagePoint>();
            if (File.Exists(path))
            {
                int posY = 0;
                foreach (string line in File.ReadAllLines(path))
                {
                    string[] parts = line.Split(' ');
                    int posX = 0;
                    for (int i = 2; i < parts.Length; i = i + 3)
                    {
                        ImagePoint currentPoint = new ImagePoint();
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
