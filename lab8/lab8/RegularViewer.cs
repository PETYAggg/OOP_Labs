using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class RegularViewer: Viewer
    {
        public int discount;
        public int quantity;

       public RegularViewer()
        {
            name = null;
            discount = 0;
            quantity = 0;
        }

       public bool GetViewer(string viewer)
        { 
           string filename = "viewerbase.txt";
            string getdiscount = null;
            if (File.Exists(filename))

                foreach (var line in File.ReadAllLines(filename))
                {
                    if (line.Contains(viewer))
                    {
                        getdiscount = line;
                       // Console.WriteLine(line);
                    }
                }
            
            else
            {
                // FileStream file1 = new FileStream(date, FileMode.Create);
                Console.WriteLine("Base doesn't exist please create a database with \"viewerbase.txt\" filename. ");
            }

            if (getdiscount == null) return false;
            else
            {
                string[] viewerinput = getdiscount.Split(' ');
                name = viewerinput[0];
                int.TryParse(viewerinput[1], out discount);
                int.TryParse(viewerinput[2], out quantity);
                //   Console.WriteLine(discount);
                return true;
            }
            
        }

       public   void RewriteFile(string filename,string name,int discount, int quantity)
        {
            string temp=null;
            foreach (var line in File.ReadAllLines(filename+".txt"))
            {
                if (line.Contains(name))
                {

                    temp = line;
                }
                
            }
            if (temp != null)
            {
                string text = File.ReadAllText(filename + ".txt");
                text = text.Replace(temp, name + " " + discount + " " + quantity);
                File.WriteAllText(filename + ".txt", text);
               
            }
            else
            {
                StreamWriter sw = File.AppendText(filename + ".txt");
                sw.WriteLine(name + " " + discount + " " + quantity);
                sw.Close();
            }
        }


        
    }
}
