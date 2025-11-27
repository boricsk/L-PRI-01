namespace NullazhatoTipusok
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int? nullableInt = 10;
            double? nullableDouble = 3.14;
            bool? nullableBool = null;
            char? nullableChar = 'a';
            int?[] arrayOfNullableInts = new int?[10];
            // Error! Strings are reference types!
            // string? s = "oops";

            //A? egyszerűsítés a Nullable<T> használatához
            Nullable<int> nullableInt1 = 10;
            Nullable<double> nullableDouble1 = 3.14;
            Nullable<bool> nullableBool1 = null;
            Nullable<char> nullableChar1 = 'a';
            Nullable<int>[] arrayOfNullableInts1 = new Nullable<int>[10];

            //A ?? Operátor
            Console.WriteLine("***** Fun with Nullable Data *****\n");
            DatabaseReader dr = new DatabaseReader();
            // If the value from GetIntFromDatabase() is null,
            // assign local variable to 100.
            int myData = dr.GetIntFromDatabase() ?? 100;
            Console.WriteLine("Value of myData: {0}", myData);

            //Ha nem a ?? operátort használjuk
            int? moreData = dr.GetIntFromDatabase();
            if (!moreData.HasValue)
                moreData = 100;
            Console.WriteLine("Value of moreData: {0}", moreData);

        }
    }
}
