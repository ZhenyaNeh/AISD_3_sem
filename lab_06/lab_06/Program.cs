using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_06
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string input = "Nehaychik";
            Dictionary<char, string> huffmanTable = Huffman.BuildHuffmanTree(input);
            
            string encription = Huffman.Encryption(input, huffmanTable);
            Console.WriteLine($"Encription: {encription}");
            string decription = Huffman.Decryption(encription, huffmanTable);
            Console.WriteLine($"Decription: {decription}");
        }
    }
}
