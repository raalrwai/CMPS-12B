//Rami ALrwais
//raalrwai
//12m
//Reverse.java
//4/08/16
//File takes in an input file full which contains a String and reverses the 
//string on a new line for each token
import java.io.*;
import java.util.Scanner;

class FileReverse{
  public static void main(String[] args) throws IOException{

    Scanner in = null;
    PrintWriter out = null;
    String line = null;
    String[] token = null;
    int i, n, lineNumber = 0;

    // check number of command line arguments is at least 2 otherwise prints 
    // prints correct usage message
    if(args.length < 2){
      System.out.println("Usage: FileReverse <input file> <output file>");
      System.exit(1);
    }

    // open files 1 and 2 based off user input
    in = new Scanner(new File(args[0]));
    out = new PrintWriter(new FileWriter(args[1]));

    // read lines from in useing a while statment to extract and print tokens
    while( in.hasNextLine() ){
      lineNumber++;

      // trim leading and trailing spaces, then add one trailing space so 
      // split works on blank lines
      line = in.nextLine().trim() + " "; 

      // split line around white space 
      token = line.split("\\s+");  

      //calls to function stringReverse to print out tokens in reverse order    
     // n = token.length;
      // out.println("Line " + lineNumber + " contains " + n + " tokens:");
      for(i=0; i<token.length; i++){
        n = token[i].length();
        out.println(stringReverse(token[i], n));
      }
    }

    // close files 1 and 2
    in.close();
    out.close();
  
}//Recursively calls stringReverse to print out the
//tokens each backwards 
public static String stringReverse(String s, int n){
  if(n>0){
    return  s.charAt(n-1) + stringReverse(s,n-1); 
  }  
     return "";//Returns a blank string
}
}
