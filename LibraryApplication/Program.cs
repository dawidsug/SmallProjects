using System;
using System.Collections.Generic;

namespace LibraryApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            Book book1 = new Book();
            book1.name = "Ogniem i mieczem";
            book1.pages = 453;
            book1.borrowed = false;
            Book book2 = new Book();
            book2.name = "Potop";
            book2.pages = 631;
            book2.borrowed = false;
            Book book3 = new Book();
            book3.name = "Trzej muszkieterowie";
            book3.pages = 544;
            book3.borrowed = false;
            Library ourLibrary = new Library();
            ourLibrary.inLibrary = new List<Book>();
            ourLibrary.outOfLibrary = new List<Book>();
            ourLibrary.inLibrary.Add(book1);
            ourLibrary.inLibrary.Add(book2);
            ourLibrary.inLibrary.Add(book3);
            ViewMethods.Menu(ourLibrary);
        }
    }
}
