using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_08
{
    internal class Product
    {
        public string? Name { get; set; }   
        public int ItemWeight { get; set; }   
        public int Cost { get; set; }   

        public Product(string? name, int itemWeight, int cost)
        {
            Name = name;
            ItemWeight = itemWeight;
            Cost = cost;
        }

        public override string ToString()
        {
            return $"[ Name: {Name} \t|| " +
                   $"ItemWeight: {ItemWeight} \t|| " +
                   $"Cost: {Cost} ]";
        }
    }
}
