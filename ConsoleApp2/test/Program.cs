using System;
using System.Globalization;

class Program
{
    static void Main()
    {
        // Устанавливаем культуру форматирования, где используется запятая как разделитель
        CultureInfo culture = new CultureInfo("ru-RU"); // Русская культура, где используется запятая

        // Применяем установленную культуру форматирования
        CultureInfo.DefaultThreadCurrentCulture = culture;
        CultureInfo.DefaultThreadCurrentUICulture = culture;

        double value = 1234.56;

        // Теперь, если вы форматируете число, оно будет использовать запятую как разделитель дробной части
        string formattedValue = string.Format("{0:0.00}", value);

        Console.WriteLine("Форматированное значение: " + formattedValue); // Вывод с запятой вместо точки
    }
}