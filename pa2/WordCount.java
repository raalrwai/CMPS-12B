//-----------------------------------------------------------------------------
// WordCount.java
// Counts the number of lines, words, and characters in a text file.  The 
// output is similar to that of the unix command wc, i.e. 
//
//               #lines #words #characters filename
//
//-----------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

class WordCount {

   public static void main(String[] args) throws IOException {
      
      int lineCount, wordCount, charCount, i, j, k;
      String line;
      String[] token = null;
      Scanner in = null;
      
      // check command line arguments
      if(args.length != 1){
         System.err.println("Usage: WordCount file");
         System.exit(1);
      }
      
      // count lines, words, and chars in file
      in = new Scanner(new File(args[0]));
      lineCount = wordCount = charCount = 0;
      while( in.hasNextLine() ){
         line = in.nextLine().trim()+" ";  
         // trim() and +" " are needed to count blank lines correctly
         // see the example SplitTest.java
         token = line.split("[ \\t\\n]+");  // same as "\\s+"
         lineCount += 1;
         wordCount += token.length;
         charCount += line.length() + 1;  // why the  + 1 ?
      }
      in.close();
      
      System.out.println( " "+lineCount+" "+wordCount+" "+charCount+" "+args[0] );
      
   }
}
