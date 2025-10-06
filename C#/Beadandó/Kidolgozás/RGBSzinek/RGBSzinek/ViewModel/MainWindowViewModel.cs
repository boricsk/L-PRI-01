using Microsoft.Win32;
using RGBSzinek.Classes;
using RGBSzinek.Model;
using RGBSzinek.RelayCommand;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace RGBSzinek.ViewModel
{
    internal class MainWindowViewModel : INotifyPropertyChanged
    {
        private List<ImagePoint> _image = new List<ImagePoint>();

        #region PropChangedInterface

        public event PropertyChangedEventHandler? PropertyChanged;
        protected void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
        #endregion

        #region WPF Communication
        #endregion

        #region ICommand
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

        }
        #endregion
    }
}
