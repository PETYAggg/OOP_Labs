using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class Paydesk
    {
        string date=null;
        Movie movie = new Movie();
        Kinozal kinozal=new Kinozal();
        Timetable timetable = new Timetable();
        //Ticket ticket;


        public void SayHi()
        {
            string str = "";
            char pad = '-';
            Console.WriteLine(str.PadLeft(40, pad));
            Console.WriteLine("Welcome to the Petro_Cinema Paydesk!");
            Console.WriteLine(str.PadLeft(40, pad));
        }
        public void MainMenu()
        {   string key;
            string str = "";
            char pad = '-';
           

            MainMenu:
            Console.WriteLine(str.PadLeft(40, pad));

            do
            {
                Console.WriteLine("1.Show time table");
                Console.WriteLine("2.Set Date");
                Console.WriteLine("3.Watch Movies info");
                Console.WriteLine("type exit or q to quit");
                key =Console.ReadLine();
            }
            while (key!="exit"&& key!="q"&& key!="1" && key != "2" && key != "3");

            if(key=="1")
            {
                ShowTimeTable();
            
            }

            if(key=="2")
            {
                Console.WriteLine("Input date in format ddmmyyyy");
                date = Console.ReadLine();
                goto MainMenu;
                
            }

            if(key=="3")

            {
                Movie movik = new Movie();
                movik.GetMovies("D:\\TRY\\lab8\\lab8\\movies\\movielist.txt");
                MainMenu();
            }
        }
        void ShowTimeTable()
        {


            if (date == null)
            {
                Console.WriteLine("Input date in format ddmmyyyy");
                date = Console.ReadLine();
            }
            ShowTime:
            while(!timetable.GetTimeTable("D:\\TRY\\lab8\\lab8\\schedules\\" + date + ".txt"))
            {
                Console.WriteLine("Try another date");
                Console.WriteLine("Input date in format ddmmyyyy");
                date = Console.ReadLine();
                
            }


        willreturn:
            
                Console.WriteLine("1.Search ");
                Console.WriteLine("2.Look at zal ");
                Console.WriteLine("3.Main Menu");
                string key = Console.ReadLine();



            if (key=="1")
                {

                string temp = "y";
                while (temp == "y")
                {
                    temp = "n";
                    Search();                                                               //SEARCH
                    Console.WriteLine("Find anything else? y/n");
                    temp = Console.ReadLine();
                }
                goto willreturn;
                 }
            
            if (key == "2")
            {
                inputtime:                                                                                  //OPEN ZAL
                Console.WriteLine("Input time in such format hh.mm");
                string time = Console.ReadLine();
                if (!ShowZal(time)) goto inputtime;
                Console.WriteLine("1.Buy ticket for this movie on this time");
                Console.WriteLine("2.Look at another zal");
                Console.WriteLine("3.Main Menu");
                string temp = Console.ReadLine();
                    if(temp=="1")
                    {
                Sell_exact:
                    Ticket ticket = new Ticket();
                    
                    ticket.Sell_exact(time, date);
                    ShowZal(time);
                    Console.WriteLine("Buy another? y/n");
                    string t = Console.ReadLine();
                    if (t == "y") goto Sell_exact;
                    else goto ShowTime;
                    }
                if (temp == "2") goto inputtime;
                if (temp == "3") MainMenu();
                   

            }

            if(key=="3")
            {
                MainMenu();             //MAINMENU
                
            }

            }
        void Search()
        {
            Console.WriteLine("Enter your request: ");
          string  findrequest = Console.ReadLine();
            timetable.FindByName("D:\\TRY\\lab8\\lab8\\schedules\\" + date + ".txt", findrequest);
            
        }
        bool ShowZal(string time)
        {
            if (kinozal.ReadFromFile("D:\\TRY\\lab8\\lab8\\kinozalu\\"+date+"\\"+date + "h" + time + ".txt")) 
            {
                kinozal.Show();
                return true;
            }
            else return false;
        }

      
    }
}
