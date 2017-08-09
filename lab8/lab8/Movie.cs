using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class Movie : ReadFromFile
    {
        private int base_price = 0;
        private string name = "Default";
        private int length_in_min ;
        private string genre = "default";
        private string info = "nothing";

        public bool SetMovieFromFile(string filename)
        {
            if (!File.Exists(filename)) return false;
            else
            {
                FileStream file1 = new FileStream(filename, FileMode.Open);
                StreamReader reader = new StreamReader(file1);
                base_price = Convert.ToInt16(reader.ReadLine());
                name = reader.ReadLine();
                length_in_min = Convert.ToInt16(reader.ReadLine());
                genre = reader.ReadLine();

                info = reader.ReadToEnd();

                reader.Close();
                return true;
            }
        }

        public string Name()
        {
            return name.ToString();
        }

        public int Length()
        {
            return length_in_min;
        }

        public string Genre()
        {
            return genre;
        }

     

        public string Info()
        {
            return info;
        }

        public int Price()
        {
            return base_price;
        }

   public     bool GetMovies(string filename)
        {
            if (!File.Exists(filename))
            {
                Console.WriteLine("Eror Opening file");
                return false;
            }
            else
            {

                StreamReader reader = new StreamReader(File.Open(filename, FileMode.Open));

                Console.WriteLine(reader.ReadToEnd());
                reader.Close();
                typemoviename:
                Console.WriteLine("Type movie name: ");
                if (!SetMovieFromFile("D:\\TRY\\lab8\\lab8\\movies\\"+Console.ReadLine()+".txt")) goto typemoviename;


                Console.WriteLine("Name:"+name);
                Console.WriteLine("Duration" + length_in_min.ToString());
                Console.WriteLine("Genre:" + genre);
                Console.WriteLine("Info:");
                Console.WriteLine(info);

               
                return true;
            }
        }


        public override string ToString()
        {
            return name;
        }


    }
}
