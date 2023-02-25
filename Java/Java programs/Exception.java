public class Exception
{
    public static void main(String[] args)
    {
        try{
            Divide d = new Divide();
            d.divi();
        }
        catch(java.lang.Exception e)
        {
            System.out.println("Main function: Exception Handeled");
        }
    }
}

class Divide
{
    void divi() throws java.lang.Exception
    {
        System.out.println("program starts");
        try{
            int div = 10/0;
            System.out.println("ans:"+div);
        }
        catch(java.lang.Exception e)
        {
            System.out.println("Exception Handled");
            throw e;
        }
        finally{
            System.out.println("program end");
        }
    }
}