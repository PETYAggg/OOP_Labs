using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class Ticket : ReadFromFile
    {
        
        Movie movie;
        RegularViewer viewer;
        Kinozal kinozal = new Kinozal();
        string name;
        string personalnumber;
        string time;
        double price;
        bool sold = false;
        int placerow;
        int placecolumn;
        string date;



        public Ticket()
        {
            name = " ";
            personalnumber = "0000000";
            sold = false;
        }
        public void Sell_exact(string time, string date)
        {
            this.date = date;
            this.time = time;

            Console.WriteLine("Input name (if you want annonymously type - )");
            name = Console.ReadLine();


        Rewrite:

            Console.WriteLine("Input place row");
            if (!int.TryParse(Console.ReadLine(), out placerow)) goto Rewrite;
            Console.WriteLine("Input place column");
            if (!int.TryParse(Console.ReadLine(), out placecolumn)) goto Rewrite;

            if (name != "-" && name != " " && name != "\n")
            {
                if (sold) return;
                else
                {
                    viewer = new RegularViewer();
                    viewer.name = name;

                    Timetable timetable = new Timetable();
                    timetable.date = date + ".txt";
                    Movie movie = new Movie();


                    movie.SetMovieFromFile("D:\\TRY\\lab8\\lab8\\movies\\" + timetable.GetMovieByTime(time) + ".txt");
                    this.movie = movie;
                    viewer.GetViewer(name);
                    price = movie.Price() * (1-viewer.discount * 0.01);



                }


            }

            else
            {
                name = " ";


                Timetable timetable = new Timetable();
                timetable.date = date + ".txt";
                Movie movie = new Movie();


                movie.SetMovieFromFile("D:\\TRY\\lab8\\lab8\\movies\\" + timetable.GetMovieByTime(time) + ".txt");
                this.movie = movie;
                price = movie.Price();
            }
            Console.WriteLine("Your price is " + price);
            Console.WriteLine("Buy?");
            string ti = Console.ReadLine();
            if (ti != "y") return;

            kinozal.ReadFromFile("D:\\TRY\\lab8\\lab8\\kinozalu\\" + date + "\\" + date + "h" + time + ".txt");
            if (!kinozal.Buy(placerow, placecolumn)) goto Rewrite;
            kinozal.WriteInFile("D:\\TRY\\lab8\\lab8\\kinozalu\\" + date + "\\" + date + "h" + time + ".txt");
            Random random = new Random();
            int randomNumber = random.Next(0, 100000);
            personalnumber = randomNumber.ToString();
            sold = true;


        WriteInFile:
            if (!WriteInFile("D:\\TRY\\lab8\\lab8\\ticketbase\\tickets" + date + ".txt"))
            {
                File.Create("D:\\TRY\\lab8\\lab8\\ticketbase\\tickets" + date + ".txt");

                goto WriteInFile;

            }


            if (name != " " && name != null)
            {
                viewer.quantity++;
                if (viewer.discount < 50) viewer.discount += 1;
                viewer.RewriteFile("viewerbase", name, viewer.discount, viewer.quantity);

            }
            Druk("D:\\TRY\\lab8\\lab8\\Druk\\"+personalnumber.ToString()+".txt");

        }
        public bool WriteInFile(string filename)
        {

            if (!File.Exists(filename))
            {
                Console.WriteLine("Eror Opening file");
                return false;
            }
            else
            {

                StreamWriter writer = new StreamWriter(File.Open(filename, FileMode.Append));

                writer.Write(name +" "+date +" " + time + " " + placerow + " " + placecolumn + " " + personalnumber);
                writer.Write(Environment.NewLine);


                writer.Close();
                return true;
            }
        }
        public void Druk(string filename)
        {

            string key;
            string str = "";
            char pad = '-';

            StreamWriter writer = new StreamWriter(File.Create(filename));

            writer.WriteLine(str.PadLeft(40, pad));

            writer.WriteLine("Movie: "+movie.Name());
            writer.WriteLine("Time: "+time);
            writer.WriteLine("Duration: "+movie.Length());
            writer.WriteLine(name);
            writer.WriteLine();
            writer.WriteLine(personalnumber.ToString());
            writer.WriteLine(str.PadLeft(40, pad));
            writer.Close();
        }
    }
}


