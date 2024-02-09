using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Node
{
    public char Symbol { get; set; }
    public int Frequency { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }
}

class Huffman
{
    public static Dictionary<char, string> BuildHuffmanTree(string input)
    {
        Dictionary<char, int> frequencyTable = input
            .GroupBy(c => c)
            .ToDictionary(group => group.Key, group => group.Count());

        List<Node> nodes = frequencyTable
            .Select(pair => new Node { Symbol = pair.Key, Frequency = pair.Value })
            .ToList();

        while (nodes.Count > 1)
        {
            List<Node> orderedNodes = nodes.OrderBy(node => node.Frequency).ToList();

            if (orderedNodes.Count >= 2)
            {
                List<Node> taken = orderedNodes.Take(2).ToList();

                Node parent = new Node
                {
                    Symbol = '*',
                    Frequency = taken[0].Frequency + taken[1].Frequency,
                    Left = taken[0],
                    Right = taken[1]
                };

                nodes.Remove(taken[0]);
                nodes.Remove(taken[1]);
                nodes.Add(parent);
            }
        }

        Node root = nodes.FirstOrDefault();

        Dictionary<char, string> huffmanTable = new Dictionary<char, string>();
        if (root != null)
        {
            AssignCodes(root, "", huffmanTable);
        }

        return huffmanTable;
    }

    private static void AssignCodes(Node node, string code, Dictionary<char, string> huffmanTable)
    {
        if (node != null)
        {
            if (node.Left == null && node.Right == null)
            {
                huffmanTable[node.Symbol] = code;
            }
            else
            {
                AssignCodes(node.Left, code + "0", huffmanTable);
                AssignCodes(node.Right, code + "1", huffmanTable);
            }
        }
    }

    public static string Compress(string input, Dictionary<char, string> huffmanTable)
    {
        StringBuilder compressed = new StringBuilder();

        foreach (char c in input)
        {
            compressed.Append(huffmanTable[c]);
        }

        return compressed.ToString();
    }

    public static string Decompress(string compressed, Dictionary<char, string> huffmanTable)
    {
        StringBuilder decompressed = new StringBuilder();
        string currentCode = "";

        foreach (char bit in compressed)
        {
            currentCode += bit;

            if (huffmanTable.ContainsValue(currentCode))
            {
                char symbol = huffmanTable.First(pair => pair.Value == currentCode).Key;
                decompressed.Append(symbol);
                currentCode = "";
            }
        }

        return decompressed.ToString();
    }
}

class Program
{
    static void Main(string[] args)
    {
        string input = "this is an example for huffman encoding";

        Dictionary<char, string> huffmanTable = Huffman.BuildHuffmanTree(input);
        string compressed = Huffman.Compress(input, huffmanTable);
        string decompressed = Huffman.Decompress(compressed, huffmanTable);

        Console.WriteLine("Original: " + input);
        Console.WriteLine("Compressed: " + compressed);
        Console.WriteLine("Decompressed: " + decompressed);
    }
}
