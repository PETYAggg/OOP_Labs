using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class Kinozal
    {
        bool[][] Zal;
        int columns;
        int rows;
        public Kinozal()
        { }

        public Kinozal(int rows, int columns)
        {
            this.columns = columns;
            this.rows = rows;
            Zal = new bool[columns][];
            for (int i = 0; i < columns; i++)
                Zal[i] = new bool[rows];
        }


        public Kinozal(string a)
        {


            Console.WriteLine("You entered manual setting of cinema seat scheme");


            int r = 0;
            Console.WriteLine("Enter the quantity of rows");
            r = Convert.ToInt16(Console.ReadLine());
            Zal = new bool[r][];
            this.rows = r;
            for (int i = 0; i < r; i++)
            {
                int c;
                Console.WriteLine("Enter Number of Seats in row number: " + i);
                c = Convert.ToInt16(Console.ReadLine());
                Zal[i] = new bool[c];
            }



        }
    
        

        public void Show()
        {
            Console.Write("     ");
            for (int j = 0; j < Zal[0].Length; j++)
            {   if (j < 10)
                    Console.Write((j + 1) + "  ");
                else
                    Console.Write((j + 1) + " ");
            }
            Console.WriteLine();

            for (int i = 0; i < Zal.Length; i++)
            {   if(i<9)
                   Console.Write("row"+(i+1)+" ");
                else
                    Console.Write("row" + (i + 1) );
                for (int j=0;j<Zal[i].Length;j++)
                {
                    if (Zal[i][j] == true) Console.Write(" 0 ");
                    if (Zal[i][j] == false) Console.Write(" x ");
                }
             

                Console.WriteLine(" ");
            }
         
        }


        public void WriteInFile(string filename)
        {

            if (!File.Exists(filename))
                Console.WriteLine("Eror Opening file");

            else
            {
                StreamWriter writer = new StreamWriter(File.Open(filename, FileMode.Open));


                for (int i = 0; i < Zal.Length; i++)
                {
                    for (int j = 0; j < Zal[i].Length; j++)
                    {
                        writer.Write((Zal[i][j] ? "0" : "x"));
                    }
                    writer.Write(Environment.NewLine);

                }
                writer.Close();
            }
            }
        

        public bool ReadFromFile(string filename)
        {
            
            if (File.Exists(filename))
            {
                FileStream file1 = new FileStream(filename, FileMode.Open);
                StreamReader reader = new StreamReader(file1);
                rows = 0;
                while (!reader.EndOfStream)
                {
                    reader.ReadLine();
                        rows++;
                 }
               
                

                Zal = new bool[rows][];

                file1.Position = 0;
                reader.DiscardBufferedData();

                string temp;
                int k = 0;
                while (!reader.EndOfStream)
                {   
                   temp= reader.ReadLine();
                    Zal[k] = new bool[temp.Length];
                    for(int i=0;i<temp.Length;i++)
                    {
                        if (temp[i] == 'x') Zal[k][i] = false;
                        if (temp[i] == '0') Zal[k][i] = true;
                    }

                    k++;
                }
                reader.Close();

                return true;
            }
            else
            {
                // FileStream file1 = new FileStream(date, FileMode.Create);
                Console.WriteLine("Timetable doesnt exist. Please input the data and proceed");
                return false;
            }

        }

        public bool Buy(int row, int column)
        {
            row = row - 1;
            column = column - 1;
            if (Zal[row][column] == true)
            {
                Console.WriteLine("Already bought!");
                return false;
            }
            if (row > rows)
            {
                Console.WriteLine("Erooor no place");
                return false;
            }
            if (Zal[row].Length<column)
            {
                Console.WriteLine("Erooor no place");
                return false;
            }

            Zal[row][column] = true;
            return true;
        }

    }
}
