using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class Timetable
    {
        public string date;

        public bool GetTimeTable(string date)
        {
            
            if (File.Exists(date))
            {
                FileStream file1 = new FileStream(date, FileMode.Open);
                StreamReader reader = new StreamReader(file1);
                string str = "";
                char pad = '-';
                Console.WriteLine(str.PadLeft(40, pad));
                Console.WriteLine(reader.ReadToEnd());
                Console.WriteLine(str.PadLeft(40, pad));
                reader.Close();

                return true;
            }
            else
            {
               // FileStream file1 = new FileStream(date, FileMode.Create);
               // Console.WriteLine("Timetable doesnt exist. Please input the data and proceed");
                return false;
            }
         
        }


        public void FindByName(string date, string name)
        {
         //   date += ".txt";
            string str = "";
            char pad = '-';
            Console.WriteLine(str.PadLeft(40, pad));
           // Console.WriteLine("You're searching for  " + name + "  in " + date);
            Console.WriteLine("Searching results:");


            if (File.Exists(date))
            {
                

                foreach (var line in File.ReadAllLines(date))
                {
                    if (line.Contains(name))
                    {
                        Console.WriteLine(line);

                    }
                }
            }
            else
            {
                // FileStream file1 = new FileStream(date, FileMode.Create);
                Console.WriteLine("Timetable doesnt exist. Please input the data and proceed");
            }
            
            Console.WriteLine(str.PadLeft(40, pad));
        }

        public string GetMovieByTime(string time)
        {   

            string wantedfilm = null;
            if (File.Exists("D:\\TRY\\lab8\\lab8\\schedules\\"+date))
            {


                foreach (var line in File.ReadAllLines("D:\\TRY\\lab8\\lab8\\schedules\\" + date))
                {
                    if (line.Contains(time))
                    {
                        wantedfilm = line;

                    }

                }

                if (wantedfilm == null) return null;
                else
                {
                    string[] viewerinput = wantedfilm.Split(' ');
                    return viewerinput[1];

                }
            }
            else
            {
                // FileStream file1 = new FileStream(date, FileMode.Create);
                Console.WriteLine("Timetable doesnt exist. Please input the data and proceed");
                return null; 
            }
        }

        public override string ToString()
        {
            return date;
        }
    }
}
