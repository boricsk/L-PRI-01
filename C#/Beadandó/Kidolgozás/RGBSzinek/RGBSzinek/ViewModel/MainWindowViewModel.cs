using Microsoft.Win32;
using RGBSzinek.Classes;
using RGBSzinek.Model;
using RGBSzinek.RelayCommand;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;

namespace RGBSzinek.ViewModel
{
    internal class MainWindowViewModel : INotifyPropertyChanged
    {
        private List<ImagePoint>? _image = new List<ImagePoint>();
        private ImageHandling _imageHandling;

        #region PropChangedInterface

        public event PropertyChangedEventHandler? PropertyChanged;
        protected void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
        #endregion

        #region WPF Communication
        private WriteableBitmap _loadedImage;
        public WriteableBitmap LoadedImage
        { 
            get => _loadedImage;
            set { _loadedImage = value; OnPropertyChanged(); }
        }

        private string _xCoord;
        public string XCoord
        {
            get => _xCoord;
            set { _xCoord = value; OnPropertyChanged(); }
        }

        private string _yCoord;
        public string YCoord
        {
            get => _yCoord;
            set { _yCoord = value; OnPropertyChanged(); }
        }

        private string _RGBColorCode;
        public string RGBColorCode
        {
            get => _RGBColorCode;
            set { _RGBColorCode = value; OnPropertyChanged(); }
        }

        private ObservableCollection<string> _darkestPointsRgbCode;
        public ObservableCollection<string> DarkestPointsRgbCode
        {
            get => _darkestPointsRgbCode;
            set { _darkestPointsRgbCode = value; OnPropertyChanged(); }
        }

        #endregion

        #region ICommand

        public ICommand GetDarkestPixels => new ProjectRealyCommand(_ => GettingDarkestPixels());
        private void GettingDarkestPixels()
        {
            if (_imageHandling != null)
            {
                var DarkestRgb = _imageHandling.GetDarkestPointRGBCode();
                _darkestPointsRgbCode = new ObservableCollection<string>();
                foreach (var point in DarkestRgb)
                {
                    _darkestPointsRgbCode.Add($"RGB ({point.R}, {point.G}, {point.B})");
                }
                _darkestPointsRgbCode.Add($"Minimum : {_imageHandling.GetSumOfDarkestPoint()}");

                OnPropertyChanged(nameof(DarkestPointsRgbCode));
            }
            else
            {
                MessageBox.Show($"No picture loaded...", "Light pixels", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        public ICommand CountLightPixel => new ProjectRealyCommand(_ => CountingLightPixel());
        private void CountingLightPixel()
        {
            if (_imageHandling != null)
            {
                MessageBox.Show($"Number of light pixels are {_imageHandling.NumberOfLightPoint()} pc.", "Light pixels", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            { 
                MessageBox.Show($"No picture loaded...", "Light pixels", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        public ICommand GetBorders => new ProjectRealyCommand(_ => GettingBorders());
        private void GettingBorders()
        {
            if (_imageHandling != null)
            {
                MessageBox.Show($"Borders are {_imageHandling.GetCloudBorders()} .", "Borders", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                MessageBox.Show($"No picture loaded...", "Light pixels", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        public ICommand GrabColor => new ProjectRealyCommand(_ => GrabbingColor());
        private void GrabbingColor()
        {            
            _RGBColorCode = $"RGB {_imageHandling.GetColor(int.Parse(_xCoord), int.Parse(_yCoord))}";
            OnPropertyChanged(nameof(RGBColorCode));
        }

        public ICommand OpenFile => new ProjectRealyCommand(_ => OpeningFile());
        private void OpeningFile()
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.Filter = "Text files (*.txt)|*.txt";
            openFile.Title = "Open text files";
            if (openFile.ShowDialog() == true)
            {
                try
                {
                    _image = ImageHandling.OpenFile(openFile.FileName);
                    ViewImage();
                    _imageHandling = new ImageHandling(_image);
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"{ex.Message}", "OpenTextFile", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
        }
        #endregion


        #region Constructor
        public MainWindowViewModel()
        {
            _loadedImage = new WriteableBitmap(640, 360, 96, 96, PixelFormats.Rgb24, null);
        }
        #endregion

        #region Private Methods
        private void ViewImage()
        {
            int width = 640;
            int height = 360;
            int bytesPerPixel = 3; //RGB kódunk van ez 3 X 1 byte
            /*
             A memóriában így néz ki:
            [0,0,0, 0,0,0, 0,0,0]
            stride => egy teljes sor helyigénye
             */
            int stride = width * bytesPerPixel; 
            byte[] pixels = new byte[height * stride]; //Teljes 640 X 360 felbontáshoz tartozó byte tömb

            if (_image != null && _image.Any())
            {
                //Dict a gyors lekérdezéshez, hogy O(1) időben tudjuk lekérdezni a szineket
                Dictionary<(int, int), ImagePoint> pixelMap = _image.ToDictionary(p => (p.PointX, p.PointY));

                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x++)
                    {
                        int index = y * stride + x * bytesPerPixel;

                        //A TryGetValue a kulcs (x,y) tuple segítségével adja vissza a hozzá tartozó ImagePoint típusú adatot
                        //Gyorsabb a LINQ-nál.
                        if (pixelMap.TryGetValue((x, y), out ImagePoint p))
                        {
                            pixels[index + 0] = p.R; // R
                            pixels[index + 1] = p.G; // G
                            pixels[index + 2] = p.B; // B
                        }
                        else
                        {
                            // nincs adat → fekete pixel
                            pixels[index + 0] = 0;
                            pixels[index + 1] = 0;
                            pixels[index + 2] = 0;
                        }
                    }
                }
                //Mivel a formon lévő image komponens csak megjelenítésre van (nem lehet írni rá közvetlen) ezért
                //a WritableBitmat-ot kell létrehozni, amit be kell adni forrásként.
                WriteableBitmap bitmap = new WriteableBitmap(width, height, 96, 96, PixelFormats.Rgb24, null);
                bitmap.WritePixels(new Int32Rect(0, 0, width, height), pixels, stride, 0);

                _loadedImage = bitmap;
                OnPropertyChanged(nameof(LoadedImage));
            }        
        }
        #endregion
    }
}
