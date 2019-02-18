//Rami Alrwais
//raalrwai
//cmps12b
//DictionaryTest
//Tests out all the functions of Dictionary.java in 
public class DictionaryTest {

  public static void main(String[] args) {
    Dictionary A = new Dictionary();
    System.out.println(A.isEmpty());
    A.insert("1","f");
    System.out.println(A.isEmpty());
    A.insert("5","h");
    System.out.println(A.size());
    A.insert("3","a");
    System.out.println("*********");
    System.out.println(A.size());
    System.out.println("*********");
    A.insert("8","c");
    A.insert("2","e");
    A.insert("9","3");
    //A.delete("4");
    //A.insert("7","e");
    //throws exception
    A.delete("1");
    System.out.println(A);
    System.out.println(A.size());
    A.delete("3");
    System.out.println(A.size());
    System.out.println(A);
    System.out.println(A.lookup("5"));
    A.insert("1", "f"); //throws DuplicateKeyException
   // A.delete("10"); //throws KeyNotFoundException
   // A.makeEmpty();
    System.out.println(A.size() + " " + A.isEmpty());
  }
}
