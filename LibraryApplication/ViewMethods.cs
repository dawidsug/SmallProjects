using System;
using System.Threading;

namespace LibraryApplication
{
    public class ViewMethods
    {
        public static void Menu(Library library)
        {
            Console.Clear();
            char choice = ' ';
            Console.WriteLine("WITAMY W BIBLIOTECE\nPokaż listę książek: wciśnij l\nWprowadź nową książkę: wciśnij i\n");
            choice = Console.ReadKey().KeyChar;
            if(choice == 'l')
            {
                ShowListOfBooks(library);
            }
            if(choice == 'i')
            {
                InsertNewBook(library);
            }
            else
            {
                Menu(library);
            }
        }

        public static void ShowListOfBooks(Library library)
        {
            Console.Clear();
            Console.WriteLine("Książki w bibliotece:\n");
            if(library.inLibrary.Count != 0)
            {
                for(int i = 0; i < library.inLibrary.Count; i++)
                {
                    Console.WriteLine($"{i+1}. {library.inLibrary[i].name}, {library.inLibrary[i].pages}, In");
                }
            }

            if(library.outOfLibrary.Count != 0)
            {
                Console.WriteLine("\nKsiążki wypożyczone:\n");
                for(int j = 0; j < library.outOfLibrary.Count; j++)
                {
                    Console.WriteLine($"{j+1}. {library.outOfLibrary[j].name}, {library.outOfLibrary[j].pages}, Out");
                }
            }
            char choice = ' ';
            Console.WriteLine("\nOpcje do wyboru:\n" + 
                                        "Wypożycz książkę - wciśnij l\n" + 
                                        "Zwróć książkę - wciśnij i\n" + 
                                        "Usuń książkę z biblioteki - wciśnij u\n" +
                                        "Wróć do menu - wciśnij m");
            choice = Console.ReadKey().KeyChar;
            if(choice == 'l' || choice == 'i' || choice == 'u')
            {
                AdditionalMethods.ChooseBook(library, choice);
            }
            if(choice == 'm')
            {
                Menu(library);
            }
            else
            {
                ShowListOfBooks(library);
            }
        }

        public static void InsertNewBook(Library library)
        {
            Console.Clear();
            Book newBook = new Book();
            Console.WriteLine("Wpisz nazwę");
            newBook.name = Console.ReadLine();
            Console.WriteLine("\nWpisz liczbę stron");
            var num = Console.ReadLine();
            bool check = Int32.TryParse(num, out int choose);
            if(check)
            {
                newBook.pages = choose;
            }
            else
            {
                Console.WriteLine("\nTo nie jest liczba! Spróbuj jeszcze raz!");
                Thread.Sleep(2000);
                InsertNewBook(library);
            }
            newBook.borrowed = false;
            library.inLibrary.Add(newBook);
            Menu(library);
        }
    }
}