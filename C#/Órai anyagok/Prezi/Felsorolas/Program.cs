namespace Felsorolas
{
    internal class Program
    {
        enum EmpType : byte
        {
            Manager = 10, Grunt = 1, Contractor = 100, VicePresident = 9
        }
        static void Main(string[] args)
        {
            EmpType e2 = EmpType.Contractor;
            Console.WriteLine("=> Information about {0}", e2.GetType().Name);
            Console.WriteLine("Underlying storage type: {0}", Enum.GetUnderlyingType(e2.GetType()));
            //Array enumData = Enum.GetValues(e2.GetType());
            Array enumData = Enum.GetValues(typeof(EmpType));
            Console.WriteLine("This enum has {0} members.", enumData.Length);
            for (int i = 0; i < enumData.Length; i++)
            {
                Console.WriteLine("Name: {0}, Value: {0:D}", enumData.GetValue(i));
            }

        }
    }
}
