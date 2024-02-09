using Microsoft.CSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace lab_06
{
    internal class Huffman
    {
        public static Dictionary<char, string> BuildHuffmanTree(string input)
        {
            Dictionary<char, int> frequencyTable = input
                .GroupBy(c => c)
                .ToDictionary(group => group.Key, group => group.Count());

            List<HuffmanNode> nodes = frequencyTable
                .Select(pair => new HuffmanNode { Symbol = pair.Key, Repetitions = pair.Value })
                .ToList();

            while (nodes.Count > 1)
            {
                List<HuffmanNode> orderedNodes = nodes.OrderBy(node => node.Repetitions).ToList();

                if (orderedNodes.Count >= 2)
                {
                    List<HuffmanNode> taken = orderedNodes.Take(2).ToList();

                    HuffmanNode parent = new HuffmanNode
                    {
                        Symbol = '\0',
                        Repetitions = taken[0].Repetitions + taken[1].Repetitions,
                        Left = taken[0],
                        Right = taken[1]
                    };

                    nodes.Remove(taken[0]);
                    nodes.Remove(taken[1]);
                    nodes.Add(parent);
                }
            }

            HuffmanNode root = nodes.FirstOrDefault();

            Dictionary<char, string> huffmanTable = new Dictionary<char, string>();
            if (root != null)
            {
                BuildHuffCode(root, huffmanTable, "");
            }

            foreach(var sym in huffmanTable)
                Console.WriteLine($"{sym.Key} = {sym.Value}");

            return huffmanTable;
        }

        public static void BuildHuffCode(HuffmanNode node, Dictionary<char, string> huffCodes, string code)
        {
            if (node == null)
                return;

            if (node.Symbol != '\0')
                huffCodes[node.Symbol] = code;

            BuildHuffCode(node.Left, huffCodes, code + "0");
            BuildHuffCode(node.Right, huffCodes, code + "1");
        }

        public static string Encryption(string input, Dictionary<char, string> huffCodes)
        {
            var encription = new StringBuilder();
            foreach (var symb in input) 
            {
                if (huffCodes.TryGetValue(symb, out var code))
                    encription.Append(code);
                else
                    throw new Exception($"Symbol '{symb}' does not have a Huffman code.");
            }

            return encription.ToString();
        }

        public static string Decryption(string compressed, Dictionary<char, string> huffTable)
        {
            var decription = new StringBuilder();
            string stringCode = "";

            foreach (var symb in compressed)
            {
                stringCode += symb;

                if(huffTable.ContainsValue(stringCode))
                {
                    char symbol = huffTable.First(val => val.Value == stringCode).Key; 
                    decription.Append(symbol);
                    stringCode = "";
                }
            }

            return decription.ToString();
        }

    }
}
