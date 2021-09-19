using System.Linq;

namespace LibraryApplication
{
    public static class Actions
    {
        public static void BorrowBook(string name, Library library){
            library.outOfLibrary.Add(library.inLibrary.Where(x => x.name == name).First());
            library.inLibrary.Remove(library.inLibrary.Where(x => x.name == name).First());
            library.outOfLibrary.Where(x => x.name == name).First().borrowed = true;
        }

        public static void ReturnBook(string name, Library library){
            library.inLibrary.Add(library.outOfLibrary.Where(x => x.name == name).First());
            library.outOfLibrary.Remove(library.outOfLibrary.Where(x => x.name == name).First());
            library.inLibrary.Where(x => x.name == name).First().borrowed = false;
        }

        public static void DeleteBook(string name, Library library)
        {
            library.inLibrary.Remove(library.inLibrary.Where(x => x.name == name).First());
        }
    }
}