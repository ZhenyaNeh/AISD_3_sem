using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_06
{
    public class HuffmanNode
    {
        public char Symbol { get; set; }
        public int Repetitions { get; set; }
        public HuffmanNode Left { get; set; }
        public HuffmanNode Right { get; set;}
    }
}
