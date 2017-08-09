using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
   abstract class ReadFromFile
    {
       virtual public bool  OpenAndOutputFile(string filename)
        {

            if (File.Exists(filename))
            {
                FileStream file1 = new FileStream(filename, FileMode.Open);
                StreamReader reader = new StreamReader(file1);
                string str = "";
                char pad = '-';
                Console.WriteLine(str.PadLeft(40, pad));
                Console.WriteLine(reader.ReadToEnd());
                Console.WriteLine(str.PadLeft(40, pad));
                reader.Close();

                return true;
            }
            else return false;

        }
    }
}
