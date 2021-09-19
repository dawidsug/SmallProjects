using System;
using System.Linq;

namespace LibraryApplication
{
    public static class AdditionalMethods
    {
        public static void ChooseBook(Library library, char ch)
        {
            System.Console.WriteLine("\nWpisz numer książki");
            var num = System.Console.ReadLine();
            bool check = Int32.TryParse(num, out int choose);
            if(ch == 'l' && choose <= library.inLibrary.Count() && check)
            {
                string name = library.inLibrary[choose-1].name;
                Actions.BorrowBook(name, library);
                ViewMethods.ShowListOfBooks(library);
            }
            if(ch == 'i' && choose <= library.outOfLibrary.Count() && check)
            {
                string name = library.outOfLibrary[choose-1].name;
                Actions.ReturnBook(name, library);
                ViewMethods.ShowListOfBooks(library);
            }
            if(ch == 'u' && choose <= library.inLibrary.Count() && check)
            {
                string name = library.inLibrary[choose-1].name;
                Actions.DeleteBook(name, library);
                ViewMethods.ShowListOfBooks(library);
            }
        }
    }
}