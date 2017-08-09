using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    class Collection
    {
        RegularViewer[] arrays;

        public Collection()
        {
            arrays = new RegularViewer[] { new RegularViewer(), new RegularViewer(), new RegularViewer() };
        }
        public RegularViewer this[int index]
        {
            get { return arrays[index]; }
            set { arrays[index] = value; }
        }
    }
}

